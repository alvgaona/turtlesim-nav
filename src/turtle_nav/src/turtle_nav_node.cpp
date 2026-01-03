#include "turtle_nav_node.h"

#include <spline.h>

#include <casadi/casadi.hpp>
#include <casadi/core/optistack.hpp>
#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <memory>
#include <rclcpp/node.hpp>
#include <rerun.hpp>
#include <rerun/archetypes/arrows2d.hpp>
#include <rerun/archetypes/boxes2d.hpp>
#include <rerun/archetypes/line_strips2d.hpp>
#include <rerun/archetypes/points2d.hpp>
#include <rerun/archetypes/view_coordinates.hpp>
#include <rerun/recording_stream.hpp>
#include <std_srvs/srv/detail/empty__struct.hpp>
#include <string_view>
#include <turtlesim/msg/detail/pose__struct.hpp>

#include "point_stabilizer.h"
#include "trajectory_tracker.h"
#include "turtle_nav/srv/detail/follow_path__struct.hpp"

using namespace std::chrono_literals;

TurtleNav::TurtleNav() : Node("turtle_nav"), rec_("turtle_nav") {
  publisher_ =
    this->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel", 10);
  subscriber_ = this->create_subscription<turtlesim::msg::Pose>(
    "turtle1/pose",
    10,
    [this](const std::shared_ptr<const turtlesim::msg::Pose>& msg) {  // NOLINT
      current_pose_ = std::const_pointer_cast<turtlesim::msg::Pose>(msg);
    }
  );
  goto_service_ = this->create_service<turtle_nav::srv::GoTo>(
    "turtle_nav/goto",
    [this](
      const std::shared_ptr<turtle_nav::srv::GoTo::Request>& request,
      const std::shared_ptr<turtle_nav::srv::GoTo::Response>& response
    ) { go_to(request, response); }
  );
  follow_path_service_ = this->create_service<turtle_nav::srv::FollowPath>(
    "turtle_nav/follow_path",
    [this](
      const std::shared_ptr<turtle_nav::srv::FollowPath::Request>& request,
      const std::shared_ptr<turtle_nav::srv::FollowPath::Response>& response
    ) { follow_path(request, response); }
  );
  cancel_service_ = this->create_service<std_srvs::srv::Empty>(
    "turtle_nav/cancel",
    [this](
      [[maybe_unused]] const std::shared_ptr<std_srvs::srv::Empty::Request>&
        request,
      [[maybe_unused]] const std::shared_ptr<std_srvs::srv::Empty::Response>&
        response
    ) { timer_ = nullptr; }
  );

  point_stabilizer_ = PointStabilizer({
    .horizon_length = 25,
    .state_dim = 3,
    .input_dim = 2,
    .dt = 0.05,
    .Q = casadi::DM::diag({10.0, 150.0}),
    .R = casadi::DM::diag({0.05, 0.05}),
  });

  trajectory_tracker_ = TrajectoryTracker({
    .horizon_length = 20,
    .state_dim = 3,  // [x, y, θ]
    .input_dim = 2,  // [v, ω]
    .dt = 0.05,
    .Q = casadi::DM::diag({1000.0, 1000.0, 50.0}),  // Match MATLAB
    .R = casadi::DM::diag({100.0, 100.0}),            // Match MATLAB
  });

  rec_.spawn().exit_on_failure();

  rec_.log(
    "world/frame",
    rerun::Arrows2D::from_vectors({{1.0, 0.0}, {0.0, 1.0}})
      .with_origins({{-0.1, -0.1}, {-0.1, -0.1}})
      .with_colors({{255, 0, 0}, {0, 255, 0}})
      .with_labels({"x", "y"})
      .with_draw_order(0)
  );

  rec_.log(
    "world/landmarks",
    rerun::Points2D({{0, 0}, {10, 10}, {5, 5}, {0, 10}, {10, 0}})
      .with_draw_order(1)
  );

  rec_.log(
    "world/limits",
    rerun::Boxes2D::from_centers_and_half_sizes({{5.0f, 5.0f}}, {{5.0f, 5.0f}})
      .with_colors(rerun::Color(0, 0, 255))
      .with_labels({"limits"})
      .with_draw_order(0)
  );
}

void TurtleNav::go_to(
  const std::shared_ptr<turtle_nav::srv::GoTo::Request>& request,
  const std::shared_ptr<turtle_nav::srv::GoTo::Response>& response
) {
  point_stabilizer_.set_target({request->x, request->y, 0.0});

  rec_.log(
    "world/goal",
    rerun::Points2D({
                      {
                        static_cast<float>(request->x),
                        static_cast<float>(request->y),
                      },
                    })
      .with_colors(rerun::Color(255, 0, 0))
      .with_labels({"goal"})
  );

  timer_ = this->create_wall_timer(50ms, [this]() { go_to_callback(); });
  response->accepted = true;
}

void TurtleNav::follow_path(
  const std::shared_ptr<turtle_nav::srv::FollowPath::Request>& request,
  const std::shared_ptr<turtle_nav::srv::FollowPath::Response>& response
) {
  double average_speed = (request->speed > 0.0) ? request->speed : 1.0;

  // Build waypoints from request
  std::vector<rerun::Position2D> waypoints;
  waypoints.reserve(request->x.size());
  for (size_t i = 0; i < request->x.size(); ++i) {
    waypoints.emplace_back(request->x[i], request->y[i]);
  }

  rec_.log(
    "world/trajectory/control_points",
    rerun::Points2D(waypoints)
      .with_radii(0.1)
      .with_colors(rerun::Color(255, 0, 0))
      .with_draw_order(2)
  );

  // Generate spline trajectory (fixed number of samples)
  constexpr int num_samples = 500;
  auto xy = planar_trajectory(
    waypoints, static_cast<int>(waypoints.size()), 2, 2, num_samples
  );

  // Visualize reference trajectory
  std::vector<rerun::LineStrip2D> ref;
  for (size_t i = 0; i < xy.size() - 1; i++) {
    auto curr = xy[i];
    auto next = xy[i + 1];
    ref.push_back(
      rerun::LineStrip2D({{curr.x(), curr.y()}, {next.x(), next.y()}})
    );
  }
  rec_.log("world/trajectory/ref", rerun::LineStrips2D(ref).with_draw_order(2));

  trajectory_tracker_.reset();
  trajectory_tracker_.set_ref_traj(xy);
  trajectory_tracker_.set_v_ref(average_speed);

  timer_ = this->create_wall_timer(50ms, [this]() { follow_path_callback(); });
  response->accepted = true;
}

void TurtleNav::go_to_callback() {
  rec_.log("robot/state/x", rerun::Scalars(current_pose_->x));
  rec_.log("robot/state/y", rerun::Scalars(current_pose_->y));
  rec_.log("robot/state/orientation", rerun::Scalars(current_pose_->theta));

  real_traj_.emplace_back(current_pose_->x, current_pose_->y);

  rec_.log("world/robot/xy", rerun::Points2D(real_traj_));

  casadi::DM u = point_stabilizer_.step(casadi::DM({
    current_pose_->x,
    current_pose_->y,
    current_pose_->theta,
  }));

  auto u_0 = u(casadi::Slice(), 0);

  rec_.log("control/linear_velocity", rerun::Scalars(u_0(0).scalar()));
  rec_.log("control/angular_velocity", rerun::Scalars(u_0(1).scalar()));

  geometry_msgs::msg::Twist message;
  message.linear.x = u_0(0).scalar();
  message.linear.y = 0.0;
  message.angular.z = u_0(1).scalar();
  publisher_->publish(message);
}

void TurtleNav::follow_path_callback() {
  rec_.log("robot/state/x", rerun::Scalars(current_pose_->x));
  rec_.log("robot/state/y", rerun::Scalars(current_pose_->y));
  rec_.log("robot/state/orientation", rerun::Scalars(current_pose_->theta));

  real_traj_.emplace_back(current_pose_->x, current_pose_->y);

  rec_.log("world/robot/xy", rerun::Points2D(real_traj_));

  // Pass state: [x, y, θ]
  casadi::DM u = trajectory_tracker_.step(casadi::DM({
    current_pose_->x,
    current_pose_->y,
    current_pose_->theta,
  }));

  auto u_0 = u(casadi::Slice(), 0);
  double v = u_0(0).scalar();
  double omega = u_0(1).scalar();

  // Dead zone: force zero velocity when at goal to prevent drift
  if (trajectory_tracker_.reached_goal(current_pose_->x, current_pose_->y)) {
    v = 0.0;
    omega = 0.0;
  }

  rec_.log("control/linear_velocity", rerun::Scalars(v));
  rec_.log("control/angular_velocity", rerun::Scalars(omega));

  geometry_msgs::msg::Twist message;
  message.linear.x = v;
  message.linear.y = 0.0;
  message.angular.z = omega;
  publisher_->publish(message);
}

int main(const int argc, char* argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<TurtleNav>());
  rclcpp::shutdown();
  return 0;
}


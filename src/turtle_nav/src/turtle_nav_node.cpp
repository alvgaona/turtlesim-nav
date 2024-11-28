#include "turtle_nav_node.h"

#include <spline.h>

#include <casadi/casadi.hpp>
#include <casadi/core/optistack.hpp>
#include <chrono>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <rclcpp/node.hpp>
#include <rerun.hpp>
#include <rerun/archetypes/arrows2d.hpp>
#include <rerun/archetypes/boxes2d.hpp>
#include <rerun/archetypes/points2d.hpp>
#include <rerun/archetypes/view_coordinates.hpp>
#include <rerun/recording_stream.hpp>
#include <std_srvs/srv/detail/empty__struct.hpp>
#include <string_view>
#include <turtlesim/msg/detail/pose__struct.hpp>

#include "geometry_msgs/geometry_msgs/msg/twist.hpp"
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
    .dt = 0.02,
    .Q = casadi::DM::diag({10.0, 150.0}),
    .R = casadi::DM::diag({0.05, 0.05}),
  });

  trajectory_tracker_ = TrajectoryTracker({
    .horizon_length = 25,
    .state_dim = 3,
    .input_dim = 2,
    .dt = 0.02,
    .Q = casadi::DM::diag({10.0, 150.0}),
    .R = casadi::DM::diag({0.05, 0.05}),
  });

  rec_.spawn().exit_on_failure();

  rec_.log(
    "world/frame",
    rerun::Arrows2D::from_vectors({{1.0, 0.0}, {0.0, 1.0}})
      .with_origins({{-0.1, -0.1}, {-0.1, -0.1}})
      .with_colors({{255, 0, 0}, {0, 255, 0}})
      .with_labels({"x", "y"})
  );

  rec_.log(
    "world/landmarks",
    rerun::Points2D({{0, 0}, {10, 10}, {5, 5}, {0, 10}, {10, 0}})
  );

  rec_.log(
    "world/limits",
    rerun::Boxes2D::from_centers_and_half_sizes({{5.0f, 5.0f}}, {{5.0f, 5.0f}})
      .with_colors(rerun::Color(0, 0, 255))
      .with_labels({"limits"})
  );
}

void TurtleNav::go_to(
  const std::shared_ptr<turtle_nav::srv::GoTo::Request>& request,
  const std::shared_ptr<turtle_nav::srv::GoTo::Response>& response
) {
  point_stabilizer_.set_target({request->x, request->y, 0.0});

  rec_.log(
    "world/goal",
    rerun::Points2D({{static_cast<float>(request->x),
                      static_cast<float>(request->y)}})
      .with_colors(rerun::Color(255, 0, 0))
      .with_labels({"goal"})
  );

  timer_ = this->create_wall_timer(25ms, [this]() { go_to_callback(); });
  response->accepted = true;
}

void TurtleNav::follow_path(
  const std::shared_ptr<turtle_nav::srv::FollowPath::Request>& request,
  const std::shared_ptr<turtle_nav::srv::FollowPath::Response>& response
) {
  std::vector<rerun::Position2D> waypoints;
  waypoints.reserve(request->x.size());
  for (size_t i = 0; i < request->x.size(); ++i) {
    waypoints.emplace_back(request->x[i], request->y[i]);
  }
  [[maybe_unused]] double speed = request->speed;

  rec_.log("trajectory/control_points", rerun::Points2D(waypoints));

  auto xy =
    planar_trajectory(waypoints, static_cast<int>(waypoints.size()), 2, 2);

  // rec_.log("trajectory", rerun::Points2D(xy));

  trajectory_tracker_.set_ref_traj(std::move(xy));

  timer_ = this->create_wall_timer(25ms, [this]() { follow_path_callback(); });
  response->accepted = true;
}

void TurtleNav::go_to_callback() {
  rec_.log("x", rerun::Scalar(current_pose_->x));
  rec_.log("y", rerun::Scalar(current_pose_->y));
  rec_.log("orientation", rerun::Scalar(current_pose_->theta));

  real_traj_.emplace_back(current_pose_->x, current_pose_->y);

  rec_.log("world/xy", rerun::Points2D(real_traj_));

  casadi::DM u = point_stabilizer_.step(casadi::DM({
    current_pose_->x,
    current_pose_->y,
    current_pose_->theta,
  }));

  auto u_0 = u(casadi::Slice(), 0);

  rec_.log("control/linear_velocity", rerun::Scalar(u_0(0).scalar()));
  rec_.log("control/angular_velocity", rerun::Scalar(u_0(1).scalar()));

  geometry_msgs::msg::Twist message;
  message.linear.x = u_0(0).scalar();
  message.linear.y = 0.0;
  message.angular.z = u_0(1).scalar();
  publisher_->publish(message);
}

void TurtleNav::follow_path_callback() {
  // rec_.log("x", rerun::Scalar(current_pose_->x));
  // rec_.log("y", rerun::Scalar(current_pose_->y));
  // rec_.log("orientation", rerun::Scalar(current_pose_->theta));

  real_traj_.emplace_back(current_pose_->x, current_pose_->y);

  rec_.log("world/xy", rerun::Points2D(real_traj_));

  casadi::DM u = trajectory_tracker_.step(casadi::DM({
    current_pose_->x,
    current_pose_->y,
    current_pose_->theta,
  }));

  auto u_0 = u(casadi::Slice(), 0);

  rec_.log("control/linear_velocity", rerun::Scalar(u_0(0).scalar()));
  rec_.log("control/angular_velocity", rerun::Scalar(u_0(1).scalar()));

  geometry_msgs::msg::Twist message;
  message.linear.x = u_0(0).scalar();
  message.linear.y = 0.0;
  message.angular.z = u_0(1).scalar();
  publisher_->publish(message);
}

int main(const int argc, char* argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<TurtleNav>());
  rclcpp::shutdown();
  return 0;
}

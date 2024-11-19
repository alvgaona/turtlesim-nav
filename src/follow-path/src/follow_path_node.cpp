#include "follow_path_node.h"

#include <casadi/casadi.hpp>
#include <casadi/core/optistack.hpp>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <turtlesim/msg/detail/pose__struct.hpp>

#include "geometry_msgs/geometry_msgs/msg/twist.hpp"
#include "point_stabilizer.h"

using namespace std::chrono_literals;

FollowPathNode::FollowPathNode()
  : Node("follow_path"),
    point_stabilizer_({
      .horizon_length = 25,
      .state_dim = 3,
      .input_dim = 2,
      .dt = 0.02,
      .Q = casadi::DM::diag({10.0, 150.0, 5.0}),
      .R = casadi::DM::diag({0.05, 0.05}),
    }) {
  publisher_ =
    this->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel", 10);
  subscriber_ = this->create_subscription<turtlesim::msg::Pose>(

    "turtle1/pose",
    10,
    [this](const std::shared_ptr<const turtlesim::msg::Pose>& msg) {  // NOLINT
      current_pose_ = std::const_pointer_cast<turtlesim::msg::Pose>(msg);
    }
  );
  timer_ = this->create_wall_timer(25ms, [this]() { timer_callback(); });
  goto_service_ = this->create_service<follow_path::srv::GoTo>(
    "follow_path/goto",
    [this](
      const std::shared_ptr<follow_path::srv::GoTo::Request>& request,
      const std::shared_ptr<follow_path::srv::GoTo::Response>& response
    ) { GoToGoal(request, response); }
  );
}

void FollowPathNode::GoToGoal(
  const std::shared_ptr<follow_path::srv::GoTo::Request>& request,
  const std::shared_ptr<follow_path::srv::GoTo::Response>& response
) {
  point_stabilizer_.set_target({request->x, request->y, 0.0});
  has_target_ = true;
  response->accepted = true;
}

void FollowPathNode::timer_callback() {
  if (has_target_) {
    casadi::DM u = point_stabilizer_.step(casadi::DM({
      current_pose_->x,
      current_pose_->y,
      current_pose_->theta,
    }));

    auto u_0 = u(casadi::Slice(), 0);

    geometry_msgs::msg::Twist message;
    message.linear.x = u_0(0).scalar();
    message.linear.y = 0.0;
    message.angular.z = u_0(1).scalar();
    publisher_->publish(message);
  }
}

int main(const int argc, char* argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<FollowPathNode>());
  rclcpp::shutdown();
  return 0;
}

#include "follow_path_node.h"

#include <chrono>

#include "geometry_msgs/geometry_msgs/msg/twist.hpp"

using namespace std::chrono_literals;

FollowPathNode::FollowPathNode() : Node("follow_path") {
  publisher_ =
      this->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel", 10);
  timer_ = this->create_wall_timer(500ms, [this]() { timer_callback(); });
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
  // TODO: compute velocity command and publish it to the /turtle1/cmd_vel topic
  response->accepted = true;
}

void FollowPathNode::timer_callback() const {
  geometry_msgs::msg::Twist message;
  message.linear.x = 0.1;
  message.linear.y = 0.1;
  publisher_->publish(message);
}

int main(const int argc, char* argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<FollowPathNode>());
  rclcpp::shutdown();
  return 0;
}

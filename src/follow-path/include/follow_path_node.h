#pragma once

#include <geometry_msgs/geometry_msgs/msg/twist.hpp>
#include <rclcpp/rclcpp.hpp>
#include <rclcpp/subscription.hpp>
#include <turtlesim/msg/detail/pose__struct.hpp>
#include <turtlesim/msg/pose.hpp>

#include "follow_path/srv/go_to.hpp"
#include "point_stabilizer.h"

class FollowPathNode final : public rclcpp::Node {
 public:
  FollowPathNode();
  ~FollowPathNode() override = default;

 private:
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
  rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr subscriber_;
  rclcpp::Service<follow_path::srv::GoTo>::SharedPtr goto_service_;

  turtlesim::msg::Pose::SharedPtr current_pose_;
  PointStabilizer point_stabilizer_;
  bool has_target_;

  void timer_callback();

  void GoToGoal(
    const std::shared_ptr<follow_path::srv::GoTo::Request>& request,
    const std::shared_ptr<follow_path::srv::GoTo::Response>& response
  );
};

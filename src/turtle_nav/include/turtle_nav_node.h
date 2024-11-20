#pragma once

#include <geometry_msgs/geometry_msgs/msg/twist.hpp>
#include <rclcpp/rclcpp.hpp>
#include <rclcpp/subscription.hpp>
#include <turtlesim/msg/detail/pose__struct.hpp>
#include <turtlesim/msg/pose.hpp>

#include "point_stabilizer.h"
#include "turtle_nav/srv/follow_path.hpp"
#include "turtle_nav/srv/go_to.hpp"

class TurtleNav final : public rclcpp::Node {
 public:
  TurtleNav();
  ~TurtleNav() override = default;

 private:
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
  rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr subscriber_;
  rclcpp::Service<turtle_nav::srv::GoTo>::SharedPtr goto_service_;
  rclcpp::Service<turtle_nav::srv::FollowPath>::SharedPtr follow_path_service_;

  turtlesim::msg::Pose::SharedPtr current_pose_;
  PointStabilizer point_stabilizer_;
  bool has_target_;

  void timer_callback();

  void go_to(
    const std::shared_ptr<turtle_nav::srv::GoTo::Request>& request,
    const std::shared_ptr<turtle_nav::srv::GoTo::Response>& response
  );

  void follow_path(
    const std::shared_ptr<turtle_nav::srv::FollowPath::Request>& request,
    const std::shared_ptr<turtle_nav::srv::FollowPath::Response>& response
  );
};

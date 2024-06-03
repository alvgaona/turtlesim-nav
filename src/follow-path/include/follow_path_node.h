#pragma once

#include "rclcpp/rclcpp.hpp"
#include "follow_path/srv/go_to.hpp"
#include "geometry_msgs/geometry_msgs/msg/twist.hpp"

class FollowPathNode final : public rclcpp::Node {
  public:
    FollowPathNode();
    ~FollowPathNode() = default;

  private:
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;

    rclcpp::Service<follow_path::srv::GoTo>::SharedPtr goto_service_;

    void timer_callback() const;

    void GoToGoal(std::shared_ptr<follow_path::srv::GoTo::Request> request, std::shared_ptr<follow_path::srv::GoTo::Response> response);
};

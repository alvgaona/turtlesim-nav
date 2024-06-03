// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from follow_path:srv/GoTo.idl
// generated code does not contain a copyright notice

#ifndef FOLLOW_PATH__SRV__DETAIL__GO_TO__BUILDER_HPP_
#define FOLLOW_PATH__SRV__DETAIL__GO_TO__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "follow_path/srv/detail/go_to__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace follow_path
{

namespace srv
{

namespace builder
{

class Init_GoTo_Request_speed
{
public:
  explicit Init_GoTo_Request_speed(::follow_path::srv::GoTo_Request & msg)
  : msg_(msg)
  {}
  ::follow_path::srv::GoTo_Request speed(::follow_path::srv::GoTo_Request::_speed_type arg)
  {
    msg_.speed = std::move(arg);
    return std::move(msg_);
  }

private:
  ::follow_path::srv::GoTo_Request msg_;
};

class Init_GoTo_Request_y
{
public:
  explicit Init_GoTo_Request_y(::follow_path::srv::GoTo_Request & msg)
  : msg_(msg)
  {}
  Init_GoTo_Request_speed y(::follow_path::srv::GoTo_Request::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_GoTo_Request_speed(msg_);
  }

private:
  ::follow_path::srv::GoTo_Request msg_;
};

class Init_GoTo_Request_x
{
public:
  Init_GoTo_Request_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GoTo_Request_y x(::follow_path::srv::GoTo_Request::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_GoTo_Request_y(msg_);
  }

private:
  ::follow_path::srv::GoTo_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::follow_path::srv::GoTo_Request>()
{
  return follow_path::srv::builder::Init_GoTo_Request_x();
}

}  // namespace follow_path


namespace follow_path
{

namespace srv
{

namespace builder
{

class Init_GoTo_Response_accepted
{
public:
  Init_GoTo_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::follow_path::srv::GoTo_Response accepted(::follow_path::srv::GoTo_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return std::move(msg_);
  }

private:
  ::follow_path::srv::GoTo_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::follow_path::srv::GoTo_Response>()
{
  return follow_path::srv::builder::Init_GoTo_Response_accepted();
}

}  // namespace follow_path

#endif  // FOLLOW_PATH__SRV__DETAIL__GO_TO__BUILDER_HPP_

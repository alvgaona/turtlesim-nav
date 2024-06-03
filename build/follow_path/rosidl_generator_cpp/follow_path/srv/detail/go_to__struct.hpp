// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from follow_path:srv/GoTo.idl
// generated code does not contain a copyright notice

#ifndef FOLLOW_PATH__SRV__DETAIL__GO_TO__STRUCT_HPP_
#define FOLLOW_PATH__SRV__DETAIL__GO_TO__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__follow_path__srv__GoTo_Request __attribute__((deprecated))
#else
# define DEPRECATED__follow_path__srv__GoTo_Request __declspec(deprecated)
#endif

namespace follow_path
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GoTo_Request_
{
  using Type = GoTo_Request_<ContainerAllocator>;

  explicit GoTo_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0;
      this->y = 0.0;
      this->speed = 0.0;
    }
  }

  explicit GoTo_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0;
      this->y = 0.0;
      this->speed = 0.0;
    }
  }

  // field types and members
  using _x_type =
    double;
  _x_type x;
  using _y_type =
    double;
  _y_type y;
  using _speed_type =
    double;
  _speed_type speed;

  // setters for named parameter idiom
  Type & set__x(
    const double & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const double & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__speed(
    const double & _arg)
  {
    this->speed = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    follow_path::srv::GoTo_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const follow_path::srv::GoTo_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<follow_path::srv::GoTo_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<follow_path::srv::GoTo_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      follow_path::srv::GoTo_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<follow_path::srv::GoTo_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      follow_path::srv::GoTo_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<follow_path::srv::GoTo_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<follow_path::srv::GoTo_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<follow_path::srv::GoTo_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__follow_path__srv__GoTo_Request
    std::shared_ptr<follow_path::srv::GoTo_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__follow_path__srv__GoTo_Request
    std::shared_ptr<follow_path::srv::GoTo_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GoTo_Request_ & other) const
  {
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->speed != other.speed) {
      return false;
    }
    return true;
  }
  bool operator!=(const GoTo_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GoTo_Request_

// alias to use template instance with default allocator
using GoTo_Request =
  follow_path::srv::GoTo_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace follow_path


#ifndef _WIN32
# define DEPRECATED__follow_path__srv__GoTo_Response __attribute__((deprecated))
#else
# define DEPRECATED__follow_path__srv__GoTo_Response __declspec(deprecated)
#endif

namespace follow_path
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GoTo_Response_
{
  using Type = GoTo_Response_<ContainerAllocator>;

  explicit GoTo_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  explicit GoTo_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  // field types and members
  using _accepted_type =
    bool;
  _accepted_type accepted;

  // setters for named parameter idiom
  Type & set__accepted(
    const bool & _arg)
  {
    this->accepted = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    follow_path::srv::GoTo_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const follow_path::srv::GoTo_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<follow_path::srv::GoTo_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<follow_path::srv::GoTo_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      follow_path::srv::GoTo_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<follow_path::srv::GoTo_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      follow_path::srv::GoTo_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<follow_path::srv::GoTo_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<follow_path::srv::GoTo_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<follow_path::srv::GoTo_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__follow_path__srv__GoTo_Response
    std::shared_ptr<follow_path::srv::GoTo_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__follow_path__srv__GoTo_Response
    std::shared_ptr<follow_path::srv::GoTo_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GoTo_Response_ & other) const
  {
    if (this->accepted != other.accepted) {
      return false;
    }
    return true;
  }
  bool operator!=(const GoTo_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GoTo_Response_

// alias to use template instance with default allocator
using GoTo_Response =
  follow_path::srv::GoTo_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace follow_path

namespace follow_path
{

namespace srv
{

struct GoTo
{
  using Request = follow_path::srv::GoTo_Request;
  using Response = follow_path::srv::GoTo_Response;
};

}  // namespace srv

}  // namespace follow_path

#endif  // FOLLOW_PATH__SRV__DETAIL__GO_TO__STRUCT_HPP_

// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from follow_path:srv/GoTo.idl
// generated code does not contain a copyright notice

#ifndef FOLLOW_PATH__SRV__DETAIL__GO_TO__TRAITS_HPP_
#define FOLLOW_PATH__SRV__DETAIL__GO_TO__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "follow_path/srv/detail/go_to__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace follow_path
{

namespace srv
{

inline void to_flow_style_yaml(
  const GoTo_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: speed
  {
    out << "speed: ";
    rosidl_generator_traits::value_to_yaml(msg.speed, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GoTo_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "speed: ";
    rosidl_generator_traits::value_to_yaml(msg.speed, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GoTo_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace follow_path

namespace rosidl_generator_traits
{

[[deprecated("use follow_path::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const follow_path::srv::GoTo_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  follow_path::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use follow_path::srv::to_yaml() instead")]]
inline std::string to_yaml(const follow_path::srv::GoTo_Request & msg)
{
  return follow_path::srv::to_yaml(msg);
}

template<>
inline const char * data_type<follow_path::srv::GoTo_Request>()
{
  return "follow_path::srv::GoTo_Request";
}

template<>
inline const char * name<follow_path::srv::GoTo_Request>()
{
  return "follow_path/srv/GoTo_Request";
}

template<>
struct has_fixed_size<follow_path::srv::GoTo_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<follow_path::srv::GoTo_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<follow_path::srv::GoTo_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace follow_path
{

namespace srv
{

inline void to_flow_style_yaml(
  const GoTo_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: accepted
  {
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GoTo_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: accepted
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GoTo_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace follow_path

namespace rosidl_generator_traits
{

[[deprecated("use follow_path::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const follow_path::srv::GoTo_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  follow_path::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use follow_path::srv::to_yaml() instead")]]
inline std::string to_yaml(const follow_path::srv::GoTo_Response & msg)
{
  return follow_path::srv::to_yaml(msg);
}

template<>
inline const char * data_type<follow_path::srv::GoTo_Response>()
{
  return "follow_path::srv::GoTo_Response";
}

template<>
inline const char * name<follow_path::srv::GoTo_Response>()
{
  return "follow_path/srv/GoTo_Response";
}

template<>
struct has_fixed_size<follow_path::srv::GoTo_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<follow_path::srv::GoTo_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<follow_path::srv::GoTo_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<follow_path::srv::GoTo>()
{
  return "follow_path::srv::GoTo";
}

template<>
inline const char * name<follow_path::srv::GoTo>()
{
  return "follow_path/srv/GoTo";
}

template<>
struct has_fixed_size<follow_path::srv::GoTo>
  : std::integral_constant<
    bool,
    has_fixed_size<follow_path::srv::GoTo_Request>::value &&
    has_fixed_size<follow_path::srv::GoTo_Response>::value
  >
{
};

template<>
struct has_bounded_size<follow_path::srv::GoTo>
  : std::integral_constant<
    bool,
    has_bounded_size<follow_path::srv::GoTo_Request>::value &&
    has_bounded_size<follow_path::srv::GoTo_Response>::value
  >
{
};

template<>
struct is_service<follow_path::srv::GoTo>
  : std::true_type
{
};

template<>
struct is_service_request<follow_path::srv::GoTo_Request>
  : std::true_type
{
};

template<>
struct is_service_response<follow_path::srv::GoTo_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // FOLLOW_PATH__SRV__DETAIL__GO_TO__TRAITS_HPP_

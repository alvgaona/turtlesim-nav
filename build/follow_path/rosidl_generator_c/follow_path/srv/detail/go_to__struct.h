// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from follow_path:srv/GoTo.idl
// generated code does not contain a copyright notice

#ifndef FOLLOW_PATH__SRV__DETAIL__GO_TO__STRUCT_H_
#define FOLLOW_PATH__SRV__DETAIL__GO_TO__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/GoTo in the package follow_path.
typedef struct follow_path__srv__GoTo_Request
{
  double x;
  double y;
  double speed;
} follow_path__srv__GoTo_Request;

// Struct for a sequence of follow_path__srv__GoTo_Request.
typedef struct follow_path__srv__GoTo_Request__Sequence
{
  follow_path__srv__GoTo_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} follow_path__srv__GoTo_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/GoTo in the package follow_path.
typedef struct follow_path__srv__GoTo_Response
{
  bool accepted;
} follow_path__srv__GoTo_Response;

// Struct for a sequence of follow_path__srv__GoTo_Response.
typedef struct follow_path__srv__GoTo_Response__Sequence
{
  follow_path__srv__GoTo_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} follow_path__srv__GoTo_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FOLLOW_PATH__SRV__DETAIL__GO_TO__STRUCT_H_

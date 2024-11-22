cmake_minimum_required(VERSION 3.16)
project(turtle_nav)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 20)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(std_srvs REQUIRED)
find_package(rerun_sdk REQUIRED)
find_package(turtlesim REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(casadi REQUIRED)
find_package(rosidl_default_generators REQUIRED)

include_directories(
  include
  ${rclcpp_INCLUDE_DIRS}
  ${std_msgs_INCLUDE_DIRS}
  ${std_srvs_INCLUDE_DIRS}
  ${geometry_msgs_INCLUDE_DIRS}
  ${turtlesim_INCLUDE_DIRS}
  ${casadi_INCLUDE_DIRS}
)

file(GLOB_RECURSE src_files src/*.cpp)
list(FILTER src_files EXCLUDE REGEX "src/.*_node.cpp")

set(srv_files
  "srv/GoTo.srv"
  "srv/FollowPath.srv"
)

rosidl_generate_interfaces(${PROJECT_NAME}
  ${srv_files}
  DEPENDENCIES
  geometry_msgs
  std_msgs
  std_srvs
)

rosidl_get_typesupport_target(cpp_typesupport_target ${PROJECT_NAME} rosidl_typesupport_cpp)

add_executable(turtle_nav_node src/turtle_nav_node.cpp ${src_files})
ament_target_dependencies(
  turtle_nav_node PUBLIC
  rclcpp
  std_msgs
  std_srvs
  geometry_msgs
  turtlesim
)
target_link_libraries(
  turtle_nav_node PUBLIC
  "${cpp_typesupport_target}"
  casadi
)

install(
  TARGETS turtle_nav_node
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}
)

if(BUILD_TESTING)
  set(test_src "test/utest_follow.cpp")
  file(GLOB_RECURSE src_for_test src/*.cpp)
  list(FILTER src_for_test EXCLUDE REGEX "src/.*_node.cpp")

  find_package(ament_cmake_gmock REQUIRED)

  ament_add_gmock(turtle_nav_test ${test_src} ${src_for_test})
  ament_target_dependencies(turtle_nav_test std_msgs)
endif()

ament_package()

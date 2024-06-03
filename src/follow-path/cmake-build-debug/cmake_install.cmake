# Install script for directory: /home/alvaro/github.com/turtlesim-follow-path/src/follow-path

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/home/alvaro/github.com/turtlesim-follow-path/.pixi/envs/default/bin/x86_64-conda-linux-gnu-objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/rosidl_interfaces" TYPE FILE FILES "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/ament_cmake_index/share/ament_index/resource_index/rosidl_interfaces/follow_path")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/follow_path/follow_path" TYPE DIRECTORY FILES "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/rosidl_generator_c/follow_path/" REGEX "/[^/]*\\.h$")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libfollow_path__rosidl_generator_c.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libfollow_path__rosidl_generator_c.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libfollow_path__rosidl_generator_c.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/libfollow_path__rosidl_generator_c.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libfollow_path__rosidl_generator_c.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libfollow_path__rosidl_generator_c.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/home/alvaro/github.com/turtlesim-follow-path/.pixi/envs/default/bin/x86_64-conda-linux-gnu-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libfollow_path__rosidl_generator_c.so")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/follow_path/follow_path" TYPE DIRECTORY FILES "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/rosidl_typesupport_fastrtps_c/follow_path/" REGEX "/[^/]*\\.cpp$" EXCLUDE)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libfollow_path__rosidl_typesupport_fastrtps_c.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libfollow_path__rosidl_typesupport_fastrtps_c.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libfollow_path__rosidl_typesupport_fastrtps_c.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/libfollow_path__rosidl_typesupport_fastrtps_c.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libfollow_path__rosidl_typesupport_fastrtps_c.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libfollow_path__rosidl_typesupport_fastrtps_c.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libfollow_path__rosidl_typesupport_fastrtps_c.so"
         OLD_RPATH "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/home/alvaro/github.com/turtlesim-follow-path/.pixi/envs/default/bin/x86_64-conda-linux-gnu-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libfollow_path__rosidl_typesupport_fastrtps_c.so")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/follow_path/follow_path" TYPE DIRECTORY FILES "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/rosidl_generator_cpp/follow_path/" REGEX "/[^/]*\\.hpp$")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/follow_path/follow_path" TYPE DIRECTORY FILES "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/rosidl_typesupport_fastrtps_cpp/follow_path/" REGEX "/[^/]*\\.cpp$" EXCLUDE)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libfollow_path__rosidl_typesupport_fastrtps_cpp.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libfollow_path__rosidl_typesupport_fastrtps_cpp.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libfollow_path__rosidl_typesupport_fastrtps_cpp.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/libfollow_path__rosidl_typesupport_fastrtps_cpp.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libfollow_path__rosidl_typesupport_fastrtps_cpp.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libfollow_path__rosidl_typesupport_fastrtps_cpp.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/home/alvaro/github.com/turtlesim-follow-path/.pixi/envs/default/bin/x86_64-conda-linux-gnu-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libfollow_path__rosidl_typesupport_fastrtps_cpp.so")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/follow_path/follow_path" TYPE DIRECTORY FILES "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/rosidl_typesupport_introspection_c/follow_path/" REGEX "/[^/]*\\.h$")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libfollow_path__rosidl_typesupport_introspection_c.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libfollow_path__rosidl_typesupport_introspection_c.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libfollow_path__rosidl_typesupport_introspection_c.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/libfollow_path__rosidl_typesupport_introspection_c.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libfollow_path__rosidl_typesupport_introspection_c.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libfollow_path__rosidl_typesupport_introspection_c.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libfollow_path__rosidl_typesupport_introspection_c.so"
         OLD_RPATH "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/home/alvaro/github.com/turtlesim-follow-path/.pixi/envs/default/bin/x86_64-conda-linux-gnu-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libfollow_path__rosidl_typesupport_introspection_c.so")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libfollow_path__rosidl_typesupport_c.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libfollow_path__rosidl_typesupport_c.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libfollow_path__rosidl_typesupport_c.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/libfollow_path__rosidl_typesupport_c.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libfollow_path__rosidl_typesupport_c.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libfollow_path__rosidl_typesupport_c.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libfollow_path__rosidl_typesupport_c.so"
         OLD_RPATH "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/home/alvaro/github.com/turtlesim-follow-path/.pixi/envs/default/bin/x86_64-conda-linux-gnu-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libfollow_path__rosidl_typesupport_c.so")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/follow_path/follow_path" TYPE DIRECTORY FILES "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/rosidl_typesupport_introspection_cpp/follow_path/" REGEX "/[^/]*\\.hpp$")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libfollow_path__rosidl_typesupport_introspection_cpp.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libfollow_path__rosidl_typesupport_introspection_cpp.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libfollow_path__rosidl_typesupport_introspection_cpp.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/libfollow_path__rosidl_typesupport_introspection_cpp.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libfollow_path__rosidl_typesupport_introspection_cpp.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libfollow_path__rosidl_typesupport_introspection_cpp.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/home/alvaro/github.com/turtlesim-follow-path/.pixi/envs/default/bin/x86_64-conda-linux-gnu-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libfollow_path__rosidl_typesupport_introspection_cpp.so")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libfollow_path__rosidl_typesupport_cpp.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libfollow_path__rosidl_typesupport_cpp.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libfollow_path__rosidl_typesupport_cpp.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/libfollow_path__rosidl_typesupport_cpp.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libfollow_path__rosidl_typesupport_cpp.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libfollow_path__rosidl_typesupport_cpp.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/home/alvaro/github.com/turtlesim-follow-path/.pixi/envs/default/bin/x86_64-conda-linux-gnu-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libfollow_path__rosidl_typesupport_cpp.so")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/follow_path/environment" TYPE FILE FILES "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/ament_cmake_environment_hooks/pythonpath.sh")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/follow_path/environment" TYPE FILE FILES "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/ament_cmake_environment_hooks/pythonpath.dsv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python3.11/site-packages/follow_path-0.1.0-py3.11.egg-info" TYPE DIRECTORY FILES "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/ament_cmake_python/follow_path/follow_path.egg-info/")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python3.11/site-packages/follow_path" TYPE DIRECTORY FILES "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/rosidl_generator_py/follow_path/" REGEX "/[^/]*\\.pyc$" EXCLUDE REGEX "/\\_\\_pycache\\_\\_$" EXCLUDE)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(
        COMMAND
        "/home/alvaro/github.com/turtlesim-follow-path/.pixi/envs/default/bin/python" "-m" "compileall"
        "lib/python3.11/site-packages/follow_path"
      )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.11/site-packages/follow_path/follow_path_s__rosidl_typesupport_fastrtps_c.cpython-311-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.11/site-packages/follow_path/follow_path_s__rosidl_typesupport_fastrtps_c.cpython-311-x86_64-linux-gnu.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.11/site-packages/follow_path/follow_path_s__rosidl_typesupport_fastrtps_c.cpython-311-x86_64-linux-gnu.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python3.11/site-packages/follow_path" TYPE SHARED_LIBRARY FILES "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/rosidl_generator_py/follow_path/follow_path_s__rosidl_typesupport_fastrtps_c.cpython-311-x86_64-linux-gnu.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.11/site-packages/follow_path/follow_path_s__rosidl_typesupport_fastrtps_c.cpython-311-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.11/site-packages/follow_path/follow_path_s__rosidl_typesupport_fastrtps_c.cpython-311-x86_64-linux-gnu.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.11/site-packages/follow_path/follow_path_s__rosidl_typesupport_fastrtps_c.cpython-311-x86_64-linux-gnu.so"
         OLD_RPATH "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/rosidl_generator_py/follow_path:/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/home/alvaro/github.com/turtlesim-follow-path/.pixi/envs/default/bin/x86_64-conda-linux-gnu-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.11/site-packages/follow_path/follow_path_s__rosidl_typesupport_fastrtps_c.cpython-311-x86_64-linux-gnu.so")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  include("/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/CMakeFiles/follow_path__rosidl_typesupport_fastrtps_c__pyext.dir/install-cxx-module-bmi-Debug.cmake" OPTIONAL)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.11/site-packages/follow_path/follow_path_s__rosidl_typesupport_introspection_c.cpython-311-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.11/site-packages/follow_path/follow_path_s__rosidl_typesupport_introspection_c.cpython-311-x86_64-linux-gnu.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.11/site-packages/follow_path/follow_path_s__rosidl_typesupport_introspection_c.cpython-311-x86_64-linux-gnu.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python3.11/site-packages/follow_path" TYPE SHARED_LIBRARY FILES "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/rosidl_generator_py/follow_path/follow_path_s__rosidl_typesupport_introspection_c.cpython-311-x86_64-linux-gnu.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.11/site-packages/follow_path/follow_path_s__rosidl_typesupport_introspection_c.cpython-311-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.11/site-packages/follow_path/follow_path_s__rosidl_typesupport_introspection_c.cpython-311-x86_64-linux-gnu.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.11/site-packages/follow_path/follow_path_s__rosidl_typesupport_introspection_c.cpython-311-x86_64-linux-gnu.so"
         OLD_RPATH "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/rosidl_generator_py/follow_path:/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/home/alvaro/github.com/turtlesim-follow-path/.pixi/envs/default/bin/x86_64-conda-linux-gnu-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.11/site-packages/follow_path/follow_path_s__rosidl_typesupport_introspection_c.cpython-311-x86_64-linux-gnu.so")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  include("/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/CMakeFiles/follow_path__rosidl_typesupport_introspection_c__pyext.dir/install-cxx-module-bmi-Debug.cmake" OPTIONAL)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.11/site-packages/follow_path/follow_path_s__rosidl_typesupport_c.cpython-311-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.11/site-packages/follow_path/follow_path_s__rosidl_typesupport_c.cpython-311-x86_64-linux-gnu.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.11/site-packages/follow_path/follow_path_s__rosidl_typesupport_c.cpython-311-x86_64-linux-gnu.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python3.11/site-packages/follow_path" TYPE SHARED_LIBRARY FILES "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/rosidl_generator_py/follow_path/follow_path_s__rosidl_typesupport_c.cpython-311-x86_64-linux-gnu.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.11/site-packages/follow_path/follow_path_s__rosidl_typesupport_c.cpython-311-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.11/site-packages/follow_path/follow_path_s__rosidl_typesupport_c.cpython-311-x86_64-linux-gnu.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.11/site-packages/follow_path/follow_path_s__rosidl_typesupport_c.cpython-311-x86_64-linux-gnu.so"
         OLD_RPATH "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/rosidl_generator_py/follow_path:/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/home/alvaro/github.com/turtlesim-follow-path/.pixi/envs/default/bin/x86_64-conda-linux-gnu-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.11/site-packages/follow_path/follow_path_s__rosidl_typesupport_c.cpython-311-x86_64-linux-gnu.so")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  include("/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/CMakeFiles/follow_path__rosidl_typesupport_c__pyext.dir/install-cxx-module-bmi-Debug.cmake" OPTIONAL)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libfollow_path__rosidl_generator_py.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libfollow_path__rosidl_generator_py.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libfollow_path__rosidl_generator_py.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/rosidl_generator_py/follow_path/libfollow_path__rosidl_generator_py.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libfollow_path__rosidl_generator_py.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libfollow_path__rosidl_generator_py.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libfollow_path__rosidl_generator_py.so"
         OLD_RPATH "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/home/alvaro/github.com/turtlesim-follow-path/.pixi/envs/default/bin/x86_64-conda-linux-gnu-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libfollow_path__rosidl_generator_py.so")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/follow_path/srv" TYPE FILE FILES "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/rosidl_adapter/follow_path/srv/GoTo.idl")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/follow_path/srv" TYPE FILE FILES "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/srv/GoTo.srv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/follow_path/srv" TYPE FILE FILES "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/rosidl_cmake/srv/GoTo_Request.msg")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/follow_path/srv" TYPE FILE FILES "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/rosidl_cmake/srv/GoTo_Response.msg")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/follow_path/follow_path_node" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/follow_path/follow_path_node")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/follow_path/follow_path_node"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/follow_path" TYPE EXECUTABLE FILES "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/follow_path_node")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/follow_path/follow_path_node" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/follow_path/follow_path_node")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/follow_path/follow_path_node"
         OLD_RPATH "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/home/alvaro/github.com/turtlesim-follow-path/.pixi/envs/default/bin/x86_64-conda-linux-gnu-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/follow_path/follow_path_node")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  include("/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/CMakeFiles/follow_path_node.dir/install-cxx-module-bmi-Debug.cmake" OPTIONAL)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/package_run_dependencies" TYPE FILE FILES "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/ament_cmake_index/share/ament_index/resource_index/package_run_dependencies/follow_path")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/parent_prefix_path" TYPE FILE FILES "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/ament_cmake_index/share/ament_index/resource_index/parent_prefix_path/follow_path")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/follow_path/environment" TYPE FILE FILES "/home/alvaro/github.com/turtlesim-follow-path/.pixi/envs/default/share/ament_cmake_core/cmake/environment_hooks/environment/ament_prefix_path.sh")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/follow_path/environment" TYPE FILE FILES "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/ament_cmake_environment_hooks/ament_prefix_path.dsv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/follow_path/environment" TYPE FILE FILES "/home/alvaro/github.com/turtlesim-follow-path/.pixi/envs/default/share/ament_cmake_core/cmake/environment_hooks/environment/path.sh")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/follow_path/environment" TYPE FILE FILES "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/ament_cmake_environment_hooks/path.dsv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/follow_path" TYPE FILE FILES "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/ament_cmake_environment_hooks/local_setup.bash")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/follow_path" TYPE FILE FILES "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/ament_cmake_environment_hooks/local_setup.sh")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/follow_path" TYPE FILE FILES "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/ament_cmake_environment_hooks/local_setup.zsh")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/follow_path" TYPE FILE FILES "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/ament_cmake_environment_hooks/local_setup.dsv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/follow_path" TYPE FILE FILES "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/ament_cmake_environment_hooks/package.dsv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/packages" TYPE FILE FILES "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/ament_cmake_index/share/ament_index/resource_index/packages/follow_path")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/follow_path/cmake/export_follow_path__rosidl_generator_cExport.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/follow_path/cmake/export_follow_path__rosidl_generator_cExport.cmake"
         "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/CMakeFiles/Export/e21437688ec6d4f0b936624a71d29e66/export_follow_path__rosidl_generator_cExport.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/follow_path/cmake/export_follow_path__rosidl_generator_cExport-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/follow_path/cmake/export_follow_path__rosidl_generator_cExport.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/follow_path/cmake" TYPE FILE FILES "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/CMakeFiles/Export/e21437688ec6d4f0b936624a71d29e66/export_follow_path__rosidl_generator_cExport.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/follow_path/cmake" TYPE FILE FILES "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/CMakeFiles/Export/e21437688ec6d4f0b936624a71d29e66/export_follow_path__rosidl_generator_cExport-debug.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/follow_path/cmake/export_follow_path__rosidl_typesupport_fastrtps_cExport.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/follow_path/cmake/export_follow_path__rosidl_typesupport_fastrtps_cExport.cmake"
         "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/CMakeFiles/Export/e21437688ec6d4f0b936624a71d29e66/export_follow_path__rosidl_typesupport_fastrtps_cExport.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/follow_path/cmake/export_follow_path__rosidl_typesupport_fastrtps_cExport-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/follow_path/cmake/export_follow_path__rosidl_typesupport_fastrtps_cExport.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/follow_path/cmake" TYPE FILE FILES "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/CMakeFiles/Export/e21437688ec6d4f0b936624a71d29e66/export_follow_path__rosidl_typesupport_fastrtps_cExport.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/follow_path/cmake" TYPE FILE FILES "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/CMakeFiles/Export/e21437688ec6d4f0b936624a71d29e66/export_follow_path__rosidl_typesupport_fastrtps_cExport-debug.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/follow_path/cmake/export_follow_path__rosidl_generator_cppExport.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/follow_path/cmake/export_follow_path__rosidl_generator_cppExport.cmake"
         "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/CMakeFiles/Export/e21437688ec6d4f0b936624a71d29e66/export_follow_path__rosidl_generator_cppExport.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/follow_path/cmake/export_follow_path__rosidl_generator_cppExport-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/follow_path/cmake/export_follow_path__rosidl_generator_cppExport.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/follow_path/cmake" TYPE FILE FILES "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/CMakeFiles/Export/e21437688ec6d4f0b936624a71d29e66/export_follow_path__rosidl_generator_cppExport.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/follow_path/cmake/export_follow_path__rosidl_typesupport_fastrtps_cppExport.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/follow_path/cmake/export_follow_path__rosidl_typesupport_fastrtps_cppExport.cmake"
         "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/CMakeFiles/Export/e21437688ec6d4f0b936624a71d29e66/export_follow_path__rosidl_typesupport_fastrtps_cppExport.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/follow_path/cmake/export_follow_path__rosidl_typesupport_fastrtps_cppExport-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/follow_path/cmake/export_follow_path__rosidl_typesupport_fastrtps_cppExport.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/follow_path/cmake" TYPE FILE FILES "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/CMakeFiles/Export/e21437688ec6d4f0b936624a71d29e66/export_follow_path__rosidl_typesupport_fastrtps_cppExport.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/follow_path/cmake" TYPE FILE FILES "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/CMakeFiles/Export/e21437688ec6d4f0b936624a71d29e66/export_follow_path__rosidl_typesupport_fastrtps_cppExport-debug.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/follow_path/cmake/follow_path__rosidl_typesupport_introspection_cExport.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/follow_path/cmake/follow_path__rosidl_typesupport_introspection_cExport.cmake"
         "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/CMakeFiles/Export/e21437688ec6d4f0b936624a71d29e66/follow_path__rosidl_typesupport_introspection_cExport.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/follow_path/cmake/follow_path__rosidl_typesupport_introspection_cExport-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/follow_path/cmake/follow_path__rosidl_typesupport_introspection_cExport.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/follow_path/cmake" TYPE FILE FILES "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/CMakeFiles/Export/e21437688ec6d4f0b936624a71d29e66/follow_path__rosidl_typesupport_introspection_cExport.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/follow_path/cmake" TYPE FILE FILES "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/CMakeFiles/Export/e21437688ec6d4f0b936624a71d29e66/follow_path__rosidl_typesupport_introspection_cExport-debug.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/follow_path/cmake/follow_path__rosidl_typesupport_cExport.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/follow_path/cmake/follow_path__rosidl_typesupport_cExport.cmake"
         "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/CMakeFiles/Export/e21437688ec6d4f0b936624a71d29e66/follow_path__rosidl_typesupport_cExport.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/follow_path/cmake/follow_path__rosidl_typesupport_cExport-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/follow_path/cmake/follow_path__rosidl_typesupport_cExport.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/follow_path/cmake" TYPE FILE FILES "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/CMakeFiles/Export/e21437688ec6d4f0b936624a71d29e66/follow_path__rosidl_typesupport_cExport.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/follow_path/cmake" TYPE FILE FILES "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/CMakeFiles/Export/e21437688ec6d4f0b936624a71d29e66/follow_path__rosidl_typesupport_cExport-debug.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/follow_path/cmake/follow_path__rosidl_typesupport_introspection_cppExport.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/follow_path/cmake/follow_path__rosidl_typesupport_introspection_cppExport.cmake"
         "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/CMakeFiles/Export/e21437688ec6d4f0b936624a71d29e66/follow_path__rosidl_typesupport_introspection_cppExport.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/follow_path/cmake/follow_path__rosidl_typesupport_introspection_cppExport-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/follow_path/cmake/follow_path__rosidl_typesupport_introspection_cppExport.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/follow_path/cmake" TYPE FILE FILES "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/CMakeFiles/Export/e21437688ec6d4f0b936624a71d29e66/follow_path__rosidl_typesupport_introspection_cppExport.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/follow_path/cmake" TYPE FILE FILES "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/CMakeFiles/Export/e21437688ec6d4f0b936624a71d29e66/follow_path__rosidl_typesupport_introspection_cppExport-debug.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/follow_path/cmake/follow_path__rosidl_typesupport_cppExport.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/follow_path/cmake/follow_path__rosidl_typesupport_cppExport.cmake"
         "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/CMakeFiles/Export/e21437688ec6d4f0b936624a71d29e66/follow_path__rosidl_typesupport_cppExport.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/follow_path/cmake/follow_path__rosidl_typesupport_cppExport-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/follow_path/cmake/follow_path__rosidl_typesupport_cppExport.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/follow_path/cmake" TYPE FILE FILES "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/CMakeFiles/Export/e21437688ec6d4f0b936624a71d29e66/follow_path__rosidl_typesupport_cppExport.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/follow_path/cmake" TYPE FILE FILES "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/CMakeFiles/Export/e21437688ec6d4f0b936624a71d29e66/follow_path__rosidl_typesupport_cppExport-debug.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/follow_path/cmake/export_follow_path__rosidl_generator_pyExport.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/follow_path/cmake/export_follow_path__rosidl_generator_pyExport.cmake"
         "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/CMakeFiles/Export/e21437688ec6d4f0b936624a71d29e66/export_follow_path__rosidl_generator_pyExport.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/follow_path/cmake/export_follow_path__rosidl_generator_pyExport-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/follow_path/cmake/export_follow_path__rosidl_generator_pyExport.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/follow_path/cmake" TYPE FILE FILES "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/CMakeFiles/Export/e21437688ec6d4f0b936624a71d29e66/export_follow_path__rosidl_generator_pyExport.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/follow_path/cmake" TYPE FILE FILES "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/CMakeFiles/Export/e21437688ec6d4f0b936624a71d29e66/export_follow_path__rosidl_generator_pyExport-debug.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/follow_path/cmake" TYPE FILE FILES "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/rosidl_cmake/rosidl_cmake-extras.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/follow_path/cmake" TYPE FILE FILES "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/ament_cmake_export_dependencies/ament_cmake_export_dependencies-extras.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/follow_path/cmake" TYPE FILE FILES "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/ament_cmake_export_include_directories/ament_cmake_export_include_directories-extras.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/follow_path/cmake" TYPE FILE FILES "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/ament_cmake_export_libraries/ament_cmake_export_libraries-extras.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/follow_path/cmake" TYPE FILE FILES "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/ament_cmake_export_targets/ament_cmake_export_targets-extras.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/follow_path/cmake" TYPE FILE FILES "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/rosidl_cmake/rosidl_cmake_export_typesupport_targets-extras.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/follow_path/cmake" TYPE FILE FILES "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/rosidl_cmake/rosidl_cmake_export_typesupport_libraries-extras.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/follow_path/cmake" TYPE FILE FILES
    "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/ament_cmake_core/follow_pathConfig.cmake"
    "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/ament_cmake_core/follow_pathConfig-version.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/follow_path" TYPE FILE FILES "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/package.xml")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/follow_path__py/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/alvaro/github.com/turtlesim-follow-path/src/follow-path/cmake-build-debug/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")

from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration


def generate_launch_description():
    return LaunchDescription(
        [
            Node(
                package="turtlesim",
                executable="turtlesim_node",
                name="turtilesim_node",
            ),
            Node(
                package="turtle_nav",
                executable="turtle_nav_node",
                name="turtle_nav",
                namespace="turtle1",
                output="screen",
                arguments=["--ros-args", "--log-level", "info"],
            )
        ]
    )

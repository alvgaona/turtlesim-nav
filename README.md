# TurtleSim Nav

https://github.com/user-attachments/assets/4f7f2ef3-c4e4-4324-9834-b4eed234d826

This project implements two robotic motion controllers using ROS2 and the `turtlesim` package.
The first controller enables point-to-point navigation, allowing the turtle to reach a desired target
position without following a predefined trajectory. It achieves this by continuously minimizing the
error between the current state and target position. This functionality is exposed through a ROS2
service named `/goto`, which accepts both the target goal coordinates and desired average speed
(speed control pending implementation).
The second controller focuses on path tracking and is accessible via the `/follow_path` ROS2 service.

## Model Predictive Control

The project utilizes a Nonlinear Model Predictive Control (NMPC) approach.
While both controllers share a standard NMPC implementation as their foundation,
they differ in several key aspects of their operation and configuration.

The controller implementation relies on a mathematical unicycle model, which can be readily adapted
to function as a differential-drive system.

The foundation for this implementation comes from a previous simulation that focused on mathematical
model interactions specifically to compute the control input and to apply said input.
For more details, see this [post](https://alvgaona.com/posts/casadi-mpc-controller-0x4a3b/).

## Visualization

The visualization in this project is powered by [Rerun](https://rerun.io/), which must be installed before running
the simulation. Once installed, the node utilizes Rerun to log and display data throughout
the simulation process.

> [!IMPORTANT]
> Please note that the 2D visualization's coordinate system is inverted compared
> to the turtlesim GUI coordinate system.
> Keep this in mind when interpreting the visual output.

## Usage

The very first thing you'll need is [Pixi](https://pixi.sh/latest/).
Go to their site and download it, of course, then install it.

Once installed, execute this in your command line while on the project's folder.

```text
pixi install
```

This will have all the dependencies installed on your machine but just locally.
It won't affect your system-level libraries or programs.

Now build it.

```text
pixi run build
```

You're good to go now. Let's run it.
On one shell start up the nodes.

```text
pixi run ros2 launch run.launch.py
```

And on another shell

```text
pixi run ros2 service call \
  /turtle_nav/follow_path 'turtle_nav/srv/FollowPath' \
  "{x: [5.544445, 9.0, 9.0], y: [5.544445, 7.0, 1.0], speed: 0.0}"
```

You can also choose to use the `/goto` service.

```text
pixi run ros2 service call /turtle_nav/goto \
  'turtle_nav/srv/GoTo' "{x: 1.0, y: 9.0, speed: 0.0}"
```

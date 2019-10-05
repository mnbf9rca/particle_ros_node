
# particle_ros_node
Demonstates the minimum necessary to connect a Particle Photon to ROS.

Implements [rosserial_python](http://wiki.ros.org/rosserial_python) on the server, and [rosserial_arduino](http://wiki.ros.org/rosserial_arduino) on the Photon.

# Instructions
## ROS server
1. clone ros folder to catkin_ws and run `catkin_make`. Tested on Lubuntu 18.04 LTS with [Ros Melodic Morenia](http://wiki.ros.org/melodic). Remember to install Python on your ROS server too.
2. Launch `roscore`
3. Launch `rosrun rosserial_python serial_node.py tcp`
## Particle Photon
1. Build particle_ros_node.ino
2. doesn't seem to work via cloud build...
3. flash to device (via cloud is ok)
4. check at [https://console.particle.io/devices](https://console.particle.io/devices) to see the status
/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "application.h"
#line 1 "/Users/rob/Downloads/git/particle_ros_node/src/particle_ros_node.ino"
/*
 * rosserial Publisher Example
 * Prints "hello world!"
 * This intend modified from an example which uses Arduino Ethernet Shield
 * to use the Particle Photon wifi module instead.
 * You still need a rosserial socket server.
 * 
 * Modified from https://github.com/ros-drivers/rosserial/tree/melodic-devel/rosserial_arduino/src/ros_lib/examples/TcpHelloWorld
 *
 */

// To use the TCP version of rosserial_arduino
void publishChar(const char *eventName, const char *data);
void setup();
void loop();
#line 13 "/Users/rob/Downloads/git/particle_ros_node/src/particle_ros_node.ino"
#define ROSSERIAL_ARDUINO_TCP

#include <ros.h>
#include <std_msgs/String.h>


// Set the rosserial socket server IP address
IPAddress server(192,168,17,29);
// Set the rosserial socket server port
const uint16_t serverPort = 11411;

ros::NodeHandle nh;
// Make a chatter publisher
std_msgs::String str_msg;
ros::Publisher chatter("chatter", &str_msg);

// Be polite and say hello
char hello[13] = "hello world!";
uint16_t period = 1000;
uint32_t last_time = 0;

void publishChar(const char *eventName, const char *data)
{
  Particle.publish(eventName, data,  PRIVATE);
}


void setup()
{
  
  // Connect the Ethernet
  // typically not needed as this is default behaviour
  WiFi.on();
  WiFi.connect();

  

  // Let some time for the network to be initialized
  delay(1000);
  char IP[] = "xxx.xxx.xxx.xxx";
  IPAddress ip = WiFi.localIP();
  ip.toString().toCharArray(IP, 16);

  publishChar("Ethernet connected", IP);

  // Set the connection to rosserial socket server
  nh.getHardware()->setConnection(server, serverPort);
  nh.initNode();

  // Another way to get IP
  ip = (nh.getHardware()->getLocalIP());
  ip.toString().toCharArray(IP, 16);

  publishChar("another way to get IP",  IP);

  // Start to be polite
  nh.advertise(chatter);
}

void loop()
{
  if(millis() - last_time >= period)
  {
    last_time = millis();
    if (nh.connected())
    {
      publishChar("Connected", "");
      // Say hello
      str_msg.data = hello;
      chatter.publish( &str_msg );
    } else {
      publishChar("Not Connected", "");
    }
  }
  nh.spinOnce();
  delay(1);
}
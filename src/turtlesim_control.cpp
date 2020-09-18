#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include <sstream>
int main(int argc, char **argv)
{
ros::init(argc, argv, "replace_with_your_node_name");
ros::NodeHandle n;
ros::Publisher ttu_publisher =
n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1000);
ros::Rate loop_rate(10);
int count = 0;
while (ros::ok())
{
geometry_msgs::Twist msg;
msg.linear.x = 2+0.01*count;
msg.angular.z = 2;
ttu_publisher.publish(msg);
ros::spinOnce();
loop_rate.sleep();
count++;
}
}

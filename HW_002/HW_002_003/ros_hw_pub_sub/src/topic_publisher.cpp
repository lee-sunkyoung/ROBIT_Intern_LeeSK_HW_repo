#include "ros/ros.h"
#include "ros_hw_pub_sub/MsgTutorial.h"

using namespace std;

int main(int argc, char **argv) 
{
ros::init(argc, argv, "topic_publisher");
ros::NodeHandle nh;
ros::Publisher ros_hw_pub_sub = nh.advertise<ros_hw_pub_sub::MsgTutorial>("ros_hw_pub_sub_msg", 100);

ros::Rate loop_rate(10);

ros_hw_pub_sub::MsgTutorial msg;
int num1=0;
int num2=0;
string mymessage="sunkyoung";


while (ros::ok())
{
    nh.getParam("num1",num1);
    nh.getParam("num2",num2);
    nh.getParam("mymessage",mymessage);
msg.data1=num1;
msg.data2=num2;
msg.message=mymessage;

msg.stamp = ros::Time::now();
ROS_INFO("%d", msg.stamp.sec);
ROS_INFO("%d", msg.stamp.nsec);
ROS_INFO("%ld", msg.data1);
ROS_INFO("%ld", msg.data2);
ROS_INFO("%s", msg.message.c_str());
ros_hw_pub_sub.publish(msg);
}
return 0;
}

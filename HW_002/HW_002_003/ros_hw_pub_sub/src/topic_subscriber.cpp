#include "ros/ros.h" 
#include "ros_hw_pub_sub/MsgTutorial.h" 
void msgCallback(const ros_hw_pub_sub::MsgTutorial::ConstPtr& msg)
{
ROS_INFO("receive msg = %d", msg->stamp.sec);
ROS_INFO("receive msg = %d", msg->stamp.nsec);
ROS_INFO("receive msg = %ld", msg->data1);
ROS_INFO("receive msg = %ld", msg->data2);
ROS_INFO("receive msg = %s", msg->message.c_str());
}
int main(int argc, char **argv) 
{
ros::init(argc, argv, "topic_subscriber"); 
ros::NodeHandle nh; 

ros::Subscriber ros_hw_pub_sub = nh.subscribe("ros_hw_pub_sub_msg", 100, msgCallback);
ros::spin();
return 0;
}

/**
 * @file /src/qnode.cpp
 *
 * @brief Ros communication central!
 *
 * @date February 2011
 **/

/*****************************************************************************
** Includes
*****************************************************************************/

#include <ros/ros.h>
#include <ros/network.h>
#include <string>
#include <std_msgs/String.h>
#include <sstream>
#include <iostream>
#include "../include/sk_turtle/qnode.hpp"
#include "geometry_msgs/Twist.h"

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace sk_turtle
{
  /*****************************************************************************
  ** Implementation
  *****************************************************************************/

  QNode::QNode(int argc, char** argv) : init_argc(argc), init_argv(argv)
  {
  }

  QNode::~QNode()
  {
    if (ros::isStarted())
    {
      ros::shutdown();  // explicitly needed since we use ros::start();
      ros::waitForShutdown();
    }
    wait();
  }

  bool QNode::init()
  {
    ros::init(init_argc, init_argv, "sk_turtle");
    if (!ros::master::check())
    {
      return false;
    }
    ros::start();  // explicitly needed since our nodehandle is going out of scope.
    ros::NodeHandle n;
    // Add your ros communications here.
    start();
    return true;
  }


  void QNode::run()
  { 
    
    ros::NodeHandle n;
    ros::Publisher pub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1000);
    ros::Rate loop_rate(33);

    while (ros::ok())
    {
      // char a[100]="apple";
      // std::cin>>a;
      //  ros::NodeHandle n;
      // ros::Publisher pub = n.advertise<std_msgs::String>("/string", 1000);

      // if(a=="w"||a=="W"){
      //   geometry_msgs::Twist mytwist;
      //   mytwist.linear.x+=2;
      //   pub.publish(mytwist);
      // }
      // else if(a=="s"||a=="S"){
      //   geometry_msgs::Twist mytwist;
      //   mytwist.linear.x-=2;
      // pub.publish(mytwist);
      // }
      // else if(a=="a"||a=="A"){
      //   geometry_msgs::Twist mytwist;
      //   mytwist.angular.z-=2;
      // pub.publish(mytwist);
      // }
      // else if(a=="d"||a=="D"){
      //   geometry_msgs::Twist mytwist;
      //   mytwist.angular.z-=2;
      // pub.publish(mytwist);
      // }
      // else{
      //  ROS_INFO("U pressed wrong key : %s",a);
      //  ROS_INFO("use only 'w','a','s','d' please.Capital letter is available.\n");
      // }
      ros::spinOnce();
      loop_rate.sleep();
    }
    std::cout << "Ros shutdown, proceeding to close the gui." << std::endl;
    Q_EMIT rosShutdown();  // used to signal the gui for a shutdown (useful to roslaunch)
  }

  void QNode::go(){

    ros::NodeHandle n;
    ros::Publisher pub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1000);
    geometry_msgs::Twist mytwist;
    mytwist.linear.x+=2;

    pub.publish(mytwist);

  }

    void QNode::stop(){

    ros::NodeHandle n;
    ros::Publisher pub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1000);
    geometry_msgs::Twist mytwist;

    mytwist.linear.x=0;

    pub.publish(mytwist);
    
  }


  void QNode::back(){

    ros::NodeHandle n;
    ros::Publisher pub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1000);
    geometry_msgs::Twist mytwist;
    mytwist.linear.x-=2;
    

    pub.publish(mytwist);
    
  }


  void QNode::left(){

    ros::NodeHandle n;
    ros::Publisher pub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1000);
   geometry_msgs::Twist mytwist;

      mytwist.angular.z=+2;
    
    pub.publish(mytwist);
    
  }


  void QNode::right(){

    ros::NodeHandle n;
    ros::Publisher pub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1000);
    geometry_msgs::Twist mytwist;
   
    mytwist.angular.z=-2;
   

    pub.publish(mytwist);
    
  }








}  // namespace s

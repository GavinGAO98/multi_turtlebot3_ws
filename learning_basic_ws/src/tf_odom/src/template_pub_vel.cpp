/*
Author:Gavin
Function: to write a template of publishing a message of a certain topic
Date: 10/11/2021
*/


//导入ros核心包和消息的头文件
# include "ros/ros.h"
# include "geometry_msgs/Twist.h"

#include <sstream>

int main(int argc, char ** argv){

    //Step1:初始化一个节点
    ros::init(argc,argv, "vel_publisher");

    //Step2:创建一个节点的句柄
    ros::NodeHandle n;

    //Step3:用句柄发布的返回值初始化一个发布类的对象
    ros::Publisher pub_vel = n.advertise<geometry_msgs::Twist>("/cmd_vel",10);

    //设置循环频率，其中loop_rate是类Rate的对象，括号内的值是参数，单位Hz
    ros::Rate loop_rate(10);

    //设置了具体的移动距离后，循环条件改变了
    while( ros::ok()){
        
        //Step4:创建一个Twist类的对象twist，用于保存发布的速度数据
        geometry_msgs::Twist twist;

        twist.linear.x = 0.1;
        twist.linear.y = 0;
        twist.linear.z = 0;

        twist.angular.x = 0;
        twist.angular.y = 0;
        twist.angular.z = 0;

        ROS_INFO("current linear velocity is: %f" , twist.linear.x);

        //Step5:正式发布速度话题
        pub_vel.publish(twist);

        ros::spinOnce();

        //相当于sleep(1/10)，保证从上一次sleep()到这次sleep()的时间间隔是0.1s
        loop_rate.sleep();
    }

    return 0;
}
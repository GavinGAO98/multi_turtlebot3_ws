/*
    goals:add a new frame by publishing a tf transform
    只能通过发布tf变换来新建坐标系？
*/

#include "ros/ros.h"
#include "tf/transform_broadcaster.h"

int main(int argc, char** argv){
    
 
        //Q ：为什么不能只发布一个tf变换？而是要循环发布？
        ros::init(argc,argv, "add_turtle2_frame");
        ros::NodeHandle n;

        tf::Transform transform;
        tf::TransformBroadcaster br;
        ros::Rate rate(10);

        while(ros::ok){
        transform.setOrigin(tf::Vector3(0.0,2.0,0.0));
        transform.setRotation(tf::Quaternion(0,0,0,1));//姿态不变

        br.sendTransform(tf::StampedTransform(transform,ros::Time::now(),"/turtle2","/turtle1"));
        rate.sleep();
    }
    return 0;
}





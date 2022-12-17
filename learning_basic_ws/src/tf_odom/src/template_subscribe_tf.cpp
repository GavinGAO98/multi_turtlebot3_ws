/*
Author:Gavin
Function: to write a template of subscribing a message of /tf
Date: 11/11/2021
*/

//与订阅话题的不同：无需callback函数，订阅返回的是类Transform的对象

//Q：如何查看ros中已有的坐标系，如何只新建坐标系而不发布tf变换
//A：不能只查看坐标系而不查看tf变换，可以通过发布tf变换新建坐标系

// Q：导入的是类.h？
# include "ros/ros.h"
# include "tf/transform_listener.h"
#include "turtlesim/Spawn.h"
#include "geometry_msgs/Twist.h"
#include <sstream>

int main(int argc, char** argv){

    //Step1:节点初始化
    ros::init(argc,argv, "tf_subscr");

    //Step2:创建节点句柄
    ros::NodeHandle node;
    // （不属于监听tf的标准流程）话题名需要重映射
    ros::Publisher turtle2_pub_vel = node.advertise<geometry_msgs::Twist>("/turtle2/cmd_vel", 10);

    /*此段代码调用服务生成第二个海龟
    */
   //阻塞等待服务
    ros::service::waitForService("spawn");
    ros::ServiceClient spawn_turtle = node.serviceClient<turtlesim::Spawn>("spawn");
    turtlesim::Spawn srv;
    spawn_turtle.call(srv);

    //Step3:新建监听器对象
    tf::TransformListener listener;

    ros::Rate loop_rate(10.00);
    while(node.ok()){

        //Step4:创建一个带有时间戳的tf变换类的对象，用于存放监听到的tf变换的数据
        tf::StampedTransform stamped_tf;

        try{
            //Step5:等待两个坐标系指定时间（第三个形参）下的变换关系，超过第四个参数的阻塞时间会继续执行下面的语句
            listener.waitForTransform("/turtle2","/turtle1", ros::Time(0), ros::Duration(3.0));

            //Step6:查找tf变换并将接受到的变换放到对象中
            listener.lookupTransform("/turtle2", "/turtle1", ros::Time(0), stamped_tf);

        }
        
        //tf很容易出错，出错时记录错误日志
        catch(tf::TransformException &exc){
            ROS_ERROR("%s", exc.what() );

            ros::Duration(1.0).sleep();
            continue;
        }

        //Step7:处理订阅到的tf数据
        //Q:transform对象的类型是什么？
        geometry_msgs::Twist turtle2_vel;
        turtle2_vel.linear.x = 0.5 * sqrt(pow(stamped_tf.getOrigin().x() ,2) + pow(stamped_tf.getOrigin().y() ,2));
        //ROS_INFO("海龟2的线速度是：%f", turtle2_vel.linear.x);
        turtle2_vel.angular.z = 4.0 * atan2(stamped_tf.getOrigin().y(), stamped_tf.getOrigin().x());

        turtle2_pub_vel.publish(turtle2_vel);

        loop_rate.sleep();
    }

    return 0;
}
#include <ros/ros.h>
#include <ros/console.h>
#include <nav_msgs/Path.h>
#include <nav_msgs/Odometry.h>
#include <std_msgs/String.h>
#include <geometry_msgs/Quaternion.h>
#include <geometry_msgs/PoseStamped.h>
#include <tf/transform_broadcaster.h>
#include <tf/transform_listener.h>
#include <tf/tf.h>

//差一个从odom到map的坐标转换，方法：监听通过ROS发布的变换数据，并应用它来变换一个点
//https://www.ncnynl.com/archives/201702/1329.html

//References:https://www.cnblogs.com/gangyin/p/13399965.html
class SubOdomAndPubPath
{
public:
    SubOdomAndPubPath()
    {
        traj_pub=n.advertise<nav_msgs::Path>("trajectory_viz",1, true);
        odom_sub=n.subscribe("odom",1,&SubOdomAndPubPath::OdomCallBack,this);
    }


    void OdomCallBack(const nav_msgs::Odometry odom_msg)
    {
        geometry_msgs::PoseStamped pose;

        pose.header.stamp=odom_msg.header.stamp;
        pose.header.frame_id="/map";
         //Q：添加命名空间会改动frame_id吗？A ：虽然命名空间不改变全局名称，但是这不是全局名称，而只是msg的一个值，故命名空间不能改变
        pose.pose.position.x=odom_msg.pose.pose.position.x;
        pose.pose.position.y=odom_msg.pose.pose.position.y;
        pose.pose.position.z=odom_msg.pose.pose.position.z;
        pose.pose.orientation.x=odom_msg.pose.pose.orientation.x;
        pose.pose.orientation.y=odom_msg.pose.pose.orientation.y;
        pose.pose.orientation.z=odom_msg.pose.pose.orientation.z;
        pose.pose.orientation.w=odom_msg.pose.pose.orientation.w;

        //从odom坐标变换到/map
           
        history_path.header.stamp=odom_msg.header.stamp;
        history_path.header.frame_id="/map";

        // 将当前位置推进poses数组中
        history_path.poses.push_back(pose);
        traj_pub.publish(history_path);
    }
    
private:
    ros::NodeHandle n;
    ros::Publisher traj_pub;
    ros::Subscriber odom_sub;
    ros::Time time;
    nav_msgs::Path history_path;

};


main (int argc, char **argv)
{
    ros::init (argc, argv, "viz_trajectory");
    SubOdomAndPubPath SAP;
    ros::spin();
    return 0;
}
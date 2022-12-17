#include<signal.h>
#include<ros/ros.h>
#include<geometry_msgs/Twist.h>

int main(int argc, char **argv ){

    ros::init(argc, argv, "vel_cmd_publisher");    //初始化ROS节点,它允许ROS通过命令行进行名称重映射

    ros::NodeHandle node;

    ros::Publisher vel_pub = node.advertise<geometry_msgs::Twist>("/cmd_vel",10); //advertise()返回一个Publisher对象vel_pub，
    //后面可以通过调用publish()发布关于该主题的消息。

    ROS_INFO("Motion Start!");


    ros::Rate loop_rate(10);

    int count = 0;//统计发了多少次消息，用于创建独一无二的字符串
    while (ros::ok()){

        geometry_msgs::Twist twist_cmd;
        twist_cmd.linear.x = 0; //0.1m/s
        twist_cmd.linear.y = 0;
        twist_cmd.linear.z = 0;

        twist_cmd.angular.x = 0;
        twist_cmd.angular.y = 0;
        twist_cmd.angular.z = 0.1; //角速度0.05rad/s

        ros::spinOnce();

        loop_rate.sleep();
        ++count;

        vel_pub.publish (twist_cmd); //advertise返回的类的实例可以发布速度消息
    }
    return 0;
}

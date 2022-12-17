## <center>实物实验</center>

注意精调各种参数，如距离终点的阈值等



按照如下顺序依次roslaunch运行

1.【各机器人ssh】各机器人校准时间（每次启动都必须,，否则tf报错）

`sudo ntpdate ntp.ubuntu.com`

2.【各机器人ssh】ROS_NAMESPACE=tb3_0 roslaunch turtlebot3_bringup turtlebot3_robot.launch multi_robot_name:="tb3_0" set_lidar_frame_id:="tb3_0/base_scan"

3.【上位机remote】roslaunch real_turtlebot3_navigation navigation_three.launch

4.【上位机remote】roslaunch real_turtlebot3_navigation move_base_three.launch

5.【上位机remote】每次规划后，点击rviz界面上的`2D Pose Estimate `重新标记初始位置，通过键盘调整初始化粒子数

`ROS_NAMESPACE=tb3_0 rosrun turtlebot3_teleop turtlebot3_teleop_key`

6.【上位机remote】roslaunch real_turtlebot3_navigation multi_bag.launch （每次记得改名字）



rosbag record -o bagfiles/cmd_vel.bag /tb3_0/cmd_vel /tb3_1/cmd_vel /tb3_2/cmd_vel

rosbag record -o bagfiles/vicon.bag /vicon/bot1/bot1 /vicon/bot2/bot2 /vicon/bot3/bot3

## <center>多机建图的运行顺序</center>

> 【deprecated】Step1:启动包含world和三个机器人的gazebo`roslaunch map_merge multi_turtlebot3_gazebo.launch`
>
> 已在multi_mapping.launch的命名空间添加了turtlebot3_remote.launch
>
> Q：同时需要对tf和坐标系加上命名空间吗？

Step1:【各机器人ssh】启动激光雷达等串口输入

第一台：`ROS_NAMESPACE=tb3_0 roslaunch turtlebot3_bringup turtlebot3_robot.launch multi_robot_name:="tb3_0" set_lidar_frame_id:="tb3_0/base_scan"`

第二台：`ROS_NAMESPACE=tb3_1 roslaunch turtlebot3_bringup turtlebot3_robot.launch multi_robot_name:="tb3_1" set_lidar_frame_id:="tb3_1/base_scan"`

第三台：`ROS_NAMESPACE=tb3_2 roslaunch turtlebot3_bringup turtlebot3_robot.launch multi_robot_name:="tb3_2" set_lidar_frame_id:="tb3_2/base_scan"`

Step2:【上位机】启动三个turtlebot3的SLAM节点

`roslaunch real_merge multi_mapping.launch`

Step3:【上位机】启动三个键盘控制节点遥控机器人移动

打开三个终端分别运行`ROS_NAMESPACE=tb3_0 rosrun turtlebot3_teleop turtlebot3_teleop_key`

切换哪个终端哪个机器人移动

> Q：不同的节点需要加上命名空间吗？
>
> Step3和Step4顺序可以互换

Step4:【上位机】运行地图合并launch文件

`roslaunch real_merge multi_map_merge.launch`

Step5:分别打开两个rviz查看合并前、合并后（共四个话题）的地图

应该是可以在一个rviz中显示不重叠的四个话题的

地图融合后运行map_server保存地图`rosrun map_server map_saver -f ~/map`

## 考虑每一个机器人各探索一个部分，不走大量重复路径。其他人的视频是一个机器人控制一部分，每个机器人只移动一次

References:★★★https://guyuehome.com/35573

https://blog.csdn.net/gwplovekimi/article/details/105165699

https://www.ncnynl.com/archives/201901/2829.html


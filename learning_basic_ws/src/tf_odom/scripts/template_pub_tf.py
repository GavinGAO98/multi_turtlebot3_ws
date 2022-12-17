#! /usr/bin/env python
#-*- coding: UTF-8 -*-  #不加识别不了中文注释
# 确保脚本作为Python脚本执行

##发布tf的流程：类似于发布cmd_vel话题，初始化节点、创建发布类的实例，按照类中的方法发布
##区别：不同的是发布消息的具体数据结构(tf对象)不同，发布的具体方法不同

#Q：python2语法与python3区别很大吗？
# 还是不用python写了！！


import roslib
import rospy
from rospy.core import rospyinfo

#from  tf import tfMessage

#import package
import tf
import turtlesim.msg

#现在的问题（已解决）：进不去回调函数callback，也就发布不了tf，tf-tree也查不到
# 错误原因：海龟例程turtlesim的话题都有默认的命名空间/turtle1，但是我订阅的话题没有ns

#接受到位置话题后的callback函数，接收到话题才能发布tf
def pose_call_back(msg):
    #订阅的消息作为参数  python形参前面没有加上类型
    rospy.loginfo("接收到的位置是：%f； 线速度是： %f" ,msg.x, msg.linear_velocity)

    #实例化tf广播器
    br = tf.TransformBroadcaster()

    #订阅到位置后就发布tf变换，
    # 发布sendTransform(translation,rotation,time,child,parent)
    br.sendTransform((msg.x,msg.y,0),
                                            tf.transformations.quaternion_from_euler(0,0,msg.theta),
                                            rospy.Time.now(),
                                            "/turtle1",
                                            "world")                                        


if __name__ == '__main__':
    
    #初始化节点
    rospy.init_node('tf_pub', anonymous=True) # anonymous将使节点名后加上随机数称，从而名称唯一
    
    #订阅位置
    rospy.Subscriber("pose", turtlesim.msg.Pose, pose_call_back)
    #实际订阅的话题是/turtle1/pose，如果不在launch文件中重映射则无法跳转到callback函数

    rospy.spin()


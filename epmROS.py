#!/usr/bin/env python

import rospy
from mavros_msgs.msg import ActuatorControl


class talker:
    def __init__(self):
        magnetmsg = ActuatorControl('header', 'group.mix', 3)

        magnetmsg.controls[5] = 1.0

        publish = rospy.Publisher('/mavros/actuator_controls', ActuatorControl, queue_size=10)

        self.rate = rospy.Rate(10)  # 10Hz

        publish.publish(magnetmsg)

        self.rate.sleep()

if __name__ == '__main__':
    talker()



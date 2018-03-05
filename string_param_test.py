#!/usr/bin/env python

import rospy

rospy.init_node("string_param_test")
val = rospy.get_param("~str_param", None)
print val, type(val)
rospy.set_param("~str_param2", "4238")

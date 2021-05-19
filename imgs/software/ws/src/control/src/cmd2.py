import rospy
from geometry_msgs.msg import Twist

pub = rospy.Publisher('cmd_vel', Twist, queue_size=10)
rospy.init_node('c_control_node')
r = rospy.Rate(10)
while not rospy.is_shutdown():
	dirc = Twist()
	dirc.linear.x = 0.1
	pub.publish(dirc)
	r.sleep()
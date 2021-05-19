import rospy
import tf
from geometry_msgs.msg import Twist
from sensor_msgs.msg import LaserScan

def callback(data):
	# print(str(len(data.ranges)) + "\n")
	# print(str(data.header) + "\n")
	return

def listener():	
	rospy.spin()

class ExTf():
    def __init__(self):
        # rospy.init_node('tf_ex', anonymous=True)
        self.odom_broadcaster = tf.TransformBroadcaster()
        self.odom_broadcaster_laser = tf.TransformBroadcaster()
        self.listener = tf.TransformListener()
        self.base_link = 0
        self.th = 0
        self.len_laser = 0.2
        self.x = 1
        self.y = 0
        self.current_time = rospy.Time.now()
        self.last_time = rospy.Time.now()
        self.r = rospy.Rate(50)

    def func_tf_pub(self):
        self.current_time = rospy.Time.now()
        odom_quat = tf.transformations.quaternion_from_euler(0, 0, self.th)
        self.odom_broadcaster.sendTransform((self.x, self.y, 0.), 
                                            odom_quat, self.current_time,
                                            "base_link","odom")

        # odom_quat1 = tf.transformations.quaternion_from_euler(0, 0, 0) 
        # self.odom_broadcaster_laser.sendTransform((0, 0, self.len_laser), 
        #                                             odom_quat1, self.current_time, 
        #                                             "laser","base_link") 
        # self.x += 0.001

        self.x = var_x
        self.y = var_y
        self.th = var_z
        # self.th += 0.01
        self.r.sleep()
    
    def func_tf_sub(self): # как это работает????????????????
        try:
            (trans,rot) = self.listener.lookupTransform('/laser', '/odom', self.current_time)
            print(trans)
            print(rot)
        except (tf.LookupException, tf.ConnectivityException, tf.ExtrapolationException):
            print('er')


def main():
	pub = rospy.Publisher("cmd_vel", Twist, queue_size=10)
	rospy.Subscriber("scan", LaserScan, callback)
	rospy.init_node("c_control_node")
	r = rospy.Rate(10) # 10hz
	while not rospy.is_shutdown():
		dirс = Twist()
		dirс.linear.x = -0.0
		pub.publish(dirс)
		r.sleep()

	stored_exception=None
	obj = ExTf()
	obj.x = 0
	obj.y = 0
	obj.th = 0
	while not rospy.is_shutdown():
		try:
			obj.func_tf_pub()
			obj.func_tf_sub() # если мы можем паблишить в /odom и /base_link, то почему они не отображаются после rostopic list????????????????
			if stored_exception:
				print('game over')
				break

		except KeyboardInterrupt:
			stored_exception = sys.exc_info()

if __name__ == "__main__":
	main()
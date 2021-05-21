import rospy
import tf
from geometry_msgs.msg import Twist
from sensor_msgs.msg import LaserScan

turn_dir = True
linear_vel = 0.0
angular_vel = 0.0

def callback(data):
	global turn_dir
	global linear_vel
	global angular_vel

	barr = False

	for i in data.ranges[0:10]:
		if i < 1:
			barr = True

	for i in data.ranges[350:360]:
		if i < 1:
			barr = True

	if not barr:
		linear_vel = 0.2
		angular_vel = 0.0
	else:
		linear_vel = 0.0
		angular_vel = 0.7


def listener():	
	rospy.spin()

class ExTf():
    def __init__(self):
        self.odom_broadcaster = tf.TransformBroadcaster()
        self.odom_broadcaster_laser = tf.TransformBroadcaster()
        self.listener = tf.TransformListener()
        self.th = 0
        self.x = 0
        self.y = 0
        self.current_time = rospy.Time.now()
        self.last_time = rospy.Time.now()
        self.r = rospy.Rate(50)

    def func_tf_pub(self):
        self.current_time = rospy.Time.now()

        odom_quat = tf.transformations.quaternion_from_euler(0, 0, self.th) 
        self.odom_broadcaster.sendTransform((0, 0, 0), 
                                            odom_quat, self.current_time, 
                                            "base_scan", "base_link") 

        # odom_quat1 = tf.transformations.quaternion_from_euler(0, 0, 26 *3.14/180) 
        # self.odom_broadcaster_laser.sendTransform((-0.8, 0.6, 0.6), 
        #                                             odom_quat1, self.current_time, 
        #                                             "base_scan", "base_link") 

        self.x = 0
        self.y = 0
        self.th = 0
        self.r.sleep()


def main():
	pub = rospy.Publisher("cmd_vel", Twist, queue_size=10)
	rospy.Subscriber("scan", LaserScan, callback)
	rospy.init_node("c_control_node")
	r = rospy.Rate(10) # 10hz

	stored_exception=None
	obj = ExTf()
	obj.x = 0
	obj.y = 0
	obj.th = 0

	while not rospy.is_shutdown():
		dirс = Twist()
		dirс.linear.x = linear_vel
		dirс.angular.z = angular_vel
		pub.publish(dirс)
		print(str(linear_vel))
		r.sleep()

		try:
			obj.func_tf_pub()
			if stored_exception:
				print('game over')
				break

		except KeyboardInterrupt:
			stored_exception = sys.exc_info()

if __name__ == "__main__":
	main()
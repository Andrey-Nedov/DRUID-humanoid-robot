import pyrealsense2 as rs
import numpy as np
import cv2 as cv
import dlib
import serial
import time

def draw_image():

	x_res = 0.0
	y_res = 0.0

	sr = serial.Serial('/dev/ttyUSB0', 115200) 

	detector = dlib.get_frontal_face_detector()
	predictor = dlib.shape_predictor("/home/druid/pysense/shape_predictor_68_face_landmarks.dat")
	
	pipeline = rs.pipeline()
	config = rs.config()
	config.enable_stream(rs.stream.color, 640, 480, rs.format.bgr8, 30)
	profile = pipeline.start(config)

	cv.namedWindow("RealSense", cv.WINDOW_AUTOSIZE)

	max_face = 0
	max_i = 0
	num = 0

	x1 = 127
	x2 = 127
	y1 = 127
	y2 = 127

	xi1 = 127
	xi2 = 127
	yi1 = 127
	yi2 = 127

	try:
		while True:
			frames = pipeline.wait_for_frames()
			color_frame = frames.get_color_frame()
			if not color_frame:
				continue

			color_image = np.asanyarray(color_frame.get_data())
			color_image = np.transpose(color_image, (1, 0, 2))
			# print(np.shape(color_image_2))

			faces = detector(color_image)

			color_image = np.transpose(color_image, (1, 0, 2))

			for face in faces:

				# it detects the nearest face
				if max_face < face.right()-face.left():
					max_i = num

					x1 = face.left()
					y1 = face.top()
					x2 = face.right()
					y2 = face.bottom()

					xi1 = y1
					xi2 = y2
					yi1 = x1
					yi2 = x2

				num+=1

			cv.rectangle(color_image, (xi1, yi1), (xi2, yi2), (255, 255, 0), 1)
			
			x_res = x2 - ((x2-x1)/2.0)
			y_res = y2 - ((y2-y1)/2.0)

			x_map = int(round((x_res * 255)/480))
			y_map = int(round((y_res * 255)/640))
			
			print(str(x_map) + " " + str(y_map) + " " + str(len(faces)))

			sr.dtr = 1
			sr.write(bytearray([255, x_map, y_map]))

			color_image = np.transpose(color_image, (1, 0, 2))
			cv.imshow('RealSense', color_image)

			key = cv.waitKey(1) & 0xFF

			if (key == 27) or (key == ord('q')):
				cv.destroyWindow("RealSense")
				break

	finally:
		pipeline.stop()


if __name__ == '__main__':
	draw_image()

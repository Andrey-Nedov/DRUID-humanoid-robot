import serial

port = serial.Serial("/dev/ttyS0", baudrate=115200, timeout=3.0)

while True:
	port.write("\r\n1")
	# for number in range(100000):
	#     port.write("\r\n1")

	# for number in range(100000):
	#     port.write("\r\n0")
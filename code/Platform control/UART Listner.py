import socket
import serial

port = serial.Serial("/dev/ttyS0", baudrate=115200, timeout=3.0, parity= serial.PARITY_NONE)

coughtedString = ""
needPrint = False

readPacket = False

b1 = ""
b2 = ""
b3 = ""

while True:
	if port.inWaiting() > 0:

		b3 = b2
		b2 = b1
		b1 = port.read(1)

		if readPacket:
			coughtedString = coughtedString + b1

		if b3 + b2 + b1 == "$&^":
			readPacket = True

		if b3 + b2 + b1 == "*&^":
			readPacket = False
			print "UART Listener get by Serial <<< " + coughtedString.replace("*&^", "")
			coughtedString = ""


		# coughtedString = coughtedString + port.read(1)
		# print port.read(1)

	# if port.inWaiting() == 0 and needPrint == True:
	# 	print coughtedString
	# 	coughtedString = ""
	# 	needPrint = False
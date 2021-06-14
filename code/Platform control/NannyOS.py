import socket
import serial

# port = serial.Serial("/dev/ttyS0", baudrate=115200, timeout=3.0, parity= serial.PARITY_NONE)
port = serial.Serial("/dev/serial0", baudrate=115200, timeout=3.0, parity= serial.PARITY_NONE)

coughtedString = ""

sock = socket.socket()
sock.bind(('', 9091))
sock.listen(1)

# def tryGet():
# 	if port.inWaiting() > 0:
# 		coughtedString = coughtedString + port.read(1)
# 		# print port.read(1)

# 	if port.inWaiting() == 0:
# 		print coughtedString
# 		coughtedString = ""

while True:

	try:

		conn, addr = sock.accept()

		while True:
		    data = conn.recv(1024)
		    if not data:
		        break

		    dataArr = str(data).split('/')				#check chr(x) where x > 255!!!!!!!!!!!!!!! 
		    
		    if dataArr[0] == "a":
		    	b1 = "#"
		    	b2 = "#"

		    	if int(dataArr[1]) <= 255:
		    		b1 = chr(int(dataArr[1]))
		    		b2 = chr(0)
		    		print "NannyOS send by Serial >>> Angle: " + str(dataArr[1]) + "/" + "0" + ";"
		    	else:
		    		b2 = chr(int(dataArr[1]) - 255)
		    		b1 = chr(255)
		    		print "NannyOS send by Serial >>> Angle: " + "255" + "/" + str(int(dataArr[1]) - 255) + ";"

		    	# print "Angle: " + b1 + "/" + b2 + ";"
		    	port.write("#$%")
		    	port.write(b1)
		    	port.write(b2)

		    if dataArr[0] == "d":

		    	b1 = "#"
		    	b2 = "#"

		    	if int(dataArr[1]) <= 255:
		    		b1 = chr(int(dataArr[1]))
		    		b2 = chr(0)
		    		print "NannyOS send by Serial >>> Direction: " + str(dataArr[1]) + "/" + "0" + ";  PWR: " + dataArr[2]
		    	else:
		    		b2 = chr(int(dataArr[1]) - 255)
		    		b1 = chr(255)
		    		print "NannyOS send by Serial >>> Direction: " + "255" + "/" + str(int(dataArr[1]) - 255) + ";  PWR: " + dataArr[2]

		    	# print "Direction: " + b1 + "/" + b2 + ";  PWR: " + dataArr[2]
		    	port.write("#$&")
		    	port.write(b1)
		    	port.write(b2)
		    	port.write(chr(int(dataArr[2])))

		    if dataArr[0] == "dirUp":
		    	print "NannyOS send by Serial >>> Lock"
		    	port.write("#$'")
		    	port.write(chr(0))
		    	port.write(chr(0))

		conn.close()

	except Exception as e:
		print(e.__class__)
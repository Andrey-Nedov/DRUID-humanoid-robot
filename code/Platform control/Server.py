from BaseHTTPServer import BaseHTTPRequestHandler,HTTPServer
from os import curdir, sep
import socket

def sendToSocket(msg):
	try:
		# print msg 
		sock = socket.socket()
		sock.connect(('localhost', 9091))
		sock.send(msg)

		# data = sock.recv(1024)
		sock.close()

		# print "It's gone"

	except:
		print "Message isn't delivered!"



class HttpProcessor(BaseHTTPRequestHandler):

	def do_GET(self):

		try:

			if self.path == "/":

				f = open("PlatformPad.html") 
				self.send_response(200)
				self.send_header('Content-type','text/html')
				self.end_headers()
				self.wfile.write(f.read())
				f.close()

			elif self.path == "/PlatformPad.css":

				f = open("PlatformPad.css") 
				self.send_response(200)
				self.send_header('Content-type','text/css')
				self.end_headers()
				self.wfile.write(f.read())
				f.close()

			elif self.path == "/PlatformPad.js":

				f = open("PlatformPad.js") 
				self.send_response(200)
				self.send_header('Content-type','text/js')
				self.end_headers()
				self.wfile.write(f.read())
				f.close()

			elif self.path == "/img/RL2.png":

				f = open("img/RL2.png") 
				self.send_response(200)
				self.send_header('Content-type','img/png')
				self.end_headers()
				self.wfile.write(f.read())
				f.close()


			elif self.path == "/img/Button.png":
				f = open("img/Button.png") 
				self.send_response(200)
				self.send_header('Content-type','img/png')
				self.end_headers()
				self.wfile.write(f.read())
				f.close()


			elif self.path == "/img/1.png":
				# print("1")
				f = open("img/1.png") 
				self.send_response(200)
				self.send_header('Content-type','img/png')
				self.end_headers()
				self.wfile.write(f.read())
				f.close()

			elif self.path == "/img/2.png":
				# print("2")
				f = open("img/2.png") 
				self.send_response(200)
				self.send_header('Content-type','img/png')
				self.end_headers()
				self.wfile.write(f.read())
				f.close()

			elif self.path == "/img/3.png":
				# print("3")
				f = open("img/3.png") 
				self.send_response(200)
				self.send_header('Content-type','img/png')
				self.end_headers()
				self.wfile.write(f.read())
				f.close()

			elif self.path == "/img/CintaHeavy.otf":
				# print("Font")
				f = open("img/CintaHeavy.otf") 
				self.send_response(200)
				self.send_header('Content-type','application/x-font-opentype')
				self.end_headers()
				self.wfile.write(f.read())
				f.close()

			elif self.path == "/img/favicon.ico":
				f = open("img/favicon.ico") 
				self.send_response(200)
				self.send_header('Content-type','image/x-icon')
				self.end_headers()
				self.wfile.write(f.read())
				f.close()

			# if self.path == "/Button_pushed.png":
			# 	f = open("HTML/Button_pushed.png") 
			# 	self.send_response(200)
			# 	self.send_header('Content-type','img/png')
			# 	self.end_headers()
			# 	self.wfile.write(f.read())
			# 	f.close()

			elif self.path == "/img/rotation3.png":
				f = open("img/rotation3.png") 
				self.send_response(200)
				self.send_header('Content-type','img/png')
				self.end_headers()
				self.wfile.write(f.read())
				f.close()

			elif self.path == "/img/stop.png":
				f = open("img/stop.png") 
				self.send_response(200)
				self.send_header('Content-type','img/png')
				self.end_headers()
				self.wfile.write(f.read())
				f.close()

			elif self.path == "/img/speed_200.png":
				f = open("img/speed_200.png") 
				self.send_response(200)
				self.send_header('Content-type','img/png')
				self.end_headers()
				self.wfile.write(f.read())
				f.close()

			else:
				self.send_response(200)
				self.send_header('Content-type','text')
				self.end_headers()
				self.wfile.write(self.path)
				sendToSocket(self.path[1:])

				print(self.path[1:])
				
				# f.close()

			# if self.path == "/push":
			# 	self.send_response(200)
			# 	self.send_header('Content-type','text/html')
			# 	self.end_headers()
			# 	self.wfile.write("DOWN!")
			# 	while True:
			# 		port.write("\r\n1")

			# if self.path == "/up":
			# 	self.send_response(200)
			# 	self.send_header('Content-type','text/html')
			# 	self.end_headers()
			# 	self.wfile.write("UP!")
			# 	port.write("\r\n0")

			# return

		except IOError:
			self.send_error(404,'File Not Found: %s' % self.path)

serv = HTTPServer(("localhost", 8005),HttpProcessor)
serv.serve_forever()
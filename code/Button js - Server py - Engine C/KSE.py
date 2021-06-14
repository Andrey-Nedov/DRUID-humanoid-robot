from BaseHTTPServer import BaseHTTPRequestHandler,HTTPServer
from os import curdir, sep
import serial


port = serial.Serial("/dev/ttyS0", baudrate=115200, timeout=3.0)

class HttpProcessor(BaseHTTPRequestHandler):

	def do_GET(self):

		try:

			if self.path == "/":

				f = open("HTML/Button.html") 
				self.send_response(200)
				self.send_header('Content-type','text/html')
				self.end_headers()
				self.wfile.write(f.read())
				f.close()


			if self.path == "/RL2.png":

				f = open("HTML/RL2.png") 
				self.send_response(200)
				self.send_header('Content-type','img/png')
				self.end_headers()
				self.wfile.write(f.read())
				f.close()


			if self.path == "/Button.png":
				f = open("HTML/Button.png") 
				self.send_response(200)
				self.send_header('Content-type','img/png')
				self.end_headers()
				self.wfile.write(f.read())
				f.close()


			if self.path == "/Button_pushed.png":
				f = open("HTML/Button_pushed.png") 
				self.send_response(200)
				self.send_header('Content-type','img/png')
				self.end_headers()
				self.wfile.write(f.read())
				f.close()

			if self.path == "/push":
				self.send_response(200)
				self.send_header('Content-type','text/html')
				self.end_headers()
				self.wfile.write("DOWN!")
				while True:
					port.write("\r\n1")

			if self.path == "/up":
				self.send_response(200)
				self.send_header('Content-type','text/html')
				self.end_headers()
				self.wfile.write("UP!")
				port.write("\r\n0")

			return


		except IOError:
			self.send_error(404,'File Not Found: %s' % self.path)

serv = HTTPServer(("localhost", 8005),HttpProcessor)
serv.serve_forever()
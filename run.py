import serial
import sqlite3

from time import sleep, strftime
from flask import request
from flask import Flask,render_template



app = Flask(__name__)

### Serial Communcation ###
ser = serial.Serial('/dev/ttyACM0', 9600, timeout=1)


@app.route('/')
def hello_world():
	try:
		ser.write('1')
		sleep(1)
		v1 = ser.readline()
                hora = strftime("%H:%M:%S")
	#	v1=v1.rstrip('\n')
	#	v2 = ser.readline()
	#	v2=v2.rstrip('\n')
	#	v3 = ser.readline()
	#	v3=v3.rstrip('\n')
	#	v4 = ser.readline()
	#	v4=v4.rstrip('\n')
	#	print v1,v2,v3,v4
		print v1
		f= open("data","a")
		f.write("%s\t\t %s \n" % (hora,v1))
		f.close()
		f=open("data","r")
		content = f.read()
		#print v1
		return render_template('index.html',content=content)
	except Exception as e: print(e)
		#print 'falla en serial'


	return render_template('index.html',variable='12334')



if __name__ == "__main__":
	app.run()

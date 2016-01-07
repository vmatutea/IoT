import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BOARD)
GPIO.setup(8,GPIO.OUT)
GPIO.setup(3,GPIO.IN)
while True:
	value= GPIO.input(3)
	if value ==1:
		GPIO.output(8,True)
		time.sleep(1)	
	else:
		GPIO.output(8,True)
		time.sleep(1)
		GPIO.output(8,False)
		time.sleep(1)

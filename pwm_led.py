import RPi.GPIO as GPIO
import time

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BOARD)
LIGHT=12
GPIO.setup(LIGHT,GPIO.OUT)

pwm= GPIO.PWM(12,50)
pwm.start(0)

for i in range(100):
	pwm.ChangeDutyCycle(i)
	time.sleep(0.1)
for i in range(100,0,-1):
	pwm.ChangeDutyCycle(i)
	time.sleep(0.1)







#while True:
#	GPIO.output(LIGHT,True)
#	time.sleep(0.5)
#	GPIO.output(LIGHT,False)
#	time.sleep(0.5)




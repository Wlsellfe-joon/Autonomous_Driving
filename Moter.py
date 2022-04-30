import RPi.GPIO as GPIO          
from time import sleep

in1 = 23
in2 = 24
in3 = 22
in4 = 27
in5 = 5
in6 = 6
in7 = 4
in8 = 26

temp1=1
en=25

GPIO.setmode(GPIO.BCM)
GPIO.setup(in1,GPIO.OUT)
GPIO.setup(in2,GPIO.OUT)
GPIO.setup(in3,GPIO.OUT)
GPIO.setup(in4,GPIO.OUT)
GPIO.setup(in5,GPIO.OUT)
GPIO.setup(in6,GPIO.OUT)
GPIO.setup(in7,GPIO.OUT)
GPIO.setup(in8,GPIO.OUT)
GPIO.setup(en,GPIO.OUT)

GPIO.output(in1,GPIO.LOW)
GPIO.output(in2,GPIO.LOW)
GPIO.output(in3,GPIO.LOW)
GPIO.output(in4,GPIO.LOW)
GPIO.output(in5,GPIO.LOW)
GPIO.output(in6,GPIO.LOW)
GPIO.output(in7,GPIO.LOW)
GPIO.output(in8,GPIO.LOW)
p=GPIO.PWM(en,1000)
p.start(40)

print("\n")
print("The default speed & direction of motor is LOW & Forward.....")

try:
    f=open("test.txt",'rl')
    for a in f : 
    	k=1
    	time.sleep(0.1)
    	t=a.strip('\n')
    	print(t,k)
    	if t=='1' : #stop
            if k ==1 :
                 GPIO.output(in1,GPIO.LOW)
                 GPIO.output(in2,GPIO.HIGH)
                 GPIO.output(in3,GPIO.HIGH)
                 GPIO.output(in4,GPIO.LOW)
                 GPIO.output(in5,GPIO.LOW)
                 GPIO.output(in6,GPIO.HIGH)
                 GPIO.output(in7,GPIO.HIGH)
                 GPIO.output(in8,GPIO.LOW)
    
        else:
             GPIO.output(in1,GPIO.HIGH)
             GPIO.output(in2,GPIO.LOW)
             GPIO.output(in3,GPIO.HIGH)
             GPIO.output(in4,GPIO.LOW)
             GPIO.output(in5,GPIO.HIGH)
             GPIO.output(in6,GPIO.LOW)
             GPIO.output(in7,GPIO.HIGH)
             GPIO.output(in8,GPIO.LOW)
except:
    print("error")
                    
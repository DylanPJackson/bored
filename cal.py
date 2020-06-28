import schedule
import time
import datetime
import os
import serial

ser = serial.Serial('/dev/ttyACM0', 9600, timeout=1)
ser.flush()
date = datetime.datetime.now()

def job():
    num_day = date.strftime('%d') + "\n"
    word_day = date.strftime('%A') + "\n"
    month = date.strftime('%B') + "\n"
    os.system('arduino-cli compile --fqbn arduino:avr:mega /home/pi/Desktop/bored/calendar/')
    time.sleep(7)
    os.system('arduino-cli upload -p /dev/ttyACM0 --fqbn arduino:avr:mega /home/pi/Desktop/bored/calendar/')
    ser.write('test\n')
    time.sleep(1)
    ser.write(month) 
    time.sleep(1)
    ser.write(num_day)
    time.sleep(1)
    ser.write(word_day)

job() # Do it now
schedule.every().day.at("00:01").do(job) # And then do it all the time

while True:
    schedule.run_pending()
    time.sleep(1)

import schedule
import time
import datetime
import os
import serial

ser = serial.Serial('/dev/ttyACM0', 9600, timeout=1)

def reduce_string(string):
    """
    Cut the string down to at most five chars so it fits on the board
   
    Parameters
    ----------
    string : str
        Part of the date to be sent to the board

    Returns
    -------
    str
        The sliced string with a newline character. Helpful on Arduino side
        of things
    """
    return string[:5] + "\n"

def job():
    """
    Get the date and update the board with this info

    Gathers the month, date, and day of the week. Updates the arduino sketch
    in the case of any changes. Write date information to the arduino.  
    """
    # Clear the buffer on the serial port
    ser.flush()
    date = datetime.datetime.now()
    num_day = reduce_string(date.strftime('%d'))
    word_day = reduce_string(date.strftime('%A'))
    month = reduce_string(date.strftime('%B'))
    os.system('/home/pi/bin/arduino-cli compile --fqbn arduino:avr:mega /home/pi/Desktop/bored/calendar/')
    time.sleep(10)
    os.system('/home/pi/bin/arduino-cli upload -p /dev/ttyACM0 --fqbn arduino:avr:mega /home/pi/Desktop/bored/calendar/')
    time.sleep(7)
    ser.write(month) 
    time.sleep(1)
    ser.write(num_day)
    time.sleep(1)
    ser.write(word_day)

job() # Do it now
schedule.every().day.at("00:01").do(job) # And then do it at the start of the day 

while True:
    schedule.run_pending()
    time.sleep(1)

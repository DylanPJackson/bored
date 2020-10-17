import time
import os
import serial
import sys

ser = serial.Serial('/dev/ttyACM0', 9600, timeout = 1)

def set_timer(dur):
    """
    Starts the timer.ino sketch on the Arduino with the given time

    Parameters
    ----------
    dur : int
        The duration of the timer
    """
    ser.flush()
    os.system('/home/pi/bin/arduino-cli compile --fqbn arduino:avr:mega /home/pi/Desktop/bored/timer/')
    time.sleep(10)
    os.system('/home/pi/bin/arduino-cli upload -p /dev/ttyACM0 --fqbn arduino:avr:mega /home/pi/Desktop/bored/timer/')
    time.sleep(7)
    ser.write(dur)

def main():
    dur = str(sys.argv[1]) + "\n"
    print(dur)
    set_timer(dur)

main()

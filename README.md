# bored
<<<<<<< HEAD
A long forgotten LED-matrix turned personal assistant / AI testing grounds.
Check out [the Trello](https://trello.com/b/XVumFO86/bored) for updates.

## Current Goals
1. Calendar : Display the date and month
2. Timer : Set a timer on the board through Alexa 
3. Weather : Display the weather with a fun graphic
4. Voice interface : Implement a not all too creepy voice interface with Snips
5. Chess : Play chess against a personalized AI opponent, or against a friend
6. K-means : Visualize the k-means process on 32x32 images
=======
A long forgotten LED-matrix turned personal assistant. 

## What is it, exactly?
A 32x32 LED matrix supplied by [Adafruit](https://www.adafruit.com/product/2026), 
hooked up with jumper wires according to [this wiring diagram.](https://learn.adafruit.com/32x16-32x32-rgb-led-matrix/)
It is written to and driven by an Arduino Mega 2560, which is updated and
controlled by a Raspberry Pi 3 Model B. The Pi is accessed over SSH and uses
a connection over USB to communicate with the Arduino.

## How does it work?
The Arduino is the main driver for controlling the display of the board, and
thankfully Adafruit, the supplier of the board, provides two libraries which
make displaying to the board exceedingly straightforward. 
[This library](https://github.com/adafruit/RGB-matrix-Panel) handles low level
operations specific to this board, and 
[this library](https://github.com/adafruit/Adafruit-GFX-Library) provides basic
display functionality.

Whenever we want to update the board with a certain display, the Arduino program 
needs to be compiled and updated. All of the working sketches live on the Pi, 
and can be manually compiled and uploaded using arduino-cli. In the case of 
interactive / automated programs, a Python script handles interaction with the
user and issues command line commands to compile and update the program 
whenever necessary.

## Why?
In my sophomore year at RIT, I presented
[this project](https://github.com/DylanPJackson/K.L.A.M.P) at the President's
Ball with the Computer Science House booth. Though poorly documented, I used
the same LED board as a sort of interactive lamp that would display various
graphics related to CSH. It has been about two years since I have done anything
meaningful with the board, so I figured I would use it again to learn some new
skills and hopefully produce something useful. 

I want to use this project to more or less branch out from what I plan on
pursuing in my career, and also to work towards smart house development as a
passion project of mine. 

## Features 
1. Calendar : Display the date and month - DONE
![calendar](https://github.com/DylanPJackson/bored/blob/master/imgs/board_09_05.jpg)
2. Weather : Display the temperature with a relevant graphic - Planned
3. Voice interface : Connect Alexa to Pi to allow for voice issued updates to the
board - Planned
4. Reminders : Interactive display of daily reminders - Planned 
5. Chess : Play chess against a personalized AI opponent, or against a friend - Just an idea
>>>>>>> 3b71b358aad685f7dbb659d47b9f73d81539bcb7

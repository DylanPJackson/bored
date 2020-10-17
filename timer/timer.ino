/*
    timer.ino

    Counts down from a given time to zero, displaying when time is up,
    then turns itself off.

    Created October 16, 2020
    By Dylan P. Jackson

*/

#include <Adafruit_GFX.h>
#include <RGBmatrixPanel.h>

#define CLK 11
#define OE 9
#define LAT 10
#define A A0
#define B A1
#define C A2
#define D A3

RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, false);

void setup() {
    matrix.begin();
    Serial.begin(9600);
    matrix.fillRect(0, 0, 32, 32, matrix.Color333(0, 0, 0));
    matrix.setTextSize(3);
    matrix.setTextColor(matrix.Color333(1,0,3));
}

void loop(){
    if (Serial.available() > 0){
        int time = Serial.read();
        if (time > 0){
            delay(1000);
            if (time < 10){
                matrix.setTextSize(3);
                matrix.setCursor(9, 5);
            } else {
                matrix.setTextSize(2);
                matrix.setCursor(5, 9);
            }
            matrix.fillRect(0, 0, 32, 32, matrix.Color333(0, 0, 0));
            matrix.print(time);
            time --;
        } else if (time == 0){
            for (int i = 0; i < 3; i++){
                delay(1000);
                matrix.fillRect(0, 0, 32, 32, matrix.Color333(0, 0, 0));
                delay(500);
                matrix.setTextColor(matrix.Color333(4, 0, 1));
                matrix.setCursor(5, 8);
                matrix.setTextSize(0);
                matrix.print("Time");
                matrix.setCursor(9, 17);
                matrix.print("Up!");
            }
            time --;
            matrix.drawRect(3, 6, 27, 21, matrix.Color333(1, 0, 1));
            delay(10000);
            matrix.fillRect(0, 0, 32, 32, matrix.Color333(0, 0, 0));
        }
    } 
}

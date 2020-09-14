/*
   calendar.ino

   Handles display of calendar data in a month-date-day format, sent from
   the Arduino over USB.  

   Dylan P. Jackson
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
    // Clear the board, and setup display defaults
    matrix.fillRect(0, 0, 32, 32, matrix.Color333(0,0,0));
    matrix.setCursor(0,0);
    matrix.setTextSize(1);
    matrix.setTextColor(matrix.Color333(1,0,1));
}

void loop() {
    if (Serial.available() > 0){
        String month = Serial.readStringUntil('\n');
        delay(1000);
        String num_day = Serial.readStringUntil('\n');
        delay(1000);
        String word_day = Serial.readStringUntil('\n');
        matrix.print(month);
        matrix.setCursor(0,8);
        matrix.setTextSize(2);
        matrix.setTextColor(matrix.Color333(2,0,1));
        matrix.print(num_day);
        matrix.setCursor(0,24);
        matrix.setTextSize(1);
        matrix.setTextColor(matrix.Color333(1,0,1));
        matrix.print(word_day);
    }
}

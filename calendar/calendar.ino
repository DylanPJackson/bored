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
    matrix.fillRect(0, 0, 32, 32, matrix.Color333(0,0,0));
    matrix.setCursor(0,0);
    matrix.setTextSize(1);
    matrix.setTextColor(matrix.Color333(3,1,0));
}

void loop() {
    if (Serial.available() > 0){
        String month = Serial.readStringUntil('\n');
        delay(1000);
        String num_day = Serial.readStringUntil('\n');
        delay(1000);
        String word_day = Serial.readStringUntil('\n');
        matrix.setCursor(7,0);
        matrix.print(month);
        matrix.setCursor(5,9);
        matrix.setTextSize(2);
        matrix.setTextColor(matrix.Color333(1,0,0));
        matrix.print(num_day);
        matrix.setCursor(7,25);
        matrix.setTextSize(1);
        matrix.setTextColor(matrix.Color333(3,1,0));
        matrix.print(word_day);
    }
}

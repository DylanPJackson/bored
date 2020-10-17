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
int count = 0;

void setup() {
    matrix.begin();
    Serial.begin(9600);
}

void loop() {
    if (Serial.available() > 0){
        matrix.drawPixel(0, count, matrix.Color333(1,3,1));
        String data = Serial.readStringUntil('\n');
        Serial.print("You sent me: ");
        Serial.println(data);
        count++;
    }
}

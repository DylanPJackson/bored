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
    matrix.fillRect(0,0,11,32, matrix.Color333(0,0,1));
    matrix.fillRect(11,0,11,32, matrix.Color333(1,1,1));
    matrix.fillRect(22,0,10,32, matrix.Color333(1,0,0));
}

void loop() {
}

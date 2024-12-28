// Originally from https://wiki.seeedstudio.com/Grove-Red_LED_Matrix_w_Driver/ but then modified
// And mixed with the example from https://wiki.seeedstudio.com/Grove-Touch_Sensor (replaced the LED)

#include "Grove_LED_Matrix_Driver_HT16K33.h"
#include <Wire.h>

const int touch_input_pin = 2;

uint64_t happy_face = 0x3c4299a581a5423c;
uint64_t heart = 0x183c7effffff6600;

Matrix_8x8 matrix;


void setup() {
    Wire.begin();

    matrix.init();
    matrix.setBrightness(0);
    matrix.setBlinkRate(BLINK_OFF);

    pinMode(touch_input_pin, INPUT);
}

void loop() {
    int sensorValue = digitalRead(touch_input_pin);
    if (sensorValue == 1) {
        matrix.writeOnePicture(happy_face);
        matrix.display();
    } else {
        matrix.writeOnePicture(heart);
        matrix.display();
    }
}
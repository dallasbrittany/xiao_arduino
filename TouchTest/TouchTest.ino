#define USE_TFT_ESPI_LIBRARY
#include "lv_xiao_round_screen.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(TOUCH_INT, INPUT_PULLUP);
  Wire.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  if(chsc6x_is_pressed()){
    Serial.println("The display is touched.");
  }
  else
    Serial.println("The display is not touched.");
  delay(50);
}
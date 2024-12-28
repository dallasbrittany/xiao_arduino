// Originally from https://wiki.seeedstudio.com/Grove-Red_LED_Matrix_w_Driver/ but then modified

#include "Grove_LED_Matrix_Driver_HT16K33.h"
#include <Wire.h>

int delay_time = 2000;

uint64_t happy_face = 0x3c4299a581a5423c;
uint64_t meh_face = 0x3c4281bd81a5423c;
uint64_t sad_face = 0x3c42a59981a5423c;
uint64_t heart = 0x183c7effffff6600;

const uint64_t Emoji[] = 
{
  happy_face,
  heart,
};

const int emoji_count = sizeof(Emoji)/8;

Matrix_8x8 matrix;


void setup() {
    Wire.begin();
    matrix.init();
    matrix.setBrightness(0);
    matrix.setBlinkRate(BLINK_OFF);
    /*************************************************************
    * Description
    *    Setting the blink rate of matrix
    * Parameter
    *    blink_type: BLINK_OFF, BLINK_2HZ, BLINK_1HZ
    * Return
    *    Null.
    *************************************************************/
}

void loop() {
  for (int i = 0; i < emoji_count; i++)
    {
        matrix.writeOnePicture(Emoji[i]);
        /*************************************************************
        * Description
        *    Write a picture in display buffer.
        *    Call display() to show display buffer.
        * Parameter
        *    pic: A uint64_t type 8x8 matrix picture, you can make it at
        *         https://xantorohara.github.io/led-matrix-editor/#
        * Return
        *    Null.
        *************************************************************/
        matrix.display();
        /*************************************************************
        * Description
        *    Clear the display buffer.
        *    This function will display nothing on 8x8 Matrix after call display().
        * Parameter
        *    Null.
        * Return
        *    Null.
        *************************************************************/
        delay(delay_time);
    }
}
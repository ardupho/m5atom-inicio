#include <Arduino.h>
#include "M5Atom.h"

/*
*******************************************************************************
* Copyright (c) 2021 by M5Stack
*                  Equipped with Atom-Matrix sample source code
*                          配套  Atom-Matrix 
* Visit for more information: https://docs.m5stack.com/en/core/atom_matrix
* https://docs.m5stack.com/zh_CN/core/atom_matrix
*
* Describe: SpiritLevel
* Date: 2023/8/5
*******************************************************************************
  Shake the M5Atom and the matrix light will change with the position, you can
  set a new reference point by pressing the button.
*/

#define ALPHA       0.05  // smoothing
#define BETA        (1. - ALPHA)
#define SENSITIVITY 20.
#define BRIGHTNESS  255.
#define FADE        0.67  // determine the size of the lit area.  

bool IMU6886Flag = false;  // Stores the IMU initialization state.  

/* After Atom-Matrix is started or reset
the program in the setUp () function will be run, and this part will only be run
once. */
void setup() {
    M5.begin(true, false,
             true);  // Init Atom-Matrix(Initialize serial port, LED matrix).
    if (!M5.IMU.Init())
        IMU6886Flag = true;  // The value returned from successful IMU
                             // initialization is 0. 
}

/* After the program in setup() runs, it runs the program in loop()
The loop() function is an infinite loop in which the program runs repeatedly */

void loop() {
    M5.update();
    static float offX = 0., offY = 0.;
    static float smoX = 0., smoY = 0.;

    float accX = 0, accY = 0, accZ = 0;
    if (IMU6886Flag == true) {
        M5.IMU.getAccelData(&accX, &accY, &accZ);  // Get the acceleration data of the three axes.  
    }

    smoX = ALPHA * accX + BETA * smoX;
    smoY = ALPHA * accY + BETA * smoY;

    if (M5.Btn.wasPressed()) {  // Check if the key is pressed. 
        offX = smoX;  // Set the current position as the reference point.
        offY = smoY;  
    }

    float xc = (offX - smoX) * SENSITIVITY + 2.0;
    if (xc < 0.) xc = 0.;
    if (xc > 4.) xc = 4.;
    float yc = (offY - smoY) * SENSITIVITY + 2.0;
    if (yc < 0.) yc = 0.;
    if (yc > 4.) yc = 4.;

    byte wht[25];

    for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 5; y++) {
            float brt =
                BRIGHTNESS * (1. - FADE * ((xc - (float)x) * (xc - (float)x) +
                                           (yc - (float)y) * (yc - (float)y)));
            if (brt < 0.) brt = 0.;
            wht[x + 5 * y] = brt;
        }
    }

    for (int i = 0; i < 25; i++) {
        M5.dis.drawpix(
            i, wht[i] << 16 | wht[i] << 8 |
                   wht[i]);  // Continuously lights some LEDs with the specified
                             // RGB color. 
    }
}
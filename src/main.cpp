#include <Arduino.h>
#include "M5Atom.h"

/* After Atom-Matrix is started or reset
the program in the setUp () function will be run, and this part will only be run
once.
*/
void setup() {
    M5.begin(true, false, true);  // Init Atom-Matrix(Initialize serial port, LED). 
    delay(50);                    // delay 50ms. 
    M5.dis.drawpix(0, 0x00ff00);  // Light the LED with the specified RGB color
                                  // 00ff00(Atom-Matrix has only one light).
}

uint8_t FSM = 0;  // Store the number of key presses.  

/* After the program in setup() runs, it runs the program in loop()
The loop() function is an infinite loop in which the program runs repeatedly
*/

void loop() {
    if (M5.Btn
            .wasPressed()) {  // Check if the key is pressed.
        switch (FSM) {
            case 0:
                M5.dis.drawpix(0, 0xfff000);  // YELLOW 
                Serial.println("Button is pressed YELLOW.");
                break;
            case 1:
                M5.dis.drawpix(0, 0xff0000);  // RED  
                Serial.println("Button is pressed RED.");
                break;
            case 2:
                M5.dis.drawpix(0, 0x0000f0);  // BLUE  
                Serial.println("Button is pressed BLUE.");
                break;
            case 3:
                M5.dis.drawpix(0, 0x00ff00);  // GREEN  
                Serial.println("Button is pressed GREEN.");
                break;
            default:
                break;
        }
        FSM++;
        if (FSM >= 4) {
            FSM = 0;
        }
    }

    delay(50);
    M5.update();  // Read the press state of the key.  
}

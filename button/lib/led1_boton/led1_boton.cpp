#include "led1_boton.h"

#include <Arduino.h>
#include "M5Atom.h"

uint8_t FSM = 0;  // Store the number of key presses.  

void led1_boton_init()
{
    M5.begin(true, false, true);    // Init Atom-Matrix(Initialize serial port, LED). 
    delay(50);                      // delay 50ms.
    M5.dis.drawpix(0, 0x00ff00);    // Light the LED with the specified RGB color

}

void led1_boton_loop()
{
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

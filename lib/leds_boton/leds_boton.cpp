#include "leds_boton.h"
#include <M5Atom.h>

uint8_t FSM = 0;  // Store the number of key presses.
uint8_t DisBuff[2 + 5 * 5 * 3];  // Used to store RGB color values. 

void setBuff(uint8_t Rdata, uint8_t Gdata, uint8_t Bdata) 
{  // Set the colors of LED, and save the relevant
    // data to DisBuff[].
    DisBuff[0] = 0x05;
    DisBuff[1] = 0x05;
    for (int i = 0; i < 25; i++) {
        DisBuff[2 + i * 3 + 0] = Rdata;
        DisBuff[2 + i * 3 + 1] = Gdata;
        DisBuff[2 + i * 3 + 2] = Bdata;
    }
}

void leds_boton_init()
{
    M5.begin(true, false, true);    // Init Atom-Matrix(Initialize serial port, LED).  
    delay(10);                      // delay10ms.
    setBuff(0xff, 0x00, 0x00);
    M5.dis.displaybuff(DisBuff);    // Display the DisBuff color on the LED.
}

void leds_boton_loop()
{
if (M5.Btn.wasPressed()) 
     {  // Check if the key is pressed.
        switch (FSM) {
            case 0:
                setBuff(0x40, 0x00, 0x00);
                break;
            case 1:
                setBuff(0x00, 0x40, 0x00);
                break;
            case 2:
                setBuff(0x00, 0x00, 0x40);
                break;
            case 3:
                setBuff(0x20, 0x20, 0x20);
                break;
            default:
                break;
        }
        M5.dis.displaybuff(DisBuff);

        FSM++;
        if (FSM >= 4) {
            FSM = 0;
        }
    }
    delay(50);
    M5.update();  // Read the press state of the key.
}

#ifndef _LEDS_BOTON_H_
#define _LEDS_BOTON_H_

#include <Arduino.h>

void setBuff(uint8_t Rdata, uint8_t Gdata, uint8_t Bdata);
void leds_boton_init();
void leds_boton_loop();
 
#endif // _LEDS_BOTON_H_ 
#include <Arduino.h>
#include <leds_boton.h>

void setup() {
    leds_boton_init(); 
}

void loop() {
    leds_boton_loop();  
}
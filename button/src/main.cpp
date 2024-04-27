#include <Arduino.h>
#include "boton_events.h"

void setup() {
  boton_events_init();
}

void loop() {
  boton_events_loop();    
}
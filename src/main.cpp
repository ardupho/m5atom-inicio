#include <Arduino.h>
#include "M5Atom.h"
//#include "led1_boton.h"
#include "leds_boton.h"

/* After Atom-Matrix is started or reset
the program in the setUp () function will be run, and this part will only be run
once.
*/
void setup() 
{
  //led1_boton_init();
  leds_boton_init();

}

/* After the program in setup() runs, it runs the program in loop()
The loop() function is an infinite loop in which the program runs repeatedly
*/
void loop() 
{
  //led1_boton_loop();
  leds_boton_loop();

}

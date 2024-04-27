#include "boton_events.h"
#include "M5Atom.h"

void boton_events_init(void)
{
  M5.begin(true, false, true);
  delay(10);
}

void boton_events_loop(void)
{
  // Is the button currently down?
  if(M5.Btn.isPressed())
  {
    Serial.println("isPressed");
  }

  // Is button currently up?
  // if(M5.Btn.isReleased())
  // {
  //   Serial.println("isReleased");
  // }

  // Corresponds to onMouseDown
  if(M5.Btn.wasPressed())
  {
    Serial.println("wasPressed");
  }

  // Corresponds to onClick
  if(M5.Btn.wasReleased())
  {
    Serial.println("wasReleased");
  }

  // Long press
  if(M5.Btn.pressedFor(2000))
  {
    Serial.println("pressedFor");
  }

  // Long period of inactivity
  // if(M5.Btn.releasedFor(2000))
  // {
  //   Serial.println("releasedFor");
  // }

  delay(50);
  M5.update();
}

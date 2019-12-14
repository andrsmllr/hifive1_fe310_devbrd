#include <stdio.h>
#include "superblink.h"

/* Implemented in asm
void delay(int millis)
{
  return;
}*/

/* Implemented in asm
void setupGPIO()
{
  return;
}*/

/* Implemented in asm
int setLED(int color, int state)
{
  return color;
}*/

int main(int argc, char* argv[])
{
  int error = 0;
  int ledNum = 0;
  const int colors[NUM_LEDS] = {RED_LED, GREEN_LED, BLUE_LED};

  setupGPIO();

  while (!error)
  {
    error |= setLED(colors[ledNum], ON);
    //delay_counter(DELAY);
    delay_timer(DELAY);
    error |= setLED(colors[ledNum], OFF);
    //delay_counter(DELAY);
    delay_timer(DELAY);
    ledNum = (ledNum + 1) % NUM_LEDS;
  }
  return 0;
}

#define DELAY    200
#define ON       0x01
#define OFF      0x00
#define NUM_LEDS 0x03

#define GPIO_CTRL_ADDR  0x10012000
#define RED_LED         0x400000
#define BLUE_LED        0x200000
#define GREEN_LED       0x080000

void setupGPIO();
int setLED(int color, int state);
void delay_counter(int millis);
void delay_timer(int millis);

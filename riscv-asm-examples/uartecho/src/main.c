#include "main.h"

int main(void)
{
    uart_init();
    while (1)
    {
        uart_echo();
    }
}

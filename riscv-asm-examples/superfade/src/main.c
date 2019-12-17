#include "main.h"

int main(void)
{
    const int pwmBlk = 1;
    /* 
     * PWM channel 0 = HiFive1 board pin 4
     * PWM channel 1 = green LED
     * PWM channel 2 = blue LED
     * PWM channel 3 = red LED
     */
    const int pwmChGreen = 1;
    const int pwmChBlue = 2;
    const int pwmChRed = 3;
    int pwmCh = pwmChRed;
    const int pwmCmpValMax = 0xFF00;
    int pwmCmpVal[4] = {pwmCmpValMax, pwmCmpValMax, pwmCmpValMax, pwmCmpValMax};
    const int pwmCmpValIncMax = 1000;
    int pwmCmpValInc[4] = {pwmCmpValIncMax, pwmCmpValIncMax, pwmCmpValIncMax, pwmCmpValIncMax};
    initPwm();
    setPwm(pwmBlk, 1, pwmCmpVal[1]);
    setPwm(pwmBlk, 2, pwmCmpVal[2]);
    setPwm(pwmBlk, 3, pwmCmpVal[3]);
    while (1)
    {
        pwmCmpVal[pwmCh] += pwmCmpValInc[pwmCh];
        if (pwmCmpVal[pwmCh] > pwmCmpValMax || pwmCmpVal[pwmCh] < 0)
        {
            pwmCmpVal[pwmCh] = (pwmCmpVal[pwmCh] > 0) ? pwmCmpValMax : 0;
            pwmCmpValInc[pwmCh] *= -1;
            pwmCh += 1;
            if (pwmCh == 4)
            {
                pwmCh = 1;
            }
        }
        setPwm(pwmBlk, pwmCh, pwmCmpVal[pwmCh]);
        delay_timer(10);
    }
    return 0;
}

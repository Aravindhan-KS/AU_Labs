#include <8051.h>
#include<reg51.h>

void Timer0_Delay(unsigned int ms)
{
	unsigned int i;
	for(i = 0; i < ms; i++) {
        TMOD = 0x01;      /* Timer0, Mode1 (16-bit) */
        TH0  = 0xFC;      /* Reload value for ~1ms @ 11.0592MHz */
        TL0  = 0x66;
        TR0  = 1;         /* Start Timer0 */
        while (TF0 == 0); /* Wait for overflow */
        TF0 = 0;          /* Clear overflow flag */
        TR0 = 0;          /* Stop timer */
        }
    
}

void main(void)
{
    while (1)
    {
        P1 = ~P1;
        Timer0_Delay(2);   /* 1 ms ON/OFF */
    }
}

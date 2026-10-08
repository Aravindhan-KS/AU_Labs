/* ----------------------------------------------------
   Serial (UART) Communication
   Baud rate = 9600, Crystal = 11.0592 MHz
   ---------------------------------------------------- */
#include <reg51.h>

void UART_Init(void)
{
    TMOD = 0x20;   /* Timer1, Mode2 (8-bit auto-reload) */
    TH1  = 0xFD;   /* 9600 baud @ 11.0592MHz */
    TL1  = 0xFD;
    SCON = 0x50;   /* Mode1, 8-bit UART, REN enabled */
    TR1  = 1;      /* Start Timer1 */
}

void UART_TxChar(unsigned char ch)
{
    SBUF = ch;
    while (TI == 0);
    TI = 0;
}

unsigned char UART_RxChar(void)
{
    while (RI == 0);
    RI = 0;
    return SBUF;
}

void UART_SendString(unsigned char *str)
{
    while (*str)
    {
        UART_TxChar(*str);
        str++;
    }
}

void main(void)
{
    unsigned char rxData;

    UART_Init();
    UART_SendString("8051 UART Ready\r\n");

    while (1)
    {
        rxData = UART_RxChar();   /* wait for a character */
        UART_TxChar(rxData);      /* echo it back */
    }
}

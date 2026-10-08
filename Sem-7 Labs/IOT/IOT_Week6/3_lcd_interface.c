/* ----------------------------------------------------
   16x2 LCD Interfacing (8-bit mode)
   Data  -> P2
   RS    -> P3.0
   RW    -> P3.1
   EN    -> P3.2
   ---------------------------------------------------- */
#include <reg51.h>

sbit RS = P3^0;
sbit RW = P3^1;
sbit EN = P3^2;
#define LCD_DATA P2

void Timer_Delay(unsigned int ms)
{
    unsigned int i;
    for (i = 0; i < ms; i++)
    {
        TMOD = 0x01;
        TH0  = 0xFC;
        TL0  = 0x66;
        TR0  = 1;
        while (TF0 == 0);
        TF0 = 0;
        TR0 = 0;
    }
}

void LCD_Command(unsigned char cmd)
{
    LCD_DATA = cmd;
    RS = 0;
    RW = 0;
    EN = 1;
    Timer_Delay(1);
    EN = 0;
}

void LCD_Char(unsigned char dat)
{
    LCD_DATA = dat;
    RS = 1;
    RW = 0;
    EN = 1;
    Timer_Delay(1);
    EN = 0;
}

void LCD_Init(void)
{
    LCD_Command(0x38);   /* 8-bit, 2 line, 5x7 matrix */
    LCD_Command(0x0C);   /* Display ON, cursor OFF */
    LCD_Command(0x01);   /* Clear display */
    Timer_Delay(2);
    LCD_Command(0x06);   /* Entry mode, auto increment */
    LCD_Command(0x80);   /* First line, first position */
}

void LCD_String(unsigned char *str)
{
    while (*str)
    {
        LCD_Char(*str);
        str++;
    }
}

void main(void)
{
    LCD_Init();
    LCD_String("Hello, 8051!");
    while (1);
}

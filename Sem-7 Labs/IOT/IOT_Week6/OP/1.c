#include<8051.h>

void UART_Init()
{
	TMOD = 0x20;
	TH1 = 0xFD;
	SCON = 0x50;
	
	TR1 = 1;
}

void UART_Send(char c)
{
	SBUF = c;
	while(T1==0);
	T1=0;
}

void main()
{
	char msg[] = "HELLO";
	unsigned char i;
	UART_Init();
	while(1)
	{
		for(i=0;msg[i] != '\0'; i++)
		{
			UART_Send(msg[i]);
		}
		for(i=0;i<255;i++);
	}
}

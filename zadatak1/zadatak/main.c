/*
 * main.c
 *
 *  Created on: May 15, 2021
 *      Author: Stefan-SSD
 */

#include<stdlib.h>
#include<avr/io.h>
#include<util/delay.h>
#include "../biblioteka/usart.h"


int main ()
{
	int8_t broj[64];
	int8_t str[64];
	int16_t suma;
	usartInit(9600);

	while(1)
	{
		suma = 0;

		usartPutString("Unesi broj\r\n");

		while(!usartAvailable());

		_delay_ms(100);

		usartGetString(broj);

		for(int8_t i = 0; i < strlen(broj); i++)
		{
			suma = suma + (broj[i] - '0');
		}

		sprintf(str, "%d\0",suma);
		usartPutString(str);
		usartPutString("\r\n");

	}



return 0;
}

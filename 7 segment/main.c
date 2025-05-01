#include <stdio.h>
#include "REG51.h"

typedef unsigned char uint8_t;
sbit P1_0 = P1;
sbit P1_1 = P1^1;
sbit P1_2 = P1^2;
sbit P1_3 = P1^3;
sbit P1_4 = P1^4;
sbit P1_5 = P1^5;
sbit P1_6 = P1^6;
sbit P1_7 = P1^7;

sbit cs = P0^7;

sbit A1 = P3^4;
sbit A0 = P3^3;

int digitarr[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x98}; 

int seg_sel(uint8_t val, uint8_t pos);

int seg_sel(uint8_t val, uint8_t pos) // selects one of the 4 7-segments displays
{
	cs = 1; //cs is high (1) for the decoder to work
	P1 = digitarr[val];
	
	switch(pos)
	{
		case 0:
			A0 = 0; // 1st	7 segment selected
			A1 = 0;
			break;
	
		case 1:		
			A0 = 1; // 2nd 	7 segment selected
			A1 = 0;
			break;
		
		case 2:
			A0 = 0; // 3rd 	7 segment selected
			A1 = 1;
			break;
		
		case 3:
			A0 = 1; // 4th 	7 segment selected
			A1 = 1;
			break;
	}
	return 0;
}

int main()
{
	uint8_t i = 0;
	while(1)
	{	
		for(i = 0; i <=10; i++)
		{
			seg_sel(i,2);	
		}
	}
	return 0;
}

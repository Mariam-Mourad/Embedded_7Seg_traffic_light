/*
 * main.c
 *
 *  Created on: Aug 23, 2019
 *      Author: Mariam
 */
#include"std_types.h"
#include"Bit_calc.h"
//#include<util/delay.h>
#include"DIO_interface.h"
#include"DIO_regs.h"

/*Private Prototype*/
#define Red	PIN0
#define Yel	PIN1
#define	Ger	PIN2


void vidSetTrafficLight(u8 Copy_u8TimeSec, u8 Copy_u8Colour )
{	u8 Local_u8Iteration;
	u8 Local_7SegArr[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
	DIO_vidSetPinValue(PORTA,Copy_u8Colour,HIGH);
		for(Local_u8Iteration=Copy_u8TimeSec;Local_u8Iteration>0;Local_u8Iteration--)
			{switch (Local_u8Iteration)
			{case 10: DIO_vidSetPortValue(PORTB,0x06);DIO_vidSetPortValue(PORTD,0x3F);
                    //_delay_ms(1000);
                    for(int i=0; i<50000; i++);
                    for(int i=0; i<50000; i++);
                    break;
			default:
				DIO_vidSetPortValue(PORTB,0x3F);DIO_vidSetPortValue(PORTD,Local_7SegArr[Local_u8Iteration]);
                    //_delay_ms(1000);
                    for(int i=0; i<50000; i++);
                    for(int i=0; i<50000; i++);
                    break;
			}
			}
		DIO_vidSetPinValue(PORTA,Copy_u8Colour,LOW);
	}


/*Description:simulate the traffic lightening system:
1- Turn On Green LED for 10 seconds
2- Turn On Yellow LED for 3 seconds
3- Turn On Red LED for 10 seconds
4- Apply these forever while counting the seconds down on a 2 7-segment disp
 */

void main (void)
{

/*Set port as output*/
		DIO_vidSetPortDirection(PORTA,OUTPUT);//traffic light leds
		DIO_vidSetPortDirection(PORTB,OUTPUT);//writing on the units digit of the 7 segments
		DIO_vidSetPortDirection(PORTD,OUTPUT);//writing on the tenth digit of the 7 segments

while(1)
{
	vidSetTrafficLight(10,Red);
	vidSetTrafficLight(3,Yel);
	vidSetTrafficLight(10,Ger);
}

}

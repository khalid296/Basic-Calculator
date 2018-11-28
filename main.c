/*
 * Assignment3_Task1.c
 *
 * Created: 4/9/2018 6:25:22 PM
 * Author : khali
 */ 
/* include calculator library*/
#include "calc.h"

int main(void)
{
	LCD_init();/*initialize lcd*/
	LCD_displayStringRowColumn(0,0,"Calculator");/*Display calculator in the first line*/
	LCD_displayStringRowColumn(1,0,"PLEASE PRESS ON");/*Display in the second row*/
	_delay_ms(50);/*delay*/

	while(1)/*main loop*/
	{	/*wait for On key to start*/
		if(KeyPad_getPressedKey()=='C'){
			LCD_clearScreen();/*clear lcd*/
			calculate();/*start calculation process*/
		}
	}
}

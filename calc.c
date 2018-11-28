/*
 * calc.c
 *
 * Created: 25-Sep-16 2:47:42 PM
 *  Author: Serag
 */ 
#include "calc.h"

static uint8 key;		//key variable to store pressed key

static uint8 op;		//op variable to store operation ID

static uint8 op_char;	//op_char for operation symbol

uint32 a, b;					//a & b variables to store two numbers of operation

static double result;			//result value should be stored in this variable

static uint8 lcd_buf[16];		//lcd_buf array is the lcd buffer

//cal_op function to get operation from user input and assign operation number and sign to variables
void cal_op(void)
{
	switch(key){// switch case for all signs +-*/= on
		case'+':
			key=0;//reset key variable
			op=1;// assign operation number
			op_char='+';//assign operation sign
			break;
		case'-':
			key=0;
			op=2;
			op_char='-';
			break;
		case'*':
			key=0;
			op=3;
			op_char='x';
			break;
		case'/':
			key=0;
			op=4;
			op_char='/';
			break;
		case'0':// bug fix to allow 0
			key=0;
			break;
		case'=':
			key=0;//reset key variable
			op=5;// assign operation variable to start calculations
			break;
		case'C':// on key to reset calculator by reset all variables and clear screen
			a=0;
			b=0;
			result=0;
			op=0;
			key = 0;
			LCD_clearScreen();
			break;
	}
}



void cal_run(void)
{

		if(op==0)										//if no operation is selected then store the first number
		{
			a=a*10+key;									//storing number of n digits
			sprintf(lcd_buf,"%1li",a);					//convert long int (li) to string
			LCD_displayStringRowColumn(0,0,lcd_buf);	//display the string to lcd screen
		}
														//if Any operation is selected then start storing the second number
		else if(op==1 || op==2 || op==3 || op==4)		//if operation is selected start store the second number and display
														//both numbers and operation sign
		{
			b=b*10+key;									//display both numbers at the same time through lcd buffer
			sprintf(lcd_buf,"%1li%c%1li",a,op_char,b);	//convert variables and concatinate with the sign (a+sign+b) to string
			LCD_displayStringRowColumn(0,0,lcd_buf);	//display string
		}
		
		else if(op==5)				//if operation execute is selected
		{
			switch(op_char){		//switch case to perform the operation and store the result					
				case'+':
					result=a+b;
					break;

				case'-':
					result=a-b;
					break;
				
				case'x':
					result=a*b;
					break;
				
				case'/':
					result=(float)a/b;
					break;
			}
														
			sprintf(lcd_buf,"=%.2f",result);			//convert result to string
			LCD_displayStringRowColumn(1,0,lcd_buf);	//display result
			//wait for on key to reset and start the next calculation
			while(KeyPad_getPressedKey()!='C'){} 
		}
}


void calculate(void)
{
	while(1){
		key = KeyPad_getPressedKey();		//obtain key pressed

		if (key != 0)			//if key = true
		{
			cal_op();			//first check if pressed key is operation identifier
			cal_run();			//store number or apply operation
			key = 0;			//clear key for next trial
		}
		_delay_ms(500);
	}
}

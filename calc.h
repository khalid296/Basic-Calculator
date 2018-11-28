/*
 * calc.h
 *
 *  Created on: Apr 9, 2018
 *      Author: khali
 */

#ifndef CALC_H_
#define CALC_H_

#include "micro_config.h"
#include "common_macros.h"
#include <stdio.h>
#include "keypad.h"
#include "lcd.h"

/*determine calculator operation*/
void cal_op(void);

/*run the calculation process*/
void cal_run(void);

/*run the calculator*/
void calculate(void);

#endif /* CALC_H_ */

/*
Filename : ADC.h - INITIALISE ADC , AND CONVERT  ANALOG TO DIGITAL 
Hardware : Controller  -> 89C51
           XTAL        -> 11.0592 MHz
            
 Compiler : SDCC/KEIL            
 Author   : prashanth b.s
 Date		: 06/03/08
 */
#ifndef ADC8_H
#define ADC8_H

//INCLUDES
#include "includes.h"

//DEFINE PORTS/PINS
#define StartOfConversion 		P0_7
#define EndOfConversion			P0_6
#define OutputEnable 			P0_5
#define Clock 					P0_4

// #define AddressLatchEnable 	P3_5

// #define AddressA			P3_7


#define ADCDataPort		    		P1

//DEFINE CONSTANTS
#define 	AVG_SAMP			16
#define		AVG_DIV				4

//DEFINE MACROS
#define StartClock()			(TR1 = 1)
#define StopClock()				(TR1 = 0)

// FUCTION PROTOTYPES
				void 	adc8init			(void);
static 	INT8U ADCGetData		(INT8U ChannelNo);
				INT8U adc8get				(INT8U ChannelNo);
static 	void 	inittmr				(void);
#endif


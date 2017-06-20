#ifndef LCD_H
#define LCD_H

//INCLUDES
#include "includes.h"

//DEFINE CONSTANT

#define LCD_DOT		'.'
#define LCD_SPC		' '

//#define LCD_20X4		/* 20*4 LCD */


//DEFINES PORT/PINS
#define LCD_EN_PIN	P2_3
#define LCD_RS_PIN	P2_2
#define LCD_DATA_PORT	P2


//DEFINE MACROS 


//DEFINE PROTOTYPES
static	void lcden		(void);
				void lcdwc		(INT8U command);
				void lcdwd		(INT8U ascii);
				void lcdws		(INT8U *s);
static 	void lcdwb		(INT8U  LCDData);
				void lcdinit	(void);
				void lcddinit	(void);
static 	void lcdrs		(void);
				void lcdclrr	(INT8U rowno);
				void lcdclr		(void);
				void lcdr1		();
				void lcdr2		();
				void itoa			(signed int n, char s[]);
				void reverse	(char s[]);
				void lcdwint	(INT8U loc,signed int x);
				#if defined FLOAT_T0_STRING > 0
					void ftoa			(float n, char s[]);
				#endif
#endif


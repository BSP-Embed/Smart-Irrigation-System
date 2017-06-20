//DEFINE MAIN HEADER FILE
#ifndef MAIN_H
#define MAIN_H

//INCLUDE DEFINITION OF HEADER FILE
#include "includes.h"


//DEFINE PORTS/PINS
#define PUMP_PIN 			P0_2


//DEFINE CONSTANT
#define DEF_THRES			25


#define PROJECT_NAME	"AGRICUL MONIT SM"

//DEFINE MACROS
#define pumpon()				PUMP_PIN = LOW
#define pumpoff()				PUMP_PIN = HIGH



#define ADCGetTemp(x)		(100 - (adc8get(x) * 0.39))

#define starttmr()			TR0 = 1
#define stoptmr()			TR0 = 0

//FUNCTION PROTOTYPES
		void 	init		(void);
		void	tmr0_init	(void);
		void 	disp_title	(void);
static 	void 	getcrop		(void);

#endif


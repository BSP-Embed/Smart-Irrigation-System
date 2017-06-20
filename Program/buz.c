/* buz.c: driver program for buzzer */
#include"buz.h"
void beep(INT8U nbeep, INT16U ontime){
	while(nbeep--)	{
		buzon();
		dlyms(ontime);
		buzoff();
		dlyms(OFF_TIME);
	}
}



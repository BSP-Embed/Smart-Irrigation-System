
#include "adc8.h"

void adc8init(void)
{
	ADCDataPort        = INPUT_PORT;
	EndOfConversion    = INPUT_PIN;
	StartOfConversion  = OUTPUT_PIN;
	OutputEnable       = OUTPUT_PIN;
	Clock              = OUTPUT_PIN;
	inittmr();
	
//	AddressLatchEnable = OUTPUT_PIN;
//	AddressA            = OUTPUT_PIN;    
}
static void inittmr(void)
{
	TMOD = TMOD & 0x0F | 0x20;				/* 8-bit Auto Reload */
	EA	 = ET1 = 1;	
	TH1 	= TL1 = 0;
}
static tmr1ISR(void) interrupt 3 using 3
{
	Clock = ~Clock;
}
static unsigned char ADCGetData(unsigned char ChannelNo)
{		
	INT8U reading;
	ChannelNo = ChannelNo;
/*	switch(ChannelNo)
	{
		case ONE:  AddressA = LOW;
				   break;
		case TWO: AddressA = HIGH;
				    break;
	   
	 }
	AddressLatchEnable = HIGH;			// LATCH ADDRESS H-L
	delay(1);
	AddressLatchEnable = LOW;
	delay(1);     */
	
	StartOfConversion = HIGH;			// StartOfConversion CONVERSION H-L
	dlyms(1);
	StartOfConversion = LOW;
	
	while(EndOfConversion == LOW);
	
	dlyms(1);
	OutputEnable = HIGH;
	dlyms(1);
	reading = ADCDataPort;
	OutputEnable = LOW;
	
	return reading;
}
INT8U adc8get(INT8U ChannelNo)
{
	INT8U i;
	INT16U Value;
	
	Value = 0;
	
	StartClock();
	
	for(i = 0; i < AVG_SAMP; i++)
		Value += ADCGetData(ChannelNo);
	
	StopClock();
	Value >>= AVG_DIV;
	
	return (INT8U) Value;
}

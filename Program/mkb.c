//INCLUDE KEYBOARD HEADER FILE
#include"mkb.h"

//DECLARE GLOABL VARIABLE
#if MKB_CGF == MKB4_4
	code const INT8U kb_value[] = "A321B654C987D#0*";	
#else
	code const INT8U kb_value[] = "123456789*0#";	
#endif

void KBDinit(void)
{
	KB_PORT = MKB_CFG;
}
INT8U getkey()
{
	
	INT16U  time_out = 0;
	INT8U digit;

	while(KB_PORT != MKB_CFG);
	dlyms(KEY_DEBOUNE);					/* key debounce time */
	while(KB_PORT != MKB_CFG);
	dlyms(KEY_DEBOUNE);					/* key debounce time */

	while(KB_PORT == MKB_CFG){
		#ifdef NON_BLOCK 
			dlyms(1);
			if(time_out++ >= MAX_TIME_OUT)
				return 0;
		#endif
	}

  if((KB_PORT = (0xe0 | MKB_CFG)) && MASK != MKB_CFG)
   		digit = find_col(0*COL);
	else if((KB_PORT = (0xd0 | MKB_CFG)) && MASK != MKB_CFG)
   		digit = find_col(1*COL); 
	else if((KB_PORT = (0xb0 | MKB_CFG)) && MASK != MKB_CFG)
   		digit = find_col(2*COL);	 
	else if((KB_PORT = (0x70 | MKB_CFG)) && MASK != MKB_CFG)
   		digit = find_col(3*COL);

	return kb_value[digit];
}
	
INT8U find_col(INT8U key)
{
	KB_PORT &= MKB_CFG;
	
	#if MKB_CGF == MKB4_4
		if(KB_PORT == 0x0d)
			key++;
		else if(KB_PORT == 0x0b)
			key +=2;
		else if(KB_PORT == 0x07)
			key +=3;
		return key;
	#else
		switch (KB_PORT) {
			case 0x0c:	break;
			case 0x0a:  ++key; 	break;
			case 0x06: key += 2; break;
		}
		return key;
	#endif
}


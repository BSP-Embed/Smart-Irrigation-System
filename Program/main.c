/* main application program : Measure body temperature and heart beat */
#include"main.h"
 
extern INT8U lcdptr;

const char *cropstr[] = { 	"",
							"RICE",
							"WHEAT",
							"SUNFLOWER",
							"JOWER" };
char *CropName;
INT8U CropThreshold;
bit dispflag = 0;

void main(void)
{
	INT8U mos;
	init();

	while (TRUE) {
	 	if (dispflag == 1) {
			dispflag = 0;
			lcdwint(0xcd, mos = ADCGetTemp(0));
			if (mos <= CropThreshold)
				pumpon();
			else if ( mos > (CropThreshold-2))
				pumpoff();
		}
	}
}
static void disp_title(void)
{
	lcdclr();
	lcdws(PROJECT_NAME);
	lcdr2();
 	lcdws("C:");
	lcdws(CropName);
	lcdptr = 0xcb;
	lcdws("M:   ");
}
static void init(void)
{
	beep(2,75);
	tmr0_init();
	lcdinit();
	adc8init();
	KBDinit();
	getcrop();
	disp_title();
	starttmr();
}
static void getcrop(void)
{
	INT8U crop;
	INT8U cflag = 0;
	lcdclr();
	lcdws("Enter Crop Name");
	beep(1,100);
	lcdr2();
	crop = 0x0f & getkey();
	lcdwint(0xc0,crop);
	switch (crop) {
		case 1: case 2: case 3: case 4:
			CropName = cropstr[crop];
			CropThreshold = crop * DEF_THRES;
			lcdws(CropName);
			cflag = 1;
			break;
		default:
			beep(1,500);
			break;
	}
	if (!cflag)
		getcrop();
}

static void tmr0_init(void)
{
	TMOD = TMOD & 0xf0 | 0x01;		/* TMR0 in mode1*/
	TH0 = 0x4B;
	TL0 = 0xFD;
	EA = ET0 = 1;
} 
static void tmr0ISR() interrupt 1 using 2
{
	static INT8U i,j,k;

	TH0 = 0x4B;
	TL0 = 0xFD;
		
	if (++i >= 2) {
		i = 0;
		if (++j >= 50) j = 0;
		switch(j) {
			case 0: case 2: ledon();  break;
			case 1: case 3: ledoff(); break;
		}
		if (++k == 10) { 
			k = 0;
			dispflag = 1;
		}
	
	}
} 

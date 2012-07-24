#ifndef GENERAL_H_
#define GENERAL_H_

#include <msp430.h>

#define UINT unsigned int
//#define BYTEPTR(BYTE) ((unsigned char*)(&BYTE))

//////////////////////////////
// WatchDog
//////////////////////////////
#define WATCHDOG_STOPPED() WDTCTL = WDTPW | WDTHOLD;

//////////////////////////////
// Processor mode
//////////////////////////////
#define ENABLEGLOBALINTERRUPTS _BIS_SR(GIE)
#define ENTERSUSPENDMODE(MODE) _BIS_SR(MODE)

#define DELAY_CYCLES(QTY1, QTY2) \
	for (int i = 0; i < QTY1; i++) \
		for (int j = 0; j < QTY2; j++) \
			;

typedef enum PINVALUE_VALUES {PINLOW = 0, PINHIGH = 1} PINVALUE;
typedef enum PINDIR_VALUES {PININPUT = 0, PINOUTPUT = 1} PINDIR;
typedef enum DIRECTION_VALUES {FORWARD = 0, BACKWARD = 1} DIRECTION;
typedef enum FREQUENCY_VALUES {KHZ0800 = 0, KHZ7800 = 1, KHZ15250 = 2} FREQUENCY;

#define SETLOW(REG, PIN) REG &= ~(PIN)
#define SETHIGH(REG, PIN) REG |= PIN
#define SETVAL(REG, PIN, VALUE) \
	if (VALUE == PINLOW) \
		SETLOW(REG, PIN); \
	else \
		SETHIGH(REG, PIN);
#define TOGGLE(REG, PIN) REG ^= PIN


#define INITPULLUPBUTTONLOWTOHIGH(PORT, BIT) \
		SETOUTHIGH(PORT, BIT); \
		ENABLEPINRESISTANCE(PORT, BIT); \
		ENABLEINTFROMLOWTOHIGH(PORT, BIT); \
		CLEARIFG(PORT, BIT); \
		ENABLEINT(PORT, BIT);

#define SETBLOCKPINVALUE(PORT, WIDTH, OFFSET, VALUE) \
		{ \
			const UINT widthmask = (1 << WIDTH) - 1; \
			PORT = (~(widthmask << OFFSET) & PORT) | ((VALUE & widthmask) << OFFSET); \
		}

void InitPullUpButtonHighToLow();

#endif /* GENERAL_H_ */

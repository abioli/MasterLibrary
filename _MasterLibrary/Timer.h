#ifndef TIMER_H_
#define TIMER_H_

#include "General.h"

#ifdef __MSP430_HAS_TA2__

// #ifdef __MSP430_HAS_TA3__
// #ifdef __MSP430_HAS_T1A3__

class TimerA0
{
	friend void TIMERA0_ISR();
public:
	static UINT cicliperdecimillesimo;

	static void InitInternalClock(UINT decimilliseconds, void (*tf)());
	static void InitExternalCrystal(void (*tf)());
private:
	static void (*_timerfunction)();
};
#endif // __MSP430_HAS_TA2__

#endif /* TIMER_H_ */

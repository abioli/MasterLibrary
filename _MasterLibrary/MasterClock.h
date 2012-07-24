#ifndef MASTERCLOCK_H_
#define MASTERCLOCK_H_

#include "msp430.h"
#include "General.h"


#define SETCALIBRATED(i) BCSCTL1 = CALBC1_##i##MHZ, DCOCTL = CALDCO_##i##MHZ

class MasterClock
{
public:
	static inline void SetDCOParameters(int rsel, int dco, int mod)
	{
		SETBLOCKPINVALUE(BCSCTL1, 4, 0, rsel);
		SETBLOCKPINVALUE(DCOCTL, 3, 5, dco);
		SETBLOCKPINVALUE(DCOCTL, 5, 0, mod);
	}

	static inline void SetCalibrated1Mhz() { SETCALIBRATED(1); }
#ifdef CALBC1_8MHZ
	static inline void SetCalibrated8Mhz() { SETCALIBRATED(8); }
#endif
#ifdef CALBC1_12MHZ
	static inline void SetCalibrated12Mhz() { SETCALIBRATED(12); }
#endif
#ifdef CALBC1_16MHZ
	static inline void SetCalibrated16Mhz() { SETCALIBRATED(16); }
#endif
};

#endif /* MASTERCLOCK_H_ */

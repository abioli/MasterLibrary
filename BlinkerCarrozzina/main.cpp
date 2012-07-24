#include "General.h"
#include "Port.h"
#include "Pin.h"
#include "MasterClock.h"

DEFINE_PIN(p10, P1, BIT0);

void main(void)
{
	WATCHDOG_STOPPED();

	//MasterClock::SetDCOParameters(15, 3, 0);
	//MasterClock::SetCalibrated1Mhz();

	p10.SetDirOut();

	while (1)
	{
		p10.Toggle();
		__delay_cycles(50000);
		DELAY_CYCLES(10, 5000);
	}
}

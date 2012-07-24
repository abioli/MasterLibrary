#ifndef ADC10_H_
#define ADC10_H_

#include "msp430.h"

#ifdef __MSP430_HAS_ADC10__

class ADC10
{
public:
	static inline void Init()
	{
		ADC10CTL1 = INCH_5 + ADC10DIV_3 ;         // Channel 5, ADC10CLK/4
		ADC10CTL0 = SREF_0 + ADC10SHT_3 + ADC10ON + ADC10IE;  //Vcc & Vss as reference
		ADC10AE0 |= BIT5;
	}
};
#endif // __MSP430_HAS_ADC10__

#endif /* ADC10_H_ */

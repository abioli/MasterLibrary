#include "msp430.h"
#include "General.h"

#pragma vector=WDT_VECTOR
__interrupt void WDT_ISR()
{
}

/*
#pragma vector=COMPARATORA_VECTOR
__interrupt void COMPARATORA_ISR()
{
}
*/

#pragma vector=NMI_VECTOR
__interrupt void NMI_ISR()
{
}

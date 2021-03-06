#include "tmr2.h"

TMR2_InterruptHandler_t tmr2_isr_handler;
void TMR2_InterruptHandler_Default ( );

/**
 * ckps:1 outps:16 disabled pr2:249 isr enabled
 */
void TMR2_Initialize ( ) {
	T2CON = T2CON_CKPS_1 | T2CON_OUTPS_1;
	PR2 = 0xF9;
	TMR2 = 0x00;
	PIR1bits.TMR2IF = 0;
	PIE1bits.TMR2IE = 1;
	tmr2_isr_handler = TMR2_InterruptHandler_Default;
}

void TMR2_ISR ( ) {
	PIR1bits.TMR2IF = 0;
	tmr2_isr_handler ( );
}

void TMR2_InterruptHandler_Default ( ) {
}

void TMR2_SetInterruptHandler ( TMR2_InterruptHandler_t handler ) {
	tmr2_isr_handler = handler;
}

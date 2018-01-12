#include "tmr1.h"

TMR1_InterruptHandler_t tmr1_isr_handler;
TMR1_InterruptHandler_t tmr1_gate_isr_handler;
void TMR1_InterruptHandler_Default ( );
void TMR1_Gate_InterruptHandler_Default ( );

/**
 * fosc/4 ckps:8
 */
void TMR1_Initialize ( ) {
	T1CON = T1CON_T1CKPS_8 | T1CON_T1SYNC_DISABLE | T1CON_TMR1CS_FOSC_4;

	TMR1 = 0x00;
	PIR1bits.TMR1IF = 0;
	PIE1bits.TMR1IE = 0;
	PIR1bits.TMR1GIF = 0;
	PIE1bits.TMR1GIE = 0;
	tmr1_isr_handler = TMR1_InterruptHandler_Default;
	tmr1_gate_isr_handler = TMR1_Gate_InterruptHandler_Default;
}

void TMR1_ISR ( ) {
	PIR1bits.TMR1IF = 0;
	tmr1_isr_handler ( );
}

void TMR1_GATE_ISR ( ) {
	PIR1bits.TMR1GIF = 0;
	tmr1_gate_isr_handler ( );
}

void TMR1_InterruptHandler_Default ( ) {
}

void TMR1_Gate_InterruptHandler_Default ( ) {
}

void TMR1_SetInterruptHandler ( TMR1_InterruptHandler_t handler ) {
	tmr1_isr_handler = handler;
}

void TMR1_Gate_SetInterruptHandler ( TMR1_InterruptHandler_t handler ) {
	tmr1_gate_isr_handler = handler;
}


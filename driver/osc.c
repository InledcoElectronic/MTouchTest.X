#include "osc.h"

/**
 * INTOSC 16MHz
 */
void OSC_Initialize ( ) {
	OSCCON = OSCCON_IRCF_16M_HF | OSCCON_SCS_INTOSC;
	while ( OSCSTATbits.HFIOFS == 0 );
}

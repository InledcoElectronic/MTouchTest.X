#include "pin.h"

void PIN_Initialize()
{
	APFCON = APFCON_TXCKSEL_RA4;
	LATA = 0x30;
	TRISA = 0x00;
	ANSELA = 0x04;
	WPUA = 0x00;
}

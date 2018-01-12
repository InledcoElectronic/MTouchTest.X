#include "eusart.h"

#define TX_BUF_SIZE		32
static uint8_t txTail;
static uint8_t txRemain;
static uint8_t txHead;
static uint8_t txBuf[TX_BUF_SIZE];

static EUSART_ReceiveInterruptHandler_t eusart_rcv_isr_handler;
void EUSART_ReceiveInterruptHandler_Default ( uint8_t rcv );

/**
 * baudrate 9600@16MHz, rx isr disabled,
 */
void EUSART_Initialize ( ) {
	PIE1bits.RCIE = 0;
	PIE1bits.TXIE = 0;
	BAUDCON = BAUDCON_BRG16;
	RCSTA = RCSTA_SPEN | RCSTA_CREN;
	TXSTA = TXSTA_TXEN | TXSTA_BRGH;
	SPBRG = BAUDRATE_16M_57600;

	//    PIE1bits.RCIE = 1;
	txTail = 0;
	txHead = 0;
	txRemain = sizeof (txBuf );
	
	eusart_rcv_isr_handler = EUSART_ReceiveInterruptHandler_Default;
}

uint8_t EUSART_Write ( uint8_t byte ) {
	while ( 0 == txRemain );

	if ( !PIE1bits.TXIE ) {
		TXREG = byte;
	} else {
		PIE1bits.TXIE = 0;
		txBuf[txHead++] = byte;
		if ( sizeof (txBuf ) <= txHead ) {
			txHead = 0;
		}
		txRemain--;
	}
	PIE1bits.TXIE = 1;
	return byte;
}

void EUSART_Receive_ISR ( ) {
	uint8_t rcv = RCREG;
	eusart_rcv_isr_handler ( rcv );
}

void EUSART_Transmit_ISR ( ) {
	if ( sizeof (txBuf ) > txRemain ) {
		TXREG = txBuf[txTail++];
		if ( sizeof (txBuf ) <= txTail ) {
			txTail = 0;
		}
		txRemain++;
	} else {
		PIE1bits.TXIE = 0;
	}
}

void EUSART_ReceiveInterruptHandler_Default ( uint8_t rcv )
{	
}

void EUSART_SetReceiveInterruptHandler ( EUSART_ReceiveInterruptHandler_t handler )
{
	eusart_rcv_isr_handler = handler;
}


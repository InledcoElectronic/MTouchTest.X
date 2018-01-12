/**
  Generated Main Source File

  Company:
	Microchip Technology Inc.

  File Name:
	main.c

  Summary:
	This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
	This header file provides implementations for driver APIs for all modules selected in the GUI.
	Generation Information :
		Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65
		Device            :  PIC12F1572
		Driver Version    :  2.00
 */

/*
	(c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
	software and any derivatives exclusively with Microchip products.

	THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
	EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
	WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
	PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
	WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

	IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
	INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
	WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
	BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
	FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
	ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
	THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

	MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
	TERMS.
 */

#include "driver/pin.h"
#include "driver/osc.h"
#include "driver/tmr2.h"
#include "driver/eusart.h"
#include "mtouch/mtouch.h"

// CONFIG1
#pragma config FOSC = INTOSC    // ->INTOSC oscillator; I/O function on CLKIN pin
#pragma config WDTE = ON    // Watchdog Timer Enable->WDT enabled
#pragma config PWRTE = ON    // Power-up Timer Enable->PWRT enabled
#pragma config MCLRE = ON    // MCLR Pin Function Select->MCLR/VPP pin function is MCLR
#pragma config CP = OFF    // Flash Program Memory Code Protection->Program memory code protection is disabled
#pragma config BOREN = ON    // Brown-out Reset Enable->Brown-out Reset enabled
#pragma config CLKOUTEN = OFF    // Clock Out Enable->CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin

// CONFIG2
#pragma config WRT = OFF    // Flash Memory Self-Write Protection->Write protection off
#pragma config PLLEN = OFF    // PLL Enable->4x PLL disabled
#pragma config STVREN = ON    // Stack Overflow/Underflow Reset Enable->Stack Overflow or Underflow will cause a Reset
#pragma config BORV = LO    // Brown-out Reset Voltage Selection->Brown-out Reset Voltage (Vbor), low trip point selected.
#pragma config LPBOREN = OFF    // Low Power Brown-out Reset enable bit->LPBOR is disabled
#pragma config LVP = ON    // Low-Voltage Programming Enable->Low-voltage programming enabled

#define LED		LATAbits.LATA5

void SYSTEM_Initialize ( ) {
	PIN_Initialize ( );
	OSC_Initialize ( );
	TMR2_Initialize ( );
	EUSART_Initialize ( );
}

void interrupt INTERRUPT_Manager ( ) {
	if ( INTCONbits.PEIE ) {
		if ( PIE1bits.TMR2IE && PIR1bits.TMR2IF ) {
			TMR2_ISR ();
		} else if ( PIE1bits.TXIE && PIR1bits.TXIF ) {
			EUSART_Transmit_ISR ();
			MTOUCH_Sensor_NotifyInterruptOccurred ();
		}
	}
}

void log_info ( enum mtouch_button_names button ) {
	mtouch_button_reading_t reading = MTOUCH_Button_Reading_Get ( button );
	mtouch_button_reading_t baseline = MTOUCH_Button_Baseline_Get ( button );
	mtouch_sensor_sample_t value = MTOUCH_Sensor_RawSample_Get ( (enum mtouch_sensor_names)button );
	EUSART_Write ( '0' + button );
	EUSART_Write ( ':' );
	EUSART_Write ( value / 10000 + '0' );
	EUSART_Write ( value / 1000 % 10 + '0' );
	EUSART_Write ( value / 100 % 10 + '0' );
	EUSART_Write ( value / 10 % 10 + '0' );
	EUSART_Write ( value % 10 + '0' );
	EUSART_Write ( '-' );
	EUSART_Write ( reading / 10000 + '0' );
	EUSART_Write ( reading / 1000 % 10 + '0' );
	EUSART_Write ( reading / 100 % 10 + '0' );
	EUSART_Write ( reading / 10 % 10 + '0' );
	EUSART_Write ( reading % 10 + '0' );
	EUSART_Write ( '-' );
	EUSART_Write ( baseline / 10000 + '0' );
	EUSART_Write ( baseline / 1000 % 10 + '0' );
	EUSART_Write ( baseline / 100 % 10 + '0' );
	EUSART_Write ( baseline / 10 % 10 + '0' );
	EUSART_Write ( baseline % 10 + '0' );
	EUSART_Write ( '\r' );
	EUSART_Write ( '\n' );
}

void led_on()
{
	LED = 0;
}

void led_off()
{
	LED = 1;
}

//void log_rawsample( enum mtouch_sensor_names sensor )
//{
//	mtouch_sensor_sample_t value = MTOUCH_Sensor_RawSample_Get ( sensor );
//	EUSART_Write ( '0' + sensor );
//	EUSART_Write ( ':' );
//	EUSART_Write ( value/10000 + '0' );
//	EUSART_Write ( value/1000%10 + '0' );
//	EUSART_Write ( value/100%10 + '0' );
//	EUSART_Write ( value/10%10 + '0' );
//	EUSART_Write ( value%10 + '0' );
//	EUSART_Write ( '\r' );
//	EUSART_Write ( '\n' );
//}

/*
						 Main application
 */
void main ( void ) {
	// initialize the device
	SYSTEM_Initialize ( );
	MTOUCH_Initialize ( );
	MTOUCH_Sensor_SetSampledCallback ( log_info );
	MTOUCH_Button_SetPressedCallback ( led_on );
	MTOUCH_Button_SetNotPressedCallback ( led_off );

	// When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
	// Use the following macros to:

	// Enable the Global Interrupts
	INTERRUPT_GlobalInterruptEnable ( );

	// Enable the Peripheral Interrupts
	INTERRUPT_PeripheralInterruptEnable ( );

	// Disable the Global Interrupts
	//INTERRUPT_GlobalInterruptDisable();

	// Disable the Peripheral Interrupts
	//INTERRUPT_PeripheralInterruptDisable();

	while ( 1 ) {
		// Add your application code
		CLRWDT ( );
		MTOUCH_Service_Mainloop ( );
	}
}
/**
 End of File
 */
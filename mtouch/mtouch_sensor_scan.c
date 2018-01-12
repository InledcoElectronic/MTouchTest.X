#include "mtouch_sensor_scan.h"
#include <xc.h>

#define MTOUCH_ADCON0_NONE					113
#define MTOUCH_TX_GAURD_LAT					LATA
#define MTOUCH_TX_GAURD_PIN					1

#define MTOUCH_S0_ADCON0_SENSOR              ( 0x2<<2 | 0x1 )
#define MTOUCH_S0_LAT                        LATA
#define MTOUCH_S0_TRIS                       TRISA
#define MTOUCH_S0_PIN                        2
#define MTOUCH_S0_REF_ADCON0                 ( 0x2<<2 | 0x1 )
#define MTOUCH_S0_REF_LAT                    LATA
#define MTOUCH_S0_REF_PIN                    2
#define MTOUCH_S0_PRECHARGE_TIME             10
#define MTOUCH_S0_ACQUISITION_TIME           5
#define MTOUCH_S0_SWITCH_TIME                0
#define MTOUCH_S0_DISCON_TIME                3

/**
 * @prototype    void MTOUCH_CVD_ScanA_0
 * @description  CVD scanA for sensor 0
 *               - name:                         Sensor_AN2
 *               - pin:                          RA2
 *               - analog channel:               AN2
 *               - reference type:               MTOUCH_OPTION_REFTYPE_SELF
 *               - guard type:                   MTOUCH_OPTION_GUARDTYPE_IO
 */
void MTOUCH_CVD_ScanA_0 ( void ) {
	/* Initialize Precharge Source */
	asm ( "BANKSEL        " ___mkstr( MTOUCH_S0_REF_LAT ) );
	asm ( "bsf            " ___mkstr( MTOUCH_S0_REF_LAT ) " & 0x7F, " ___mkstr( MTOUCH_S0_REF_PIN ) );

	/* Begin Precharge Stage */
	asm ( "BANKSEL        ADCON0" );
	asm ( "movlw          " ___mkstr( MTOUCH_S0_REF_ADCON0 ) );
	asm ( "movwf          ADCON0 & 0x7F" );

	/* Precharge Delay */
	_delay ( MTOUCH_S0_PRECHARGE_TIME );

	/* Self-Reference Logic */
	asm ( "movlw          " ___mkstr( MTOUCH_ADCON0_NONE ) );
	asm ( "movwf          ADCON0 & 0x7F" );
	asm ( "BANKSEL        " ___mkstr( MTOUCH_S0_LAT ) );
	asm ( "bcf            " ___mkstr( MTOUCH_S0_LAT ) " & 0x7F, " ___mkstr( MTOUCH_S0_PIN ) );
	asm ( "BANKSEL        ADCON0" );

	/* Prepare FSR0 for Settling Phase */
	asm ( "movlw LOW      " ___mkstr( MTOUCH_S0_TRIS ) );
	asm ( "movwf          FSR0L & 0x7F" );
	asm ( "movlw HIGH     " ___mkstr ( MTOUCH_S0_TRIS ) );
	asm ( "movwf          FSR0H & 0x7F" );

	/* Prepare FSR1 for Settling Phase */
	asm ( "movlw LOW      " ___mkstr( MTOUCH_TX_GAURD_LAT ) );
	asm ( "movwf          FSR1L & 0x7F" );
	asm ( "movlw HIGH     " ___mkstr ( MTOUCH_TX_GAURD_LAT ) );
	asm ( "movwf          FSR1H & 0x7F" );

	/* Begin Settling Stage: Connect */
	asm ( "movlw          " ___mkstr ( MTOUCH_S0_ADCON0_SENSOR ) );
	asm ( "bsf            INDF0 & 0x7F, " ___mkstr ( MTOUCH_S0_PIN ) );
	_delay ( MTOUCH_S0_SWITCH_TIME );
	asm ( "movwf          ADCON0 & 0x7F" );
	asm ( "bsf            INDF1 & 0x7F, " ___mkstr( MTOUCH_TX_GAURD_PIN ) );

	/* Settling Delay */
	_delay ( MTOUCH_S0_ACQUISITION_TIME );

	/* Begin Conversion */
	asm ( "BANKSEL        ADCON0" );
	asm ( "bsf            ADCON0 & 0x7F, 1" );									

	/* Disconnection Delay */
	_delay ( MTOUCH_S0_DISCON_TIME );

	/* Exit Logic - Output Low */								
	asm ( "BANKSEL        " ___mkstr( MTOUCH_S0_LAT ) );
	asm ( "bsf            " ___mkstr( MTOUCH_S0_LAT ) " & 0x7F, " ___mkstr ( MTOUCH_S0_PIN ) );
	asm ( "bcf            INDF0 & 0x7F, " ___mkstr ( MTOUCH_S0_PIN ) );
}

/**
 * @prototype    void MTOUCH_CVD_ScanB_0
 * @description    CVD scanB for sensor 0
 *                - name:                         Sensor_AN2
 *                - pin:                          RA2
 *                - analog channel:               AN2
 *                - reference type:               MTOUCH_OPTION_REFTYPE_SELF
 *                - guard type:                   MTOUCH_OPTION_GUARDTYPE_IO
 */
void MTOUCH_CVD_ScanB_0 ( void ) {
	/* Initialize Precharge Source */
	asm ( "BANKSEL        " ___mkstr( MTOUCH_S0_REF_LAT ) );
	asm ( "bcf            " ___mkstr( MTOUCH_S0_REF_LAT ) " & 0x7F, " ___mkstr( MTOUCH_S0_REF_PIN ) );

	/* Begin Precharge Stage */
	asm ( "BANKSEL        ADCON0" );
	asm ( "movlw          " ___mkstr( MTOUCH_S0_REF_ADCON0 ) );
	asm ( "movwf          ADCON0 & 0x7F" );

	/* Precharge Delay */
	_delay ( MTOUCH_S0_PRECHARGE_TIME );

	/* Self-Reference Logic */
	asm ( "movlw          " ___mkstr( MTOUCH_ADCON0_NONE ) );
	asm ( "movwf          ADCON0 & 0x7F" );
	asm ( "BANKSEL        " ___mkstr( MTOUCH_S0_LAT ) );
	asm ( "bsf            " ___mkstr ( MTOUCH_S0_LAT ) " & 0x7F, " ___mkstr ( MTOUCH_S0_PIN ) );
	asm ( "BANKSEL        ADCON0" );

	/* Prepare FSR0 for Settling Phase */
	asm ( "movlw LOW      " ___mkstr ( MTOUCH_S0_TRIS ) );
	asm ( "movwf          FSR0L & 0x7F" );
	asm ( "movlw HIGH     " ___mkstr ( MTOUCH_S0_TRIS ) );
	asm ( "movwf          FSR0H & 0x7F" );

	/* Prepare FSR1 for Settling Phase */
	asm ( "movlw LOW      " ___mkstr ( MTOUCH_TX_GAURD_LAT ) );
	asm ( "movwf          FSR1L & 0x7F" );
	asm ( "movlw HIGH     " ___mkstr ( MTOUCH_TX_GAURD_LAT ) );
	asm ( "movwf          FSR1H & 0x7F" );

	/* Begin Settling Stage: Connect */
	asm ( "movlw          " ___mkstr ( MTOUCH_S0_ADCON0_SENSOR ) );
	asm ( "bsf            INDF0 & 0x7F, " ___mkstr ( MTOUCH_S0_PIN ) );
	_delay ( MTOUCH_S0_SWITCH_TIME );
	asm ( "movwf          ADCON0 & 0x7F" );
	asm ( "bcf            INDF1 & 0x7F, " ___mkstr ( MTOUCH_TX_GAURD_PIN ) );

	/* Settling Delay */
	_delay ( MTOUCH_S0_ACQUISITION_TIME );

	/* Begin Conversion */
	asm ( "BANKSEL        ADCON0" );
	asm ( "bsf            ADCON0 & 0x7F, 1" );

	/* Disconnection Delay */
	_delay ( MTOUCH_S0_DISCON_TIME );

	/* Exit Logic - Output Low */
	asm ( "BANKSEL        " ___mkstr( MTOUCH_S0_LAT ) );
	asm ( "bcf            " ___mkstr( MTOUCH_S0_LAT ) " & 0x7F, " ___mkstr ( MTOUCH_S0_PIN ) );
	asm ( "bcf            INDF0 & 0x7F, " ___mkstr ( MTOUCH_S0_PIN ) );
}

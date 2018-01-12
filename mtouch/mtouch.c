#include <xc.h>
#include <stdint.h>

#include "mtouch.h"

/*
 * =======================================================================
 * MTOUCH_Init()
 * =======================================================================
 *  Root initialization routine for all enabled mTouch library modules.
 */
void MTOUCH_Initialize ( void ) {
	MTOUCH_Sensor_InitializeAll ( );
	MTOUCH_Button_InitializeAll ( );
	MTOUCH_Sensor_Sampled_ResetAll ( );
	MTOUCH_Sensor_Scan_Initialize ( );
}

/*
 * =======================================================================
 * MTOUCH_Service_Mainloop()
 * =======================================================================
 *  Root mainloop service routine for all enabled mTouch library modules.
 */
bool MTOUCH_Service_Mainloop ( void ) {
	if ( MTOUCH_Sensor_SampleAll ( ) == false )
		return false;
	MTOUCH_Button_ServiceAll ( ); /* Execute state machine for all buttons w/scanned sensors */
	MTOUCH_Sensor_Sampled_ResetAll ( );
	MTOUCH_Tick ( );
	return true;
}

/*
 * =======================================================================
 * MTOUCH_Tick
 * =======================================================================
 */
void MTOUCH_Tick ( void ) {
}

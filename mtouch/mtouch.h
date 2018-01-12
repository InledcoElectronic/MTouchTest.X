/* 
 * File:   mtouch.h
 * Author: liruya
 *
 * Created on 2018年1月10日, 下午4:59
 */

#ifndef MTOUCH_H
#define	MTOUCH_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include "mtouch_sensor.h"
#include "mtouch_button.h"

#if (__XC8_VERSION < 1420)
#error  Please update XC8 compiler to version 1.42 or higher. 
#endif

    /*
     * =======================================================================
     * Global Functions :: mTouch Library API
     * =======================================================================
     */
    void MTOUCH_Initialize(void);
    bool MTOUCH_Service_Mainloop(void);
    void MTOUCH_Tick(void);

    /*
     * =======================================================================
     * mTouch Library :: State API
     * =======================================================================
     * To get state information on mTouch sensors, there are two options:
     *
     * 1. Provide callback functions defined in your
     *    own application's files. To do this:
     *
     *         Use the 'Set Callback' API to provide the function pointer
     *         to your application's function:
     *          void MTOUCH_Button_SetPressedCallback   (void (*callback)(enum mtouch_button_names button));
     *          void MTOUCH_Button_SetNotPressedCallback(void (*callback)(enum mtouch_button_names button));
     *
     *  2. Alternatively, you may choose to directly poll the status of the
     *     mTouch state machine by using the appropriate API. To do this:
     *
     *          Use the appropriate API in your application:
     *          bool MTOUCH_Button_isPressed     (enum mtouch_button_names    button);
     */

    /*
     * =======================================================================
     * Firmware and product ID
     * =======================================================================
     */

#define ID_PRODUCT                  (uint32_t)0x00000000
#define ID_MANUFACTURER             (uint16_t)0x0001
#define ID_BUILD                    (uint8_t)0
#define ID_MINOR                    (uint8_t)30
#define ID_MAJOR                    (uint8_t)2

#ifdef	__cplusplus
}
#endif

#endif	/* MTOUCH_H */


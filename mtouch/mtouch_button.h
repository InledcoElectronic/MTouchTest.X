/* 
 * File:   mtouch_button.h
 * Author: liruya
 *
 * Created on 2018年1月10日, 下午4:57
 */

#ifndef MTOUCH_BUTTON_H
#define	MTOUCH_BUTTON_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include "mtouch.h"

    /*
     * =======================================================================
     * Application / Configuration Settings
     * =======================================================================
     */
#define MTOUCH_BUTTONS 1

    enum mtouch_button_names {
        Button0 = 0
    };


#define MTOUCH_BUTTON_THRESHOLD_Button0 600

#define MTOUCH_BUTTON_SCALING_Button0 1
    
#define MTOUCH_BUTTON_DEFAULT_BASELINE_Button0  (uint16_t)5000

    /*
     * =======================================================================
     * Typedefs / Data Types
     * =======================================================================
     */
    typedef uint8_t mtouch_buttonmask_t;

    typedef uint16_t mtouch_button_statecounter_t;
#define MTOUCH_BUTTON_STATECOUNTER_MIN (0)
#define MTOUCH_BUTTON_STATECOUNTER_MAX (UINT16_MAX)
#define MTOUCH_BUTTON_NEGATIVEDEVIATION ((mtouch_button_statecounter_t)32)

    typedef uint16_t mtouch_button_baselinecounter_t;
#define MTOUCH_BUTTON_BASECOUNTER_MIN (0)
#define MTOUCH_BUTTON_BASECOUNTER_MAX (UINT16_MAX)

    typedef uint16_t mtouch_button_reading_t;
#define MTOUCH_BUTTON_READING_MIN (0)
#define MTOUCH_BUTTON_READING_MAX (UINT16_MAX)
#define MTOUCH_BUTTON_READING_GAIN (uint8_t)2

    typedef uint32_t mtouch_button_baseline_t;
#define MTOUCH_BUTTON_BASELINE_MIN (0)
#define MTOUCH_BUTTON_BASELINE_MAX (UINT32_MAX)
#define MTOUCH_BUTTON_BASELINE_GAIN ((uint8_t)4)
#define MTOUCH_BUTTON_BASELINE_INIT ((mtouch_button_statecounter_t)16)
#define MTOUCH_BUTTON_BASELINE_RATE ((mtouch_button_baselinecounter_t)32)

    typedef int16_t mtouch_button_deviation_t;
#define MTOUCH_BUTTON_DEVIATION_MIN (INT16_MIN)
#define MTOUCH_BUTTON_DEVIATION_MAX (INT16_MAX)
#define MTOUCH_BUTTON_NEGATIVETHRESHOLD (mtouch_button_deviation_t)-10

    typedef uint8_t mtouch_button_threshold_t;
#define MTOUCH_BUTTON_THRESHOLD_MIN ((mtouch_button_threshold_t)(1))
#define MTOUCH_BUTTON_THRESHOLD_MAX ((mtouch_button_threshold_t)(127))

    typedef uint8_t mtouch_button_scaling_t;
#define MTOUCH_BUTTON_SCALING_MIN ((mtouch_button_scaling_t)(0))
#define MTOUCH_BUTTON_SCALING_MAX ((mtouch_button_scaling_t)(8))


    /*
     * =======================================================================
     * Global Functions
     * =======================================================================
     */
    void MTOUCH_Button_SetPressedCallback(void (*callback)(enum mtouch_button_names button));
    void MTOUCH_Button_SetNotPressedCallback(void (*callback)(enum mtouch_button_names button));

    void MTOUCH_Button_Initialize(enum mtouch_button_names button);
    void MTOUCH_Button_InitializeAll(void);
    void MTOUCH_Button_ServiceAll(void);

    mtouch_button_deviation_t MTOUCH_Button_Deviation_Get(enum mtouch_button_names button);
    mtouch_button_reading_t MTOUCH_Button_Reading_Get(enum mtouch_button_names button);
    mtouch_button_reading_t MTOUCH_Button_Baseline_Get(enum mtouch_button_names button);
    mtouch_button_scaling_t MTOUCH_Button_Scaling_Get(enum mtouch_button_names button);
    void MTOUCH_Button_Scaling_Set(enum mtouch_button_names button, mtouch_button_scaling_t scaling);
    mtouch_button_threshold_t MTOUCH_Button_Threshold_Get(enum mtouch_button_names button);
    void MTOUCH_Button_Threshold_Set(enum mtouch_button_names button, mtouch_button_threshold_t threshold);

    bool MTOUCH_Button_isPressed(enum mtouch_button_names button);
    bool MTOUCH_Button_isInitialized(enum mtouch_button_names button);
    mtouch_buttonmask_t MTOUCH_Button_Buttonmask_Get(void);


#ifdef	__cplusplus
}
#endif

#endif	/* MTOUCH_BUTTON_H */


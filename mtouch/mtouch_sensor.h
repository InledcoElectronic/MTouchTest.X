/* 
 * File:   mtouch_sensor.h
 * Author: liruya
 *
 * Created on 2018年1月10日, 下午3:01
 */

#ifndef MTOUCH_SENSOR_H
#define	MTOUCH_SENSOR_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

#define MTOUCH_SENSORS      1

    enum mtouch_sensor_names {
        Sensor_AN2 = 0
    };

    enum mtouch_sensor_error {
        MTOUCH_SENSOR_ERROR_none = 0,
        MTOUCH_SENSOR_ERROR_invalid_index = -1,
        MTOUCH_SENSOR_ERROR_interrupt_notEnabled = -2,
        MTOUCH_SENSOR_ERROR_invalid_calibrate = -3,
        MTOUCH_SENSOR_ERROR_tooManyRetries = -4,
        MTOUCH_SENSOR_ERROR_scanOverrun = -5,
        MTOUCH_SENSOR_ERROR_interruptedScan = -6
    };

    /*
     * =======================================================================
     * Typedefs / Data Types
     * =======================================================================
     */
    typedef uint16_t mtouch_sensor_sample_t;
#define MTOUCH_SENSOR_SAMPLE_MIN (0)
#define MTOUCH_SENSOR_SAMPLE_MAX (UINT16_MAX)

    typedef uint8_t mtouch_sensor_mask_t;
#define MTOUCH_SENSOR_MASK_MIN (0)
#define MTOUCH_SENSOR_MASK_MAX (UINT8_MAX)

    /*
     * =======================================================================
     * Global Functions
     * =======================================================================
     */
    enum mtouch_sensor_error MTOUCH_Sensor_Initialize(enum mtouch_sensor_names sensor);
    void MTOUCH_Sensor_Scan_Initialize(void);
    void MTOUCH_Sensor_InitializeAll(void);
    void MTOUCH_Sensor_SetSampledCallback(void (*callback)(enum mtouch_sensor_names sensor));
    bool MTOUCH_Sensor_SampleAll(void);

    bool MTOUCH_Sensor_isActive(enum mtouch_sensor_names sensor);
    bool MTOUCH_Sensor_wasSampled(enum mtouch_sensor_names sensor);
    bool MTOUCH_Sensor_isCalibrated(enum mtouch_sensor_names sensor);
    bool MTOUCH_Sensor_isEnabled(enum mtouch_sensor_names sensor);
    void MTOUCH_Sensor_Sampled_ResetAll(void);
    void MTOUCH_Sensor_Disable(enum mtouch_sensor_names sensor);
    void MTOUCH_Sensor_Enable(enum mtouch_sensor_names sensor);
    void MTOUCH_Sensor_Calibrate(enum mtouch_sensor_names sensor);
    mtouch_sensor_sample_t MTOUCH_Sensor_RawSample_Get(enum mtouch_sensor_names sensor);

    void MTOUCH_Sensor_NotifyInterruptOccurred(void);


#ifdef	__cplusplus
}
#endif

#endif	/* MTOUCH_SENSOR_H */


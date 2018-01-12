/* 
 * File:   tmr2.h
 * Author: liruya
 *
 * Created on 2018年1月10日, 上午10:05
 */

#ifndef TMR2_H
#define	TMR2_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "chip_12f1572.h"

#define T2CON_OUTPS_SHIFT   3
#define T2CON_OUTPS_16      (15<<T2CON_OUTPS_SHIFT)
#define T2CON_OUTPS_15      (14<<T2CON_OUTPS_SHIFT)
#define T2CON_OUTPS_14      (13<<T2CON_OUTPS_SHIFT)
#define T2CON_OUTPS_13      (12<<T2CON_OUTPS_SHIFT)
#define T2CON_OUTPS_12      (11<<T2CON_OUTPS_SHIFT)
#define T2CON_OUTPS_11      (10<<T2CON_OUTPS_SHIFT)
#define T2CON_OUTPS_10      (9<<T2CON_OUTPS_SHIFT)
#define T2CON_OUTPS_9       (8<<T2CON_OUTPS_SHIFT)
#define T2CON_OUTPS_8       (7<<T2CON_OUTPS_SHIFT)
#define T2CON_OUTPS_7       (6<<T2CON_OUTPS_SHIFT)
#define T2CON_OUTPS_6       (5<<T2CON_OUTPS_SHIFT)
#define T2CON_OUTPS_5       (4<<T2CON_OUTPS_SHIFT)
#define T2CON_OUTPS_4       (3<<T2CON_OUTPS_SHIFT)
#define T2CON_OUTPS_3       (2<<T2CON_OUTPS_SHIFT)
#define T2CON_OUTPS_2       (1<<T2CON_OUTPS_SHIFT)
#define T2CON_OUTPS_1       (0<<T2CON_OUTPS_SHIFT)
#define T2CON_TMR2ON_SHIFT  2
#define T2CON_TMR2ON        (1<<T2CON_TMR2ON_SHIFT)
#define T2CON_CKPS_SHIFT    0
#define T2CON_CKPS_64       (3<<T2CON_CKPS_SHIFT)
#define T2CON_CKPS_16       (2<<T2CON_CKPS_SHIFT)
#define T2CON_CKPS_4        (1<<T2CON_CKPS_SHIFT)
#define T2CON_CKPS_1        (0<<T2CON_CKPS_SHIFT)

    typedef void ( *TMR2_InterruptHandler_t) (void);

    extern void TMR2_Initialize();
    extern void TMR2_ISR();
    extern void TMR2_SetInterruptHandler(TMR2_InterruptHandler_t handler);

    static inline void TMR2_StartTimer(void) {
        T2CONbits.TMR2ON = 1;
    }

    static inline void TMR2_StopTimer(void) {
        T2CONbits.TMR2ON = 0;
    }
    static inline void TMR2_DisableISR() {
        PIE1bits.TMR2IE = 0;
    }

    static inline void TMR2_EnableISR() {
        PIE1bits.TMR2IE = 1;
    }
    
    static inline void TMR2_LoadPeriodRegister(uint8_t period) {
        PR2 = period;
    }

#ifdef	__cplusplus
}
#endif

#endif	/* TMR2_H */


/* 
 * File:   tmr1.h
 * Author: liruya
 *
 * Created on 2018年1月10日, 上午9:53
 */

#ifndef TMR1_H
#define	TMR1_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "chip_12f1572.h"
    
    //T1CON
#define T1CON_TMR1CS_SHIFT          6
#define T1CON_TMR1CS_LFINTOSC       (3<<T1CON_TMR1CS_SHIFT)
#define T1CON_TMR1CS_T1CKI_SOSC     (2<<T1CON_TMR1CS_SHIFT)
#define T1CON_TMR1CS_FOSC           (1<<T1CON_TMR1CS_SHIFT)
#define T1CON_TMR1CS_FOSC_4         (0<<T1CON_TMR1CS_SHIFT)
#define T1CON_T1CKPS_SHIFT          4
#define T1CON_T1CKPS_1              (0<<T1CON_T1CKPS_SHIFT)
#define T1CON_T1CKPS_2              (1<<T1CON_T1CKPS_SHIFT)
#define T1CON_T1CKPS_4              (2<<T1CON_T1CKPS_SHIFT)
#define T1CON_T1CKPS_8              (3<<T1CON_T1CKPS_SHIFT)
#define T1CON_T1SYNC_SHIFT          2
#define T1CON_T1SYNC_DISABLE        (1<<T1CON_T1SYNC_SHIFT)
#define T1CON_T1SYNC_ENABLE         (0<<T1CON_T1SYNC_SHIFT)
#define T1CON_TMR1ON_SHIFT          0
#define T1CON_TMR1ON                (1<<T1CON_TMR1ON_SHIFT)

    //T1GCON
#define T1GCON_TMR1GE_SHIFT         7
#define T1GCON_TMR1GE               (1<<T1GCON_TMR1GE_SHIFT)
#define T1GCON_T1GPOL_SHIFT         6
#define T1GCON_T1GPOL_HIGH          (1<<T1GCON_T1GPOL_SHIFT)
#define T1GCON_T1GPOL_LOW           (0<<T1GCON_T1GPOL_SHIFT)
#define T1GCON_T1GTM_SHIFT          5
#define T1GCON_T1GTM_ENABLE         (1<<T1GCON_T1GTM_SHIFT)
#define T1GCON_T1GTM_DISABLE        (0<<T1GCON_T1GTM_SHIFT)
#define T1GCON_T1GSPM_SHIFT         4
#define T1GCON_T1GSPM_ENABLE        (1<<T1GCON_T1GSPM_SHIFT)
#define T1GCON_T1GSPM_DISABLE       (0<<T1GCON_T1GSPM_SHIFT)
#define T1GCON_T1GGO_SHIFT          3
#define T1GCON_T1GGOnDONE           (1<<T1GCON_T1GGO_SHIFT)
#define T1GCON_T1GVAL_SHIFT         2
#define T1GCON_T1GVAL               (1<<T1GCON_T1GVAL_SHIFT)
#define T1GCON_T1GSS_SHIFT          0
#define T1GCON_T1GSS_RSV            (3<<T1GCON_T1GSS_SHIFT)     
#define T1GCON_T1GSS_CMP1OUT        (2<<T1GCON_T1GSS_SHIFT) 
#define T1GCON_T1GSS_TMR0OVF        (1<<T1GCON_T1GSS_SHIFT) 
#define T1GCON_T1GSS_T1G            (0<<T1GCON_T1GSS_SHIFT)  

    typedef void ( *TMR1_InterruptHandler_t) ();

    extern void TMR1_Initialize();
    extern void TMR1_ISR();
    extern void TMR1_GATE_ISR();
    extern void TMR1_SetInterruptHandler(TMR1_InterruptHandler_t handler);
    extern void TMR1_Gate_SetInterruptHandler(TMR1_InterruptHandler_t handler);
    
    static inline void TMR1_StartTimer() {
        T1CONbits.TMR1ON = 1;
    }

    static inline void TMR1_StopTimer() {
        T1CONbits.TMR1ON = 0;
    }

    static inline void TMR1_EnableISR() {
        PIE1bits.TMR1IE = 1;
    }

    static inline void TMR1_DisableISR() {
        PIE1bits.TMR1IE = 0;
    }

    static inline void TMR1_EnableGateISR() {
        PIE1bits.TMR1GIE = 1;
    }

    static inline void TMR1_DisableGateISR() {
        PIE1bits.TMR1GIE = 0;
    }
    
#ifdef	__cplusplus
}
#endif

#endif	/* TMR1_H */


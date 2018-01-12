/* 
 * File:   osc.h
 * Author: liruya
 *
 * Created on 2018年1月10日, 上午9:28
 */

#ifndef OSC_H
#define	OSC_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "chip_12f1572.h"

#define OSCCON_SPLLEN_SHIFT         7
#define OSCCON_SPLLEN               (1<<OSCCON_SPLLEN_SHIFT)
#define OSCCON_IRCF_SHIFT           3
#define OSCCON_IRCF_16M_HF          (15<<OSCCON_IRCF_SHIFT)
#define OSCCON_IRCF_8M_HF           (14<<OSCCON_IRCF_SHIFT)
#define OSCCON_IRCF_4M_HF           (13<<OSCCON_IRCF_SHIFT)
#define OSCCON_IRCF_2M_HF           (12<<OSCCON_IRCF_SHIFT)
#define OSCCON_IRCF_1M_HF           (11<<OSCCON_IRCF_SHIFT)
#define OSCCON_IRCF_500K_HF         (10<<OSCCON_IRCF_SHIFT)
#define OSCCON_IRCF_250K_HF         (9<<OSCCON_IRCF_SHIFT)
#define OSCCON_IRCF_125K_HF         (8<<OSCCON_IRCF_SHIFT)
#define OSCCON_IRCF_500K_MF         (7<<OSCCON_IRCF_SHIFT)
#define OSCCON_IRCF_250K_MF         (6<<OSCCON_IRCF_SHIFT)
#define OSCCON_IRCF_125K_MF         (5<<OSCCON_IRCF_SHIFT)
#define OSCCON_IRCF_62_5K_MF        (4<<OSCCON_IRCF_SHIFT)
#define OSCCON_IRCF_31_25K_HF       (3<<OSCCON_IRCF_SHIFT)
#define OSCCON_IRCF_31_25K_MF       (2<<OSCCON_IRCF_SHIFT)
#define OSCCON_IRCF_31K_LF          (0<<OSCCON_IRCF_SHIFT)
#define OSCCON_SCS_SHIF             0
#define OSCCON_SCS_INTOSC           (2<<OSCCON_SCS_SHIF)
#define OSCCON_SCS_TMR1OSC          (1<<OSCCON_SCS_SHIF)
#define OSCCON_SCS_FOSC             (0<<OSCCON_SCS_SHIF)

    extern void OSC_Initialize();

#ifdef	__cplusplus
}
#endif

#endif	/* OSC_H */


/* 
 * File:   pin.h
 * Author: liruya
 *
 * Created on 2018年1月10日, 下午1:09
 */

#ifndef PIN_H
#define	PIN_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "chip_12f1572.h"

#define APFCON_RXDTSEL_RA5      0x80
#define APFCON_RXDTSEL_RA1      0x00
#define APFCON_CWGASEL_RA5      0x40
#define APFCON_CWGASEL_RA2      0x00
#define APFCON_CWGBSEL_RA4      0x20
#define APFCON_CWGBSEL_RA0      0x00
#define APFCON_T1GSEL_RA3       0x08
#define APFCON_T1GSEL_RA4       0x00
#define APFCON_TXCKSEL_RA4      0x04
#define APFCON_TXCKSEL_RA0      0x00
#define APFCON_PWM2SEL_RA4      0x02
#define APFCON_PWM2SEL_RA0      0x00
#define APFCON_PWM1SEL_RA5      0x01
#define APFCON_PWM1SEL_RA1      0x00 

    extern void PIN_Initialize();

#ifdef	__cplusplus
}
#endif

#endif	/* PIN_H */


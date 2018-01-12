/* 
 * File:   chip_12f1572.h
 * Author: liruya
 *
 * Created on 2018年1月10日, 上午9:29
 */

#ifndef CHIP_12F1572_H
#define	CHIP_12F1572_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <xc.h>
    
#define _XTAL_FREQ  16000000
    
#define INTERRUPT_GlobalInterruptEnable() (INTCONbits.GIE = 1)
#define INTERRUPT_GlobalInterruptDisable() (INTCONbits.GIE = 0)
#define INTERRUPT_PeripheralInterruptEnable() (INTCONbits.PEIE = 1)
#define INTERRUPT_PeripheralInterruptDisable() (INTCONbits.PEIE = 0)

#ifdef	__cplusplus
}
#endif

#endif	/* CHIP_12F1572_H */


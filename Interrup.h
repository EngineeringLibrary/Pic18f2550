/* 
 * File:   Interrup.h
 * Author: BatCaverna
 * Interrupção [...]
 * Created on 23 de Março de 2016, 13:26
 */

#ifndef INTERRUP_H
#define	INTERRUP_H
#include <pconfig.h>
#include <delays.h>
#include <xc.h>
#include "Serial.h"
#include "PWM.h"
#include "ADC.h"
#include "ADXL345.h"

void interrupt Interrupt();                             ///INTERRUPÇÃO

#endif	/* INTERRUP_H */


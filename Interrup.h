/* 
 * File:   Interrup.h
 * Author: BatCaverna
 * Interrup��o [...]
 * Created on 23 de Mar�o de 2016, 13:26
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

void interrupt INTERRUPTION();
void interrupt high_priority INTERRUPTION_TIMERS();                             ///INTERRUP��O
void interrupt low_priority  INTERRUPTION_peripheral();

void INTERRUPTION_Timer0();
void INTERRUPTION_Serial();
void INTERRUPTION_ADC();
#endif	/* INTERRUP_H */


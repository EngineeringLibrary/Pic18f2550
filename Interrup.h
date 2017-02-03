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

//#ifndef useSerial
//    #define SERIAL_H
//#endif
//#ifndef usePWM
//    #define PWM_H
//#endif
//#ifndef useADC
//    #define ADC_H
//#endif
//#ifndef usePID
//    #define PID_H
//#endif
//#ifndef useWifi
//    #define WIFITCP_H
//#endif
//#ifndef useGiroAccel
//    #define GiroAccel_H
//#endif

#include "Serial.h"
#include "PWM.h"
#include "ADC.h"
#include "PID.h"
#include "wifiTCP.h"
#include "ADXL345.h"

void interrupt INTERRUPTION();
void interrupt high_priority INTERRUPTION_TIMERS();                             ///INTERRUPÇÃO
void interrupt low_priority  INTERRUPTION_peripheral();
//#ifdef usePWM
    void INTERRUPTION_Timer0();
//#endif

//#ifdef useSerial 
    void INTERRUPTION_Serial();
//#endif
    
//#ifdef useADC
    void INTERRUPTION_ADC();
//#endif
    
#endif	/* INTERRUP_H */


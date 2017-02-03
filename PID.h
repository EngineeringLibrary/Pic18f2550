/* 
 * File:   ADC.h
 * Author: BatCaverna
 * Classe com os metodos para inicialização e leitura do ADC
 * Created on 30 de Agosto de 2016, 14:13
 */
#ifndef _XTAL_FREQ
    #define _XTAL_FREQ 48000000
#endif
#ifndef PID_H
#define	PID_H
#include "ADXL345.h"

struct PID{
    float Kp, Ki, Kd, error, dError, iError, aError, 
          step, upperLimit, lowerLimit, controlSignal; 
    unsigned checkUpLim, checkLowLim;
};
long unsigned PID_interruptCounter = 0;
struct PID pid[4];
//float reference[4];

void PID_outputControlCalc(float reference, float systemOutput, unsigned char whichPID);
//void PID_interrupt_I2C();

#endif	/* PID_H */


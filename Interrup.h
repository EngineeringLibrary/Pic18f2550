/* 
 * File:   Interrup.h
 * Author: Domingos Neto
 *
 * Created on 23 de Março de 2016, 13:26
 */

#ifndef INTERRUP_H
#define	INTERRUP_H
#include <pconfig.h>
#include <delays.h>
#include <xc.h>
#include "Serial.h"

int freq = 80;                       //CARGA DO TIMER0 PARA APROXIMADAMENTE 1Khz
int _pwm[5] = {0,0,0,0,0};             //VALORES DE COMPARAÇÃO PARA PWM
unsigned char counter = 0; //counter2 = 0;

void pwmExecute();
void interrupt Interrupt();
void initPWM();


#endif	/* INTERRUP_H */


/* 
 * File:   PWM.h
 * Author: BatCaverna
 * CLASSE COM O INTUITO DE CONFIGURAR E EXECUTAR O PWM,
 *  É EXECUTADO DENTRO DA INTERRUPÇÃO
 * Created on 30 de Agosto de 2016, 16:36
 */

#ifndef PWM_H
#define	PWM_H

#include <pconfig.h>
#include <delays.h>
#include <xc.h>
#include "Serial.h"

int freq = 80;                      //CARGA DO TIMER0 PARA APROXIMADAMENTE 1Khz
int _pwm[5] = {0,0,0,0,0};          //VALORES DE COMPARAÇÃO PARA PWM
unsigned char counter = 0;          //counter2 = 0;

void pwmExecute();                  //EXECUTA PWM
void initPWM();                     //INICIALIZA PWM

#endif	/* PWM_H */


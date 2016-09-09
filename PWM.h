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

unsigned freq = 80;                      //CARGA DO TIMER0 PARA APROXIMADAMENTE 1Khz
unsigned _pwm[5] = {255,255,255,255,255};          //VALORES DE COMPARAÇÃO PARA PWM
unsigned char PWM_Counter = 0;          //PWM_Counter2 = 0;

void PWM_Init();                     //INICIALIZA PWM
void PWM_Execute();                  //EXECUTA PWM

#endif	/* PWM_H */


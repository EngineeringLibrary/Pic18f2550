/* 
 * File:   ADC.h
 * Author: BatCaverna
 * Classe com os metodos para inicialização e leitura do ADC
 * Created on 30 de Agosto de 2016, 14:13
 */
#ifndef _XTAL_FREQ
    #define _XTAL_FREQ 48000000
#endif
#ifndef ADC_H
#define	ADC_H

#include <plib/adc.h>

unsigned ADC[10];                               //A CADA 2 POSIÇÕES 1 BYTE
unsigned ADC_Channel = 0, ADC_NChannel = 5;

void ADC_Init();                                //INICIALIZA ADC
void ADC_reInit(unsigned AdcChannel);    
void ADC_Read_Interrupt(unsigned AdcChannel);   //LEITURA ADC
unsigned* ADC_Read(unsigned channel);

#endif	/* ADC_H */


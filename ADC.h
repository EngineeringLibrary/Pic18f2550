/* 
 * File:   ADC.h
 * Author: BatCaverna
 * Classe com os metodos para inicialização e leitura do ADC
 * Created on 30 de Agosto de 2016, 14:13
 */

#ifndef ADC_H
#define	ADC_H

#include <plib/adc.h>

unsigned ADC[10];                           //A CADA 2 POSIÇÕES 1 BYTE                           

void initADC();                             //INICIALIZA ADC
void StartADC();                            //LEITURA ADC

#endif	/* ADC_H */


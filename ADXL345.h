/* 
 * File:   teste2.h
 * Author: BatCaverna
 * Classe com os metodos para inicialização e leitura do ACC e GIRO
 * Created on 4 de Março de 2016, 19:00
 */

#ifndef TESTE2_H
#define	TESTE2_H

#include <plib/i2c.h>
#include <delays.h>
#include "Serial.h"

unsigned char valoresEnviar[220]={0,0,0,0,0,0,0,0,0,0,
                                  0,0,0,0,0,0,0,0,0,0,
                                  0,0,0,0,0,0,0,0,0,0,
                                  0,0,0,0,0,0,0,0,0,0,
                                  0,0,0,0,0,0,0,0,0,0,
                                  0,0,0,0,0,0,0,0,0,0,
                                  0,0,0,0,0,0,0,0,0,0,
                                  0,0,0,0,0,0,0,0,0,0,
                                  0,0,0,0,0,0,0,0,0,0,
                                  0,0,0,0,0,0,0,0,0,0,
                                  0,0,0,0,0,0,0,0,0,0,
                                  0,0,0,0,0,0,0,0,0,0,
                                  0,0,0,0,0,0,0,0,0,0,
                                  0,0,0,0,0,0,0,0,0,0,
                                  0,0,0,0,0,0,0,0,0,0,
                                  0,0,0,0,0,0,0,0,0,0,
                                  0,0,0,0,0,0,0,0,0,0,
                                  0,0,0,0,0,0,0,0,0,0,
                                  0,0,0,0,0,0,0,0,0,0,
                                  0,0,0,0,0,0,0,0,0,0,
                                  0,0,0,0,0,0,0,0,0,0,
                                  0,0,0,0,0,0,0,0,0,0};

unsigned const char Oksend[] = "OK\r\n";
unsigned const char sendCmd[] = "AT+CIPSEND=0,220\r\n";

void lerADXL();                                                 //LEITURA ADXL
unsigned readACC(unsigned Adress);                              //LEITURA ACC
unsigned readGIRO(unsigned Adress);                             //LEITURA GIRO
void initI2C(unsigned Adress1, unsigned Adress2);               //INIT I2C



#endif	/* TESTE2_H */


/* 
 * File:   teste2.h
 * Author: Domingos Neto
 *
 * Created on 4 de Março de 2016, 19:00
 */

#ifndef TESTE2_H
#define	TESTE2_H

#include <plib/i2c.h>
#include <delays.h>
#include "Serial.h"
#include "conversions.h"

int valoresAcelerometroReal[50];
unsigned const char Oksend[] = "OK\r\n";
unsigned char valoresAcelerometroBruto[100];
unsigned const char sendCmd[] = "AT+CIPSEND=0,100\r\n";

void lerAceleracao();
unsigned readACC(unsigned Adress);
void initI2C(unsigned Adress1, unsigned Adress2);



#endif	/* TESTE2_H */


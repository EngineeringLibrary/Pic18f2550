/* 
 * File:   wifiTCP.h
 * Author: Domingos Neto
 *
 * Created on 29 de Julho de 2015, 15:38
 */

#ifndef WIFITCP_H
#define	WIFITCP_H

#include "Serial.h"
#include "conversions.h"
    
bit flagLink = 0, flagData;
unsigned char WifiTCPData[15];
unsigned WifiTCPDataLen = 15;

void WifiTCPinit();                                             //INICIALIZA WIFI
void WifiTCPSend(unsigned char *stringToSend, unsigned lenStr); //ESCREVE
void WifiTCPRead(void);                                         //LER

#endif	 WIFITCP_H

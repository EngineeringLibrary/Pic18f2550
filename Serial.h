/* 
 * File:   Serial.h
 * Author: Domingos Neto
 *
 * Created on 29 de Julho de 2015, 15:36
 */

#ifndef SERIAL_H
#define	SERIAL_H
#define _XTAL_FREQ 48000000 // Internal oscillator  
#define BAUDRATE 115200

#include <usart.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
   
unsigned char SerialReceivedData;
unsigned char SerialReceivedString[50];
unsigned char SerialSendString[50];
unsigned SerialLen = 50;

void delaySeg(unsigned waitTime);                           //DELAY
void initUART(void);                                        //INICIALIZA UART
void SerialPrint(unsigned char byte);                       //ESCREVE BYTE
void SerialWifiWrite (char* Valor, unsigned Tamanho);       //ESCREVE DA WIFI
void SerialWrite(const char* frase);                        //ESCREVE DA SERIAL
char SerialRead(void);                                      //LER BYTE
void SerialReadString();                                    //LER DA WIFI
bit ContainString(const char* containedString);             
bit waitToken(char value);
void waitUntil(const unsigned char stringToCompare[]);
void SerialReadUntilToken(const char charToCompare);
void SerialReceiveNChar(const int NumberOfCharToReceive);

#endif	/* SERIAL_H */


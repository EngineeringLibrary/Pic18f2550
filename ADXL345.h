/* 
 * File:   teste2.h
 * Author: BatCaverna
 * Classe com os metodos para inicialização e leitura do ACC e GIRO
 * Created on 4 de Março de 2016, 19:00
 */

#ifndef GiroAccel_H
#define	GiroAccel_H

#ifndef _XTAL_FREQ
    #define _XTAL_FREQ 48000000
#endif
#ifndef BAUDRATE
    #define BAUDRATE 115200
#endif

#include <plib/i2c.h>
#include <delays.h>

//unsigned char valoresEnviar[220]={0,0,0,0,0,0,0,0,0,0,
//                                  0,0,0,0,0,0,0,0,0,0,
//                                  0,0,0,0,0,0,0,0,0,0,
//                                  0,0,0,0,0,0,0,0,0,0,
//                                  0,0,0,0,0,0,0,0,0,0,
//                                  0,0,0,0,0,0,0,0,0,0,
//                                  0,0,0,0,0,0,0,0,0,0,
//                                  0,0,0,0,0,0,0,0,0,0,
//                                  0,0,0,0,0,0,0,0,0,0,
//                                  0,0,0,0,0,0,0,0,0,0,
//                                  0,0,0,0,0,0,0,0,0,0,
//                                  0,0,0,0,0,0,0,0,0,0,
//                                  0,0,0,0,0,0,0,0,0,0,
//                                  0,0,0,0,0,0,0,0,0,0,
//                                  0,0,0,0,0,0,0,0,0,0,
//                                  0,0,0,0,0,0,0,0,0,0,
//                                  0,0,0,0,0,0,0,0,0,0,
//                                  0,0,0,0,0,0,0,0,0,0,
//                                  0,0,0,0,0,0,0,0,0,0,
//                                  0,0,0,0,0,0,0,0,0,0,
//                                  0,0,0,0,0,0,0,0,0,0,
//                                  0,0,0,0,0,0,0,0,0,0};
float filtro = 0.1;
float h = 0.1;
struct Giro{ float x,y,z; }giro;
struct GiroTemp{ float x,y,z; }giroTemp;
struct AccelTemp{float x,y,z; }accelTemp;
struct Accel{float x,y,z; }accel;
struct Vel{  float x,y,z; }vel;
struct Pos{  float x,y,z; }pos;
struct AccelBias{  float x,y,z; }accelBias;
struct GiroBias{   float x,y,z; }giroBias;
//unsigned const char Oksend[] = "OK\r\n";
//unsigned const char sendCmd[] = "AT+CIPSEND=0,22\r\n";
void lerADXL(); //LEITURA ADXL     
unsigned char readACC(unsigned char Adress);                              //LEITURA ACC
unsigned char readGIRO(unsigned char Adress);                             //LEITURA GIRO
void readAccelGiroValues();
void initI2C(unsigned char Adress1, unsigned char Adress2);               //INIT I2C
void sensorInit();



#endif	/* TESTE2_H */


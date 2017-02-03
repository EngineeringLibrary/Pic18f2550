#include"ADXL345.h"

void initI2C(unsigned char Adress1, unsigned char Adress2){
    
    SSPSTAT = 0b10000000;                 
    SSPCON1 = 0b00101000;                 
    SSPCON2 = 0x00;                 
    PIE1bits.SSPIE=0;
    PIR1bits.SSPIF=0;
    
    SSPADD = 119;
    
    //Acelerometro
    StartI2C();
    WriteI2C(Adress1);
    IdleI2C();
    WriteI2C(Adress2);
    IdleI2C();
    WriteI2C(8);
    IdleI2C();
    StopI2C();
    
    // giroscopio
    StartI2C();
    WriteI2C(0xD2);
    IdleI2C();
    WriteI2C(0x20);
    IdleI2C();
    WriteI2C(0x0F);
    NotAckI2C();
    StopI2C();
    
    StartI2C();
    WriteI2C(0xD2);
    IdleI2C();
    WriteI2C(0x22);
    IdleI2C();
    WriteI2C(0x08);
    NotAckI2C();
    StopI2C();
    
    StartI2C();
    WriteI2C(0xD2);
    IdleI2C();
    WriteI2C(0x23);
    IdleI2C();
    WriteI2C(0x30);
    NotAckI2C();
    StopI2C();
    return;
}

unsigned char readACC(unsigned char Adress){
    
    StartI2C();
    WriteI2C(0xA6);
    IdleI2C();
    WriteI2C(Adress);
    IdleI2C();
    RestartI2C();
    WriteI2C(0xA7);
    IdleI2C();
    unsigned char c = ReadI2C();
    NotAckI2C();
    StopI2C();
    return c;       
}

unsigned char readGIRO(unsigned char Adress){
    
    StartI2C();
    WriteI2C(0xD2);
    IdleI2C();
    WriteI2C(Adress);
    IdleI2C();
    RestartI2C();
    WriteI2C(0xD3);
    IdleI2C();
    unsigned char c = ReadI2C();
    NotAckI2C();
    StopI2C();
    return c;       
}

void sensorInit()
{
    accel.x = 0;    accel.y = 0;    accel.z = 0;
    accelTemp.x = 0;    accelTemp.y = 0;    accelTemp.z = 0;
    giroTemp.x = 0;     giroTemp.y = 0;     giroTemp.z = 0;
    giro.x = 0;     giro.y = 0;     giro.z = 0;
    vel.x = 0;      vel.y = 0;      vel.z = 0;
    pos.x = 0;      pos.y = 0;      pos.z = 0;
    accelBias.x = 0;      accelBias.y = 0;      accelBias.z = 0;
    giroBias.x = 0;       giroBias.y = 0;       giroBias.z = 0;
    
    for(unsigned char i = 0; i < 100; ++i)
        readAccelGiroValues();
    
    accelBias.x = accelTemp.x;
    accelBias.y = accelTemp.y;
    accelBias.z = accelTemp.z;
    
    giroBias.x = giroTemp.x;
    giroBias.y = giroTemp.y;
    giroBias.z = giroTemp.z;
}

void readAccelGiroValues()
{
    accelTemp.x += filtro*((readACC(0x32) + readACC(0x33)<<8)/256 - accelTemp.x);
    accelTemp.y += filtro*((readACC(0x34) + readACC(0x35)<<8)/256 - accelTemp.y);
    accelTemp.z += filtro*((readACC(0x36) + readACC(0x37)<<8)/256 - accelTemp.z);
    
    accel.x = accel.x - accelTemp.x;
    accel.y = accel.y - accelTemp.y;
    accel.z = accel.z - accelTemp.z;
    
    vel.x +=  h*accel.x;
    vel.y +=  h*accel.y;
    vel.z +=  h*accel.z;
    
    pos.x +=  h*vel.x;
    pos.y +=  h*vel.y;
    pos.z +=  h*vel.z;
    
    giroTemp.x += filtro*((readGIRO(0x28) + readGIRO(0x29)<<8)/256 - giroTemp.x);
    giroTemp.y += filtro*((readGIRO(0x2A) + readGIRO(0x2B)<<8)/256 - giroTemp.y);
    giroTemp.z += filtro*((readGIRO(0x2C) + readGIRO(0x2D)<<8)/256 - giroTemp.z);
    giro.x = giro.x - giroTemp.x;
    giro.y = giro.y - giroTemp.y;
    giro.z = giro.z - giroTemp.z;
}

//void lerADXL(){
             
//   for(unsigned i = 0; i < 110; i += 22){
//        __delay_ms(10);
//
////        StartADC();
//        
        //Acelerometro
        //x0x1
//        valoresEnviar[i] = readACC(0x32);
//        valoresEnviar[i+1] = readACC(0x33);   
//        //y0y1
//        valoresEnviar[i+2] = readACC(0x34);
//        valoresEnviar[i+3] = readACC(0x35);
//        //z0z1
//        valoresEnviar[i+4] = readACC(0x36);
//        valoresEnviar[i+5] = readACC(0x37);
//        //FIM
//        
//        //Giroscopio
//        valoresEnviar[i+6]   = readGIRO(0x28);
//        valoresEnviar[i+7] = readGIRO(0x29);
//        //y0y1
//        valoresEnviar[i+8] = readGIRO(0x2A);
//        valoresEnviar[i+9] = readGIRO(0x2B);
//        //z0z1
//        valoresEnviar[i+10] = readGIRO(0x2C);
//        valoresEnviar[i+11] = readGIRO(0x2D);
        //FIM
        
        //sensroflex -Projeto Luva-
//        valoresEnviar[i+12] = ADC[0];
//        valoresEnviar[i+13] = ADC[1];
//        valoresEnviar[i+14] = ADC[2];
//        valoresEnviar[i+15] = ADC[3];
//        valoresEnviar[i+16] = ADC[4];
//        valoresEnviar[i+17] = ADC[5];
//        valoresEnviar[i+18] = ADC[6];
//        valoresEnviar[i+19] = ADC[7];
//        valoresEnviar[i+20] = ADC[8];
//        valoresEnviar[i+21] = ADC[9];
        //FIM
        
//    }
    
//    #ifdef useSerial 
//        SerialWrite((unsigned char *)sendCmd);
//    #endif 
//
//     for(unsigned j = 110; j < 220; j += 22){
//        __delay_ms(10);//__delay_ms(10);
////        StartADC();
//        
//        //Acelerometro
//        //x0x1
//        valoresEnviar[j] = readACC(0x32);
//        valoresEnviar[j+1] = readACC(0x33);
//        //y0y1
//        valoresEnviar[j+2] = readACC(0x34);
//        valoresEnviar[j+3] = readACC(0x35);
//        //z0z1
//        valoresEnviar[j+4] = readACC(0x36);
//        valoresEnviar[j+5] = readACC(0x37);
//        
//        //Giroscopio
//        //x0x1
//        valoresEnviar[j+6]   = readGIRO(0x28);
//        valoresEnviar[j+7] = readGIRO(0x29);
//        //y0y1
//        valoresEnviar[j+8] = readGIRO(0x2A);
//        valoresEnviar[j+9] = readGIRO(0x2B);
//        //z0z1
//        valoresEnviar[j+10] = readGIRO(0x2C);
//        valoresEnviar[j+11] = readGIRO(0x2D);
//        //FIM
//        
//        //SensorFlex -Projeto Luva-
////        valoresEnviar[j+12] = ADC[0];
////        valoresEnviar[j+13] = ADC[1];
////        valoresEnviar[j+14] = ADC[2];
////        valoresEnviar[j+15] = ADC[3];
////        valoresEnviar[j+16] = ADC[4];
////        valoresEnviar[j+17] = ADC[5];
////        valoresEnviar[j+18] = ADC[6];
////        valoresEnviar[j+19] = ADC[7];
////        valoresEnviar[j+20] = ADC[8];
////        valoresEnviar[j+21] = ADC[9];
//        //FIM
        
//    }
//    #ifdef includeUSART 
//        SerialWifiWrite((unsigned char *)valoresEnviar,220);   
//        SerialWrite("\r\n");
//    #endif
//    return;
//}


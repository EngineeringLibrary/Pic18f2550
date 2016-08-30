#include"ADXL345.h"

void initI2C(unsigned Adress1, unsigned Adress2){
    
    TRISBbits.RB0=1;
    TRISBbits.RB1=1;

    SSPSTAT = 0b10000000;                 
    SSPCON1 = 0b00101000;                 
    SSPCON2 = 0x00;                 
    PIE1bits.SSPIE=0;
    PIR1bits.SSPIF=0;
    
    SSPADD = 119;
    
    StartI2C();
    WriteI2C(Adress1);
    IdleI2C();
    WriteI2C(Adress2);
    IdleI2C();
    WriteI2C(8);
    IdleI2C();
    StopI2C();
    return;
}
unsigned readACC(unsigned Adress){
    
    StartI2C();
    WriteI2C(0xA6);
    IdleI2C();
    WriteI2C(Adress);
    IdleI2C();
    RestartI2C();
    WriteI2C(0xA7);
    IdleI2C();
    unsigned c = ReadI2C();
    NotAckI2C();
    StopI2C();
    return c;       
}
void lerAceleracao(){
             
   for(unsigned i = 0; i < 50; ++i )
   {
        //x0x1
        valoresAcelerometroBruto[i] = readACC(0x32);
        valoresAcelerometroBruto[i+1] = readACC(0x33);
        //y0y1
        valoresAcelerometroBruto[i+2] = readACC(0x34);
        valoresAcelerometroBruto[i+3] = readACC(0x35);
        //z0z1
        valoresAcelerometroBruto[i+4] = readACC(0x36);
        valoresAcelerometroBruto[i+5] = readACC(0x37);
        
        //Rotina de Controle
        //Essa rotina sera implementada da seguinte forma
        //Serao passados os valores do acelerometro de 0 a 5
        //e retornado 4 valores de PWM
        //esses valores de pwm serão enviados em sequencia juntamente
        //com os valores do acelerometro
    }

   SerialWrite((unsigned char *)sendCmd);
    
   for(unsigned j = 50; j < 100; ++j )
   {
         //x0x1
        valoresAcelerometroBruto[j] = readACC(0x32);
        valoresAcelerometroBruto[j+1] = readACC(0x33);
        //y0y1
        valoresAcelerometroBruto[j+2] = readACC(0x34);
        valoresAcelerometroBruto[j+3] = readACC(0x35);
        //z0z1
        valoresAcelerometroBruto[j+4] = readACC(0x36);
        valoresAcelerometroBruto[j+5] = readACC(0x37);        
        //Rotina de Controle
        //Essa rotina sera implementada da seguinte forma
        //Serao passados os valores do acelerometro de 0 a 5
        //e retornado 4 valores de PWM
        //esses valores de pwm serão enviados em sequencia juntamente
        //com os valores do acelerometro
    }

    SerialWifiWrite((unsigned char *)valoresAcelerometroBruto,100);
        
    return;
}


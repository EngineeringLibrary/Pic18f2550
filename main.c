//--------------------Inclusão dos módulos que serão utilizados---------------//
#define useSerial
#define usePWM
#define useADC
#define usePID
#define useWifi
#define useGiroAccel
//-------------------Inclusão da biblioteca principal-------------------------//
#include "Interrup.h"
//-------------------Diretrizes para o microcontrolador-----------------------//
#pragma config USBDIV = 2
#pragma config PLLDIV = 5
#pragma config CPUDIV = OSC1_PLL2
#pragma config FOSC = HSPLL_HS 
#pragma config WDT = OFF               
#pragma config MCLRE = ON               
#pragma config LVP = OFF               
#pragma config PWRT = ON        
#pragma config PBADEN = OFF

//---------------------------Início do programa-------------------------------//
//unsigned const char Oksend[] = "OK\r\n";
//unsigned const char sendCmd[] = "AT+CIPSEND=0,2\r\n";

void main(void) {
        
//Inicializando todos metodos para leitura e escrida de dados
//Olhar "Interrup.h" para maiores detalhes:    
//    ADC_Init();
    initUART();
//    WifiTCPinit();
    PWM_Init();
//    initI2C(0xA6,0x2D);
    
    float z = -11.6; float phi = -3; float psi = -2; float theta = -2;
  
    pid[0].lowerLimit = -127; pid[0].upperLimit = 127;
    pid[0].Kp = 1.0; pid[0].Ki = 0.0; pid[0].Kd = 0.0; pid[0].step = 1.0;
    
     pid[1].lowerLimit = -127; pid[1].upperLimit = 127;
    pid[1].Kp = 1.0; pid[1].Ki = 0.0; pid[1].Kd = 0.0; pid[1].step = 1.0;
    
     pid[2].lowerLimit = -127; pid[2].upperLimit = 127;
    pid[2].Kp = 1.0; pid[2].Ki = 0.0; pid[2].Kd = 0.0; pid[2].step = 1.0;
    
     pid[3].lowerLimit = -127; pid[3].upperLimit = 127;
    pid[3].Kp = 1.0; pid[3].Ki = 0.0; pid[3].Kd = 0.0; pid[3].step = 1.0;

    unsigned char j=1;
    for(unsigned char i = 1; i < 165; ++i) {
        if(i < 35)
            j++;
        _pwm[0] = i;
        _pwm[1] = i;
        _pwm[3] = i + 8;
        _pwm[2] = i + j;
        delayMS(90);
    }
    while(1){          
        
        float l = 2, lambda = 1;
        z += filtro*((readACC(0x36) + readACC(0x37)<<8)/256 - z);
        PID_outputControlCalc(0,(z + 11.6),0);
        float u1 = pid[0].controlSignal + 740;
        phi += filtro*((readGIRO(0x28) + readGIRO(0x29)<<8)/256 - phi);
        PID_outputControlCalc(0.0,(phi + 3.0),1);
        float u2 = pid[1].controlSignal;
        psi += filtro*((readGIRO(0x2A) + readGIRO(0x2B))/256 - psi);
        PID_outputControlCalc(0.0,(psi + 2.0),2);
        float u3 = pid[2].controlSignal;
        theta = filtro*((readGIRO(0x2C) + readGIRO(0x2D))/256-theta);
        PID_outputControlCalc(0.0,(theta + 2.0),3);
        float u4 = pid[3].controlSignal;
        
//         _pwm[0] = SerialRead();
//         SerialPrint(_pwm[0]);
//         _pwm[1] = SerialRead();
//         SerialPrint(_pwm[1]);
//         _pwm[2] = SerialRead();
//         SerialPrint(_pwm[2]); 
//         _pwm[3] = SerialRead();
//        SerialPrint(_pwm[3]);
//        //----------------------------------------------------
        float pwmTemp = (u1/4 - u3/(2*l) - u4/(4*lambda));
        if(pwmTemp <= 0)
            pwmTemp = 1;
        _pwm[0] = (unsigned char) pwmTemp;
        pwmTemp = (u1/4 - u2/(2*l) + u4/(4*lambda));
        if(pwmTemp <= 0)
            pwmTemp = 1;
        _pwm[1] = (unsigned char) pwmTemp;
        pwmTemp = (u1/4 + u3/(2*l) - u4/(4*lambda));
        if(pwmTemp <= 0)
            pwmTemp = 1;
        _pwm[3] = (unsigned char) pwmTemp;
        pwmTemp = (u1/4 + u2/(2*l) + u4/(4*lambda));
        if(pwmTemp <= 0)
            pwmTemp = 1;
        _pwm[2] = (unsigned char) pwmTemp;
        
        __delay_ms(10); __delay_ms(10); __delay_ms(10); __delay_ms(10); __delay_ms(10); __delay_ms(10);
        __delay_ms(10); __delay_ms(10); __delay_ms(10); __delay_ms(10); __delay_ms(10); __delay_ms(10);
    }
    return;
}
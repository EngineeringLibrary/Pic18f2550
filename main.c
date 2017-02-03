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
    initI2C(0xA6,0x2D);
    sensorInit();
    
    float l = 2, lambda = 1;
  
    pid[0].lowerLimit = -127; pid[0].upperLimit = 127;
    pid[0].Kp = 1.0; pid[0].Ki = 0.0; pid[0].Kd = 0.0; pid[0].step = 1.0;
    
     pid[1].lowerLimit = -127; pid[1].upperLimit = 127;
    pid[1].Kp = 1.0; pid[1].Ki = 0.0; pid[1].Kd = 0.0; pid[1].step = 1.0;
    
     pid[2].lowerLimit = -127; pid[2].upperLimit = 127;
    pid[2].Kp = 1.0; pid[2].Ki = 0.0; pid[2].Kd = 0.0; pid[2].step = 1.0;
    
     pid[3].lowerLimit = -127; pid[3].upperLimit = 127;
    pid[3].Kp = 1.0; pid[3].Ki = 0.0; pid[3].Kd = 0.0; pid[3].step = 1.0;

    unsigned char j=1;           //165
    for(unsigned char i = 1; i < 185; ++i) {
//        if(i < 35)
//            j++;
        _pwm[0] = i;
        _pwm[1] = i;
        _pwm[3] = i; //+ 8;
        _pwm[2] = i; //+ j;
        delayMS(90);
    }
    while(1){          
        readAccelGiroValues();
        PID_outputControlCalc(5,pos.z,0);
        float u1 = pid[0].controlSignal + 740;
        PID_outputControlCalc(0.0,giro.x,1);
        float u2 = pid[1].controlSignal;
        PID_outputControlCalc(0.0,giro.y,2);
        float u3 = pid[2].controlSignal;
        PID_outputControlCalc(0.0,giro.z,3);
        float u4 = pid[3].controlSignal;
        
        float pwmTemp = (u1/4 - u3/(2*l) - u4/(4*lambda));
        if(pwmTemp < 0)
            pwmTemp = 0;
        _pwm[0] = (unsigned char) pwmTemp;
        pwmTemp = (u1/4 - u2/(2*l) + u4/(4*lambda));
        if(pwmTemp < 0)
            pwmTemp = 0;
        _pwm[1] = (unsigned char) pwmTemp;
        pwmTemp = (u1/4 + u3/(2*l) - u4/(4*lambda));
        if(pwmTemp < 0)
            pwmTemp = 0;
        _pwm[3] = (unsigned char) pwmTemp;
        pwmTemp = (u1/4 + u2/(2*l) + u4/(4*lambda));
        if(pwmTemp < 0)
            pwmTemp = 0;
        _pwm[2] = (unsigned char) pwmTemp;
        
        __delay_ms(10); __delay_ms(10); __delay_ms(10); __delay_ms(10); __delay_ms(10); __delay_ms(10);
        __delay_ms(10); __delay_ms(10); __delay_ms(10); __delay_ms(10); __delay_ms(10); __delay_ms(10);
    }
    return;
}
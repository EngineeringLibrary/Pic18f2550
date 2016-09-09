#include <pconfig.h>
#include <delays.h>
#include <xc.h>
#include "Interrup.h"


         
#pragma config USBDIV = 2
#pragma config PLLDIV = 5
#pragma config CPUDIV = OSC1_PLL2
#pragma config FOSC = HSPLL_HS 
#pragma config WDT = OFF               
#pragma config MCLRE = ON               
#pragma config LVP = OFF               
#pragma config PWRT = ON        
#pragma config PBADEN = OFF

#define _XTAL_FREQ 48000000
//F05
//typedef struct pid{
//    int Kp, Ki, Kd, outPutControl;
//    float e, ea, ed, ei;
//}PID;
//extern PID PID1;


void main(void) {
        
//Inicializando todos metodos para leitura e escrida de dados
//Olhar "Interrup.h" para maiores detalhes:    
    
    initUART();
    PWM_Init();
    WifiTCPinit();
    ADC_Init();
//    initI2C(0xA6,0x2D);
//-----------------------------------------------------------  


    while(1){            
//        ADC_Start();
        ///TESTE DE LEITURA ADC E ADXL
//        _pwm[0] = 255;
        //lerAceleracao();
//        StartADC();
        
//        _pwm[0] = ADC[1];//ADC[1];
        ///-----------------------
    }
    return;
}
#include <pconfig.h>
#include <delays.h>
#include <xc.h>
#include "Serial.h"
#include "PWM.h"
#include "Interrup.h"
#include "wifiTCP.h"
#include "ADC.h"
#include "ADXL345.h"

         
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

long unsigned i = 0, j = 0;
bit FlagTXSend = 0;

void main(void) {
        
//Inicializando todos metodos para leitura e escrida de dados
//Olha "Interrup.h" para maiores detalhes:    
//-----------------------------------------------------------    
    initUART();
    initPWM();
    WifiTCPinit();
    initADC();
    initI2C(0xA6,0x2D);
//-----------------------------------------------------------  
    FlagTXSend = 0;
    ADCON0bits.CHS0 = 0;
    ADCON0bits.CHS1 = 0;
    ADCON0bits.CHS2 = 0;
    while(1){                
        ///TESTE DE LEITURA ADC E ADXL
        //lerAceleracao();
        //StartADC();
        ///-----------------------
    }
    return;
}
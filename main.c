#include <pconfig.h>
#include <delays.h>
#include <xc.h>
#include "Serial.h"
#include "Interrup.h"
#include "wifiTCP.h"
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
    
    initUART();
    initPWM();
    WifiTCPinit();
    
    FlagTXSend = 0;
//----------------------------------------------------
    //initI2C(0xA6,0x2D);
//----------------------------------------------------  
    
    while(1){                
        
        //lerAceleracao();
        
    }
    return;
}
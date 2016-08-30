#include "ADC.h"

void initADC(){
    
    TRISA = 0xFF;
    
//    TRISAbits.TRISA0 = 1;
//    TRISAbits.TRISA1 = 1;
//    TRISAbits.TRISA2 = 1;
//    TRISAbits.TRISA3 = 1;
//    TRISAbits.TRISA5 = 1;
    
	ADCON0 = 0b00000001;
    ADCON1 = 0;//ADCON2 setup: Left justified, Tacq=2Tad, Tad=2*Tosc (or Fosc/2)
    ADCON1bits.PCFG3 = 1;
    ADCON1bits.PCFG2 = 0;
    ADCON1bits.PCFG1 = 1;
    ADCON1bits.PCFG0 = 0;
    ADCON2 = 0b00000000;//ADCON2 setup: Left justified, Tacq=2Tad, Tad=2*Tosc (or Fosc/2)
    ADCON0bits.ADON = 0x01;//Enable A/D module
    PIE1bits.ADIE = 1;
    return;
}

void StartADC(){
        
        ADCON0bits.CHS0 = 0;
        ADCON0bits.CHS1 = 0;
        ADCON0bits.CHS2 = 0;
        ADCON0bits.GO_DONE = 1;
        while(ADCON0bits.GO_DONE != 0);
        
        ADC[0] = ((unsigned char)ADRESL);
        ADC[1] = ((unsigned char)ADRESH);
        
        ADCON0bits.CHS0 = 1;
        ADCON0bits.CHS1 = 0;
        ADCON0bits.CHS2 = 0;
        ADCON0bits.GO_DONE = 1;
        while(ADCON0bits.GO_DONE != 0);
        
        ADC[2] = ((unsigned char)ADRESL);
        ADC[3] = ((unsigned char)ADRESH);
        
        
        ADCON0bits.CHS0 = 0;
        ADCON0bits.CHS1 = 1;
        ADCON0bits.CHS2 = 0;
        ADCON0bits.GO_DONE = 1;
        while(ADCON0bits.GO_DONE != 0);
        
        ADC[4] = ((unsigned char)ADRESL);
        ADC[5] = ((unsigned char)ADRESH);
        
        
        ADCON0bits.CHS0 = 1;
        ADCON0bits.CHS1 = 1;
        ADCON0bits.CHS2 = 0;
        ADCON0bits.GO_DONE = 1;
        while(ADCON0bits.GO_DONE != 0);
        
        ADC[6] = ((unsigned char)ADRESL);
        ADC[7] = ((unsigned char)ADRESH);
        
        
        ADCON0bits.CHS0 = 0;
        ADCON0bits.CHS1 = 0;
        ADCON0bits.CHS2 = 1;
        ADCON0bits.GO_DONE = 1;
        while(ADCON0bits.GO_DONE != 0);
        
        
        ADC[8] = ((unsigned char)ADRESL);
        ADC[9] = ((unsigned char)ADRESH);
        return;
}


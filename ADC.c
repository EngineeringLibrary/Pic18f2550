#include "ADC.h"

void ADC_Init(){
    TRISA |= 0x2F; // RA0,RA1,RA2,RA3,RA5 como entrada
    ADCON1 = 0x0A; //o "A" corresponde AN0 - AN4 como analógicas e o "0" deixa a faixa de tensão entre vcc e terra 
    ADCON0 = 0;
//    ADCON0 = ADC_Channel<<2;//ADON = 1
    ADCON2 = 2<<3;
    ADCON0bits.ADON = 1;
//    ADC_INT_ENABLE();
//    ei();
//    __delay_ms(2);
    ADCON0bits.GO_DONE = 1;
    return;
}
void ADC_ReInit(unsigned AdcChannel){
    ADCON0 = AdcChannel<<2;//ADON = 1
    ADCON2 = 2<<3;
    ADCON0bits.ADON = 1;
    __delay_us(5);
    return;
}
unsigned* ADC_Read(unsigned channel){
    ADC_ReInit(channel);
    ADCON0bits.GO_DONE = 1;
    return ADC;
}
void ADC_Read_Interrupt(unsigned AdcChannel){
    if(AdcChannel == 0)
    {
        ADCON0bits.CHS0 = 0;
        ADCON0bits.CHS1 = 0;
        ADCON0bits.CHS2 = 0;
        ADCON0bits.ADON = 1;
        __delay_us(10);
        ADCON0bits.GO_DONE = 1;
        while(ADCON0bits.GO_DONE != 0);
        
        ADC[0] = ((unsigned char)ADRESL);
        ADC[1] = ((unsigned char)ADRESH);
    }
    else if(AdcChannel == 1)
    {
        ADCON0bits.CHS0 = 1;
        ADCON0bits.CHS1 = 0;
        ADCON0bits.CHS2 = 0;
        ADCON0bits.ADON = 1;
        __delay_us(10);
        ADCON0bits.GO_DONE = 1;
        while(ADCON0bits.GO_DONE != 0);

        ADC[2] = ((unsigned char)ADRESL);
        ADC[3] = ((unsigned char)ADRESH);
    }
    else if(AdcChannel == 2)
    {
        ADCON0bits.CHS0 = 0;
        ADCON0bits.CHS1 = 1;
        ADCON0bits.CHS2 = 0;
        ADCON0bits.ADON = 1;
        __delay_us(10);
        ADCON0bits.GO_DONE = 1;
        while(ADCON0bits.GO_DONE != 0);

        ADC[4] = ((unsigned char)ADRESL);
        ADC[5] = ((unsigned char)ADRESH);
    }
    else if(AdcChannel == 3)
    {
        ADCON0bits.CHS0 = 1;
        ADCON0bits.CHS1 = 1;
        ADCON0bits.CHS2 = 0;
        ADCON0bits.ADON = 1;
        __delay_us(10);
        ADCON0bits.GO_DONE = 1;
        while(ADCON0bits.GO_DONE != 0);

        ADC[6] = ((unsigned char)ADRESL);
        ADC[7] = ((unsigned char)ADRESH);
    }
    else if(AdcChannel == 4)
    {
        ADCON0bits.CHS0 = 0;
        ADCON0bits.CHS1 = 0;
        ADCON0bits.CHS2 = 1;
        ADCON0bits.ADON = 1;
        __delay_us(10);
        ADCON0bits.GO_DONE = 1;
        while(ADCON0bits.GO_DONE != 0);

        ADC[8] = ((unsigned char)ADRESL);
        ADC[9] = ((unsigned char)ADRESH);
    }
    return;
}

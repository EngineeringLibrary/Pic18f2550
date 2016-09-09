#include "PWM.h"


void PWM_Init(){
     INTCON = 0xA0;                  //HABILITA INT GLOBAL
                                     //HABILITA A INT DO TIMER0
     //TMR0IP = 1;                                
     T0CON = 0xC1;                   //HABILITA TIMER0
                                     //HABILITA TIMER0 COMO 8BIT'S
                                     //HABILITA CONT. PELO CLOCK INTERNO
                                     //HABILITA PRESCALER 1:4
                                     
     TRISB = 0x03;                    //DEFINE PORT A COMO SAIDA
     //LATB = 0xFF;                    //INICIA PORT A EM 1
     TMR0L = freq;                   //CARGA INICIAL DO TIMER0
}

void PWM_Execute(){
        
    PWM_Counter++;
    
    if(PWM_Counter == _pwm[0])
        PORTB &= 0b11111011; 
    if(PWM_Counter == _pwm[1])
        PORTB &= 0b11110111; 
    if(PWM_Counter == _pwm[2])
        PORTB &= 0b11101111; 
    if(PWM_Counter == _pwm[3])
        PORTB &= 0b11011111;        
    if(PWM_Counter == _pwm[4])
        PORTB &= 0b10111111;
    else if(PWM_Counter == 0)
        PORTB |= 0b11111100;
    return;
}

#include "PWM.h"


void initPWM(){
     INTCON = 0xA0;                  //HABILITA INT GLOBAL
                                     //HABILITA A INT DO TIMER0
                                     
     T0CON = 0xC1;                   //HABILITA TIMER0
                                     //HABILITA TIMER0 COMO 8BIT'S
                                     //HABILITA CONT. PELO CLOCK INTERNO
                                     //HABILITA PRESCALER 1:4
                                     
     TRISB = 0x03;                    //DEFINE PORT A COMO SAIDA
     //LATB = 0xFF;                    //INICIA PORT A EM 1
     TMR0L = freq;                   //CARGA INICIAL DO TIMER0
}

void pwmExecute(){
        
        counter++;
    
    if(counter == _pwm[0]){
        PORTB &= 0b11111011; 
    }
    if(counter == _pwm[1]){
        PORTB &= 0b11110111; 
    }
    if(counter == _pwm[2]){
        PORTB &= 0b11101111; 
    }
    if(counter == _pwm[3]){
        PORTB &= 0b11011111; 
    }else if(counter == 0){
        PORTB |= 0b11111100;
    }
   // else if(counter == 256){
     //   counter = 0;
    //}

}

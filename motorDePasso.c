#include <pic18f2550.h>
#include <pic18.h>

#include "motorDePasso.h"
/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

void initMotor()
{
    TRISB = 0x00;                    //DEFINE PORT A COMO SAIDA
    LATB  = 0x00;                    //INICIA PORT A EM 1
}

void increaseStep()
{
    if(step == 0){
        //    passo1
        PORTB &= 0b11110000;
        PORTB |= 0b00000001;
        __delay_us(1);
    }
    if(step == 1){
        //    passo2    
        PORTB &= 0b11110000;
        PORTB |= 0b00000011;
        __delay_us(1);
    }
    if(step == 2){
        //    passo3  
        PORTB &= 0b11110000;
        PORTB |= 0b00000010;
        __delay_us(1);
    }
    if(step == 3){
        //    passo4    
        PORTB &= 0b11110000;
        PORTB |= 0b00000110;
        __delay_us(1);
    }
    if(step == 4){
        //    passo5    
        PORTB &= 0b11110000;
        PORTB |= 0b00000100;
        __delay_us(1);
    }
    if(step == 5){
        //    passo6
        PORTB &= 0b11110000;
        PORTB |= 0b00001100;
        __delay_us(1);
    }
    if(step == 6){
        //    passo7    
        PORTB &= 0b11110000;
        PORTB |= 0b00001000;
        __delay_us(1);
    }
    if(step == 7){
        //    passo8    
        PORTB &= 0b11110000;
        PORTB |= 0b00001001;
        __delay_us(1);
    }
    
    ++step;
    if(step > 8)
        step = 0;
}



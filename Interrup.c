#include"Interrup.h"

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
    else if(counter == 256){
        counter = 0;
    }

}

void interrupt Interrupt() {
     if(INTCONbits.TMR0IF) {             //TIMER0 OVERFLOW?
        //counter++;                        //INCREMENTA CONT EM 1
        //pwmExecute();
        INTCONbits.TMR0IF = 0;
        TMR0L = freq;
        pwmExecute();                     //CHAMA FUNÇÃO PWM
      }
     if(PIR1bits.RCIF){
         
         PIR1bits.RCIF = 0;
         
         if(waitToken('_'))
         {
            SerialReadUntilToken('_');
            //SerialWrite("ok\r\n");
            
            if(SerialReceivedString[0] == '1'){
                _pwm[0]+=1;
            }
            if(SerialReceivedString[0] == '0'){
                _pwm[0]-=1;
            }
            if(SerialReceivedString[0] == '3'){
                _pwm[1]+=1;
            }
            if(SerialReceivedString[0] == '2'){
                _pwm[1]-=1;
            }
            if(SerialReceivedString[0] == '5'){
                _pwm[2]+=1;
            }
            if(SerialReceivedString[0] == '4'){
                _pwm[2]-=1;
            }
            if(SerialReceivedString[0] == '7'){
                _pwm[3]+=1;
            }
            if(SerialReceivedString[0] == '6'){
                _pwm[3]-=1;
            }
            if(SerialReceivedString[0] == 't'){
                _pwm[0]=255;
                _pwm[1]=255;
                _pwm[2]=255;
                _pwm[3]=255;
            }
            if(SerialReceivedString[0] == 'g'){
                _pwm[0]=150;
                _pwm[1]=150;
                _pwm[2]=150;
                _pwm[3]=150;
            }
            if(SerialReceivedString[0] == 'b'){
                _pwm[0]=1;
                _pwm[1]=1;
                _pwm[2]=1;
                _pwm[3]=1;
            }
        }
    }
}

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


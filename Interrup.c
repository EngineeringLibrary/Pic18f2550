#include"Interrup.h"

void interrupt Interrupt() {
     if(INTCONbits.TMR0IF) {                //TIMER0 OVERFLOW?

        INTCONbits.TMR0IF = 0;
        TMR0L = freq;
        pwmExecute();                       //CHAMA FUNÇÃO PWM
      }
     if(PIR1bits.RCIF){
         
         PIR1bits.RCIF = 0;
         //_pwm[0]=255;
         
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
    ///ISSO NÃO É AQUI(Y) 
    //lerADXL();                          //CHAMA FUNÇÃO LEITURA ADXL
     if(PIR1bits.ADIF){
         //StartADC();                         //CHAMA FUNÇÃO LEITURA ADC
        PIR1bits.ADIF = 0;
        ADC[0] = ((unsigned char)ADRESL);
        ADC[1] = ((unsigned char)ADRESH);
        _pwm[0] = ADC[1];
     }
     return;
}



#include"Interrup.h"
unsigned contador = 0;
void interrupt INTERRUPTION() {
    

    INTERRUPTION_Timer0();
    INTERRUPTION_ADC();
    INTERRUPTION_Serial();
     
     return;
}

void INTERRUPTION_Timer0(){
    if(INTCONbits.TMR0IF) {                //TIMER0 OVERFLOW?
        INTCONbits.TMR0IF = 0;
//        PORTBbits.RB2 = !PORTBbits.RB2;
        TMR0L = freq;
        PWM_Execute();                       //CHAMA FUNÇÃO PWM
     }
    return;
}
void INTERRUPTION_Serial(){
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
    return;
}
void INTERRUPTION_ADC(){
    if(PIR1bits.ADIF){
        PIR1bits.ADIF = 0;
        
        ADC_Channel++;
        if(ADC_Channel >= ADC_NChannel)
            ADC_Channel = 0;
//        ADC_Read(ADC_Channel);
        ADC_PWM(ADC_Channel);
     }
    return;
}

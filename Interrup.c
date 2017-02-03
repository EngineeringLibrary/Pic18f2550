#include"Interrup.h"

unsigned contador = 0;
void interrupt INTERRUPTION() {
    
//    #ifdef usePWM
        INTERRUPTION_Timer0();
//    #endif    
//    #ifdef useADC
//        INTERRUPTION_ADC();
//    #endif
//    #ifdef useSerial 
        INTERRUPTION_Serial();
//    #endif
     
    return;
}

//#ifdef usePWM
void INTERRUPTION_Timer0(){
    if(INTCONbits.TMR0IF) {                //TIMER0 OVERFLOW?
        INTCONbits.TMR0IF = 0;
        PWM_Execute();                       //CHAMA FUNÇÃO PWM
        TMR0L = freq;
//        PID_interrupt_I2C();
     }
    return;
}
//#endif

//#ifdef useSerial 
    void INTERRUPTION_Serial(){
        if(PIR1bits.RCIF){

             PIR1bits.RCIF = 0;
             if(waitToken('_'))
             {
                SerialReadUntilToken('_');
//                SerialWrite("ok\r\n");

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
                    _pwm[0]=127;
                    _pwm[1]=127;
                    _pwm[2]=127;
                    _pwm[3]=127;
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
//#endif

//#ifdef useADC    
void INTERRUPTION_ADC(){
    if(PIR1bits.ADIF){
        PIR1bits.ADIF = 0;
        
        ADC_Channel++;
        if(ADC_Channel >= ADC_NChannel)
            ADC_Channel = 0;
        ADC_Read_Interrupt(ADC_Channel);
        __delay_us(10);__delay_us(10);__delay_us(10);__delay_us(10);__delay_us(10);
     }
    return;
}
//#endif

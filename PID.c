#include "PID.h"

void PID_outputControlCalc(float reference, float systemOutput, unsigned char whichPID)
{
    pid[whichPID].error = reference - systemOutput;
    
    // derivating the error
    pid[whichPID].dError = ((pid[whichPID].error - pid[whichPID].aError)/pid[whichPID].step);
    pid[whichPID].aError = pid[whichPID].error;

    // integrating the error. It is done onle if it weren't achieved the system's output limits
    if(!pid[whichPID].checkUpLim && !pid[whichPID].checkLowLim)
        pid[whichPID].iError += pid[whichPID].error*pid[whichPID].step;
    
    pid[whichPID].controlSignal = (pid[whichPID].Kp*pid[whichPID].error + pid[whichPID].Ki*pid[whichPID].iError + pid[whichPID].Kd*pid[whichPID].dError);
    
    //checking the output limits, if so, limit the output control signal
    if(pid[whichPID].controlSignal >= pid[whichPID].upperLimit)
    {
        pid[whichPID].checkUpLim = 1;
        pid[whichPID].controlSignal = pid[whichPID].upperLimit;
    }
    else
        pid[whichPID].checkUpLim = 0;

    if(pid[whichPID].controlSignal <= pid[whichPID].lowerLimit)
    {
        pid[whichPID].checkLowLim = 1;
        pid[whichPID].controlSignal = pid[whichPID].lowerLimit;
    }
    else
        pid[whichPID].checkLowLim = 0;
    
    return;
}

//void PID_interrupt_I2C()
//{
//    PID_interruptCounter++;
//    if(PID_interruptCounter == 16777215)
//    {
//        float systemOutput = readACC(0x36) + (readACC(0x37)<<8);
//        pid[0] = PID_outputControlCalc(reference[0],systemOutput,pid[0]);
//        
//        systemOutput = readGIRO(0x28) + (readGIRO(0x29)<<8);
//        pid[1] = PID_outputControlCalc(reference[1],systemOutput,pid[1]);
//        
//        systemOutput = readGIRO(0x2A) + (readGIRO(0x2B)<<8);
//        pid[2] = PID_outputControlCalc(reference[2],systemOutput,pid[2]);
//        
//        systemOutput = readGIRO(0x2C) + (readGIRO(0x2D)<<8);
//        pid[3] = PID_outputControlCalc(reference[3],systemOutput,pid[3]);
//                
//    }
//    return;    
//}
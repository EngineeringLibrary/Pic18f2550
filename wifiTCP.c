#include"wifiTCP.h"

void WifiTCPinit(){
   
//   SerialWrite("AT+UART=115200,8,1,0,0\r\n");
//   delaySeg(2);
   
   SerialWrite("AT+RST\r\n");
   delaySeg(2);


   SerialWrite("AT+CWMODE=1\r\n");
    delaySeg(2);

   SerialWrite("AT+CWJAP=\"BatCaverna\",\"23dfd1b64b\"\r\n");
    //SerialWrite("AT+CWJAP=\"Igor\",\"motog123\"\r\n");
    delaySeg(8);

   SerialWrite("AT+CIPMUX=1\r\n");
    delaySeg(2);

   SerialWrite("AT+CIPSERVER=1,4000\r\n");
    delaySeg(2);
    return;
}

void WifiTCPSend(unsigned char *stringToSend, unsigned lenStr)
{
    unsigned char newLine[] = "\r\n";
    unsigned sizeStringToSend = strlen(stringToSend);
    SerialWrite("AT+CIPSEND=0,");
    SerialPrint(lenStr+48);
    SerialWrite(newLine);

    if(ContainString("link is not") && flagLink)
        flagLink = 0;
    __delay_ms(10);
    SerialWrite(stringToSend);
    SerialWrite(newLine);
    waitUntil("OK");
    return;
}


void WifiTCPRead(void)
{
    waitToken('_');
    SerialReadUntilToken('_');
    for(unsigned i = 0; i < SerialLen; ++i)
            WifiTCPData[i] = SerialReceivedString[i];
    WifiTCPData[SerialLen] = '\0';
    WifiTCPDataLen = SerialLen;
    return;
}

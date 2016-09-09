#include "Serial.h"

void delaySeg(unsigned waitTime)
{
    for(unsigned j = 0; j < waitTime; ++j)
        for(unsigned i = 0; i <= 113; ++i)  
            __delay_ms(10);
    return;
}

void delayMS(unsigned waitTime)
{
    for(unsigned j = 0; j < waitTime; ++j)
            __delay_ms(1);
    return;
}

void initUART(void)
{
    TRISCbits.TRISC7 = 1;    TRISCbits.TRISC6 = 0;

    SPBRG =  (unsigned char) (_XTAL_FREQ/(16*BAUDRATE) - 1);   
    SPBRGH =  (unsigned char) (_XTAL_FREQ/(16*BAUDRATE) - 1);   

    CSRC = 0;    TX9  = 0;    TXEN = 1;
    SYNC = 0;    SENDB = 0;   BRGH = 1;
    TRMT = 0;    TX9D = 0;    SPEN = 1;
    RX9  = 0;    SREN = 0;    CREN = 1;
    ADDEN = 0;   FERR = 0;    OERR = 0;
    RX9D = 0;    TXIE = 0;    RCIE = 1;
    
    return;
}

void SerialPrint(unsigned char byte)
{
    while(!TXIF);
    TXREG = byte;
    RCIF = 0;
    OERR = 0;
    
    return;
}

void SerialWifiWrite (char* Valor, unsigned Tamanho){
    
    int i;
    
    for (i = 0; i < Tamanho; ++i){
        SerialPrint(Valor[i]);
    }
    
    return;
}

void SerialWrite(const char* frase)
{
    unsigned char indice = 0;
    unsigned char tamanho = strlen(frase);

    while(indice < tamanho){
        if(frase[indice] != '\0')
        {
            SerialPrint(frase[indice]);
            ++indice;
        }
        else
            break;
    }
    SerialLen = indice;
    return;
}

char SerialRead(void)
{
    if(OERR)
    {
        CREN = 0;
        CREN = 1;
    }
    while(!RCIF);
    SerialReceivedData = RCREG;
    RCIF = 0;
    return RCREG;
}

void SerialReadString()
{
    unsigned i = 0;
    while(1)
    {
        SerialReceivedString[i] = SerialRead();
        if( ('\n' == SerialReceivedString[i]) || ('\r' == SerialReceivedString[i]) || (' ' == SerialReceivedString[i]))
        {
            SerialReceivedString[i+1] = '\0';
            break;
        }
        ++i;
    }
    SerialLen = i+1;
    return;
}

bit ContainString(const char* containedString)
{
    unsigned char sizeString = strlen(SerialReceivedString),i, j, sizeStringToCompare = strlen(containedString);
    unsigned char * hasString = strstr(SerialReceivedString, containedString);
    if(hasString)
        return 1;

    return 0;
}

bit waitToken(char value)
{
    if(!RCIF)
        return 0;
    
    if((SerialRead() == value)){
        RCREG = value+1;
        return 1;
    }
    else
        return 0;
}

void waitUntil(const unsigned char stringToCompare[])
{
    
    while(!ContainString(stringToCompare))
        SerialReadString();
    return;
}

void SerialReadUntilToken(const char charToCompare)
{
    unsigned i = 0;
    while(1)
    {
        SerialReceivedString[i] = SerialRead();
        if( charToCompare == SerialReceivedString[i])
        {
            SerialReceivedString[i] = '\0';
            break;
        }
        ++i;
    }
    SerialLen = i;
    return;
}

void SerialReceiveNChar(const int NumberOfCharToReceive)
{
    SerialReceivedString[NumberOfCharToReceive] = '\0';
    for(unsigned i = 0; i < NumberOfCharToReceive; ++i)
    {
        SerialReceivedString[i] = SerialRead();
    }
    return;
}
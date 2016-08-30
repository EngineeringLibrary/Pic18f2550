
#include"conversions.h"

//char *intToString(int Number)
//{
//
//    if(Number < 10)
//    {
//        char Ret[1];
//        Ret[0] = Number+48;
//        return Ret;
//    }else if (Number < 100)  
//    {
//        char Ret[2];
//        int temp = (Number / 10);
//        Ret[0] = temp + 48;
//        int temp2 = (Number - temp*10);
//        Ret[1] = temp2+48;
//        return Ret;
//    }
//    return 0;
//}
//
//int stringToInt(const char CharNumber[])
//{
//    unsigned tamChar = strlen(CharNumber);
//    unsigned number = 0;
//    unsigned pow = 1;
//    for(unsigned i = tamChar-1; i >= 0; --i)
//    {
//        number += (CharNumber[i] - 48)*pow;
//        pow *= 10;
//    }
//    return number;
//}

int scaleChange(int Xmax, int Xmin, int Ymax, int Ymin, int Y){
    return ((Y - Ymin)/(Ymax - Ymin)) * (Xmax - Xmin) + Xmin;
}
int ConvBrutoToReal(unsigned char n1, unsigned char n2){
    return ((int)n2<<8)|(int)n1;
}
//double *MutMatA(const double *B){
//    double Res[];
//    
//    for(unsigned i = 0; i < 6; ++i){
//        for(unsigned j = 0; j < 6; ++j){
//            Res[i] += A[i][j] * B[j];
//        }
//    }
//    return Res;
//}
void AllocA(unsigned char *DataReceive){
    unsigned j = 0;
    
    for(unsigned i = 0; i < strlen(DataReceive); ++i){
       A[j][i] = DataReceive[i];
       
       if(i == 6) ++j;
    }
}

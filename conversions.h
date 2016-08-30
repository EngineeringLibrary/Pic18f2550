/* 
 * File:   conversions.h
 * Author: test
 *
 * Created on 29 de Julho de 2015, 18:38
 */

#ifndef CONVERSIONS_H
#define	CONVERSIONS_H

#include <string.h>

unsigned char A[6][6];
    
char *intToString(int Number);
int stringToInt(const char CharNumber[]);
int scaleChange(int Xmax, int Xmin, int Ymax, int Ymin, int Y);
int ConvBrutoToReal(unsigned char n1, unsigned char n2);
double *MutMatA(const double *B);
void AllocA(unsigned char *DataReceive);

#endif	/* CONVERSIONS_H */


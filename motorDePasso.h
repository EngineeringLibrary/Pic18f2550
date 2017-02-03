/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */
#ifndef _XTAL_FREQ
    #define _XTAL_FREQ 48000000
#endif
#ifndef MOTORPASSO_H
#define	MOTORPASSO_H

unsigned char step = 0;
void initMotor();
void increaseStep();

#endif	/* MOTORPASSO_H */


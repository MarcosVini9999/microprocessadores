/*
 * File:   main.c
 * Author: marco
 *
 * Created on 19 de Julho de 2022, 15:37
 */


#include <xc.h>
#define _XTAL_FREQ 4000000

void main(void) {
    TRISDbits.TRISD0 = 0; //RD0 COMO SAÍDA
    T2CONbits.T2CKPS = 0b00; //Prescaler 1:1 -> ftmr2 = 1MHz
    return;
}

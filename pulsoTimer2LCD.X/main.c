/*
 * File:   main.c
 * Author: marco
 *
 * Created on 19 de Julho de 2022, 15:37
 */

#define _XTAL_FREQ 4000000
#pragma config FOSC = XT_XT     // Oscillator Selection bits (XT oscillator (XT))
#pragma config WDT = OFF        // Watchdog Timer Enable bit (WDT disabled (control is placed on the SWDTEN bit))
#pragma config PBADEN = OFF     // PORTB A/D Enable bit (PORTB<4:0> pins are configured as digital I/O on Reset)
#pragma config MCLRE = ON       // MCLR Pin Enable bit (MCLR pin enabled; RE3 input pin disabled)
#pragma config LVP = OFF        // Single-Supply ICSP Enable bit (Single-Supply ICSP disabled)

#include <xc.h>
#include <stdio.h>
#include <pic18f4550.h>
#include "lcd.h"

void putch(char data){
  escreve_lcd(data);   
}

unsigned char cont = 0;

void main(void) {
    TRISBbits.RB0 = 1; // Pino RB0 EM 1
    INTEDG0 = 1; // habilita a interrupcao por borda de subida
    TRISD = 0x00; 
    inicializa_lcd();
    T2CONbits.T2CKPS = 0b00; // Prescaler 1:1
    T2CONbits.TOUTPS = 0b0000; // Postscaler 1:1
    T2CONbits.TMR2ON = 1;//Habilita o timer 2
    INTCONbits.GIE = 1; //Habilita as interrupções globais
    INTCONbits.INT0IE = 1; //Habilita a interrupcao do INT0
    INTCONbits.GIEH = 1; // Habilita interrupçoes de alta prioridade
    
    while(1==1) {
        __delay_ms(10);
        caracter_inicio(1,1);  //define o ponto de inicio da frase na primeira linha
        printf("TMR2 = %d",cont);
        caracter_inicio(2,1);  //define o ponto de inicio da frase na segunda linha
        printf("Largura+ = %d",2*cont);
    }
    return;
}

void __interrupt(high_priority) ISR(void){
  if(INT0IF){
     INT0IF = 0;
     if (INTEDG0){
      TMR2 = 0; //timer 2 reseta
      INTEDG0 = 0; 
     } else {
      cont = TMR2; //cont recebe valor do timer 2
      INTEDG0 = 1;
     }       
  }
}

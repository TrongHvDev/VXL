/*
 * File:   main_array_LED.c
 * Author: Trong Ho
 *
 * Created on March 22, 2022, 3:28 PM
 */


// PIC16F877A Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#define _XTAL_FREQ 1000000
void oneLED (){
unsigned char data = 0b10000000, data1 = 0b10000000;
        for(int i = 0; i < 9; i++){
           PORTD = data; 
           data = data >> 1;
           if(i == 8) break;
           __delay_ms(300);
        }   
        for(int j = 0; j < 9; j++){
           PORTC = data1; 
           data1 = data1 >> 1;
           if(j == 8) break;
           __delay_ms(300); 
        }    
}

void oneByOneLED(){
unsigned char data = 0b10000000 , data1 = 0b10000000, n = 0b10000000 , m = 0b10000000 ;
        for(int i = 0; i < 9; i++){
           data = (data >> 1);
           PORTD = m;
           m =   data + m ;
           if(i == 8) break;
           __delay_ms(300);
        }   
        for(int j = 0; j < 9; j++){
           data1 = (data1 >> 1);
           PORTC = n;
           n =   data1 + n ;
           if(j == 8) {
               PORTC = 0;
               PORTD = 0;
             //  break;
              
           }
           __delay_ms(300);
        }    
         
}    

void main(void) {
    TRISC = 0;
    TRISD = 0;
    PORTC = 0;
    PORTD = 0;
    while(1){
        oneLED();
        oneByOneLED();
    }
    return;
}

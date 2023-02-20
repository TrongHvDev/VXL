/*
 * File:   newmain.c
 * Author: Trong Ho
 *
 * Created on March 14, 2022, 9:05 PM
 */

// PIC16F1509 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1
#pragma config FOSC = HS        // Oscillator Selection Bits (HS Oscillator, High-speed crystal/resonator connected between OSC1 and OSC2 pins)
#pragma config WDTE = OFF       // Watchdog Timer Enable (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable (PWRT disabled)
#pragma config MCLRE = OFF      // MCLR Pin Function Select (MCLR/VPP pin function is digital input)
#pragma config CP = OFF         // Flash Program Memory Code Protection (Program memory code protection is disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable (Brown-out Reset disabled)
#pragma config CLKOUTEN = OFF   // Clock Out Enable (CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin)
#pragma config IESO = OFF       // Internal/External Switchover Mode (Internal/External Switchover Mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable (Fail-Safe Clock Monitor is disabled)

// CONFIG2
#pragma config WRT = OFF        // Flash Memory Self-Write Protection (Write protection off)
#pragma config STVREN = OFF     // Stack Overflow/Underflow Reset Enable (Stack Overflow or Underflow will not cause a Reset)
#pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), low trip point selected.)
#pragma config LPBOR = OFF      // Low-Power Brown Out Reset (Low-Power BOR is disabled)
#pragma config LVP = OFF        // Low-Voltage Programming Enable (High-voltage on MCLR/VPP must be used for programming)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#define _XTAL_FREQ 1000000
#include <xc.h>
int array[100] = {0,0,1,1,1,1,1,1, 0,0,0,0,0,1,1,0, 0,1,0,1,1,0,1,1,
              0,1,0,0,1,1,1,1, 0,1,1,0,0,1,1,0, 0,1,1,0,1,1,0,1,
              0,1,1,1,1,1,0,1, 0,0,0,0,0,1,1,1, 0,1,1,1,1,1,1,1,
              0,1,1,0,1,1,1,1};
void data(int i)
{
    LATCbits.LATC1 = i;
    LATCbits.LATC0 = 1;
    LATCbits.LATC0 = 0;
}
void input(int j)
{
    for (int i = 0 + 8*j; i < 8 + 8 * j; i++)
    {
        data(array[i]);
    }
}
void main(void) {
    TRISC = 0;
    LATCbits.LATC0 = 0;
    LATCbits.LATC1 = 0;
    LATCbits.LATC2 = 0;
    while(1)
    {
        for (int k = 59; k >= 0; k--)
        {
            for (int j = 60; j >= 0; j--)
            {
                input(j % 10); 
                input(j / 10);
                input(k % 10); 
                input(k / 10);
                __delay_us(1);
                LATCbits.LATC2 = 1;
                LATCbits.LATC2 = 0;
            }
        }
    }
    return;
}

/*
 * File:   button_LED_main.c
 * Author: Trong Ho
 *
 * Created on March 15, 2022, 10:04 AM
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

#include <xc.h>
#define _XTAL_FREQ 1000000
void button (){
    int s1_state = 0, s2_state = 0, count, countTime;
     while(1){
 
         for(int i = 1; i <= 10; i+=2){
             if(PORTCbits.RC0 == 1 && s1_state == i - 1) s1_state = i;
         }
         for(int i = 2; i <= 10; i+=2){
             if(PORTCbits.RC0 == 0 && s1_state == i - 1) s1_state = i;
         }
         
        if(s1_state == 2) LATCbits.LATC3 = 1;
        if(s1_state == 4){
            LATCbits.LATC3 = 0;
            LATCbits.LATC4 = 1;
        }
         if(s1_state == 6){
            LATCbits.LATC3 = 0;
            LATCbits.LATC4 = 0;
            LATCbits.LATC5 = 1;
         }
        if(s1_state == 8){
            LATCbits.LATC3 = 0;
            LATCbits.LATC4 = 0;
            LATCbits.LATC5 = 0;
        }
        if(s1_state == 10) return;
        
//-----------------------------------------------------------------------------------------------------        
        
        for(int i = 1; i <= 10; i+=2){
             if(PORTCbits.RC1 == 1 && s2_state == i - 1) s2_state = i;
         }
         for(int i = 2; i <= 10; i+=2){
             if(PORTCbits.RC1 == 0 && s2_state == i - 1) s2_state = i;
         }
        
        
        if(s2_state == 2) {
            if(count < 125){      //Tmachine = 4/1000000; 0.5/4*10^-3 = 125
            LATCbits.LATC3 = 1;
            __delay_ms(1);
            count ++;
            }
            else if(count <250){
            LATCbits.LATC3 = 0;
            __delay_ms(1);
            count ++;
            }  
            else count = 0;
            
        }
        if(s2_state == 4){
           // count = 0;
            LATCbits.LATC3 = 0;
            if(count < 125){
            LATCbits.LATC4 = 1;
            __delay_ms(1);
            count ++;
            }
            else if(count <250){
            LATCbits.LATC4 = 0;
            __delay_ms(1);
            count ++;
            }  
            else count = 0;
        }
         if(s2_state == 6){
           //  count = 0;
            LATCbits.LATC3 = 0;
            LATCbits.LATC4 = 0;    
            if(count < 125){
            LATCbits.LATC5 = 1;
            __delay_ms(1);
            count ++;
            }
            else if(count <250){
            LATCbits.LATC5 = 0;
            __delay_ms(1);
            count ++;
            }  
            else count = 0;
         }
        if(s2_state == 8){
            LATCbits.LATC3 = 0;
            LATCbits.LATC4 = 0;
            LATCbits.LATC5 = 0;
        }
        if(s2_state == 10) return;
//-------------------------------------------------------------------------------------------
         
 
         if(PORTCbits.RC2 == 1){
             if(countTime > 750){
                 return;
             }   
            countTime ++;
            __delay_ms(1);
             if (countTime > 751) countTime = 0;   
         }

     }
}


void main(void) {
    TRISCbits.TRISC0 = 1;
    TRISCbits.TRISC1 = 1;
    TRISCbits.TRISC2 = 1;
    
    TRISCbits.TRISC3 = 0;
    TRISCbits.TRISC4 = 0;
    TRISCbits.TRISC5 = 0;
    
    
    
        LATCbits.LATC3 = 0;
        LATCbits.LATC4 = 0;
        LATCbits.LATC5 = 0;
      
        button();
        
    return;
}

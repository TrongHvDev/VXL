/*
 * File:   newmain.c
 * Author: Trong Ho
 *
 * Created on May 29, 2022, 10:05 PM
 */



#include "Config_1.h"
#include "Config_2.h"
#include <xc.h>
#include <math.h>
#define _XTAL_FREQ 1000000
#define CLK PORTCbits.RC0
#define DATA PORTCbits.RC1
#define LAT PORTCbits.RC2
#define Button PORTCbits.RC3
#define CLK2 PORTCbits.RC4
#define DATA2 PORTCbits.RC5
const unsigned char ma7doan[10] = {0b1000000, 0b11111001, 0b0100100, 0b0110000, 0b0011001,
0b0010010, 0b0000010, 0b1111000, 0b0000000, 0b0010000};

void hien_thi_1_byte(unsigned char data) {
    unsigned char tmp = 0b10000000;
    for (unsigned char i=0; i<8; i++)
    {
        if ((data&tmp)==0) 
        {
            DATA = 0;
        }
        else
        {
            DATA = 1;
        }
        CLK = 1;
        CLK = 0;
        tmp>>=1;
    }
}

void hien_thi_1_byte2(unsigned char data) {
    unsigned char tmp = 0b10000000;
    for (unsigned char i=0; i<8; i++)
    {
        if ((data&tmp)==0) 
        {
            DATA2 = 0;
        }
        else
        {
            DATA2 = 1;
        }
        CLK2 = 1;
        CLK2 = 0;
        tmp>>=1;
    }
}

void hien_thi_phut(unsigned char tmp) {
    int chuc, donvi;
    chuc = ma7doan[tmp/10];
    donvi = ma7doan[tmp%10];
    hien_thi_1_byte(donvi);
    hien_thi_1_byte(chuc);
    LAT = 1;
    LAT = 0;
}

void hien_thi_giay(unsigned char tmp) {
    int chuc, donvi;
    chuc = ma7doan[tmp/10];
    donvi = ma7doan[tmp%10];
    hien_thi_1_byte2(donvi);
    hien_thi_1_byte2(chuc);
    LAT = 1;
    LAT = 0;
}

unsigned int ADC_Conversion()
{
    __delay_ms(1);
    ADCON0bits.GO_nDONE = 1;
    while (ADCON0bits.GO_nDONE == 1);
    return ((ADRESH<<8) + ADRESL);
}

void main(void) {
    unsigned char state = 0;
    unsigned int ADC_Result;
    float m, s;
    TRISAbits.TRISA0 = 1; //Set RA0 input
    ANSELbits.ANS0 = 1; // Set RA0 to analog input
    TRISCbits.TRISC0 = 0; // CLK
    TRISCbits.TRISC1 = 0; // Data
    TRISCbits.TRISC2 = 0; // Latch
    TRISCbits.TRISC3 = 1; // Button input
    TRISCbits.TRISC4 = 0; // CLK2
    TRISCbits.TRISC5 = 0; // Data2
    ADCON0 = 0b10000001;
    ADCON1 = 0b10000000;
    while (1){
        if ((state==0) && (Button==1)) state=1;
        if ((state==1) && (Button==0)) state=2;
        if ((state==2) && (Button==1)) state=3;
        if ((state==3) && (Button==0)) state=4;
        if ((state==4) && (Button==1)) state=5;
        if ((state==5) && (Button==0)) state=6;
        if ((state==6) && (Button==1)) state=1;
        if (state==0)
        {
            for (char i=0; i<60; i++)
            {
                hien_thi_phut(i);
                for (char j=0; j<60; j++)
                {
                    hien_thi_giay(j);
                    __delay_ms(200);
                    if (Button==1) 
                    {
                        i=60;
                        j=60;
                    }
                }
            }
        }
        if (state==2)
        {
            ADC_Result = ADC_Conversion();
            m = round((float)ADC_Result*60/1023);
            if (m==60) m=59;
            hien_thi_phut(m);
        }
        if (state==4)
        {
            ADC_Result = ADC_Conversion();
            s = round((float)ADC_Result*60/1023);
            if (s==60) s=59;
            hien_thi_giay(s);
        }
        if (state==6)
        {
            for (char i=m; i<60; i++)
            {
                hien_thi_phut(i);
                for (char j=s; j<60; j++)
                {
                    hien_thi_giay(j);
                    __delay_ms(200);
                    if (Button==1) 
                    {
                        i=60;
                        j=60;
                    }
                    if (j==59) s=0;
                }
                if (i==59) m=0;
            }
        }
    }
    return;
}

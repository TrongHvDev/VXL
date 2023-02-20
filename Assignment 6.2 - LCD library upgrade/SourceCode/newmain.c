/*
 * File:   newmain.c
 * Author: Trong Ho
 *
 * Created on April 6, 2022, 9:41 AM
 */

#include "_16f1509_config.h"
#include <xc.h>
#include "lcd.h"

void main(void) { 
        LCD_Initialize();
       LCDPutStr2("HoVinhTrong",3,0);
        LCDPutStr3("16:00:00", 1);
        while(1);
    return;
}

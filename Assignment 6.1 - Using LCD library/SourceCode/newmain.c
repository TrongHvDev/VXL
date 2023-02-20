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
        LCDPutStr("  Ho Vinh Trong");
        
        LCDGoto(0,1);
        LCDPutStr2('HoVinhTrong', 12, 1);
        
        while(1);
    return;
}

#include <16F1509.h>
#device ADC=10
#fuses INTRC_IO
#use delay(crystal=1000000)
#define LCD_ENABLE_PIN  PIN_C2                                  
#define LCD_RS_PIN      PIN_C0                                  
#define LCD_RW_PIN      PIN_C1                                  
#define LCD_DATA4       PIN_C3                              
#define LCD_DATA5       PIN_C4                                    
#define LCD_DATA6       PIN_C5                                  
#define LCD_DATA7       PIN_C6
#include <lcd.c>
#define VREF      PIN_A0
//!#define VREF_HIGH       PIN_A1



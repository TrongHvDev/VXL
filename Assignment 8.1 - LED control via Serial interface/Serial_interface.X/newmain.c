/*
 * File:   newmain.c
 * Author: Trong Ho
 *
 * Created on May 29, 2022, 10:19 PM
 */


#include "mcc_generated_files/mcc.h"

unsigned char cmd[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
unsigned char state[8] = {0, 0, 0, 0, 0, 0, 0, 0};
unsigned char blink = 0, on = 0, off = 0;
int count = 0;

void Blink_LED(int x) {
    if (x == 1) {
        if (count < 500) {
            LATCbits.LATC0 = 1;
            count++;
            __delay_ms(1);
        } else if (count < 1000) {
            LATCbits.LATC0 = 0;
            count++;
            __delay_ms(1);
        } else count = 0;
    }
    if (x == 2) {
        if (count < 500) {
            LATCbits.LATC1 = 1;
            count++;
            __delay_ms(1);
        } else if (count < 1000) {
            LATCbits.LATC1 = 0;
            count++;
            __delay_ms(1);
        } else count = 0;
    }
    if (x == 3) {
        if (count < 500) {
            LATCbits.LATC2 = 1;
            count++;
            __delay_ms(1);
        } else if (count < 1000) {
            LATCbits.LATC2 = 0;
            count++;
            __delay_ms(1);
        } else count = 0;
    }
    if (x == 4) {
        if (count < 500) {
            LATCbits.LATC3 = 1;
            count++;
            __delay_ms(1);
        } else if (count < 1000) {
            LATCbits.LATC3 = 0;
            count++;
            __delay_ms(1);
        } else count = 0;
    }
    if (x == 5) {
        if (count < 500) {
            LATCbits.LATC4 = 1;
            count++;
            __delay_ms(1);
        } else if (count < 1000) {
            LATCbits.LATC4 = 0;
            count++;
            __delay_ms(1);
        } else count = 0;
    }
    if (x == 6) {
        if (count < 500) {
            LATCbits.LATC5 = 1;
            count++;
            __delay_ms(1);
        } else if (count < 1000) {
            LATCbits.LATC5 = 0;
            count++;
            __delay_ms(1);
        } else count = 0;
    }
    if (x == 7) {
        if (count < 500) {
            LATCbits.LATC6 = 1;
            count++;
            __delay_ms(1);
        } else if (count < 1000) {
            LATCbits.LATC6 = 0;
            count++;
            __delay_ms(1);
        } else count = 0;
    }
    if (x == 8) {
        if (count < 500) {
            LATCbits.LATC7 = 1;
            count++;
            __delay_ms(1);
        } else if (count < 1000) {
            LATCbits.LATC7 = 0;
            count++;
            __delay_ms(1);
        } else count = 0;
    }
}

void main(void) {
    SYSTEM_Initialize();
    LATC = 0x00;
    while (1) {
        for (int i = 0; i < 10; i++) {
            while (EUSART_is_rx_ready() == 0) {
                if (state[0] == 1) {
                    Blink_LED(1);
                }
                if (state[1] == 1) {
                    Blink_LED(2);
                }
                if (state[2] == 1) {
                    Blink_LED(3);
                }
                if (state[3] == 1) {
                    Blink_LED(4);
                }
                if (state[4] == 1) {
                    Blink_LED(5);
                }
                if (state[5] == 1) {
                    Blink_LED(6);
                }
                if (state[6] == 1) {
                    Blink_LED(7);
                }
                if (state[7] == 1) {
                    Blink_LED(8);
                }
            }
            cmd[i] = EUSART_Read();
            if (cmd[i] == '#') i = 10;
        }


        if (cmd[1] == 'N') {
            on = 1;
            off = 0;
            blink = 0;
        }
        if (cmd[1] == 'F') {
            on = 0;
            off = 1;
            blink = 0;
        }
        if (cmd[1] == 'L') {
            on = 0;
            off = 0;
            blink = 1;
        }


        if (on == 1) {
            if ((cmd[0] == 'O')&&(cmd[1] == 'N')&&(cmd[2] == '0')&&(cmd[3] == '1')&&(cmd[4] == '#')) {
                LATCbits.LATC0 = 1;
                state[0] = 0;
            }
            if ((cmd[0] == 'O')&&(cmd[1] == 'N')&&(cmd[2] == '0')&&(cmd[3] == '2')&&(cmd[4] == '#')) {
                LATCbits.LATC1 = 1;
                state[1] = 0;
            }
            if ((cmd[0] == 'O')&&(cmd[1] == 'N')&&(cmd[2] == '0')&&(cmd[3] == '3')&&(cmd[4] == '#')) {
                LATCbits.LATC2 = 1;
                state[2] = 0;
            }
            if ((cmd[0] == 'O')&&(cmd[1] == 'N')&&(cmd[2] == '0')&&(cmd[3] == '4')&&(cmd[4] == '#')) {
                LATCbits.LATC3 = 1;
                state[3] = 0;
            }
            if ((cmd[0] == 'O')&&(cmd[1] == 'N')&&(cmd[2] == '0')&&(cmd[3] == '5')&&(cmd[4] == '#')) {
                LATCbits.LATC4 = 1;
                state[4] = 0;
            }
            if ((cmd[0] == 'O')&&(cmd[1] == 'N')&&(cmd[2] == '0')&&(cmd[3] == '6')&&(cmd[4] == '#')) {
                LATCbits.LATC5 = 1;
                state[5] = 0;
            }
            if ((cmd[0] == 'O')&&(cmd[1] == 'N')&&(cmd[2] == '0')&&(cmd[3] == '7')&&(cmd[4] == '#')) {
                LATCbits.LATC6 = 1;
                state[6] = 0;
            }
            if ((cmd[0] == 'O')&&(cmd[1] == 'N')&&(cmd[2] == '0')&&(cmd[3] == '8')&&(cmd[4] == '#')) {
                LATCbits.LATC7 = 1;
                state[7] = 0;
            }
            if ((cmd[0] == 'O')&&(cmd[1] == 'N')&&(cmd[2] == '*')&&(cmd[3] == '#')) {
                LATC = 0xFF;
                for (char i = 0; i < 8; i++) state[i] = 0;
            }
        }


        if (off == 1) {
            if ((cmd[0] == 'O')&&(cmd[1] == 'F')&&(cmd[2] == 'F')&&(cmd[3] == '0')&&(cmd[4] == '1')&&(cmd[5] == '#')) {
                LATCbits.LATC0 = 0;
                state[0] = 0;
            }
            if ((cmd[0] == 'O')&&(cmd[1] == 'F')&&(cmd[2] == 'F')&&(cmd[3] == '0')&&(cmd[4] == '2')&&(cmd[5] == '#')) {
                LATCbits.LATC1 = 0;
                state[1] = 0;
            }
            if ((cmd[0] == 'O')&&(cmd[1] == 'F')&&(cmd[2] == 'F')&&(cmd[3] == '0')&&(cmd[4] == '3')&&(cmd[5] == '#')) {
                LATCbits.LATC2 = 0;
                state[2] = 0;
            }
            if ((cmd[0] == 'O')&&(cmd[1] == 'F')&&(cmd[2] == 'F')&&(cmd[3] == '0')&&(cmd[4] == '4')&&(cmd[5] == '#')) {
                LATCbits.LATC3 = 0;
                state[3] = 0;
            }
            if ((cmd[0] == 'O')&&(cmd[1] == 'F')&&(cmd[2] == 'F')&&(cmd[3] == '0')&&(cmd[4] == '5')&&(cmd[5] == '#')) {
                LATCbits.LATC4 = 0;
                state[4] = 0;
            }
            if ((cmd[0] == 'O')&&(cmd[1] == 'F')&&(cmd[2] == 'F')&&(cmd[3] == '0')&&(cmd[4] == '6')&&(cmd[5] == '#')) {
                LATCbits.LATC5 = 0;
                state[5] = 0;
            }
            if ((cmd[0] == 'O')&&(cmd[1] == 'F')&&(cmd[2] == 'F')&&(cmd[3] == '0')&&(cmd[4] == '7')&&(cmd[5] == '#')) {
                LATCbits.LATC6 = 0;
                state[6] = 0;
            }
            if ((cmd[0] == 'O')&&(cmd[1] == 'F')&&(cmd[2] == 'F')&&(cmd[3] == '0')&&(cmd[4] == '8')&&(cmd[5] == '#')) {
                LATCbits.LATC7 = 0;
                state[7] = 0;
            }
            if ((cmd[0] == 'O')&&(cmd[1] == 'F')&&(cmd[2] == 'F')&&(cmd[3] == '*')&&(cmd[4] == '#')) {
                LATC = 0x00;
                for (char i = 0; i < 8; i++) state[i] = 0;
            }
        }


        if (blink == 1) {
            if ((cmd[0] == 'B')&&(cmd[1] == 'L')&&(cmd[2] == 'I')&&(cmd[3] == 'N')&&(cmd[4] == 'K')&&(cmd[5] == '0')&&(cmd[6] == '1')&&(cmd[7] == '#'))
                state[0] = 1;
            if ((cmd[0] == 'B')&&(cmd[1] == 'L')&&(cmd[2] == 'I')&&(cmd[3] == 'N')&&(cmd[4] == 'K')&&(cmd[5] == '0')&&(cmd[6] == '2')&&(cmd[7] == '#'))
                state[1] = 1;
            if ((cmd[0] == 'B')&&(cmd[1] == 'L')&&(cmd[2] == 'I')&&(cmd[3] == 'N')&&(cmd[4] == 'K')&&(cmd[5] == '0')&&(cmd[6] == '3')&&(cmd[7] == '#'))
                state[2] = 1;
            if ((cmd[0] == 'B')&&(cmd[1] == 'L')&&(cmd[2] == 'I')&&(cmd[3] == 'N')&&(cmd[4] == 'K')&&(cmd[5] == '0')&&(cmd[6] == '4')&&(cmd[7] == '#'))
                state[3] = 1;
            if ((cmd[0] == 'B')&&(cmd[1] == 'L')&&(cmd[2] == 'I')&&(cmd[3] == 'N')&&(cmd[4] == 'K')&&(cmd[5] == '0')&&(cmd[6] == '5')&&(cmd[7] == '#'))
                state[4] = 1;
            if ((cmd[0] == 'B')&&(cmd[1] == 'L')&&(cmd[2] == 'I')&&(cmd[3] == 'N')&&(cmd[4] == 'K')&&(cmd[5] == '0')&&(cmd[6] == '6')&&(cmd[7] == '#'))
                state[5] = 1;
            if ((cmd[0] == 'B')&&(cmd[1] == 'L')&&(cmd[2] == 'I')&&(cmd[3] == 'N')&&(cmd[4] == 'K')&&(cmd[5] == '0')&&(cmd[6] == '7')&&(cmd[7] == '#'))
                state[6] = 1;
            if ((cmd[0] == 'B')&&(cmd[1] == 'L')&&(cmd[2] == 'I')&&(cmd[3] == 'N')&&(cmd[4] == 'K')&&(cmd[5] == '0')&&(cmd[6] == '8')&&(cmd[7] == '#'))
                state[7] = 1;
            if ((cmd[0] == 'B')&&(cmd[1] == 'L')&&(cmd[2] == 'I')&&(cmd[3] == 'N')&&(cmd[4] == 'K')&&(cmd[5] == '*')&&(cmd[6] == '#'))
                for (char i = 0; i < 8; i++) state[i] = 1;
        }
    }
}
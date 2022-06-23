#include <xc.h>

void main(void) {
    TRISD = 0xFF;
    TRISCbits.RC0=0;
    int btn;
    while(1){
        switch(btn){
            case 0b10000000:
                __delay_ms(1.941);
                continue;
                break;
            case 0b01000000:
                __delay_ms(1.703);
                continue;
                break;
            case 0b00100000:
                __delay_ms(1.517);
                continue;
                break;
            case 0b00010000:
                __delay_ms(1.432);
                continue;
                break;
            case 0b00001000:
                __delay_ms(1.276);
                continue;
                break;
            case 0b00000100:
                __delay_ms(1.137);
                continue;
                break;
            case 0b00000010:
                __delay_ms(1.013);
                continue;
                break;
            case 0b00000001:
                __delay_ms(956);
                continue;
                break;
            default:
                TRISCbits.RC0=1;
                continue;
        }
    }
    return;
}
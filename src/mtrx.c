#include "../inc/mtrx.h"

void mtrxInit(void)
{
    DDRA = 0xFF;
    DDRD = 0xFF;
    DDRC = 0xFF;
}

void mtrxClear(void)
{
    PORTA = 0;
    PORTD = 0;
    PORTC = 0;
}

void mtrxPointWrite(uint8_t x, uint8_t y)
{
   PORTA = (1 << y);
   PORTD = (1 << x);
   PORTC = (1 << y);
   _delay_ms(1);
}

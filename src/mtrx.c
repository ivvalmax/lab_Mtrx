#include "../inc/mtrx.h"
#include "../inc/adc.h"

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
   if(x < 8)
   {
    PORTC = 0;
    PORTA = (1 << y);
    if(y < 8) PORTD = (x  << 4);
    else 
    {
        PORTD = (x+8 << 4);
        PORTA = (1 << y-8);
    }
   }
   else
    {
        PORTA = 0;
        PORTC = (1 << y);
    if(y < 8) PORTD = (x - 8 << 4);
    else 
    {
        PORTD = (x << 4);
        PORTC = (1 << y-8);
    }
   }

   

   _delay_ms(1);
}

void mtrxSnakeMove()
{
    uint8_t spd = 10;
    for(uint8_t i = 0; i < 16; i++)
    {
        for(uint8_t j = 0; j < 16; j++)
        {
            if(i%2 == 0) mtrxPointWrite(j, i);
            else mtrxPointWrite(15-j, i);

            spd = adcRead()/16;
            while(15-spd++) _delay_ms(30);
        }
           
    }
}

void mtrxTest(void){
    uint8_t x = 2;
    uint8_t y = adcRead()/16;
    PORTA = (1 << y);
    if(y < 8) PORTD = (x << 4);
    else 
    {
        PORTA = (1 << y-8);
        PORTD = (x+8 << 4);
    }

   _delay_ms(1);
}
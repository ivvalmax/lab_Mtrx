#include "inc/common.h"
#include "inc/mtrx.h"
#include "inc/adc.h"

void allInit(void);

int main(void)
{
    allInit();
    mtrxClear();

    uint8_t v = 0;

    while(1)
    {
        v = adcRead(2);
        v /= 32;
        mtrxPointWrite(0, v);
        _delay_ms(500);
    }
}


void allInit(void)
{
    mtrxInit();
    adcInit();

    sei();
}
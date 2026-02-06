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
        mtrxSnakeMove();
    }
}


void allInit(void)
{

    mtrxInit();
    adcInit();

    sei();
}
#ifndef ADC_H_
#define ADC_H_

#include "common.h"

void adcInit(void);
void adcStart(void);
uint8_t adcRead(uint8_t channel);

#endif
#include "../inc/adc.h"

uint16_t value = 0;

void adcInit(void)
{
  ADMUX = (1 << REFS0)|(1 << MUX0)|(1 << MUX1)|(1 << ADLAR);
  ADCSRA = (1 << ADIE)|(1 << ADEN)|(1 << ADFR);
}

void adcStart(void)
{
  ADCSRA |= (1 << ADSC);
}

uint8_t adcRead(uint8_t channel)
{
  adcStart();

  while(!(ADCSRA & (1<<ADIF)));
  ADCSRA |= (1 << ADIF);
  return(ADCH);
}

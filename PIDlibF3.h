#ifndef PIDlibF3_H
#define PIDlibF3_H

#include "stm32f30x.h"
#include "ENKlibF3.h"
#include "CANlibF3.h"
#include "PWMlibF3.h"

void setPID(void);

volatile uint8_t wzmocnienieP;
volatile uint16_t wzmocnienieI;
volatile uint8_t wzmocnienieK;

int16_t pidCalka1;
int16_t pidCalka2;
int16_t pidCalka3;

#endif

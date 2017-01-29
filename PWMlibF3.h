#ifndef PWMlibF3_H
#define PWMlibF3_H

#include "stm32f30x.h"
#include "CANlibF3.h"
#include "GPIOlibF3.h"
#include "PIDlibF3.h"




void setSpeed( int16_t predkosc1, int16_t predkosc2, int16_t predkosc3);
void stopMotors(void);
void startMotors(void);
void initPwm(void);

#endif

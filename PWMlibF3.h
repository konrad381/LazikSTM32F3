#ifndef PWMlibF3_H
#define PWMlibF3_H

#include "stm32f30x.h"
#include "CANlibF3.h"
#include "GPIOlibF3.h"



void setSpeed(uint8_t kierunek1, uint16_t predkosc1, uint8_t kierunek2,
		uint16_t predkosc2, uint8_t kierunek3, uint16_t predkosc3) ;
void stopMotors(void);
void initPwm(void);

#endif

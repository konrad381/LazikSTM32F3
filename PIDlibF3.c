#include "PIDlibF3.h"

volatile uint8_t wzmocnienieP = 105;
volatile uint16_t wzmocnienieI = 360;
volatile uint8_t wzmocnienieK = 1;

int16_t pidPredkosc1;
int16_t pidPredkosc2;
int16_t pidPredkosc3;

int16_t pidCalka1 = 0;
int16_t pidCalka2 = 0;
int16_t pidCalka3 = 0;

int16_t pidUchyb1 = 0;
int16_t pidUchyb2 = 0;
int16_t pidUchyb3 = 0;

int16_t pidNasycenie1 = 0;
int16_t pidNasycenie2 = 0;
int16_t pidNasycenie3 = 0;

void setPID(void) {

	pidUchyb1 = (zadPredkosc1*100 - enkPredkosc1);
	pidUchyb2 = (zadPredkosc2*100 - enkPredkosc2);
	pidUchyb3 = (zadPredkosc3*100 - enkPredkosc3);

	pidCalka1 += (pidUchyb1 - wzmocnienieK * pidNasycenie1);
	pidCalka2 += (pidUchyb2 - wzmocnienieK * pidNasycenie2);
	pidCalka3 += (pidUchyb3 - wzmocnienieK * pidNasycenie3);

	pidPredkosc1 = wzmocnienieP * (pidUchyb1 + (pidCalka1)/wzmocnienieI)/100;
	pidPredkosc2 = wzmocnienieP * (pidUchyb2 + (pidCalka2)/wzmocnienieI)/100;
	pidPredkosc3 = wzmocnienieP * (pidUchyb3 + (pidCalka3)/wzmocnienieI)/100;

	if (pidPredkosc1 > 10000) {
		pidNasycenie1 = pidPredkosc1 - 10000;
		pidPredkosc1 = 10000;
	} else if (pidPredkosc1 < -10000) {
		pidNasycenie1 = pidPredkosc1 + 10000;
		pidPredkosc1 = -10000;
	}
	if (pidPredkosc2 > 10000) {
		pidNasycenie2 = pidPredkosc2 - 10000;
		pidPredkosc2 = 10000;
	} else if (pidPredkosc2 < -10000) {
		pidNasycenie2 = pidPredkosc2 + 10000;
		pidPredkosc2 = -10000;
	}

	if (pidPredkosc3 > 10000) {
		pidNasycenie3 = pidPredkosc3 - 10000;
		pidPredkosc3 = 10000;
	} else if (pidPredkosc3 < -10000) {
		pidNasycenie3 = pidPredkosc3 + 10000;
		pidPredkosc3 = -10000;
	}

	setSpeed(pidPredkosc1, pidPredkosc2, pidPredkosc3);
}

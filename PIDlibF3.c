#include "PIDlibF3.h"

const int wzmocnienieP = 100;
const int wzmocnienieI = 3;

int16_t pidPredkosc1;
int16_t pidPredkosc2;
int16_t pidPredkosc3;

int16_t pidCalka1 = 0;
int16_t pidCalka2 = 0;
int16_t pidCalka3 = 0;

void setPID(void) {


	pidCalka1 += (zadPredkosc1 - enkPredkosc1);
	pidCalka2 += (zadPredkosc2 - enkPredkosc2);
	pidCalka3 += (zadPredkosc3 - enkPredkosc3);

	pidPredkosc1 = wzmocnienieP * (zadPredkosc1 - enkPredkosc1)
			+ wzmocnienieI * (pidCalka1);
	pidPredkosc2 = (zadPredkosc2 - enkPredkosc2) * wzmocnienieP+ wzmocnienieI * (pidCalka2);
	pidPredkosc3 = (zadPredkosc3 - enkPredkosc3) * wzmocnienieP+ wzmocnienieI * (pidCalka3);

//		pidPredkosc1=zadPredkosc1*100;
//		pidPredkosc2 =zadPredkosc2*100;
//		pidPredkosc3 = zadPredkosc3*100;

	if (pidPredkosc1 > 10000) {
		pidPredkosc1 = 10000;
	} else if (pidPredkosc1 < -10000) {
		pidPredkosc1 = -10000;
	}
	if (pidPredkosc2 > 10000) {
		pidPredkosc2 = 10000;
	} else if (pidPredkosc2 < -10000) {
		pidPredkosc2 = -10000;
	}

	if (pidPredkosc3 > 10000) {
		pidPredkosc3 = 10000;
	} else if (pidPredkosc3 < -10000) {
		pidPredkosc3 = -10000;
	}

	setSpeed(pidPredkosc1, pidPredkosc2, pidPredkosc3);
}

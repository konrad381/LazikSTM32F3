#include "main.h"
#include "CANlibF3.h"
#include "PWMlibF3.h"
#include "GPIOlibF3.h"
#include "ADClibF3.h"
#include "ENKlibF3.h"
#include "PIDlibF3.h"



static __IO uint32_t TimingDelay;
void Delay(__IO uint32_t nTime);
RCC_ClocksTypeDef RCC_Clocks;

//==================================================================================================
int main(void) {

	if (SysTick_Config(SystemCoreClock / 1000)) {
		while (1)
			;
	}
	initCan();
	initENK();
	initGpioMotors();
	initPwm();
	initADC();


	while (1) {

	}
}

//==================================================================================================
void Delay(__IO uint32_t nTime) {
	TimingDelay = nTime;

	while (TimingDelay != 0)
		;
}

void TimingDelay_Decrement(void) {
	if (TimingDelay != 0x00) {
		TimingDelay--;
	}
	setPID();
	sendParam();
}


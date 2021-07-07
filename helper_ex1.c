#include "NUC100Series.h"
#include "helper_ex1.h"
void Set_GPC12_output(void) {
	PC->PMD &= ~(0x03) << 24;
	PC->PMD |= (0x01) << 24;
}

void Turn_on_LED12(void) {
	PC->DOUT &= ~(0x01) << 12; //ON = 0
}

void Turn_off_LED12(void) {
	PC->DOUT |= (0x01) << 12; //OFF = 1
}

void Toggle_LED12(void) {
	PC->DOUT ^= (1 << 12);
}

#include "NUC100Series.h"
#define DELAY_PARAM 500000
#include "helper_ex1.h"
#include "misc.h"
int main(void) {
	Init_board();
	while (1) {
		Toggle_LED12();
		Delay_s(DELAY_PARAM);
	}
}

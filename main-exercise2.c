#include "NUC100Series.h"
#define DELAY_PARAM 500000
#include "helper_ex2.h"
#include "misc.h"
int main(void){
	Init_board();
	Set_output_mode_LEDs();
	while (1) {
		LED_chaser(DELAY_PARAM);
  }
}

#include "NUC100Series.h"
#include "helper_ex2.h"
#include "misc.h"

void LED_chaser(uint32_t delay) {
	uint8_t i;
       
  for (i = 0; i < 4; ++i) {
    PC -> DOUT ^= 1 << (12 + i);
    Delay_s(delay);
    PC -> DOUT ^= 1 << (12 + i);
    Delay_s(delay);
  }
}
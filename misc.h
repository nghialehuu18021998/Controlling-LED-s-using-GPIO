#ifndef __MISC__
#define __MISC__
#include "NUC100Series.h"               // Device header

void Delay_s(uint32_t count);
void Init_board();
void Set_output_mode_LEDs();
void Toggle_LED(int gpiopin);
void Set_output_mode_RGB();
void Set_bit_GPIOA(int pin_no);
void Clear_bit_GPIOA(int pin_no);
void Set_bit_value_GPIOA(int pin_no, int value);
void Toggle_GPIOA(int pin_no);
int32_t abs_i(int32_t i);
#endif

#include "helper_ex3.h"
#include "misc.h"
#include "helper_ex1.h"
#define STATE_ON 0
#define STATE_OFF 1
void Delay_ms(uint32_t count, int duty, int state) {
    if (state == STATE_ON) {
        count = count / 100 * duty;
    } else {
        count = count / 100 * (100 - duty);
    }
    Delay_s(count);
}
void Adv_adjust_brightness(void) {
    Init_board();
    Set_GPC12_output();
    while (1) {
        uint32_t i;
        for (i = 0; i <= 10000; i++) {
            Toggle_LED12();
            Delay_s(i);
            Toggle_LED12();
            Delay_s((10000 - i));
        }
        for (i = 10000; i > 0; i--) {
            Toggle_LED12();
            Delay_s(i);
            Toggle_LED12();
            Delay_s((10000 - i));
        }
    }
}
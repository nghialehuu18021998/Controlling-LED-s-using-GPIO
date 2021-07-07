#include "misc.h"
void Adv_chaser(void) {
    Init_board();
    Set_output_mode_LEDs();
    uint32_t j = 0;
    while (1) {
        uint32_t i;
        for (j = 0; j < 4; ++j) {
            for (i = 0; i <= 5000; i++) {
                Toggle_LED(12 + j);
                Delay_s(i);
                Toggle_LED(12 + j);
                Delay_s((5000 - i));
            }
            for (i = 5000; i > 0; i--) {
                Toggle_LED(12 + j);
                Delay_s(i);
                Toggle_LED(12 + j);
                Delay_s((5000 - i));
            }
        }
    }
}

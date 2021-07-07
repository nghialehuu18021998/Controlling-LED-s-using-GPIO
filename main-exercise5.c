#include "NUC100Series.h"

#include "helper_ex3.h"
#include "helper_ex1.h"
#include "helper_ex4.h"
#include "misc.h"

#define DELAY 10000

int main(void) {
    Init_board();
    Set_output_mode_RGB();

   int STATES[8][3] = {
        {
            0,
            0,
            0
        },
        {
            0,
            0,
            1
        },
        {
            0,
            1,
            0
        },
        {
            0,
            1,
            1
        },
        {
            1,
            0,
            0
        },
        {
            1,
            0,
            1
        },
        {
            1,
            1,
            0
        },
        {
            1,
            1,
            1
        }
    };
	while (1) {
		uint32_t i, j;
        for (i = 0; i < 8; i++) {
            //Clear bit first
            for (j = 0; j < 3; j++)
                if (!STATES[i][j]) Set_bit_value_GPIOA(12 + j, 0);
            //Then set bit later
            for (j = 0; j < 3; j++)
                if (STATES[i][j]) Set_bit_value_GPIOA(12 + j, 1);
			
			int32_t m, n, p;
			for (m= DELAY * -1; abs_i(m) < DELAY + 1; m++){
				if (!STATES[i][0]) {
					Toggle_GPIOA(12);
					Delay_s(DELAY - abs_i(m));
					Toggle_GPIOA(12);
					Delay_s(abs_i(m));
				}
				for (n= DELAY * -1; abs_i(n) < DELAY + 1; n++){
					if (!STATES[i][1]) {
						Toggle_GPIOA(13);
						Delay_s(DELAY - abs_i(n));
						Toggle_GPIOA(13);
						Delay_s(abs_i(n));
					}
					for (p= DELAY * -1; abs_i(p) < DELAY + 1; p++){
						if (!STATES[i][2]) {
							Toggle_GPIOA(14);
							Delay_s(DELAY - abs_i(p));
							Toggle_GPIOA(14);
							Delay_s(abs_i(p));
						}
						if (STATES[i][2]) break; //If LED 14 is off 
					}
					if (STATES[i][1]) break; //If LED 13 is OFF
				}
				if (STATES[i][0]) break;// If LED 14 is off
			}
			Delay_s(5000000);
        }
    }

}
#include "misc.h"
#include "NUC100Series.h"               // Device header
#define HXT_CLK 1ul<<0
#define CLK_SEL_MASK (~(0x07ul << 0))
#define PLL_CLK_SEL 0x02ul
#define HXT_STATUS 1ul<<0
#define PLL_STATUS 1ul<<2
#define PLLCON_FB_DV_MASK (~(0x01FFul << 0))
#define PLLCON_FB_DV_VAL 46
#define CPUCLOCKDIVIDE 1
void Delay_s(uint32_t count) {
	uint32_t n;
	for (n = 0; n < count; n++) {
	}
}

void Init_board() {
	SYS_UnlockReg(); // Unlock protected registers
	//Enable clock sources
	//HXT - External High frequency Crystal 12 MHz 
	CLK -> PWRCON |= HXT_CLK;
	while (!(CLK -> CLKSTATUS & HXT_STATUS));
	
	//PLL configuration starts
	CLK -> PLLCON &= ~(1ul << 19); // PLL input is HXT 12MHz (default)
	CLK -> PLLCON &= ~(1ul << 16); // PLL in normal mode
	CLK -> PLLCON &= PLLCON_FB_DV_MASK;
	/* frequency: 1 MHz * (PLLCON_FB_DV_VAL+2) */
	CLK -> PLLCON |= PLLCON_FB_DV_VAL; 
	CLK -> PLLCON &= ~(1ul << 18); // Enable PLL clock out
	while (!(CLK -> CLKSTATUS & PLL_STATUS));
	//PLL configuration ends

	//clock source selection 
	CLK -> CLKSEL0 &= CLK_SEL_MASK;
	CLK -> CLKSEL0 |= PLL_CLK_SEL;

	//clock frequency division 
	CLK -> CLKDIV &= ~0x0Ful;
	CLK -> CLKDIV |= (CPUCLOCKDIVIDE - 1);
	
	
	SYS_LockReg(); // Lock protected registers
}

void Toggle_LED(int gpiopin) {
	PC->DOUT ^= (1 << gpiopin);
}

void Set_output_mode_LEDs() {
	PC -> PMD &= ~(0xFFul) << 24;
  PC -> PMD |= (0x55ul) << 24;
}

void Set_output_mode_RGB() {
	PA -> PMD &= ~(0xFFul) << 24;
	PA -> PMD |= (0x55ul) << 24;
}

void Set_bit_GPIOA(int pin_no) {
	PA->DOUT |= (0x01) << pin_no; //OFF = 1
}

void Clear_bit_GPIOA(int pin_no) {
	PA->DOUT &= ~(0x01) << pin_no; //ON = 0
}

void Set_bit_value_GPIOA(int pin_no, int value) {
	if (value == 0) {
		Clear_bit_GPIOA(pin_no);
	} else {
		Set_bit_GPIOA(pin_no);
	}
}

void Toggle_GPIOA(int pin_no) {
	PA -> DOUT ^= 1 << pin_no;
}

int32_t abs_i(int32_t i) {
	return (i >= 0) ? i : (i * -1);
}

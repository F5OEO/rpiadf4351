#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <getopt.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/spi/spidev.h>

#include "adf4351.h"

adf4350_init_param MyAdf=
{.clkin=10000000,
.channel_spacing=5000,
.power_up_frequency=437000000,
.reference_div_factor=0,
.reference_doubler_enable=0,
.reference_div2_enable=0,

	// r2_user_settings 
.phase_detector_polarity_positive_enable=1,
.lock_detect_precision_6ns_enable=0,
.lock_detect_function_integer_n_enable=0,
.charge_pump_current=7, // FixMe
.muxout_select=0,
.low_spur_mode_enable=1,

	// r3_user_settings 
.cycle_slip_reduction_enable=1,
.charge_cancellation_enable=0,
.anti_backlash_3ns_enable=0,
.band_select_clock_mode_high_enable=1,
.clk_divider_12bit=0,
.clk_divider_mode=0,

	// r4_user_settings 
.aux_output_enable=1,
.aux_output_fundamental_enable=1,
.mute_till_lock_enable=0,
.output_power=0,//-4dbm
.aux_output_power=0

};
uint32_t registers[6] =  {0x4580A8, 0x80080C9, 0x4E42, 0x4B3, 0xBC803C, 0x580005};
//REG 0
//REG1 1000000000001000000011001 001
//REG2 100111001000 010
//REG3 10010110 011
//REG4 101111001000000000111 100

int main()
{
	adf4350_setup(0,0,MyAdf);
	adf4350_out_altvoltage0_frequency(437000000);
	int i;
	/*for(i=0;i<10000;i++)
	{
		adf4350_out_altvoltage0_frequency(437000000+i*5000);
		usleep(100000);
	}*/
	return 0;
}

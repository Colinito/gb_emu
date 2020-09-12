#include "cpu.h"
#include "mem.h"
#include "bus.h"

int main(int argc, char *argv[])
{

	struct cpu cpu;
	struct bus bus;

	init_cpu(&cpu, &bus);
	//init_gamepad(&bus);
	//init_video(&bus);

	// This loop will likely need to be controlled by some timing so the CPU doesn't run
	// way too fast.
	while (1)
	{
		// Get input

		// Run the CPU for one "cycle"
		cycle(&cpu);

		// Do sound
		//sound();

		// Render video to the emulated display
		//render(&video);
	}

	destroy_cpu(&cpu);
	return 0;
}
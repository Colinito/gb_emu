#include <stdio.h>
#include "bus.h"
#include "cpu.h"
#include "regfile.h"
#include "instructions.h"


extern instrs;

void init_cpu(struct cpu *cpu, struct bus *bus)
{
	cpu->regfile = (struct regs *) malloc(sizeof(struct regs));
	init_regfile(cpu->regfile);

	cpu->bus = bus;
	cpu->instrs = instrs;

	cpu->clk = 0;
}

void destroy_cpu(struct cpu *cpu)
{
	free(cpu->regfile);
}

void cycle(struct cpu *cpu)
{
			uint8_t byte = read_byte(cpu->bus, cpu->regfile->PC);
			struct ins inst = cpu->instrs[byte];
			switch(inst.itype)
			{
				case R:
					inst.operation(inst.dest, inst.src);
					break;
				case I8:
					inst.operation(inst.dest, read_byte(cpu->bus, cpu->regfile->PC + 1));
					break;
				case I16:
					inst.operation(inst.dest, read_byte(cpu->bus, cpu->regfile->PC + 1));
					break;
				case M8:
					break;
				case M16:
					break;
			}

			advance_PC(cpu->regfile, inst.bytes);
			cpu->clk += inst.cycles;
}



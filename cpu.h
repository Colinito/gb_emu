#ifndef CPU_H
#define CPU_H

#include "bus.h"
#include "regfile.h"
#include "instructions.h"


struct cpu
{
	struct regs *regfile;
	struct bus *bus;


	// The number of clock cycles that have been executed on this CPU
    unsigned int clk;


	// Instruction table
	struct ins *instrs;
};


void init_cpu(struct cpu *cpu, struct bus *bus);
void destroy_cpu(struct cpu *cpu);

void cycle(struct cpu *cpu);


#endif
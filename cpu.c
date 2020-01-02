struct regs regfile = {0, 0, 0, 0, 0, 0, 0};

struct ins instrs[][] =
{
	{0}
};

// IF op starts with CB...
// advance PC by 1 and get actual opcode
struct ins instrs_CB[][] =
{
	{0}
};


void nop(uint16_t *dest, uint16_t src)
{
	regfile->clock += cycles;
	regfile->PC += bytes;
}

void ld(uint16_t *dest, uint16_t src)
{
	return;
}

void add(uint16_t *dest, uint16_t src)
{
	return;
}

void adc(uint16_t *dest, uint16_t src)
{
	return;
}

void sub(uint16_t *dest, uint16_t src)
{
	return;
}

void sbc(uint16_t *dest, uint16_t src)
{
	return;
}

void and(uint16_t *dest, uint16_t src)
{
	return;
}

void or(uint16_t *dest, uint16_t src)
{
	return;
}

void xor(uint16_t *dest, uint16_t src)
{
	return;
}

void cp(uint16_t *dest, uint16_t src)
{
	return;
}

void cpl(uint16_t *dest, uint16_t src)
{
	return;
}

void ccf(uint16_t *dest, uint16_t src)
{
	return;
}

void inc(uint16_t *dest, uint16_t src)
{
	return;
}

void dec(uint16_t *dest, uint16_t src)
{
	return;
}

void push(uint16_t *dest, uint16_t src)
{
	return;
}

void pop(uint16_t *dest, uint16_t src)
{
	return;
}

void jp(uint16_t *dest, uint16_t src)
{
	return;
}

void jr(uint16_t *dest, uint16_t src)
{
	return;
}

void rlca(uint16_t *dest, uint16_t src)
{
	return;
}

void rla(uint16_t *dest, uint16_t src)
{
	return;
}

void rrca(uint16_t *dest, uint16_t src)
{
	return;
}

void rpa(uint16_t *dest, uint16_t src)
{
	return;
}

void daa(uint16_t *dest, uint16_t src)
{
	return;
}

void scf(uint16_t *dest, uint16_t src)
{
	return;
}

void halt(uint16_t *dest, uint16_t src)
{
	return;
}

void ret(uint16_t *dest, uint16_t src)
{
	return;
}

void reti(uint16_t *dest, uint16_t src)
{
	return;
}

void rst(uint16_t *dest, uint16_t src)
{
	return;
}

void call(uint16_t *dest, uint16_t src)
{
	return;
}

void di(uint16_t *dest, uint16_t src)
{
	return;
}

void ei(uint16_t *dest, uint16_t src)
{
	return;
}

void advance_PC(uint16_t *PC, unsigned int bytes)
{
	*PC += bytes;
}

void advance_clk(unsigned int *clk, unsigned int cycles)
{
	*clk += cycles;
}




#include <stdio.h>

// TODO: Set flags appropriately
void nop(struct regs *regfile, uint16_t *dest, uint16_t *src)
{
	return;
}

void ld(struct regs *regfile, uint16_t *dest, uint16_t *src)
{
	*dest = *src;
}

void ldi(struct regs *regfile, uint16_t *dest, uint16_t *src)
{
	*dest = *src;
	regfile->HL.HL++;
}

void ldd(struct regs *regfile, uint16_t *dest, uint16_t *src)
{
	*dest = *src;
	regfile->HL.HL--;
}

void add(struct regs *regfile, uint16_t *dest, uint16_t *src)
{
	*dest += *src;
}

void adc(struct regs *regfile, uint16_t *dest, uint16_t *src)
{
	return;
}

void sub(struct regs *regfile, uint16_t *dest, uint16_t *src)
{
	*dest -= *src;
}

void sbc(struct regs *regfile, uint16_t *dest, uint16_t *src)
{
	return;
}

void and(struct regs *regfile, uint16_t *dest, uint16_t *src)
{
	*dest &= *src;
}

void or(struct regs *regfile, uint16_t *dest, uint16_t *src)
{
	*dest |= *src;
}

void xor(struct regs *regfile, uint16_t *dest, uint16_t *src)
{
	*dest ^= *src;
}

//TODO: Finish implementing
void cp(struct regs *regfile, uint16_t *dest, uint16_t *src)
{
	uint16_t diff = *dest - *src;
	regfile->AF.bytes.F ^= (diff << 8);
	return;
}

void cpl(struct regs *regfile, uint16_t *dest, uint16_t *src)
{
	return;
}

void ccf(struct regs *regfile, uint16_t *dest, uint16_t *src)
{
	return;
}

void inc(struct regs *regfile, uint16_t *dest, uint16_t *src)
{
	*dest++;
}

void dec(struct regs *regfile, uint16_t *dest, uint16_t *src)
{
	*dest--;
}

void push(struct regs *regfile, uint16_t *dest, uint16_t *src)
{
	*dest = (uint8_t) (*src & 0x00ff);
	dest--; // Pointer math - move mem pointer down to store next byte
	*dest = (uint8_t) (*src >> 8);

	regfile->SP -= 2;
}

void pop(struct regs *regfile, uint16_t *dest, uint16_t *src)
{
	regfile->SP += 2;
	return;
}

void jp(struct regs *regfile, uint16_t *dest, uint16_t *src)
{
	*dest = *src;
	return;
}

void jr(struct regs *regfile, uint16_t *dest, uint16_t *src)
{
	return;
}

void rlca(struct regs *regfile, uint16_t *dest, uint16_t *src)
{
	return;
}

void rla(struct regs *regfile, uint16_t *dest, uint16_t *src)
{
	return;
}

void rrca(struct regs *regfile, uint16_t *dest, uint16_t *src)
{
	return;
}

void rpa(struct regs *regfile, uint16_t *dest, uint16_t *src)
{
	return;
}

void daa(struct regs *regfile, uint16_t *dest, uint16_t *src)
{
	return;
}

void scf(struct regs *regfile, uint16_t *dest, uint16_t *src)
{
	return;
}

void halt(struct regs *regfile, uint16_t *dest, uint16_t *src)
{
	return;
}

void ret(struct regs *regfile, uint16_t *dest, uint16_t *src)
{
	return;
}

void reti(struct regs *regfile, uint16_t *dest, uint16_t *src)
{
	return;
}

void rst(struct regs *regfile, uint16_t *dest, uint16_t *src)
{
	return;
}

void call(struct regs *regfile, uint16_t *dest, uint16_t *src)
{
	return;
}

void di(struct regs *regfile, uint16_t *dest, uint16_t *src)
{
	return;
}

void ei(struct regs *regfile, uint16_t *dest, uint16_t *src)
{
	return;
}

void invalid(struct regs *regfile, uint16_t *dest, uint16_t *src)
{
	printf("Error: invalid instruction\n");
}

//TODO: Split instructions into addressing modes
// scribble of how interpreter will work
void run()
{
	struct regs regfile = {0};

	// Setup instructions
	// TODO: Figure out how jump instructions will be handled
	struct ins instrs[] =
	{
		{1,	4,	R,	&nop,		0,		0},
		{3,	12,	I,	&ld,		BC,		u16},
		{1,	8,	M16,	&ld,		(BC),		A},
		{1,	8,	R,	&inc,		BC,		0},
		{1,	4,	R,	&inc,		B,		0},
		{1,	4,	R,	&dec,		B,		0},
		{2,	8,	R,	&ld,		B,		u8},
		{1,	4,	R,	&rlca,		0,		0},
		{3,	20,	R,	&ld,		(u16),		SP},
		{1,	8,	R,	&add,		HL,		BC},
		{1,	8,	R,	&ld,		A,		(BC)},
		{1,	8,	R,	&dec,		BC,		0},
		{1,	4,	R,	&inc,		C,		0},
		{1,	4,	R,	&dec,		C,		0},
		{2,	8,	R,	&ld,		C,		u8},
		{1,	4,	R,	&rrca,		0,		0},
		{2,	4,	R,	&stop,		0,		0},
		{3,	12,	R,	&ld,		DE,		u16},
		{1,	8,	R,	&ld,		(DE),		A},
		{1,	8,	R,	&inc,		DE,		0},
		{1,	4,	R,	&inc,		D,		0},
		{1,	4,	R,	&dec,		D,		0},
		{2,	8,	R,	&ld,		D,		u8},
		{1,	4,	R,	&rla,		0,		0},
		{2,	12,	R,	&jr,		i8,		0},
		{1,	8,	R,	&add,		HL,		DE},
		{1,	8,	R,	&ld,		A,		(DE)},
		{1,	8,	R,	&dec,		DE,		0},
		{1,	4,	R,	&inc,		E,		0},
		{1,	4,	R,	&dec,		E,		0},
		{2,	8,	R,	&ld,		E,		u8},
		{1,	4,	R,	&rra,		0,		0},
		{2,	12,	R,	&jr,		NZ,		i8},
		{3,	12,	R,	&ld,		HL,		u16},
		{1,	8,	R,	&ld,		(HL+),		A},
		{1,	8,	R,	&inc,		HL,		0},
		{1,	4,	R,	&inc,		H,		0},
		{1,	4,	R,	&dec,		H,		0},
		{2,	8,	R,	&ld,		H,		u8},
		{1,	4,	R,	&daa,		0,		0},
		{2,	12,	R,	&jr,		Z,		i8},
		{1,	8,	R,	&add,		HL,		HL},
		{1,	8,	R,	&ld,		A,		(HL+)},
		{1,	8,	R,	&dec,		HL,		0},
		{1,	4,	R,	&inc,		L,		0},
		{1,	4,	R,	&dec,		L,		0},
		{2,	8,	R,	&ld,		L,		u8},
		{1,	4,	R,	&cpl,		0,		0},
		{2,	12,	R,	&jr,		NC,		i8},
		{3,	12,	R,	&ld,		SP,		u16},
		{1,	8,	R,	&ld,		(HL-),		A},
		{1,	8,	R,	&inc,		SP,		0},
		{1,	12,	R,	&inc,		(HL),		0},
		{1,	12,	R,	&dec,		(HL),		0},
		{2,	12,	R,	&ld,		(HL),		u8},
		{1,	4,	R,	&scf,		0,		0},
		{2,	12,	R,	&jr,		C,		i8},
		{1,	8,	R,	&add,		HL,		SP},
		{1,	8,	R,	&ld,		A,		(HL-)},
		{1,	8,	R,	&dec,		SP,		0},
		{1,	4,	R,	&inc,		A,		0},
		{1,	4,	R,	&dec,		A,		0},
		{2,	8,	R,	&ld,		A,		u8},
		{1,	4,	R,	&ccf,		0,		0},
		{1,	4,	R,	&ld,		B,		B},
		{1,	4,	R,	&ld,		B,		C},
		{1,	4,	R,	&ld,		B,		D},
		{1,	4,	R,	&ld,		B,		E},
		{1,	4,	R,	&ld,		B,		H},
		{1,	4,	R,	&ld,		B,		L},
		{1,	8,	R,	&ld,		B,		(HL)},
		{1,	4,	R,	&ld,		B,		A},
		{1,	4,	R,	&ld,		C,		B},
		{1,	4,	R,	&ld,		C,		C},
		{1,	4,	R,	&ld,		C,		D},
		{1,	4,	R,	&ld,		C,		E},
		{1,	4,	R,	&ld,		C,		H},
		{1,	4,	R,	&ld,		C,		L},
		{1,	8,	R,	&ld,		C,		(HL)},
		{1,	4,	R,	&ld,		C,		A},
		{1,	4,	R,	&ld,		D,		B},
		{1,	4,	R,	&ld,		D,		C},
		{1,	4,	R,	&ld,		D,		D},
		{1,	4,	R,	&ld,		D,		E},
		{1,	4,	R,	&ld,		D,		H},
		{1,	4,	R,	&ld,		D,		L},
		{1,	8,	R,	&ld,		D,		(HL)},
		{1,	4,	R,	&ld,		D,		A},
		{1,	4,	R,	&ld,		E,		B},
		{1,	4,	R,	&ld,		E,		C},
		{1,	4,	R,	&ld,		E,		D},
		{1,	4,	R,	&ld,		E,		E},
		{1,	4,	R,	&ld,		E,		H},
		{1,	4,	R,	&ld,		E,		L},
		{1,	8,	R,	&ld,		E,		(HL)},
		{1,	4,	R,	&ld,		E,		A},
		{1,	4,	R,	&ld,		H,		B},
		{1,	4,	R,	&ld,		H,		C},
		{1,	4,	R,	&ld,		H,		D},
		{1,	4,	R,	&ld,		H,		E},
		{1,	4,	R,	&ld,		H,		H},
		{1,	4,	R,	&ld,		H,		L},
		{1,	8,	R,	&ld,		H,		(HL)},
		{1,	4,	R,	&ld,		H,		A},
		{1,	4,	R,	&ld,		L,		B},
		{1,	4,	R,	&ld,		L,		C},
		{1,	4,	R,	&ld,		L,		D},
		{1,	4,	R,	&ld,		L,		E},
		{1,	4,	R,	&ld,		L,		H},
		{1,	4,	R,	&ld,		L,		L},
		{1,	8,	R,	&ld,		L,		(HL)},
		{1,	4,	R,	&ld,		L,		A},
		{1,	8,	R,	&ld,		(HL),		B},
		{1,	8,	R,	&ld,		(HL),		C},
		{1,	8,	R,	&ld,		(HL),		D},
		{1,	8,	R,	&ld,		(HL),		E},
		{1,	8,	R,	&ld,		(HL),		H},
		{1,	8,	R,	&ld,		(HL),		L},
		{1,	4,	R,	&halt,		0,		0},
		{1,	8,	R,	&ld,		(HL),		A},
		{1,	4,	R,	&ld,		A,		B},
		{1,	4,	R,	&ld,		A,		C},
		{1,	4,	R,	&ld,		A,		D},
		{1,	4,	R,	&ld,		A,		E},
		{1,	4,	R,	&ld,		A,		H},
		{1,	4,	R,	&ld,		A,		L},
		{1,	8,	R,	&ld,		A,		(HL)},
		{1,	4,	R,	&ld,		A,		A},
		{1,	4,	R,	&add,		A,		B},
		{1,	4,	R,	&add,		A,		C},
		{1,	4,	R,	&add,		A,		D},
		{1,	4,	R,	&add,		A,		E},
		{1,	4,	R,	&add,		A,		H},
		{1,	4,	R,	&add,		A,		L},
		{1,	8,	R,	&add,		A,		(HL)},
		{1,	4,	R,	&add,		A,		A},
		{1,	4,	R,	&adc,		A,		B},
		{1,	4,	R,	&adc,		A,		C},
		{1,	4,	R,	&adc,		A,		D},
		{1,	4,	R,	&adc,		A,		E},
		{1,	4,	R,	&adc,		A,		H},
		{1,	4,	R,	&adc,		A,		L},
		{1,	8,	R,	&adc,		A,		(HL)},
		{1,	4,	R,	&adc,		A,		A},
		{1,	4,	R,	&sub,		A,		B},
		{1,	4,	R,	&sub,		A,		C},
		{1,	4,	R,	&sub,		A,		D},
		{1,	4,	R,	&sub,		A,		E},
		{1,	4,	R,	&sub,		A,		H},
		{1,	4,	R,	&sub,		A,		L},
		{1,	8,	R,	&sub,		A,		(HL)},
		{1,	4,	R,	&sub,		A,		A},
		{1,	4,	R,	&sbc,		A,		B},
		{1,	4,	R,	&sbc,		A,		C},
		{1,	4,	R,	&sbc,		A,		D},
		{1,	4,	R,	&sbc,		A,		E},
		{1,	4,	R,	&sbc,		A,		H},
		{1,	4,	R,	&sbc,		A,		L},
		{1,	8,	R,	&sbc,		A,		(HL)},
		{1,	4,	R,	&sbc,		A,		A},
		{1,	4,	R,	&and,		A,		B},
		{1,	4,	R,	&and,		A,		C},
		{1,	4,	R,	&and,		A,		D},
		{1,	4,	R,	&and,		A,		E},
		{1,	4,	R,	&and,		A,		H},
		{1,	4,	R,	&and,		A,		L},
		{1,	8,	R,	&and,		A,		(HL)},
		{1,	4,	R,	&and,		A,		A},
		{1,	4,	R,	&xor,		A,		B},
		{1,	4,	R,	&xor,		A,		C},
		{1,	4,	R,	&xor,		A,		D},
		{1,	4,	R,	&xor,		A,		E},
		{1,	4,	R,	&xor,		A,		H},
		{1,	4,	R,	&xor,		A,		L},
		{1,	8,	R,	&xor,		A,		(HL)},
		{1,	4,	R,	&xor,		A,		A},
		{1,	4,	R,	&or,		A,		B},
		{1,	4,	R,	&or,		A,		C},
		{1,	4,	R,	&or,		A,		D},
		{1,	4,	R,	&or,		A,		E},
		{1,	4,	R,	&or,		A,		H},
		{1,	4,	R,	&or,		A,		L},
		{1,	8,	R,	&or,		A,		(HL)},
		{1,	4,	R,	&or,		A,		A},
		{1,	4,	R,	&cp,		A,		B},
		{1,	4,	R,	&cp,		A,		C},
		{1,	4,	R,	&cp,		A,		D},
		{1,	4,	R,	&cp,		A,		E},
		{1,	4,	R,	&cp,		A,		H},
		{1,	4,	R,	&cp,		A,		L},
		{1,	8,	R,	&cp,		A,		(HL)},
		{1,	4,	R,	&cp,		A,		A},
		{1,	20,	R,	&ret,		NZ,		0},
		{1,	12,	R,	&pop,		BC,		0},
		{3,	16,	R,	&jp,		NZ,		u16},
		{3,	16,	R,	&jp,		u16,		0},
		{3,	24,	R,	&call,		NZ,		u16},
		{1,	16,	R,	&push,		BC,		0},
		{2,	8,	R,	&add,		A,		u8},
		{1,	16,	R,	&rst,		00h,		0},
		{1,	20,	R,	&ret,		Z,		0},
		{1,	16,	R,	&ret,		0,		0},
		{3,	16,	R,	&jp,		Z,		u16},
		{1,	4,	R,	&prefix,	CB,		0},
		{3,	24,	R,	&call,		Z,		u16},
		{3,	24,	R,	&call,		u16,		0},
		{2,	8,	R,	&adc,		A,		u8},
		{1,	16,	R,	&rst,		08h,		0},
		{1,	20,	R,	&ret,		NC,		0},
		{1,	12,	R,	&pop,		DE,		0},
		{3,	16,	R,	&jp,		NC,		u16},
		{1,	0,	R,	&invalid,	0,		0},
		{3,	24,	R,	&call,		NC,		u16},
		{1,	16,	R,	&push,		DE,		0},
		{2,	8,	R,	&sub,		A,		u8},
		{1,	16,	R,	&rst,		10h,		0},
		{1,	20,	R,	&ret,		C,		0},
		{1,	16,	R,	&reti,		0,		0},
		{3,	16,	R,	&jp,		C,		u16},
		{1,	0,	R,	&invalid,	0,		0},
		{3,	24,	R,	&call,		C,		u16},
		{1,	0,	R,	&invalid,	0,		0},
		{2,	8,	R,	&sbc,		A,		u8},
		{1,	16,	R,	&rst,		18h,		0},
		{2,	12,	R,	&ld,		(FF00+u8),	A},
		{1,	12,	R,	&pop,		HL,		0},
		{1,	8,	R,	&ld,		(FF00+C),	A},
		{1,	0,	R,	&invalid,	0,		0},
		{1,	0,	R,	&invalid,	0,		0},
		{1,	16,	R,	&push,		HL,		0},
		{2,	8,	R,	&and,		A,		u8},
		{1,	16,	R,	&rst,		20h,		0},
		{2,	16,	R,	&add,		SP,		i8},
		{1,	4,	R,	&jp,		HL,		0},
		{3,	16,	R,	&ld,		(u16),		A},
		{1,	0,	R,	&invalid,	0,		0},
		{1,	0,	R,	&invalid,	0,		0},
		{1,	0,	R,	&invalid,	0,		0},
		{2,	8,	R,	&xor,		A,		u8},
		{1,	16,	R,	&rst,		28h,		0},
		{2,	12,	R,	&ld,		A,		(FF00+u8)},
		{1,	12,	R,	&pop,		AF,		0},
		{1,	8,	R,	&ld,		A,		(FF00+C)},
		{1,	4,	R,	&di,		0,		0},
		{1,	0,	R,	&invalid,	0,		0},
		{1,	16,	R,	&push,		AF,		0},
		{2,	8,	R,	&or,		A,		u8},
		{1,	16,	R,	&rst,		30h,		0},
		{2,	12,	R,	&ld,		HL,		SP+i8},
		{1,	8,	R,	&ld,		SP,		HL},
		{3,	16,	R,	&ld,		A,		(u16)},
		{1,	4,	R,	&ei,		0,		0},
		{1,	0,	R,	&invalid,	0,		0},
		{1,	0,	R,	&invalid,	0,		0},
		{2,	8,	R,	&cp,		A,		u8},
		{1,	16,	R,	&rst,		38h,		0},
	};
	// IF op starts with CB...
	// advance PC by 1 and get actual opcode
	//struct ins instrs_CB[][] =
	//{
		//{0}
	//};
	//

	if (byte == 0xcb)
	{
		// Do CB prefixed instructions
	}
	else
	{
		// Interpreter
		while(1)
		{
			uint8_t byte = read_byte(regfile.PC);
			struct ins inst = instrs[byte];
			switch(inst.itype)
			{
				case R:
					inst.operation(inst.dest, inst.src);
					break;
				case I8:
					inst.operation(inst.dest, read_byte(PC+1));
					break;
				case I16:
					inst.operation(inst.dest, read_byte(PC+1));
					break;
				case M8:
					break;
				case M16:
					break;
			}

			// Update PC and clock registers
			regfile.PC += inst.bytes;
			regfile.clk += inst.cycles;
		}
	}
}


struct ins instrs[][] =
{

};

// IF op starts with CB...
// advance PC by 1 and get actual opcode
struct ins instrs_CB[][] =
{
	{0}
};


static void nop(struct regs *regfile, unsigned int bytes, unsigned int cycles,
		enum operand opA, enum operand opB)
{
	regfile->clock += cycles;
	regfile->PC += bytes;
}

static void ld(struct regs *regfile, unsigned int bytes, unsigned int cycles,
		enum operand opA, enum operand opB)
{
	int16_t *dest;
	int16_t *source;

	// Decode operands
	switch(opB)
	{
		case AF:
			source = regfile->AF;
			break;
		case BC:
			source = regfile->BC;
			break;
		case DE:
			source = regfile->DE;
			break;
		case HL:
			source = regfile->HL;
			break;
		case SP:
			source = regfile->SP;
			break;
		case PC:
			source = regfile->PC;
			break;
		case A:
			source = regfile->A;
			break;
		case F:
			source = regfile->F;
			break;
		case B:
			source = regfile->B;
			break;
		case C:
			source = regfile->C;
			break;
		case D:
			source = regfile->D;
			break;
		case E:
			source = regfile->E;
			break;
		case H:
			source = regfile->H;
			break;
		case L:
			source = regfile->L;
			break;
		imm8:
			source = read_byte(PC + 1);
			break;
		imm16:
			source = ((int16_t) (read_byte(PC + 2) << 8)) +
				read_byte(PC + 1);
			break;
		default:
			break;
	}

	switch(opA)
	{
		case AF:
			break;
		case BC:
			break;
		case DE:
			break;
		case HL:
			break;
		case SP:
			break;
		case PC:
			break;
		case A:
			break;
		case F:
			break;
		case B:
			break;
		case C:
			break;
		case D:
			break;
		case E:
			break;
		case H:
			break;
		case L:
			break;
		imm:
			break;
		default:
			break;
	}


	*opA = (*opA & maskA) | (opB & maskB);
	*clock += cycles;
	*PC += bytes;
}

static void add(struct regs *regfile, unsigned int bytes, unsigned int cycles,
		enum operand opA, enum operand opB)
{
	return;
}

static void adc(struct regs *regfile, unsigned int bytes, unsigned int cycles,
		enum operand opA, enum operand opB)
{
	return;
}

static void sub(struct regs *regfile, unsigned int bytes, unsigned int cycles,
		enum operand opA, enum operand opB)
{
	return;
}

static void sbc(struct regs *regfile, unsigned int bytes, unsigned int cycles,
		enum operand opA, enum operand opB)
{
	return;
}

static void and(struct regs *regfile, unsigned int bytes, unsigned int cycles,
		enum operand opA, enum operand opB)
{
	return;
}

static void or(struct regs *regfile, unsigned int bytes, unsigned int cycles,
		enum operand opA, enum operand opB)
{
	return;
}

static void xor(struct regs *regfile, unsigned int bytes, unsigned int cycles,
		enum operand opA, enum operand opB)
{
	return;
}

static void cp(struct regs *regfile, unsigned int bytes, unsigned int cycles,
		enum operand opA, enum operand opB)
{
	return;
}

static void cpl(struct regs *regfile, unsigned int bytes, unsigned int cycles,
		enum operand opA, enum operand opB)
{
	return;
}

static void ccf(struct regs *regfile, unsigned int bytes, unsigned int cycles,
		enum operand opA, enum operand opB)
{
	return;
}

static void inc(struct regs *regfile, unsigned int bytes, unsigned int cycles,
		enum operand opA, enum operand opB)
{
	return;
}

static void dec(struct regs *regfile, unsigned int bytes, unsigned int cycles,
		enum operand opA, enum operand opB)
{
	return;
}

static void push(struct regs *regfile, unsigned int bytes, unsigned int cycles,
		enum operand opA, enum operand opB)
{
	return;
}

static void pop(struct regs *regfile, unsigned int bytes, unsigned int cycles,
		enum operand opA, enum operand opB)
{
	return;
}

static void jp(struct regs *regfile, unsigned int bytes, unsigned int cycles,
		enum operand opA, enum operand opB)
{
	return;
}

static void jr(struct regs *regfile, unsigned int bytes, unsigned int cycles,
		enum operand opA, enum operand opB)
{
	return;
}

static void rlca(struct regs *regfile, unsigned int bytes, unsigned int cycles,
		enum operand opA, enum operand opB)
{
	return;
}

static void rla(struct regs *regfile, unsigned int bytes, unsigned int cycles,
		enum operand opA, enum operand opB)
{
	return;
}

static void rrca(struct regs *regfile, unsigned int bytes, unsigned int cycles,
		enum operand opA, enum operand opB)
{
	return;
}

static void rpa(struct regs *regfile, unsigned int bytes, unsigned int cycles,
		enum operand opA, enum operand opB)
{
	return;
}

static void daa(struct regs *regfile, unsigned int bytes, unsigned int cycles,
		enum operand opA, enum operand opB)
{
	return;
}

static void scf(struct regs *regfile, unsigned int bytes, unsigned int cycles,
		enum operand opA, enum operand opB)
{
	return;
}

static void halt(struct regs *regfile, unsigned int bytes, unsigned int cycles,
		enum operand opA, enum operand opB)
{
	return;
}

static void ret(struct regs *regfile, unsigned int bytes, unsigned int cycles,
		enum operand opA, enum operand opB)
{
	return;
}

static void reti(struct regs *regfile, unsigned int bytes, unsigned int cycles,
		enum operand opA, enum operand opB)
{
	return;
}

static void rst(struct regs *regfile, unsigned int bytes, unsigned int cycles,
		enum operand opA, enum operand opB)
{
	return;
}

static void call(struct regs *regfile, unsigned int bytes, unsigned int cycles,
		enum operand opA, enum operand opB)
{
	return;
}

static void di(struct regs *regfile, unsigned int bytes, unsigned int cycles,
		enum operand opA, enum operand opB)
{
	return;
}

static void ei(struct regs *regfile, unsigned int bytes, unsigned int cycles,
		enum operand opA, enum operand opB)
{
	return;
}

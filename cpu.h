/* Register file */
struct regs
{
	int16_t AF;
	int16_t BC;
	int16_t DE;
	int16_t HL;
	int16_t SP;
	int16_t PC;
	unsigned int clock;
};

/* Operands grouped in 16-bit and 8-bit */
enum operand {AF, BC, DE, HL, SP, PC, A, F, B, C, D, E, H, L, imm8, imm16}

static int8_t read_byte(uint8_t addr); // Get a byte from memory at address

/* Define Opcodes */
static void nop(struct regs *regfile, unsigned int bytes, unsigned int cycles,
		enum operand opA, enum operand opB);

static void ld(struct regs *regfile, unsigned int bytes, unsigned int cycles,
		enum operand opA, enum operand opB);

static void add(struct regs *regfile, unsigned int bytes, unsigned int cycles,
		enum operand opA, enum operand opB);

static void adc(struct regs *regfile, unsigned int bytes, unsigned int cycles,
		enum operand opA, enum operand opB);

static void sub(struct regs *regfile, unsigned int bytes, unsigned int cycles,
		enum operand opA, enum operand opB);

static void sbc(struct regs *regfile, unsigned int bytes, unsigned int cycles,
		enum operand opA, enum operand opB);

static void and(struct regs *regfile, unsigned int bytes, unsigned int cycles,
		enum operand opA, enum operand opB);

static void or(struct regs *regfile, unsigned int bytes, unsigned int cycles,
		enum operand opA, enum operand opB);

static void xor(struct regs *regfile, unsigned int bytes, unsigned int cycles,
		enum operand opA, enum operand opB);

static void cp(struct regs *regfile, unsigned int bytes, unsigned int cycles,
		enum operand opA, enum operand opB);

static void cpl(struct regs *regfile, unsigned int bytes, unsigned int cycles,
		enum operand opA, enum operand opB);

static void ccf(struct regs *regfile, unsigned int bytes, unsigned int cycles,
		enum operand opA, enum operand opB);

static void inc(struct regs *regfile, unsigned int bytes, unsigned int cycles,
		enum operand opA, enum operand opB);

static void dec(struct regs *regfile, unsigned int bytes, unsigned int cycles,
		enum operand opA, enum operand opB);

static void push(struct regs *regfile, unsigned int bytes, unsigned int cycles,
		enum operand opA, enum operand opB);

static void pop(struct regs *regfile, unsigned int bytes, unsigned int cycles,
		enum operand opA, enum operand opB);

static void jp(struct regs *regfile, unsigned int bytes, unsigned int cycles,
		enum operand opA, enum operand opB);

static void jr(struct regs *regfile, unsigned int bytes, unsigned int cycles,
		enum operand opA, enum operand opB);

static void rlca(struct regs *regfile, unsigned int bytes, unsigned int cycles,
		enum operand opA, enum operand opB);

static void rla(struct regs *regfile, unsigned int bytes, unsigned int cycles,
		enum operand opA, enum operand opB);

static void rrca(struct regs *regfile, unsigned int bytes, unsigned int cycles,
		enum operand opA, enum operand opB);

static void rpa(struct regs *regfile, unsigned int bytes, unsigned int cycles,
		enum operand opA, enum operand opB);

static void daa(struct regs *regfile, unsigned int bytes, unsigned int cycles,
		enum operand opA, enum operand opB);

static void scf(struct regs *regfile, unsigned int bytes, unsigned int cycles,
		enum operand opA, enum operand opB);

static void halt(struct regs *regfile, unsigned int bytes, unsigned int cycles,
		enum operand opA, enum operand opB);

static void ret(struct regs *regfile, unsigned int bytes, unsigned int cycles,
		enum operand opA, enum operand opB);

static void reti(struct regs *regfile, unsigned int bytes, unsigned int cycles,
		enum operand opA, enum operand opB);

static void rst(struct regs *regfile, unsigned int bytes, unsigned int cycles,
		enum operand opA, enum operand opB);

static void call(struct regs *regfile, unsigned int bytes, unsigned int cycles,
		enum operand opA, enum operand opB);

static void di(struct regs *regfile, unsigned int bytes, unsigned int cycles,
		enum operand opA, enum operand opB);

static void ei(struct regs *regfile, unsigned int bytes, unsigned int cycles,
		enum operand opA, enum operand opB);

/* instruction struct
 *
 * Only a few parameters differentiate most of the GameBoy's main instructions.
 * Pre-defining these parameters in a table simplifies instruction decoding and
 * maximizes code re-use as only a few instructions need to be actually
 * implemented.
 *
 * Example:
 * 	The GameBoy opcode table is composed of a lot of ld instructions. The
 * 	instruction has the following syntax:
 * 		ld dest, source.
 *	
 *	The dest and source registers or memory addresses are baked into the
 *	opcode. Consider the following 2 instructions:
 *		1. ld A, B
 *		2. ld BC, D
 *
 *	The ld instruction does basically the same operation in both examples;
 *	only the arguments are different. The same applies for other arithmetic
 *	and logical instructions. It is much simpler to create a generic
 *	instruction whose final operation is determined by its arguments.
 */
struct ins
{
	// Operation args
	struct regs *regfile; // Register file
	unsigned int bytes, cycles; // Number of bytes and cycles required

	/* Operation to perform
	 *
	 * @bytes:	number of bytes instruction uses
	 * @cycles:	number of cycles instruction uses
	 * regfile:	pointer to system register file
	 * @opA:	first operand register
	 * @opB:	second operand register
	 */
	void (*operation) (unsigned int bytes, unsigned int cycles,
			struct regs *regfile, enum operand opA,
			enum operand opB)};

	// Operands are placed here to make opcode obvious when declaring
	// instructions
	enum operand opA, opB; // Operands to use
};


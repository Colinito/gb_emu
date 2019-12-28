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
	unsigned int bytes, cycles;
	unsigned int *clock;
	uint16_t *PC;
	uint16_t *opA; // Pointer to modifiable register
	uint16_t opB;  // Const register
	uint16_t maskA, maskB; // Masks to select hi, lo, or both bytes

	/* Operation to perform
	 *
	 * @bytes:	number of bytes instruction uses
	 * @cycles:	number of cycles instruction uses
	 * @clock:	clock cycle counter
	 * @PC:		program counter register
	 * @opA:	pointer to first operand register
	 * @maskA:	mask to select hi, lo, or all bytes for opA
	 * @opB:	second operand register
	 * @maskB:	mask to select hi, lo, or all bytes for opB
	 */
	void (*operation) (unsigned int bytes, unsigned int cycles,
		unsigned int *clock, uint16_t *PC, uint16_t *opA,
		uint16_t maskA, uint16_t opB, uint16_t maskB);
};


struct ins instrs[][]
{

};

// IF op starts with CB...
// advance PC by 1 and get actual opcode
struct ins instrs_CB[][]
{

};



/* Define Opcodes */
static void ld();





static void ldi();
static void ldd();
static void push();
static void pop();
static void add();
static void adc();
static void sub();
static void sbc();
static void and();
static void xor();
static void or();
static void cp();
static void inc();
static void dec();
static void daa();
static void cpl();
static void rlca();
static void rla();
static void rrca();
static void rra();
static void rlc();
static void rl();
static void rrc();
static void rr();
static void sla();
static void swap();
static void sra();
static void srl();
static void bit();
static void set();
static void res();
static void ccf();
static void scf();
static void nop();
static void halt();
static void stop();
static void di();
static void ei();
static void jp();
static void jr();
static void call();
static void ret();
static void reti();
static void rst();

static int8_t read_byte(uint8_t addr);
static void nop(int bytes, int cycles, int *arg_A, int *arg_B);



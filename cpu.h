/* CPU Registers */
struct regs
{
	static int8_t A, F;
	static int8_t B, C;
	static int8_t D, E;
	static int8_t H, L;
	static int16_t SP;		// Stack pointer
	static int16_t PC;		// Program counter
};

/*
struct reg_16 // 16-bit register composed of hi and lo bytes
{
	int8_t hi;
	int8_t lo;
}
*/

static int16_t AF;
static int16_t BC;
static int16_t DE;
static int16_t HL;
static int16_t SP;
static int16_t PC;

enum arg_regs {A, F, AF, B, C, BC, D, E, DE, H, L, HL, SP, PC};


struct ins
{
	unsigned int bytes;
	unsigned int cycles;
	void (*operation) (unsigned int bytes, unsigned int cycles,
			unsigned int operand_A, unsigned int operand_B);
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



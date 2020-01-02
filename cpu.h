/* Register file */
struct regs
{
    union {struct {uint8_t F, A;} bytes; uint16_t AF;} AF;
    union {struct {uint8_t C, B;} bytes; uint16_t BC;} BC;
    union {struct {uint8_t E, D;} bytes; uint16_t DE;} DE;
    union {struct {uint8_t L, H;} bytes; uint16_t HL;} HL;
    uint16_t SP;
    uint16_t PC;

    // The clock is not an actual register in the GameBoy, but it is added here
    // for timing and debugging.
    unsigned int clk;
};

int8_t read_byte(uint8_t addr); // Get a byte from memory at address
void advance_PC(struct regs *regfile, unsigned int bytes);
void advance_clk(struct regs *regfile, unsigned int cycles);

/* Define Opcodes 
 *
 * These are the core opcodes (non-CB prefixed). Not every single micro-
 * operation is listed here. Instead, these are higher abstractions of the
 * opcodes. For instance, there is no need to create a function to represent
 * ld A, B. Instead, it is implemented by a ld function that accepts source
 * and destination registers. Thus, it emulates all ld operations in just one
 * function.
 */
void nop(uint16_t *dest, uint16_t src);
void ld(uint16_t *dest, uint16_t src);
void add(uint16_t *dest, uint16_t src);
void adc(uint16_t *dest, uint16_t src);
void sub(uint16_t *dest, uint16_t src);
void sbc(uint16_t *dest, uint16_t src);
void and(uint16_t *dest, uint16_t src);
void or(uint16_t *dest, uint16_t src);
void xor(uint16_t *dest, uint16_t src);
void cp(uint16_t *dest, uint16_t src);
void cpl(uint16_t *dest, uint16_t src);
void ccf(uint16_t *dest, uint16_t src);
void inc(uint16_t *dest, uint16_t src);
void dec(uint16_t *dest, uint16_t src);
void push(uint16_t *dest, uint16_t src);
void pop(uint16_t *dest, uint16_t src);
void jp(uint16_t *dest, uint16_t src);
void jr(uint16_t *dest, uint16_t src);
void rlca(uint16_t *dest, uint16_t src);
void rla(uint16_t *dest, uint16_t src);
void rrca(uint16_t *dest, uint16_t src);
void rpa(uint16_t *dest, uint16_t src);
void daa(uint16_t *dest, uint16_t src);
void scf(uint16_t *dest, uint16_t src);
void halt(uint16_t *dest, uint16_t src);
void ret(uint16_t *dest, uint16_t src);
void reti(uint16_t *dest, uint16_t src);
void rst(uint16_t *dest, uint16_t src);
void call(uint16_t *dest, uint16_t src);
void di(uint16_t *dest, uint16_t src);
void ei(uint16_t *dest, uint16_t src);

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
	unsigned int bytes, cycles; // Number of bytes and cycles required

	/* Operation to perform
	 *
	 * @dest:	destination register
	 * @src:	source register or immediate
	 */
	void (*operation) (uint16_t *dest, uint16_t src);

	uint16_t *dest; // Destination register
	uint16_t src;	// Source register
};

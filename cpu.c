/* CPU Registers */
static int16_t AF; // Accumulator/Flags
static int16_t BC;
static int16_t DE;
static int16_t HL;
static int16_t SP; // Stack pointer
static int16_t PC; // Program counter

/* ld
 *
 * Loads value from second operand register into first operand register.
 */
static void *ld(unsigned int bytes, unsigned int cycles, unsigned int *clock,
		uint16_t *PC, uint16_t *opA, uint16_t maskA, uint16_t opB,
		uint16_t maskB)
{
	*opA = (*opA & maskA) | (opB & maskB);
	*clock += cycles;
	*PC += bytes;
}

/* add
 *
 * Adds operands A and B together and stores the result in A.
 */
/*
static void *add(unsigned int bytes, unsigned int cycles, unsigned int *clock,
		uint16_t *PC, uint16_t *opA, uint16_t maskA, uint16_t opB,
		uint16_t maskB)
{
	*opA = (*opA & maskA) | (opB & maskB);
	*clock += cycles;
	*PC += bytes;
}
*/

static void *nop(unsigned int bytes, unsigned int cycles, unsigned int *clock,
		uint16_t *PC, uint16_t *opA, uint16_t maskA, uint16_t opB,
		uint16_t maskB)
{
	*clock += cycles;
	*PC += bytes;
}

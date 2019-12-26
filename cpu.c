static void ld(int bytes, int cycles, int *arg_A, int *arg_B)
{
	// Regular
	*arg_A = *arg_B;

	PC += cycles;
	

	// Immediate
	if (bytes == 2)
		*arg_A = read_byte(PC + 1);
	else if (bytes == 3)
		// GB is little-endian
		*arg_A = (read_byte(PC + 2) << 8) | read_byte(PC + 1);

}

static void nop(int bytes, int cycles, int *arg_A, int *arg_B)
{
	PC += cycles;
}

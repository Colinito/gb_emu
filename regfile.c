#include <stdio.h>
#include "regfile.h"

void init_regfile(struct regs *regfile)
{
    memset(regfile, 0, sizeof(struct regfile));
}

void advance_PC(struct regs *regfile, unsigned int bytes)
{
    regfile->PC += bytes;
}
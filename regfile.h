#ifndef REGFILE_H
#define REGFILE_H

#include <stdint.h>

/* Register file */
struct regs
{
    union {struct {uint8_t F, A;} bytes; uint16_t AF;} AF;
    union {struct {uint8_t C, B;} bytes; uint16_t BC;} BC;
    union {struct {uint8_t E, D;} bytes; uint16_t DE;} DE;
    union {struct {uint8_t L, H;} bytes; uint16_t HL;} HL;
    uint16_t SP;
    uint16_t PC;

};
/* init_regfile
 *
 * Initializes a register file, setting all the registers to a value of 0.
 *
 * @regfile:    register file to initialize
 */
void init_regfile(struct regs *regfile);


/* advance_PC
 *
 * Advance the PC by bytes number of bytes.
 *
 * @regfile:    register file containing PC
 * @bytes:      number of bytes by which to advance PC
 */
void advance_PC(struct regs *regfile, unsigned int bytes);

#endif
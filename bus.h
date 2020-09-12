#ifndef BUS_H
#define BUS_H

#include <stdint.h>

#include "mem.h"
#include "cart.h"

#define TOTAL_MEMORY_BYTES 1234 // TODO: Figure out what this is. Should be 2^16?

struct bus
{
    // Table of where everything is. This should make a contiguous block that includes ram, cart, and etc...
    union {uint8_t ram; uint8_t cart;} memory_map[TOTAL_MEMORY_BYTES];
};


/* read_byte
 *
 * Read a byte from a 16-bit address on the bus.
 *
 * @bus:    the memory bus
 * @addr:   16-bit memory location to read from
 *
 * @return: the byte located at addr
 */
uint8_t read_byte(struct bus *bus, uint16_t addr);

/* write_byte
 *
 * Write a byte to memory at a 16-bit address on the bus.
 *
 * @bus:    the memory bus
 * @data:   byte to write to memory
 * @addr:   16-bit memory location to write to
 */
void write_byte(struct bus *bus, uint8_t data, uint16_t addr);




#endif
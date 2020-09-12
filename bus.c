#include <stdint.h>

#include "bus.h"

uint8_t read_byte(struct bus *bus, uint16_t addr)
{
    // Perform bounds checking here and raise an exception if out of bounds error occurs
    return bus->memory_map[addr];
}


void write_byte(struct bus *bus, uint8_t data, uint16_t addr)
{
    bus->memory_map[addr] = data;
}
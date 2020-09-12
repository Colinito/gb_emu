CC=gcc
DEPS = cpu.h mem.h
OBJ = cpu.o mem.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $<

gb_emu: $(OBJ)
	$(CC) -o $@ $^

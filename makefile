# Makefile

# Program name
PROG = ldtCalculator

# Compiler C
CC = gcc

# Library flags
LF = -lgdi32 -lopengl32

# Compiler flags
CF = -c -Wall -pedantic -ansi

# .o-files
OBJ = main.o

# Binding
$(PROG): $(OBJ)
	$(CC) -o $(PROG) $(OBJ) $(LF)
	rm $(OBJ)

# Compiling
%.o: src/%.c
	$(CC) $(CF) $<

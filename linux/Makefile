# Makefile

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -g

# Source files
SRCS = ex5.c ex6.c

# Object files
OBJS = ex5.o ex6.o

# Executable file
EXEC = myprogram

# Default target
all: $(EXEC)

# Linking the executable
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

# Compiling ex5.c
ex5.o: ex5.c
	$(CC) $(CFLAGS) -c ex5.c

# Compiling ex6.c
ex6.o: ex6.c
	$(CC) $(CFLAGS) -c ex6.c

# Clean up
clean:
	rm -f $(OBJS) $(EXEC)


# Compiler and flags
CC := gcc
CFLAGS := -Wall -Wextra -std=c11 -Wno-implicit-fallthrough
LDFLAGS := -lm -g

# Rule to run specific exercises
.PHONY: run_exercise
run_exercise:
	$(CC) $(CFLAGS) -o $(exercise:.c=.out) $(exercise) $(LDFLAGS)
	./$(exercise:.c=.out)

# Clean rule
.PHONY: clean
clean:
	rm -f $(shell find . -type f -name '*.out')



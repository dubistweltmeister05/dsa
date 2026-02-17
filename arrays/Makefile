CC = gcc
CFLAGS = -Wall -g

all: 2d_arrays

2d_arrays: 2d_arrays.o
	$(CC) $< -o $@

2d_arrays.o: 2d_arrays.c
	$(CC) -c $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm *o *~ 2d_arrays

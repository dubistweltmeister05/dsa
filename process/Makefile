CC = gcc
CFLAGS=-Wall
OBJS=mem_segemts.o

all: pid_v1

pid_v1: $(OBJS)
	$(CC) $^ -o $@

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm *~ pid_v1 *.o

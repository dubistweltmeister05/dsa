CC = gcc
CFLAGS = -Wall -g -Wextra
OBJS=main.o queue.o

all: cq

cq: $(OBJS)
	$(CC) $^ -o $@

%.o: %.c %.h
	$(CC) -c $(CFLAGS) $< -o $@

.PHONY:clean
clean:
	rm *~ *.o cq

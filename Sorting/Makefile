CC=gcc
CFLAGS=-Wall -g -I .
OBJS=sorting.o main.o
TARGET=sorting_techniques

all:$(TARGET)

$(TARGET): $(OBJS)
	$(CC) $^ -o $@

%.o: %.c %.h
	$(CC) $(CFLAGS) -c  $< -o $@

.PHONY:clean
clean:
	rm *~ $(TARGET) *.o

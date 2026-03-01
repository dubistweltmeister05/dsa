CC = gcc
CFLAGS = -Wall -Wextra -g -I . -MMD -MP

TARGET = sorting_techniques
SRCS = main.c sorting.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

-include $(OBJS:.o=.d)

.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJS) $(OBJS:.o=.d)
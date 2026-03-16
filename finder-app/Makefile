CC = $(CROSS_COMPILE)gcc
CFLAGS = -Wall -Werror -g

# Default target
all: writer

# Build the writer application
writer: writer.c
	$(CC) $(CFLAGS) -o writer writer.c

# Clean target - removes writer application and object files
clean:
	rm -f writer *.o

.PHONY: all clean

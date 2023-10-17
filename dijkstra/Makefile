CC = gcc
override CFLAGS += -Wall -Wextra -g -lm
MAIN = main
EXEC = *.c graph/*.c priority_queue/*.c

all:
	$(CC) -DWEIGHTED $(CFLAGS) -o $(MAIN) $(EXEC)
clean:
	rm -f $(MAIN)

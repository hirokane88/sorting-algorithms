CC = clang 
CFLAGS = -Wall -Werror -Wextra -Wpedantic

all: sorting.o bubble.o shell.o quick.o stack.o heap.o set.o
	$(CC) -o sorting sorting.o bubble.o shell.o quick.o stack.o heap.o set.o

sorting: sorting.o bubble.o shell.o quick.o stack.o heap.o set.o
	$(CC) -o sorting sorting.o bubble.o shell.o quick.o stack.o heap.o set.o

sorting.o: sorting.c set.c
	$(CC) $(CFLAGS) -c sorting.c set.c

bubble.o: bubble.c
	$(CC) $(CFLAGS) -c bubble.c

shell.o: shell.c
	$(CC) $(CFLAGS) -c shell.c

quick.o: quick.c stack.c
	$(CC) $(CFLAGS) -c quick.c stack.c

stack.o: stack.c
	$(CC) $(CFLAGS) -c stack.c

heap.o: heap.c
	$(CC) $(CFLAGS) -c heap.c

set.o: set.c
	$(CC) $(CFLAGS) -c set.c

clean: 
	rm -f *.o

format:
	clang-format -i -style=file *.c *.h 

CC=gcc
DEPS = Stack.h Queue.h
OBJ = main.o Stack.o Queue.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $<

main: $(OBJ)
	$(CC) -o $@ $^

.PHONY: clean

clean:
	rm -f *.o main

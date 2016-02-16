CC=gcc

%.o: %.c
	$(CC) -c -o $@ $^

install: forktest.o
	$(CC) forktest.o -o unit_tests

clean:
	rm *.o unit_tests

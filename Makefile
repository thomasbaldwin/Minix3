CC=gcc

%.o: %.c
	$(CC) -c -o $@ $^

hello: main.o foo.o
	$(CC) main.o foo.o -o hello

clean:
	rm *.o hello
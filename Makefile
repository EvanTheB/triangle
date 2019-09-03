CFLAGS=-Wall -Wextra

test: test.o tri.o

tri.o: CFLAGS+=-O2

clean:
	rm -v -- *.o test

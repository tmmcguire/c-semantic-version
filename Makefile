BUILT = libsemantic-version.a semantic-version.o test-semantic-version

CFLAGS = -Wall

all: libsemantic-version.a

libsemantic-version.a: semantic-version.o
	ar rcs $@ $^

semantic-version.o: semantic-version.c semantic-version.h
	gcc -c $(CFLAGS) $<

test: libsemantic-version.a
	gcc $(CFLAGS) test-semantic-version.c -o test-semantic-version -L. -lsemantic-version
	./test-semantic-version

clean:
	rm -f $(BUILT)

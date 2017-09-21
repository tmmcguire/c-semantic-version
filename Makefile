BUILT = libsemantic-version.a semantic-version.o

CFLAGS = -Wall

all: libsemantic-version.a

libsemantic-version.a: semantic-version.o
	ar rcs $@ $^

semantic-version.o: semantic-version.c semantic-version.h
	cc -c $(CFLAGS) $<

clean:
	rm -f $(BUILT)

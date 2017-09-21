BUILT = libsemantic-version.a semantic-version.o

all: libsemantic-version.a

libsemantic-version.a: semantic-version.o
	ar rcs $@ $^

semantic-version.o: semantic-version.c semantic-version.h
	cc -c $<

clean:
	rm -f $(BUILT)

CC=gcc
CFLAGS=-lpthread

simples: simples.c
	gcc -o simples.out simples.c $(CFLAGS)

structs: structs.c
	gcc -o structs.out structs.c $(CFLAGS)

all: simples structs

clean: 
	rm *.out

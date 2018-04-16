CC=gcc
CFLAGS=-lpthread

simples: simples.c
	gcc -o simples.out simples.c $(CFLAGS)

structs: structs.c
	gcc -o structs.out structs.c $(CFLAGS)

retorno: retorno.c
	gcc -o retorno.out retorno.c $(CFLAGS)

all: simples structs retorno

clean: 
	rm *.out

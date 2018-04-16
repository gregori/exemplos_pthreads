CC=gcc
CFLAGS=lpthread

simples: simples.c
	gcc -o simples.out simples.c $(CFLAGS)

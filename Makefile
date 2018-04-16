CC=gcc
CFLAGS=lpthread

simples: parametro_simples.c
	gcc -o parametro_simples.out parametro_simples $(CFLAGS)

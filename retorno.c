#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>


/* estrutura de dados para passagem de parâmetros */
typedef struct minha_struct {
	double d;
    int i;
} minha_struct_t;

/* função que será executada pelas threads */
void *myfunc(void *thread_arg) {
    minha_struct_t *my = (minha_struct_t *) malloc(sizeof(minha_struct_t));

	my->d = 3.14149265;
	my->i = 42;

	/* devolvemos para a thread principal a struct preenchida */
    pthread_exit((void *) my);
}

int main() {
    pthread_t thread;
    minha_struct_t my;
	void *thread_data;

	/* criamos a thread - sem parâmetros */
  	pthread_create(&thread, NULL, myfunc, NULL);

	/* aguardamos o retorno do valor - será inserido em thread_data */
	pthread_join(thread, &thread_data);

	/* convertemos o valor para a struct criada e o imprimimos */
	my = *((minha_struct_t *) thread_data);
	free(thread_data);

	printf("(%f, %d)\n", my.d, my.i);

    return 0;
}

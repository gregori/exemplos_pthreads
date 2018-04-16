#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_TASKS 8

char *mensagens[NUM_TASKS];

/* estrutura de dados para passagem de parâmetros */
typedef struct thread_data {
    int thread_id;
    int soma;
    char *mensagem;
} tdata_t;

/* função que será executada pelas threads */
void *hello(void *thread_arg) {
    int taskid, soma;
    char *hello_msg;
    tdata_t *my_data;

    sleep(1);

    my_data = (tdata_t *) thread_arg; /* convertemos o parâmetro para o tipo struct */

	/* transpondo os dados da struct para variáveis locais */
    taskid = my_data->thread_id; 
    soma = my_data->soma;
    hello_msg = my_data->mensagem;
	
    printf("Thread %d: %s Soma=%d\n", taskid, hello_msg, soma);

	/* liberamos o ponteiro do parâmetro recebido - boa prática de programação */
    free(thread_arg);

    return NULL;
}

int main() {
    pthread_t threads[NUM_TASKS];
    int cod_erro, t, soma;
    tdata_t *tdata;

    soma = 0;
    mensagens[0] = "Inglês: Hellow World!";
    mensagens[1] = "Francês: Bonjour, le monde!";
    mensagens[2] = "Espanhol: Hola al mundo!";
    mensagens[3] = "Klingon: Nuq neH!";
    mensagens[4] = "Alemão: Hallo, Welt!";
    mensagens[5] = "Português: Olá, Mundo!";
    mensagens[6] = "Turco: Selam, Dünya!";
    mensagens[7] = "Latim: Orbis, te saluto!";

	for (t=0; t<NUM_TASKS; t++) {
		/* o parâmetro a ser passado é  um ponteiro para struct */
		/* criamos da forma correta, através de um malloc */
   		tdata = (tdata_t *) malloc(sizeof(tdata_t));

		/* incrementamos a variavel soma, pelo id da thread */
    	soma += t;

		/* preenchendo a struct */
    	tdata->thread_id = t;
    	tdata->soma = soma;
    	tdata->mensagem = mensagens[t];

    	printf("Criando thread %d\n", t);
		/* cria a thread, passa o ponteiro por parâmetro, se retorna erro, encerramos o programa */
    	cod_erro = pthread_create(&threads[t], NULL, hello, (void *) tdata);

    	if (cod_erro) { 
        	fprintf(stderr, "ERRO: pthread_create() ret = %d\n", cod_erro);
        	return -1;
    	}
	}

	/* aguardamos o encerramento das threads */
	for (t=0; t<NUM_TASKS; t++) {
		pthread_join(threads[t], NULL);
	}

    return 0;
}

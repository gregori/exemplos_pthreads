#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_TASKS 8

char *mensagens[NUM_TASKS];

/* Função que será executada nas threads */
void *say_hello(void *p_task_id) {
    int task_id; 
    task_id = *((int *) p_task_id); /* id passado por parâmetro, convertido para int */
    sleep(1);

    printf("Thread %d: %s\n", task_id, mensagens[task_id]);

    free(p_task_id); /* liberamos o ponteiro - boa prática de programação */

    return NULL;
}

int main() {
    pthread_t threads[NUM_TASKS]; /* array que conterá os ponteiros para as threads */
    int *p_task_id;
    int cod_erro, t;

    mensagens[0] = "Inglês: Hellow World!";
    mensagens[1] = "Francês: Bonjour, le monde!";
    mensagens[2] = "Espanhol: Hola al mundo!";
    mensagens[3] = "Klingon: Nuq neH!";
    mensagens[4] = "Alemão: Hallo, Welt!";
    mensagens[5] = "Português: Olá, Mundo!";
    mensagens[6] = "Turco: Selam, Dünya!";
    mensagens[7] = "Latim: Orbis, te saluto!";

    for (t=0; t<NUM_TASKS; t++) {
        /* o parâmetro a ser passado será um ponteiro */
        /* estamos criando da maneira correta, através de um malloc */
        p_task_id = (int *) malloc(sizeof(int));
        *p_task_id = t;
        printf("Criando thread %d\n", t);

        /* cria a thread, passa o ponteiro por parâmetro, se retornou erro, encerramos o programa */
        cod_erro = pthread_create(&threads[t], NULL, say_hello, (void *) p_task_id);

        if (cod_erro) {
            fprintf(stderr, "ERRO: pthread_create() ret = %d\n", cod_erro);
            return -1;
        }
    }

    /* aguardamos as threads encerrarem */
    for (t=0; t<NUM_TASKS; t++) {
        pthread_join(threads[t], NULL);
    }

    return 0;
}


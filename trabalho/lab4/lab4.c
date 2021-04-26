/* De:Lucas Tatsuya Tanaka */
/* DRE:118058149 */
/* Email:tanaka@dcc.ufrj.br */
/* Github:https://github.com/tatsutanka */
/* Data:20/04/2021*/


#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>


#define NTHREADS 4


//variaveis GLobais 
int x = 0;
pthread_mutex_t x_mutex;
pthread_cond_t x_cond,x_condB;

// tarefa
void *tarefaA (void *t){
    printf("A: comecei\n");
    // escreve volte sempre
    pthread_mutex_lock(&x_mutex);
    while(x<3) {
        pthread_cond_wait(&x_cond, &x_mutex); 
        if(x==3){
            printf("Volte sempre!\n");
            x++; 
        }
    }
    pthread_mutex_unlock(&x_mutex);
    pthread_exit(NULL);
}

void *tarefaB (void *t){
    printf("B: comecei\n");
    //escreve fique a vontade
    pthread_mutex_lock(&x_mutex);
    if(x==0){
        pthread_cond_wait(&x_cond,&x_mutex);
    }
    printf("Fique a vontade.\n");
    x++;
    pthread_cond_signal(&x_cond);
    pthread_mutex_unlock(&x_mutex);
    pthread_exit(NULL);
}
void *tarefaC (void *t){
    printf("C: comecei\n");
    //sente-se por favor
    pthread_mutex_lock(&x_mutex);
    if(x==0){
        pthread_cond_wait(&x_cond,&x_mutex);
    }
    printf("Sente-se por favor.\n");
    x++;
    pthread_cond_signal(&x_cond);
    pthread_mutex_unlock(&x_mutex);
    pthread_exit(NULL);
}

void *tarefaD (void *t){
    printf("D: comecei\n");
    //seja bem vindo 
    printf("Seja bem-vindo!\n");
    pthread_mutex_lock(&x_mutex);
    x++;
    pthread_cond_broadcast(&x_cond);
    pthread_mutex_unlock(&x_mutex);
    pthread_exit(NULL);
}

// main
int main(int argc,char *argv[]){
    int i;
    pthread_t threads[NTHREADS];
    printf("Inicio\n");

    /* Inicializa as variaveis de exclusão mutua e */
    /*  variavel de condicao mutua */
    pthread_mutex_init(&x_mutex,NULL);
    pthread_cond_init(&x_cond,NULL);

    /* cria as Threads */ 
    pthread_create(&threads[0],NULL,tarefaA,NULL);
    pthread_create(&threads[1],NULL,tarefaB,NULL);
    pthread_create(&threads[2],NULL,tarefaC,NULL);
    pthread_create(&threads[3],NULL,tarefaD,NULL);


    /* Espera as Threads completarem */
    for (i = 0; i < NTHREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    printf ("\n---FIM---\n");

    /* Libera as variaveis */
    pthread_mutex_destroy(&x_mutex);
    pthread_cond_destroy(&x_cond);
 return 0;
}

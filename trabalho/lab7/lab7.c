#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define NTHREADS 4

sem_t mutex,semA,semB,semC;
int x = 0;

void * tarefaA(void *argv){
    sem_wait(&semC);
    printf("Volte sempre!\n"); 
    pthread_exit(NULL);

    
}

void * tarefaB(void *argv){
    //tem que imprimir antes da Thread 1 
    sem_wait(&semA);
    printf("Fique a vontade\n");
    sem_post(&semB);
    sem_post(&semC);
    pthread_exit(NULL);
}

void * tarefaC(void *argv){
    //tem que imprimir antes da Thread 1 
    sem_wait(&semB);
    printf("Sente-se por favor\n");
    sem_post(&semA);
    sem_post(&semC);
    pthread_exit(NULL);
}

void * tarefaD(void *argv){
    //deve ser imprimido antes do 2 e 3
    printf("Seja bem-vindo\n");
    sem_wait(&mutex);
    sem_post(&semA);
    sem_post(&semB);
    sem_post(&mutex);
    pthread_exit(NULL);
}

int main(int argc, char* argv[]){
    
    pthread_t tid[NTHREADS];

    // inicio do semafro binario 
    sem_init(&mutex,0,1);
    sem_init(&semA,0,0);
    sem_init(&semB,0,0);
    sem_init(&semC,0,0);

    //inicia a execucao das Threads
    if(pthread_create(&tid[0],NULL,tarefaA,NULL)){
        printf("--ERRO: pthread_create()\n"); exit(-1);
    }
    if(pthread_create(&tid[1],NULL,tarefaB,NULL)){
        printf("--ERRO: pthread_create()\n"); exit(-1);
    }
    if(pthread_create(&tid[2],NULL,tarefaC,NULL)){
        printf("--ERRO: pthread_create()\n"); exit(-1);
    }
    if(pthread_create(&tid[3],NULL,tarefaD,NULL)){
        printf("--ERRO: pthread_create()\n"); exit(-1);
    }

    //espera o termino das Threads
    for (int t=0; t<NTHREADS; t++) {
        if (pthread_join(tid[t], NULL)) {
            printf("--ERRO: pthread_join() \n"); exit(-1); 
        } 
    }

    return 0;
}

#include<stdio.h>
#include<pthread.h>

#define NTHREADS 10

/* funcao que a thread ira executar */
void * tarefa (void *arg) {
    int ident = *(int *) arg;
    printf("ola sou a nova thread %d\n",ident);
    pthread_exit(NULL);
}

/* funcao principal */
int main(void){
    pthread_t tid[NTHREADS]; //indentificador da thread no sistema
    int ident[NTHREADS]; //indentificador local da therad
    //cria as threads novas
    for(int i=1;i<=NTHREADS;i++) {
        ident[i-1] = i;
        if( pthread_create(&tid[i-1], NULL, tarefa,(void *)&ident[i-1]))
            printf("ERRO -- Pthread_create\n");
    }
    // espera as thread acabarem
    for(int i=0;i<NTHREADS;i++) {
        if( pthread_join(tid[i], NULL))
            printf("ERRO -- Pthread_join\n");
    }
    //imprime a mensagem de boas vindas
    printf("ola sou a thread principal\n");
    //desvincula o termino da main do termino do programa

    pthread_exit(NULL);
    return 0;
}



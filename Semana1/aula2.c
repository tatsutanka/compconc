#include<stdio.h>
#include<pthread.h>

/* funcao que a thread ira executar */
void * tarefa (void *arg) {
    printf("ola sou a nova thread\n");
    pthread_exit(NULL);
}

/* funcao principal */
int main(void){
    pthread_t tid; //indentificador da thread no sistema
    //cria a thrad nova
    if( pthread_create(&tid, NULL, tarefa,NULL))
        printf("ERRO -- Pthread_create\n");
    //imprime a mensagem de boas vindas
    printf("ola sou a thread principal\n");
    //desvincula o termino da main do termino do programa
    pthread_exit(NULL);
    return 0;
}

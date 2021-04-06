/* De:Lucas Tatsuya Tanaka */
/* DRE:118058149 */
/* Email:tanaka@dcc.ufrj.br */
/* Github:https://github.com/tatsutanka */
/* Data: 25/03/21 */

/* Objetivo: Implementar um programa concorrente, com duas threads (alem da thread */
/* principal), para incrementar de 1 cada elemento de um vetor de 10000 elementos. */

#include<stdio.h>
#include<pthread.h>


#define NTHREADS 2
#define TVETOR 1000

int vetor[TVETOR];

// tarefa
void * tarefa (void* arg) {
    int ident = * (int *) arg;
    for(int i = 0; i<TVETOR;i++){
        if(ident == 1){
            // pegar os vetores pares e acrecenatr +1
            if(i%2 == 0 || i == 0){
                vetor[i]+=1;
                printf("A thread 1 acrecentou +1 no %d\n",i);
            }
        }
        else {
            // pegar os vetores inpares e acrecentar +1
            if(i%2 != 0 && ident == 2){
                vetor[i]+=1;
                printf("a thread 2 acrecentou +1 no %d\n",i);
            }
        }
    }
    pthread_exit(NULL);
}

// main
int main(void){
    int countA = 0; // conta o numero de 2 no vetor
    int countB = 0; // conta o numero de outros numeros no vetor
    pthread_t tid[NTHREADS]; // indentidicador de threads do sistema
    int ident[NTHREADS];
    ident[0] = 1;
    ident[1] = 2;

    // preenche vetor
    for(int i = 0;i < TVETOR;i++){
        vetor[i] = 1;
    }
    printf("Vetor Preenchido");

    //cria as threads
    for(int i = 1; i <= NTHREADS;i++){
        ident[i-1] = i;
        if(pthread_create(&tid[i-1], NULL,tarefa,(void *)&ident[i-1]))
            printf("ERRO -- pthread_create\n");
    }
    //espera as threads terminarem
    for(int i = 0; i<NTHREADS;i++){
        if(pthread_join(tid[i],NULL))
            printf("ERRO -- pthread_join\n");
    }

    //conferindo resultado
    // contar o numero de vetores iguais a 2
    for(int i =0; i < TVETOR;i++){
        if(vetor[i] == 2)
            countA++;
        else
            countB++;
    }
    printf("o numero de acrecentados %d\n",countA);
    printf("o numero de deviantes %d\n",countB);
    // finalizacao da execucao
    printf("finalizacao da execucao do programa\n");

    return 0;
}

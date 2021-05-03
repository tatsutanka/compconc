/* De:Lucas Tatsuya Tanaka */
/* DRE:118058149 */
/* Email:tanaka@dcc.ufrj.br */
/* Github:https://github.com/tatsutanka */
/* Data:30/04/2021*/


#include<stdio.h>
#include<pthread.h>
#include <stdlib.h>
#include <math.h>


int  NTHREADS;
int SALTO;
int *VET;
int contador = 0;
pthread_mutex_t mutex;
pthread_cond_t cond_bar;

void barreira(int nthreads){
    pthread_mutex_lock(&mutex); //inicio secao critica
    if(contador == (nthreads-1)){
        contador=0;
        pthread_cond_broadcast(&cond_bar);
    }
    else{
        contador++;
        pthread_cond_wait(&cond_bar,&mutex);
    }
    pthread_mutex_unlock(&mutex); //fim secao critica
}

// tarefa
void * tarfea (void*args){
    long int id = (long int)args;
    int aux;
    printf("A Thread %ld Começou\n",id);

    if (id-SALTO > 0){
        for (int i = id-SALTO; i < id; i++){
            aux += VET[i];
        }
    }
        
    if (id-SALTO <= 0){
        for (int i = 0; i < id; i++){
            aux += VET[i];
        }
    }
    
    barreira(NTHREADS);
    //pos barreira se faz a troca na variavel responsavel
    VET[id] += aux;
    pthread_exit(NULL);
}
// main
int main(int argc,char * argv[]){

    pthread_t *tid;

    if(argc<3){
        fprintf(stderr,"Digite; %s <o valor i da potencia de 2^i> <numero de Threads>\n",argv[0]);
        return 1;
    }
    SALTO = pow(2,atoi(argv[1]));
    NTHREADS = atoi(argv[2]);

    //aloca estruturas de dados 
    tid = (pthread_t*) malloc(sizeof(pthread_t)*NTHREADS);
    if (tid==NULL){ fprintf(stderr,"ERRO --malloc\n"); return 3;}

    //aloca o vetor
    VET = (int *) malloc(sizeof(int)*NTHREADS);
    if(VET==NULL){fprintf(stderr,"ERRO --malloc"); return 2;}

    for (int i = 1; i <= NTHREADS; i++){
       VET[i-1] = i; 
    }
    
    //print do VET
    printf("\n");
    printf("o VET de ENTRADA\n");
    printf("VET={");
    for(int i = 0;i<NTHREADS-1;i++){
        printf("%d ,",VET[i]);
    }
    printf("%d}",VET[NTHREADS-1]);
    printf("\n\n");

    //cria as Threads
    for (long int i = 0; i < NTHREADS; i++){
       if(pthread_create(tid+i,NULL,tarfea,(void*)i)){
           fprintf(stderr,"ERRO --pthread_create\n");
           return 3;
       }

    }

    //agurada o termino das Threads
     for(long int i=0; i<NTHREADS; i++) {
      if(pthread_join(*(tid+i),NULL)){
         fprintf(stderr, "ERRO--pthread_create\n");
         return 3;
      }
    }

    //exibindo os resultados
    printf("VET={");
    for(int i = 0;i<NTHREADS-1;i++){
        printf("%d ,",VET[i]);
    }
    printf("%d}\n",VET[NTHREADS-1]);
    
    //libera areas de memoria alocada
    free(tid);
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond_bar);

    printf("\nFIM\n"); // averiguando o final do programa
    return 0;
}

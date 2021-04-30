/* De:Lucas Tatsuya Tanaka */
/* DRE:118058149 */
/* Email:tanaka@dcc.ufrj.br */
/* Github:https://github.com/tatsutanka */
/* Data:30/04/2021*/


#include<stdio.h>
#include<pthread.h>
#include <stdlib.h>


int  NTHREADS;
int contador;
pthread_mutex_t mutex;
pthread_cond_t cond_bar;
int bloqueadas = 0;

void barreira(int nthreads) {
    pthread_mutex_lock(&mutex); //inicio secao critica
    if (bloqueadas == (nthreads-1)) { 
      //ultima thread a chegar na barreira
      pthread_cond_broadcast(&cond_bar);
      bloqueadas=0;
    } else {
      bloqueadas++;
      pthread_cond_wait(&cond_bar, &mutex);
    }
    pthread_mutex_unlock(&mutex); //fim secao critica
}

// tarefa
void * tarfea (void*args){

    pthread_exit(NULL);
}
// main
int main(int argc,char * argv[]){

    pthread_t *tid;

    if(argc<2){
        fprintf(stderr,"Digite; %s <numero de Threads>\n",argv[1]);
        return 1;
    }
    NTHREADS = atoi(argv[1]);

    //aloca estruturas de dados 
    
    tid = (pthread_t*) malloc(sizeof(pthread_t)*NTHREADS);
    if (tid==NULL){ fprintf(stderr,"ERRO --malloc\n"); return 3;}

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

    //libera areas de memoria alocada
    free(tid);
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond_bar);
    return 0;
}

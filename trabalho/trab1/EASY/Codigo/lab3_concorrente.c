/* De:Lucas Tatsuya Tanaka */
/* DRE:118058149 */
/* Email:tanaka@dcc.ufrj.br */
/* Github:https://github.com/tatsutanka */
/* Data:06/04/2021*/


#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<math.h>
#include"timer.h"

int nThreads; //numero de threads
long long int nSerie; // tamnho da serie

//tarfea
void * tarefa(void * arg){
    long int id = (long int) arg; //indentificador da thread
    double *somaLocal ;// variavel da soma de elemntos 
    somaLocal = (double*) malloc(sizeof(double));
    if(somaLocal==NULL){exit(1);}
    printf("Thread : %ld\n",id);

    // Multiplicacao da Thread
    for(int i = id;i< nSerie;i+=nThreads){
       *somaLocal  += pow(-1,i)/((2*i)+1);
    }
    printf("SomaLocal: %.15lf\n",*somaLocal);
    pthread_exit((void *)somaLocal);
}

// main
int main(int argc,char * argv[]){
    double sSerie = 0; // soma da serie
    pthread_t * tid; //indentificador das Threads
    double ini,fim; // tomadda de tempo
    double *retorno; //valor de retorno das threads

    // recebe e valida os paramentros de entrada
    if(argc < 3){
        fprintf(stderr,"Digite %s <Numero de elemntos N para a serie de pi> <Numero de threads>\n",argv[0]);
        return 1;
    }
    nSerie = atoll(argv[1]);
    nThreads = atoi(argv[2]);

    //alocacao das estruturas
    GET_TIME(ini);
    tid = (pthread_t *) malloc(sizeof(pthread_t) * nThreads);
    if(tid==NULL){
        fprintf(stderr,"ERRO --maloc\n");
        return 2;
    }

    //Criar Threads 
    for(long int i = 0;i<nThreads;i++){
        if(pthread_create(tid+i,NULL,tarefa,(void*) i)){
            fprintf(stderr,"ERRO --pthread_create\n");
            return 2;
        }
    }
    //agurdar o terminao das threads
    for(long int i=0;i<nThreads;i++){
        if(pthread_join(*(tid+i),(void**) &retorno)){
            fprintf(stderr,"ERRO --pthread_join\n");
            return 3;
        }
        sSerie += *retorno;
    }
    sSerie *= 4;

    GET_TIME(fim)
    //exibir os resultados 
    printf("Tempo: %lf\n",fim-ini);
    printf("Soma conc: %.15lf\n",sSerie);
    //libera as areas de memoria alocadas
    free(tid);


    return 0;
}


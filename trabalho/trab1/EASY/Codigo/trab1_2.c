/* De:Lucas Tatsuya Tanaka */
/* DRE:118058149 */
/* Email:tanaka@dcc.ufrj.br */
/* Github:https://github.com/tatsutanka */
/* Data:26/04/2021*/


#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<math.h>

long int NTHREADS; // numero de Threads
long long int NSERIES; //tamanho da serie


int fatorial(long int arg){
    long long int resposta = 1;
    for(int i = 1;i<=arg;i++){
        resposta *= i;
    }
    return resposta;
}

// tarefa
void * tarefa(void * arg){
    long int id = (long int) arg; //indentificador da thread
    long double *somaLocal ;// variavel da soma de elemntos 
    somaLocal = (long double*) malloc(sizeof(long double));
    if(somaLocal==NULL){exit(1);}
    printf("Thread : %ld\n",id);

    //multiplicação da Thread
    for(long int i = id;i < NSERIES; i+=NTHREADS){
        *somaLocal += fatorial((2*i)+1)/(pow(2,(3*i)+1)*pow(fatorial(i),2));
    }
    printf("SomaLocal: %.15LF\n",*somaLocal);
    pthread_exit((void*)somaLocal);
}

// main
int main(int argc,char * argv[]){
    long double sSerie = 0; // o valor de soma das series
    pthread_t * tid;// indentificadores de Thread
    long double *retorno; //retorno das Threads

    // recebendo parametros de entrada
    if(argc < 3){
        fprintf(stderr,"Digite %s <Numero de elemntos N para a serie de sqrt(2)> <Numero de threads>\n",argv[0]);
        return 1;
    }
    NSERIES = atoll(argv[1]);
    NTHREADS = atoi(argv[2]);

    //alocacao das estruturas
    tid = (pthread_t *) malloc(sizeof(pthread_t) * NTHREADS);
    if(tid == NULL){fprintf(stderr,"ERRO --maloc\n"); return 2;}
    
    //criação das Threads
    for(long int i = 0; i<NTHREADS;i++){
        if(pthread_create(tid+i,NULL,tarefa,(void*) i)){
            fprintf(stderr,"ERRO --pthread_create\n");
            return 2;
        }
    }
    //espera pelo Termino das Threads
    for(long int i=0;i<NTHREADS;i++){
        if(pthread_join(*(tid+i),(void**) &retorno)){
            fprintf(stderr,"ERRO --pthread_join\n");
            return 3;
        }
        sSerie +=(*retorno);
    }
    //mostrar o resultado
    printf("Soma conc: %.15LF\n",sSerie);

    //Libera o espaco de memoria alocado
    free(tid);


    return 0;
}

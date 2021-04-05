/* De:Lucas Tatsuya Tanaka */
/* DRE:118058149 */
/* Email:tanaka@dcc.ufrj.br */
/* Github:https://github.com/tatsutanka */
/* Data:03/04/2021*/


#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include"timer.h"

float *aMat; // matriz de entrada
float *bMat; // vetor de entrada
float *sMat; // vetor de saida
int nthreads; //numero de threads

typedef struct{
    int id; //indentificador do elemnto que thread ira processar
    int dim; // dimensao das estruturas de entrada
}tArgs;

// tarefa
void * tarefa(void *arg){
    tArgs *args = (tArgs*) arg;
    printf("thread %d\n",args->id);
    for(int i = (args->id);i<(args->dim);i+=nthreads){
        for(int j=0; j<(args->dim);j++){
            for(int k=0; k<(args->dim);k++){
                sMat[i*(args->dim)+j] += aMat[i*(args->dim)+k] * bMat[k*(args->dim)+j];
            }
        }
    }
    pthread_exit(NULL);
}

// main
int main(int argc,char *argv[]){
    int dim; //dimensao da matriz de entrada
    pthread_t *tid; // indentificadores das threads
    tArgs * args; //indentificadores locais da dimensao
    double inicio, fim, deltaI,deltaM,deltaF; // medidores de tempo

    GET_TIME(inicio);
    //leitura e avaliacao dos parametros de entrada
    if(argc<3) {
        printf("Digite: %s <dimensao da matriz> < numero de threads>\n",argv[0]);
        return 1;
    }
    dim = atoi(argv[1]);
    nthreads = atoi(argv[2]);
    if(nthreads > dim) nthreads = dim;
    printf("a dimensao%d\n", dim);

    //alocacao de memoria para as estruturas de dados
    aMat = (float *) malloc(sizeof(float) * dim *dim);
    if(aMat == NULL){printf("ERRO-- malloc\n"); return 2;}

    bMat = (float *) malloc(sizeof(float) * dim *dim);
    if(bMat == NULL){printf("ERRO-- malloc\n"); return 2;}

    sMat = (float *) malloc(sizeof(float) * dim *dim);
    if(sMat == NULL){printf("ERRO-- malloc\n"); return 2;}

    //inicializando as matrizes
    for(int i=0;i<dim; i++){
        for(int  j=0;j<dim;j++){
            aMat[i*dim+j] = 1;  //equivalente a mat[i][j]
            bMat[i*dim+j] = 3;
            sMat[i*dim+j] = 0;
        }
    }
    GET_TIME(fim)
    deltaI = fim - inicio;

    //multiplicacao das matrizes
    GET_TIME(inicio);
    //alocação de estruturas
    tid = (pthread_t *) malloc(sizeof(pthread_t)*nthreads);
    if(tid == NULL) {puts("ERRO-- malloc\n"); return 2;}
    args = (tArgs *) malloc(sizeof(tArgs)*nthreads);
    if(tid == NULL) {puts("ERRO-- malloc\n"); return 2;}

    // criação das trheads
    for(int i=0; i<nthreads; i++){
        (args+i)->id = i;
        (args+i)->dim = dim;
        if(pthread_create(tid+i,NULL,tarefa,(void*) (args+i))){
            puts("ERRO--pthread_create\n");return 3;
        }
    }
    //espera pelo terminao das threads
    for(int i =0 ;i<nthreads;i++){
        pthread_join(*(tid+i),NULL);
    }
    GET_TIME(fim);
    deltaM = fim - inicio;
    /* //Printando o pragama */
    /* for(int i = 0;i<dim;i++){ */
    /*     for(int j =0 ; j<dim;j++){ */
    /*         printf("%lf ",sMat[i*dim+j]); */
    /*     } */
    /*     puts(""); */
    /* } */
    //liberacao do programa
    GET_TIME(inicio);
    free(aMat);
    free(bMat);
    free(sMat);
    free(tid);
    GET_TIME(fim);
    deltaF = fim - inicio;
    printf("tempo de inicialização: %lf\n",deltaI);
    printf("Tempo de multiplicação: %lf\n",deltaM);
    printf("Tempo de finalização: %lf\n",deltaF);

    return 0;
}

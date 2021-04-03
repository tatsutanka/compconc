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
void * trabalho(void *arg){

    pthread_exit(NULL);
}

// main
int main(int argc,char *argv[]){
    int dim; //dimensao da matriz de entrada
    pthread_t *tid; // indentificadores das threads
    tArgs * args; //indentificadores locais da dimensao
    double inicio, fim, delta;

    //inicializacao das estruturas de dados
    //leitura e avaliacao dos parametros de entrada
    if(argc<3) {
        printf("Digite: %s <dimensao da matriz> < numero de threads>\n",argv[0]);
        return 1;
    }
    dim = atoi(argv[1]);
    nthreads = atoi(argv[2]);
    if(nthreads > dim) nthreads = dim;

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
            aMat[i*dim+j] = 2;  //equivalente a mat[i][j]
            bMat[i*dim+j] = 2;
            sMat[i*dim+j] = 0;
        }
    }
    //multiplicacao das matrizes
    //finalizacao de programas
 return 0;
}

/* De:Lucas Tatsuya Tanaka */
/* DRE:118058149 */
/* Email:tanaka@dcc.ufrj.br */
/* Github:https://github.com/tatsutanka */
/* Data:23/04/2021*/

/*O objetivo do trabakho é o calculo do determinante de uma matriz atravez do
metodo de Sarrus e Laplace */

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>

int nThreads; //numero de Threads
long int tMatriz; // tamanho da matriz
int *Mat;
// tarefa
void * tarefa(void *arg){

    //saber a primeira lin da matriz
    // arg deve ter o tamnho da matriz

    //separar os processamentos de cada Thread

    //vetor lin = primeira lin d a matriz
    /* for(int i = id;i < len(vetor_lin);i+=id)
     *  s=vetor_lin[i]
     *  //separar matriz grande em matriz menor 
     *  total += s * det_laplace(no vetor separado )* 
    */

    pthread_exit(NULL);
}

double det_laplace(int size_matriz , double * matriz){

    //if size da matriz == 1 return mat[0][0]
    if(size_matriz == 1){return matriz[0];}

    int lin,col;
    int j_aux,i_aux;
    double det = 0;
    int *interMatriz;

    //copiando os valores na matriz
    for(int i = 0; i < size_matriz;i++){
        if(matriz[i] != 0){
            double *aux ;
            aux = (double*)malloc(sizeof(double)*(size_matriz-1)*(size_matriz-1));
            if(aux == NULL){printf("ERRO -- malloc\n"); return 2;}
            
            i_aux = 0;
            j_aux = 0;
            
            for(lin = 1;lin < size_matriz;lin++){
                for(col= 0;col < size_matriz;col++){
                    if(col != i){
                        aux[i_aux *size_matriz + j_aux] = matriz[lin*size_matriz+col];
                        j_aux++;
                    }
                }
                i_aux++;
                j_aux = 0;
            }   
            double factor = (i % 2==0)? matriz[i] : -matriz[i];
            free(aux); //liberando valores alocados 
            det+=factor * det_laplace(size_matriz - 1,matriz); //calculando de maneira recursiva
        }    

    }

    return det; //retorna valor final 
    
}

int ler_matriz(int size,int* matriz,char* filename){
    FILE *fp;

    if(matriz == NULL){printf("ERRO -- matriz incompativel"); return 0;}

    fp = fopen(filename,"r");
    if(fp == NULL){printf("ERRO --fopen\n"); return 0;}
    
    for(int i = 0;i < size;i++){
        for(int j = 0;j<size;j++){
                fscanf(fp,"%d",&matriz[i*size+j]);
        }
    }

    fclose(fp);
    return 1;
}


// main
int main(int argc, char * argv[]){

    char filename[50];
    pthread_t tid;

    //receber parametros de entrada
    if(argc<4){
        printf("Digite: %s <Nome do arquivo> <Numero de Threads> <tamanho da matriz>",argv[0]);
        return 1;
    }
    strcpy(filename,argv[1]);
    nThreads = atoi(argv[2]);
    tMatriz = atoi(argv[3]);

    //aloca valores para a Mat
    //ler a matriz

    //cria as Threads
    //espera o termino das Threads
    //exibi resultado final 
    //libera areas alocadas

 return 0;
}

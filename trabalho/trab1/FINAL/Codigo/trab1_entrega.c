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
#include<math.h>

int nThreads; //numero de Threads
long int tMatriz; // tamanho da matriz
long int *Mat;// Matriz

//calculo do determinante de maneira sequencial
long int determinant(long int size,long int *arr) { 
    long int i,j,k;
    long int sum=0;
    long int arr1[size-1][size-1]; 

    if(size>1){ 
        for(i=0;i<size;i++){ //iterando pela primeira linha
            for(j=0;j<size;j++){//criando uma pmatriz menor
             
                if(j!=i) { 
                    for(k=1;k<size;k++) { 
                        if(j<i) 
                            arr1[k-1][j] = *(arr + j + size*k); 
                        else 
                            arr1[k-1][j-1] = *(arr + j + size*k); 
                    } 
                } 
            } 
         
        sum = sum + pow(-1,i)*(*(arr + i))*(determinant(size-1,*arr1)); 
        //calculando o valor recursivamente do determinante 
		} 
        return sum; 
    } 
    else 
        return *arr; 
} 

// leitura do arquivo para colocar seu valores na matriz peincipal
int ler_matriz(int size,long int* matriz,char* filename){
    FILE *fp;
    // verificando se matriz existe
    if(matriz == NULL){printf("ERRO -- matriz incompativel\n"); return 0;}

    //abrindo arquivo passado para o programa
    fp = fopen(filename,"r");
    if(fp == NULL){printf("ERRO --fopen\n"); return 0;}
    //preenchendo a matriz com o arquivo 
    for(int i = 0;i < size;i++){
        for(int j = 0;j<size;j++){
            fscanf(fp,"%ld",&matriz[i*size+j]);
        }
    }

    fclose(fp);//termiando o processamento do arquivo
    return 1;
}

// Tarefa concorrente
void * tarefa(void *arg){
    long int id = (long int)arg;  
    long long int *sum;
    int i_aux,j_aux;
    sum = (long long int *)malloc(sizeof(long long int));
    if(sum == NULL){fprintf(stderr,"ERRO --malloc\n");exit(0);}

    *sum = 0;
    //particionamento da matriz em matrizes menores para o calculo
    for(int i=id;i<tMatriz ; i+=nThreads){
        //alocando memoria para a nova matriz que sera calculada
        long int* tempMatriz = (long int*) malloc(sizeof(long int)*pow((tMatriz-1),2));
        if(tempMatriz == NULL){fprintf(stderr,"ERRO --malloc\n"); exit(0);}
                
        i_aux = 0;
        j_aux = 0;
        for(int j=1;j<tMatriz;j++){
            for(int k = 0; k<tMatriz;k++){
                if(k!=i){
                    tempMatriz[i_aux+(tMatriz-1)*j_aux] = Mat[k+tMatriz*j];
                    i_aux++;
                }
            }
            i_aux = 0;
            j_aux ++;
        }
        long int fator = pow(-1,i) * Mat[0*tMatriz+i];
        *sum += fator*determinant(tMatriz-1,tempMatriz); //calculo da soma do determinante
        free(tempMatriz);
    }
    pthread_exit((void*)sum);//retornando o valor somado pela Thread
    free(sum);
}



// main
int main(int argc, char * argv[]){

    char filename[50];// nome do arquivo que sera lido 
    int *retorno;// valor de retorno das Threads
    long int sDet = 0;//soma dos determiantes das Threads
    pthread_t * tid;

    //receber parametros de entrada
    if(argc<4){
        printf("Digite: %s <Nome do arquivo> <Numero de Threads> <tamanho da matriz>\n",argv[0]);
        return 1;
    }
    strcpy(filename,argv[1]);
    nThreads = atoi(argv[2]);
    tMatriz = atoi(argv[3]);
    
    //aloca as estruturas
    //alocando a matriz principal
    Mat = (long int*) malloc(sizeof(long int)*pow(tMatriz,2));
    if(Mat == NULL){fprintf(stderr,"ERRO --malloc\n"); exit(0);}

    if(ler_matriz(tMatriz,Mat,filename) == 0){
        fprintf(stderr,"ERRO --ler_matriz");
        exit(0);
    }

    //alocando indentificadores de Threads
    tid = (pthread_t*) malloc(sizeof(pthread_t) * nThreads);
    if(tid == NULL){fprintf(stderr,"ERRO --malloc\n"); exit(0);}
    
    //criando Threads
    for(long int i = 0;i<nThreads;i++){
        if(pthread_create(tid+i,NULL,tarefa,(void*)i)){
            fprintf(stderr,"ERRO --malloc\n");
            exit(0);
        }
    }

    //espera o termino das Threads
    for(long int i = 0;i<nThreads;i++){
        if(pthread_join(*(tid+i),(void**) &retorno)){
            fprintf(stderr,"ERRO --pthread_join\n");
            exit(0);
        }
        sDet += *retorno;
    }

    //exibi resultado final 
    printf("\n");
    printf("O determiante via Thread: %ld\n",sDet);
    printf("O determiante via funcao: %ld\n",determinant(tMatriz,Mat));

    //libera areas alocadas
    free(Mat);
    free(tid);

 return 0;
}

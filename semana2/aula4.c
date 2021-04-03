/* De:Lucas Tatsuya Tanaka */
/* DRE:118058149 */
/* Email:tanaka@dcc.ufrj.br */
/* Github:https://github.com/tatsutanka */
/* Data:03/04/2021*/


#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

float *mat; // matriz de entrada
float *vet; // vetor de entrada
float *saida; // vetor de saida

typedef struct{
    int id; //indentificador do elemento que thread ira processar
    int dim; // dimensao das estruturas de entrada
} tArgs;

//tarefa
void * tarefa(void *arg){
    tArgs *args = (tArgs*) arg;
    for(int j=0; j<(args->dim);j++){
        saida[args->id] += mat[(args->id)*(args->dim)+j]*vet[j];
    }
    pthread_exit(NULL);
}

// main
int main(int argc, char * argv[]){
    int dim;//dimensao da matiz de entrada
    pthread_t *tid; // indentificadores da threas no sistema
    tArgs * args; //  indentificadores locais da dimensao

    //leitura e avaliacao dos parametros de entrada
    if(argc<2) {
        printf("Digite: %s <dimensao da matriz>\n",argv[0]);
        return 1;
    }
    dim = atoi(argv[1]);

    //alocacao de memoria para as estruturas de dados
    mat = (float *) malloc(sizeof(float) * dim * dim);
    if(mat == NULL){ printf("ERRO-- malloc\n"); return 2;}

    vet = (float *) malloc(sizeof(float) * dim * dim);
    if(vet == NULL){ printf("ERRO-- malloc\n"); return 2;}

    saida = (float *) malloc(sizeof(float) * dim * dim);
    if(saida == NULL){ printf("ERRO-- malloc\n"); return 2;}

    //inicializar as estruturas de dados
    for(int i=0;i<dim; i++){
        for(int  j=0;j<dim;j++){
            mat[i*dim+j] = 1;  //equivalente a mat[i][j]
        }
        vet[i] = 1;
        saida[i] = 0;
    }

    //multiplicacao da matriz pelo vetor
    //alocacao das estruuras
    tid = (pthread_t*) malloc(sizeof(pthread_t)*dim);
    if(tid == NULL) {puts("ERRO -- malloc"); return 2;}
    args = (tArgs*) malloc(sizeof(tArgs)*dim);
    if(tid == NULL) {puts("ERRO -- malloc"); return 2;}

    //criacao das threads
    for(int i=0; i < dim; i++){
        (args+i)->id = i;
        (args+i)->dim = dim;
        if(pthread_create(tid+i,NULL,tarefa,(void*) (args+i))){
            puts("ERRO--pthread_create");return 3;
        }
    }
    //espera pelo termino das threads
    for(int i=0; i<dim;i++){
        pthread_join(*(tid+i),NULL);
    }
    //exibicao dos resultados
    puts("Matriz de entrada");
    for(int i=0;i<dim; i++){
        for(int  j=0;j<dim;j++){
            printf("%lf ", mat[i*dim+j]);
        }
        puts("");
    }
    puts("vetor de entrada");
        for(int  j=0;j<dim;j++){
            printf("%lf ", vet[j]);
        }
        puts("");
    puts("vetor de saida");
        for(int  j=0;j<dim;j++){
            printf("%lf ", saida[j]);
        }
        puts("");

    //liberacao da memoria
    free(mat);
    free(vet);
    free(saida);
    free(tid);

    return 0;
}

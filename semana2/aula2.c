/* De:Lucas Tatsuya Tanaka */
/* DRE:118058149 */
/* Email:tanaka@dcc.ufrj.br */
/* Github:https://github.com/tatsutanka */
/* Data:30/03/2021*/


#include<stdio.h>
#include<stdlib.h>

float *mat; // matriz de entrada
float *vet; // vetor de entrada
float *saida; // vetor de saida

// main
int main(int argc, char * argv[]){
    int dim;//dimensao da matiz de entrada

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
    for(int i=0; i<dim;i++) {
        for(int j=0; j<dim;j++){
            saida[i] += mat[i*dim+j]*vet[j];
        }
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

    return 0;
}

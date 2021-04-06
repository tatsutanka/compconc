//soma todos os elementos de um vetor de inteiros 

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include"timer.h"

long int dim; //diensao do vetor de entrada
int nthreads; // numero de threads
int *vetor; // vetor de entrada com dimensao dim

//fluxo das threads


//fluxo princiapl
int main(int argc,char *argv[]){
    long int somaseq=0; //soma sequencial
    long int somaconc=0; //soma concorrente
    double ini,final; // tomada de ttempo
    // receber e avalida os paramentros de entrada (dimensao do vetor,numero de threads)
    if(argc < 3){
        fprintf(stderr,"Digite o %s <dimensao do vetor> <numero de threads>\n",argv[0]);
        return 1;
    }
    dim = atoi(argv[1]);
    nthreads = atoi(argv[2]);

    // aloca o vetor de entrada
    vetor = (int*) malloc(sizeof(int)*dim);
    if(vetor == NULL){fprintf(stderr,"ERRO--malloc\n"); return 2;}

    //preenche os vetores de entrada 
    for(long int i=0;i<dim;i++)
        vetor[i] = i%10000;

    // soma sequencial dos elementos
    GET_TIME(ini);
    for(long int i=0; i<dim;i++)
        somaseq += vetor[i];
    GET_TIME(final); 
    printf("Tempo sequencial: %lf\n",final-ini);
    //soma concorrente dos elementos 

    //criar as threads 

    //aguardar o termino das threads 

    //computar o valor final 

    //exibir os resultados 
    printf("Soma seq: %ld\n",somaseq);
    printf("Soma conc: %ld\n",somaconc);

    //libera as areas alocadas
    free(vetor);

    return 0;    
}

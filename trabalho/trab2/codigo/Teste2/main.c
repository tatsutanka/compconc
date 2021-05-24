/* De:Lucas Tatsuya Tanaka */
/* DRE:118058149 */
/* Email:tanaka@dcc.ufrj.br */
/* Github:https://github.com/tatsutanka */
/* Data:dd/mm/aa*/

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<pthread.h>
#include<unistd.h>
#include"Queue.h"
#include"Threads.h"


// main
int main(int argc, char * argv[]){
    pthread_t * tid; // indentificador de Threads
    int nLeitores; // numero de Threads Leitoras Criadas
    int nEscritores; // numero de Threads Escritoras criadas
    long int *id;

    //
    if(argc < 3){
        fprintf(stderr,"Digite: %s <Numero de sensores> <Numero de atuadores>\n",argv[0]);
        return 1;
    }
    nLeitores = atoi(argv[1]);
    nEscritores = atoi(argv[2]); 
    
    //------------------alocando espaco para as variaveis
    //aloca espaco para os indentificadores de Threads
    tid = (pthread_t *) malloc(sizeof(pthread_t) * (nLeitores + nEscritores));
    if(tid == NULL){fprintf(stderr,"ERRO --malloc\n"); return 3;}
    
    id = (long int*) malloc(sizeof(long int) * (nLeitores+nEscritores));
    if(id == NULL){fprintf(stderr,"ERRO --malloc\n"); return 3;}
    
    //aloca o monitor 
    thread_lock_init();

    //aloca espaco para a Estrutura e
    createEstrutura(nLeitores + nEscritores);
    
    //------------------criadno Threads
    //cria as threads leitoras
    for(long int i=0; i<nLeitores; i++) {
        id[i] = i;
        if(pthread_create(&tid[i], NULL, Leitor,(void*)&id[i])) exit(-1);
    } 
    
    //cria as threads escritoras
    for(long int i=0; i<nEscritores; i++) {
        id[i+nLeitores] = i + nLeitores;
        if(pthread_create(&tid[i+nLeitores], NULL, Escritor, (void*)&id[i+nLeitores]))exit(-1);
    } 

    //Monstradno os resultados
    
    pthread_exit(NULL);
    //espera do termino das Threads
    return 0;
}

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

//variaveis globais 
pthread_mutex_t mutex;// varivel de lock 
pthread_cond_t cond_leit,cond_escr; // variaveis de condicao 
int leit,escr;// indicadores de quantidade de leitores e escritores
int nLeitores; // numero de Threads Leitoras Criadas
int nEscritores; // numero de Threads Escritoras criadas

// main
int main(int argc, char * argv[]){
    pthread_t * tid; // indentificador de Threads
    Queue *q_key;// fila de compartilhada entre as Threads valores;
    Queue *q_id;// fila de compartilhada entre as Threads ids;
    Queue *q_leitura;// fila de compartilhada entre as Threads lidas;
    Estrutura *e; // Variavel compartilhada entre as Threads
    Monitor *m;

    //
    if(argc < 3){
        fprintf(stderr,"Digite: %s <Numero de sensores> <Numero de atuadores>",argv[0]);
        return 1;
    }
    nLeitores = atoi(argv[1]);
    nEscritores = atoi(argv[2]); 
    
    //------------------alocando espaco para as variaveis
    //aloca espaco para os indentificadores de Threads
    tid = (pthread_t *) malloc(sizeof(pthread_t) * (nLeitores + nEscritores));
    if(tid == NULL){fprintf(stderr,"ERRO --malloc"); return 3;}
    
    //aloca Queue
    q_key = createQueue(60);//capacidade de 60 definida
    q_id = createQueue(60);
    q_leitura = createQueue(60);

    //aloca o monitor 
    pthread_mutex_init(&mutex,NULL);
    pthread_cond_init(&cond_escr,NULL);
    pthread_cond_init(&cond_leit,NULL);

    m->cond_escr = &cond_escr;
    m->cond_leit = &cond_leit;
    m->escr = &escr;
    m->leit = &leit;
    m->mutex = &mutex;

    //aloca espaco para a Estrutura e
    e = (Estrutura*) malloc(sizeof(Estrutura) * (nLeitores + nEscritores));
    if(e == NULL){fprintf(stderr,"ERRO --malloc"); return 3;}
    //inicializa a Estrutura e
    for(int i = 0; i < (nLeitores+nEscritores); i++){
        e[i] = *createEstrutura(&e[i],q_key,q_id,q_leitura,m,i); 
    }

    //------------------criadno Threads
    //cria as threads leitoras
    for(int i=0; i<nLeitores; i++) {
      if(pthread_create(&tid[i], NULL, Leitor,&e[i])) exit(-1);
    } 
    
    //cria as threads escritoras
    for(int i=0; i<nEscritores; i++) {
      if(pthread_create(&tid[i+nLeitores], NULL, Escritor, &e[i+nLeitores])) exit(-1);
    } 

    //Monstradno os resultados

    //espera do termino das Threads
    return 0;
}

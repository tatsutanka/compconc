#include<limits.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include"Threads.h"
#include"Queue.h"

int readCount , writeCount;
sem_t rmutex,wmutex,mutex;
sem_t readTry,resource;
int bloqueados;
Estrutura *e;// variavel compartilhada
//Inicializador de Estrutura
void createEstrutura( int size){
    e = (Estrutura*) malloc(sizeof(Estrutura));
    e->q_key = (Queue*) malloc(sizeof(Queue));
    e->q_id = (Queue*) malloc(sizeof(Queue));
    e->q_leitura = (Queue*) malloc(sizeof(Queue));
    e->q_id = createQueue(60);
    e->q_key = createQueue(60);
    e->q_leitura = createQueue(60);
    e->size = size;
    printf("-----Inicializando Estrutura\n");

}

// inicia as variaveis de lock
void thread_lock_init(int nThreads){
    readCount = 0;
    writeCount = 0;
    sem_init(&resource,0,1);
    sem_init(&readTry,0,1);
    sem_init(&mutex,0,1);
    sem_init(&rmutex,0,1);
    sem_init(&wmutex,0,1);
    printf("-----iniciando_lock\n");
}

// Leitor --> atuadores
void * Leitor(void* arg){
    int *id = (int *)arg;
    int vermelho = 0;//indicador de leituras acima de 35 graus
    int amarelo = 0; // quantas vezes o valor 5 aparece 
    int q_lida = 0; // quantidade de vezes em que o valor for lido
    int qt = 1;
    int armazena[15]; // os 15 valores que serao lidos 
    double lido; // valor que sera lido 
    double  soma = 0;
    
    printf("***Leitor inicializado id[%d]\n",*id);
    while(1){
        //if(/*2 segundos se passaram*/){
            //ativar barreira das Threads
            //fazendo com que as Threads escritoras 
            //se bloqueiem e liberem depois as Threads 
            //leitores
        //}
        
        entLeitor();  
        //ler Escritor de mesmo id a cada 2 segundos     
        // a cada 2 segundos o valor tem que ser lido 
        
        /* ler os 15 valores e armazena em um array */ 
        /* caso os 5 primeiros sejam maior que 35  disparar */ 
        /* *vermelho* caso entre os os 15 sejam 35 */ 
        /* disparar *amarelo* caso nao diaprar *verde* */

        sleep(2);        

        for(int j=0,i=0;j<15;j++){
            if(e->q_id->array[e->q_id->front + j] == *id+(e->size/2)){
                armazena[i] = e->q_key->array[e->q_id->front + j];
                printf("Armazena[%d]:%d\n",i,armazena[i]);
                i++;
            }
        }

        //print vetor armazena
        printf("[");
        for(int i = 0;i<15;i++){
            printf("%d ",armazena[i]);
        }
        printf("]\n");
        
        for(int i = 0;i<15;i++){
            if(armazena[i] >= 35 ){
                vermelho++;
                amarelo++;
            }
            if(armazena[i] < 35){
                vermelho = 0;
            }
        }

        if(amarelo >= 5){
            printf("amarelo\n");
        }
        if(vermelho >= 5){
            printf("vemelho\n");
        }
        if(vermelho < 5 && amarelo < 5){
            printf("verde\n");
        }
        
        //Conta da media 
        qt = 0;
        soma = 0.0;
        for(int i=0;i<e->q_key->capacity;i++){
            if(e->q_key->array[i] != 0){
                soma += e->q_key->array[i];
                qt++;
            }
        }
        if(soma == 0){qt =1;}
        
        printf("A media %.2lf %.2lf\n",soma,(float)soma/qt);

        //retorna os valores da leitura para 0 
        for(int i = 0;i<15;i++){
            armazena[i] = 0;
        }
        amarelo = 0;
        vermelho = 0;

        saiLeitor();
    }    
    free(arg);
    pthread_exit(NULL);
}

// Escritor  --> sensores
void * Escritor(void* arg){
    int *id = (int*)arg;
    int num; // numero aleatorio gerado entre [25...40]
    int contador = 0; // contar quantas vezes foi feito a soma
    printf("***Escritor Iniciado id[%d]\n",*id);
    while(1){
        entEscritor(); 
        sleep(1); // irao atuar a cada 1 segundo 
        num = (rand()% (40 -25 +1)) + 25; // numero random entre 25 a 40
        if(num>30){
            //escreve no espaco compartilhado 
            // indentificador de valor
            // indentificador do sensor 
            // identificador de leitura
            contador++;
            if(e->q_key->capacity == e->q_key->size){
                dequeue(e->q_id);
                dequeue(e->q_key);
                dequeue(e->q_leitura);
            }
            enqueue(e->q_id,*id);
            enqueue(e->q_key,num);
            enqueue(e->q_leitura,0);
            printf("na frente do id: %d\n",*id);
            printf("na frente do key: %d\n",num);
            printf("na frente do leitura: %d\n",0);
            printf("contador %d\n",contador);
           
        }
        saiEscritor();
    }
    free(arg);
    pthread_exit(NULL);
}

// entra Leitor 
void entLeitor(){
    printf("Entra Leitor\n");
    sem_wait(&mutex);
    sem_wait(&readTry);
    sem_wait(&rmutex);
    readCount++;
    if(readCount == 1){
        printf("Dentro do readcount\n");
        sem_wait(&resource);
    }
    sem_post(&rmutex);
    sem_post(&readTry);
    sem_post(&mutex);
}

// sai Leitor
void saiLeitor(){
    sem_wait(&rmutex);
    readCount--;
    if(readCount == 0)
        sem_post(&resource);
    sem_post(&rmutex);
    printf("Sai Leitor\n");
}

// entra Escritor
void entEscritor(){
    printf("Entra Escritor\n");
    sem_wait(&wmutex);
    writeCount++;
    if(writeCount == 1){
        printf("Dentro do writecount\n");
        sem_wait(&readTry);
    }
    sem_post(&wmutex);
    sem_wait(&resource);
}

// sai Escritor
void saiEscritor(){
    sem_post(&resource);
    sem_wait(&wmutex);
    writeCount--;
    if(writeCount == 0){
        sem_post(&readTry);
    }
    sem_post(&wmutex);
    printf("sai Escritor\n");
}

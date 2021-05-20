//responsavel pelo controle das operacoes de Thread 

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include"Queue.h"

#ifndef THREAD_H
#define THREAD_H

//struct compartilhado
typedef struct monitor {
    pthread_mutex_t* mutex;// variavel de Lock
    pthread_cond_t* cond_leit,*cond_escr; // bloqueadores condicionais
    int *leit,*escr; // indicadores de quantidade de leitores e escritores
}Monitor;

typedef struct estrutura {
    Queue *q_key; // utilizando o padrao FIFO 
    Queue *q_id; // fila de id com o valor da temperatura
    Queue *q_leitura; // numero de Leituras de um sensor
    int id; // id da Thread
    Monitor *m;
}Estrutura;

//Inicia Estrutura
Estrutura* createEstrutura(Estrutura *e,Queue *q_key,Queue *q_id,Queue *q_leitura,Monitor *m, int id);

//Adiciona um valor a estrutura
Estrutura* addEstrutura(Estrutura *e,int key);

// leitura dos atuadores 
int readEstrutura(Estrutura *e,int posicao);

// entra Leitor 
void entLeitor(int id, Monitor *m);

// sai Leitor
void saiLeitor(int id,Monitor *m);

// entra Escritor
void entEscritor(int id,Monitor *m);

// sai Escritor
void saiEscritor(int id,Monitor *m);

// Leitor 
void * Leitor(void* arg);

// Escritor
void * Escritor(void* arg);

#endif

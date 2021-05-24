//responsavel pelo controle das operacoes de Thread 
#include<limits.h>
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include"Queue.h"

#ifndef THREAD_H
#define THREAD_H


typedef struct estrutura {
    Queue *q_key; // utilizando o padrao FIFO 
    Queue *q_id; // fila de id com o valor da temperatura
    Queue *q_leitura; // numero de Leituras de um sensor
    int size;
}Estrutura;

//Inicia Estrutura
void createEstrutura(int size);

// inicializador dos locks
void thread_lock_init();

// entra Leitor 
void entLeitor();

// sai Leitor
void saiLeitor();

// entra Escritor
void entEscritor();

// sai Escritor
void saiEscritor();

// Leitor 
void * Leitor(void* arg);

// Escritor
void * Escritor(void* arg);

#endif

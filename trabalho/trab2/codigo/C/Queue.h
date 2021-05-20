#include<stdio.h>
#include<stdlib.h>

#ifndef QUEUE_H
#define QUEUE_H

// Struct de fila 
typedef struct queue {
    int front, rear, size;
    int capacity;
    int* array;
}Queue;

// cria a fila
Queue * createQueue(int capacidade); 

// verifica se o tamanho é igual a capacidade
int isFull( Queue * queue); 

// verifica se o tamanho é zero
int isEmpty( Queue* queue);

// ve a frentee da fila 
int front(Queue * queue);

// ve o final da fila 
int rear( Queue * queue); 

// tira o elemento do toppo 
int dequeue( Queue * queue); 

// coloca o elemnto na fila 
void enqueue( Queue * queue, int key); 

#endif

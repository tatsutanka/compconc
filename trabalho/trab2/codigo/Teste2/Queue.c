#include<limits.h>
#include<stdio.h>
#include<stdlib.h>
#include"Queue.h"

// cria a fila
 Queue * createQueue(int capacidade){
    Queue * queue = (Queue*)malloc(sizeof(Queue));
    if(queue == NULL){fprintf(stderr,"ERRO --malloc"); exit(-1);}

    queue->capacity = capacidade;
    queue->front = queue->size = 0;

    // 
    queue->rear = capacidade -1;

    queue->array = (int *) malloc(queue->capacity * sizeof(int));
    if(queue->array == NULL){fprintf(stderr,"ERRO --malloc"); exit(-1);}

    for (int i = 0; i < queue->capacity; i++){
       queue->array[i] = 0; 
    }

    return queue;
}

// verifica se o tamanho é igual a capacidade
int isFull( Queue * queue){
    return (queue->size == queue->capacity);
}

// verifica se o tamanho é zero
int isEmpty( Queue* queue){
    return (queue->size == 0);
}

// ve a frente da fila 
int front( Queue * queue){
        if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->front];
}

// ve o final da fila 
int rear( Queue * queue){
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->rear];
}

// tira o elemento do toppo 
int dequeue( Queue * queue){
    if (isEmpty(queue))
        return INT_MIN;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1)
                   % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

// coloca o elemnto na fila 
void enqueue( Queue * queue, int key){
    if(isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = key;
    queue->size = queue->size+1;
}

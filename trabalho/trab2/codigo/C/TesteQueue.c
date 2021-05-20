#include<limits.h>
#include<stdio.h>
#include<stdlib.h>
#include"Queue.h"

#define NTESTE 10

int main (void) {
    Queue *q;
    int conta=0;
    // cria Queue
    q = createQueue(NTESTE);
    //imprime resultado da Queue
    printf("-----Inicializacao-----\n");
    for (size_t i = 0; i < q->capacity; i++){
       if(q->array[i] == 0){conta++;}
    }  
    printf("Tamanho vetor captado %d/%d\n",conta,q->capacity);
    // adicona valores
    conta = 0;
    printf("-----Adiciona Valor-----\n");
    for (size_t i = 0; i < NTESTE; i++){
       enqueue(q,i); 
       conta++;
    }
    printf("Tamanho vetor adicionado %d/%d\n",q->size,NTESTE);
    // imprime valores 
    // retira valores
    // imprime valores
    return 1;
}

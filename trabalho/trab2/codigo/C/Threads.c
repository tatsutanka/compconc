#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include"Threads.h"
#include"Queue.h"

//Inicializador de Estrutura
Estrutura* createEstrutura(Estrutura *e,Queue *q_key,Queue *q_id,Queue *q_leitura,Monitor *m, int id){
    e->q_key = q_key;
    e->q_id = q_id;
    e->q_leitura = q_leitura;
    e->m = m;
    e->id = id;
    return e;
}

//adiciona a Estrutura e de acordo com o id
Estrutura* addEstrutura(Estrutura *e,int key){
    enqueue(e->q_id,e->id); // adiciona o id que colocou na fila 
    enqueue(e->q_key,key); // adicona o valor a fila
    enqueue(e->q_leitura,1); // adiciona 1
    return e;
}

// realiza a leitura da estrutura para os leitores
// le a estrutura de acordo com a posicao relativa ao
// id
int readEstrutura(Estrutura *e,int posicao){
    int contPosicao = 0;
    //retornar Erro caso nao tenha Estrura
    if(isEmpty(e->q_id)){
        return 0;
    }
    //retorna Erro se nao tiver posicoes suficientes
    //
    for(int i=0;i<e->q_id->size;i++){
        if(e->id == e->q_id->array[i]){
            contPosicao++;
        }
        if(contPosicao == posicao){
            e->q_leitura->array[i]++;
            return e->q_key->array[i];
        }
    }
    

    return 0;    
}

// Leitor --> atuadores
void * Leitor(void* arg){
    Estrutura * e = (Estrutura*)arg;
    int lido; // valor que sera lido 
    int vermelho = 0;//indicador de leituras acima de 35 graus
    int amarelo = 0; // quantas vezes o valor 5 aparece 
    int q_lida = 0; // quantidade de vezes em que o valor for lido
    int soma = 0;
    int qt = 0;
    
    while(1){
        entLeitor(e->id,e->m);  

        //ler Escritor de mesmo id a cada 2 segundos     
        sleep(120); // leitura a cada 2 segundos
        
        //TODO o valor lido tem que ser o mesmo do id do 
        //escritor 
        /* lido = front(&e->q); */
        /*Toda vez que le adiciona contador de leitura*/
        //e->contadorLeitura++

        qt++;
        soma+=lido;
        if(lido >= 35){
            vermelho++;
            amarelo++;
            q_lida++;
        }
        if(lido < 35){
            vermelho = 0;
        }

        if(vermelho >= 5){
           // dispara um alerta vermelho 
           /*  // apos disparo valor zera ?
           vermelho = 0;
           */

            //passa pelos valores dos 5 ultimos valores com id igual
           printf("VERMELHO\n");
        }

        if(amarelo>=5 && q_lida >= 15){
            // passa pelos 15 ultimos valores do array com id  igual
            //dispara alerta amarelo
           printf("AMARELO\n");
        }
        if(vermelho < 5 && amarelo < 5 && q_lida < 15){
            //dispara sinal de condicao normal caso nenumha das leituras 
            //possitivo 
           printf("VERDE\n");
        }

        //deve ser printado a media das temperaturas constantemente 

        saiLeitor(e->id,e->m);
    }    
    pthread_exit(NULL);
}

// Escritor  --> sensores
void * Escritor(void* arg){
    Estrutura *e = (Estrutura*)arg;
    while(1){
       entEscritor(e->id,e->m); 
       sleep(60); // irao atuar a cada 1 segundo 
       int num = (rand()% (40 -25 +1)) + 25; // numero random entre 25 a 40
       if(num>30){
           //TODO
           //escreve no espaco compartilhado 
           // indentificador do sensor 
           // identificador de leitura
            
       }
       saiEscritor(e->id,e->m);
    }
    pthread_exit(NULL);
}

// entra Leitor 
void entLeitor(int id, Monitor *m){
    pthread_mutex_lock(m->mutex);
    while (m->escr > 0){
        pthread_cond_wait(m->cond_leit,m->mutex);
    }
    m->leit++;
    pthread_mutex_unlock(m->mutex);
}

// sai Leitor
void saiLeitor(int id,Monitor *m){
    pthread_mutex_lock(m->mutex);
    m->leit--;
    if(m->leit==0){pthread_cond_signal(m->cond_escr);}
    pthread_mutex_unlock(m->mutex);
}

// entra Escritor
void entEscritor(int id,Monitor *m){
    pthread_mutex_lock(m->mutex);
    while ((m->leit>0) || (m->escr>0)){
        pthread_cond_wait(m->cond_escr,m->mutex);
        
    }
    m->escr++;
    pthread_mutex_unlock(m->mutex);
}

// sai Escritor
void saiEscritor(int id,Monitor* m){
    pthread_mutex_lock(m->mutex);
    m->escr--;
    pthread_cond_signal(m->cond_escr);
    pthread_cond_broadcast(m->cond_leit);
    pthread_mutex_unlock(m->mutex);
}

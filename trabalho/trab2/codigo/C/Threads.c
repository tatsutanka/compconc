#include<limits.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include"Threads.h"
#include"Queue.h"
pthread_mutex_t mutex;// varivel de lock 
pthread_cond_t cond_leit,cond_escr; // variaveis de condicao 
int leit,escr;// indicadores de quantidade de leitores e escritores
Estrutura *e;// variavel compartilhada

//Inicializador de Estrutura
void createEstrutura( ){
    e = (Estrutura*) malloc(sizeof(Estrutura));
    e->q_key = (Queue*) malloc(sizeof(Queue));
    e->q_id = (Queue*) malloc(sizeof(Queue));
    e->q_leitura = (Queue*) malloc(sizeof(Queue));
    e->q_id = createQueue(60);
    e->q_key = createQueue(60);
    e->q_leitura = createQueue(60);
    printf("-----Inicializando Estrutura\n");

}

// inicia as variaveis de lock
void thread_lock_init(){
    pthread_mutex_init(&mutex,NULL);
    pthread_cond_init(&cond_escr,NULL); 
    pthread_cond_init(&cond_leit,NULL); 
    leit = 0;
    escr = 0;
    printf("-----iniciando_lock\n");
}
// realiza a leitura da estrutura para os leitores
// le a estrutura de acordo com a posicao relativa ao
// id
int readEstrutura(int id,int posicao){
    int contPosicao = 0;
    //retornar Erro caso nao tenha Estrura
    if(isEmpty(e->q_id)){
        //retorna valor de oversize
        return 0;
    }
    //TODO
    // o comportamento nao esta certo nao esta tratando as filas de forma 
    // correta pois e necessario que ele comece a ler a partir do comeco da 
    // fila nao do array
    for(int i=0;i<e->q_id->size;i++){
        
        if(contPosicao == posicao){
            e->q_leitura->array[i]++;
            return e->q_key->array[i];
        }

        if(id == e->q_id->array[i]){
            contPosicao++;
        }
    }
    
    //retorna Erro se nao tiver posicoes suficientes
    return 0;
}

// Leitor --> atuadores
void * Leitor(void* arg){
    int *id = (int *)arg;
    int vermelho = 0;//indicador de leituras acima de 35 graus
    int amarelo = 0; // quantas vezes o valor 5 aparece 
    int q_lida = 0; // quantidade de vezes em que o valor for lido
    int qt = 1;
    double lido; // valor que sera lido 
    double  soma = 0;
    double media = 0;
    
    printf("***Leitor inicializado id[%d]\n",*id);
    while(1){
        entLeitor();  
        //ler Escritor de mesmo id a cada 2 segundos     
        sleep(2); // leitura a cada 2 segundos
        
        //TODO o valor lido tem que ser o mesmo do id do 
        //escritor 
        /* lido = front(&e->q); */
        /*Toda vez que le adiciona contador de leitura*/
        //e->contadorLeitura++
        lido = readEstrutura(*id,0);
        soma+=lido;
        qt++;
        if(lido >= 35){
            vermelho++;
            amarelo++;
            q_lida++;
        }
        if(lido < 35){
            vermelho = 0;
            qt--;
        }

        if(vermelho >= 5){
           // dispara um alerta vermelho 
           /*  // apos disparo valor zera ?
           */
            vermelho = 0;
            
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
        media = soma/qt;
        printf("A media %lf %lf\n",soma,media);
        saiLeitor();
    }    
    free(arg);
    pthread_exit(NULL);
}

// Escritor  --> sensores
void * Escritor(void* arg){
    int *id = (int*)arg;
    int num; // numero aleatorio gerado entre [25...40]
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
            //TODO
            // tratar de quando ele ficar > 60 o tamanho da fila           
            if(e->q_key->size == e->q_key->capacity){
                dequeue(e->q_id);
                dequeue(e->q_key);
                dequeue(e->q_leitura);
            }
            enqueue(e->q_id,*id);
            enqueue(e->q_key,num);
            enqueue(e->q_leitura,0);
            printf("na frente do id: %d\n",front(e->q_id));
            printf("na frente do key: %d\n",front(e->q_key));
            printf("na frente do leitura: %d\n",front(e->q_leitura));
        }
        printf("*******valor:%d",num);
        saiEscritor();
    }
    free(arg);
    pthread_exit(NULL);
}

// entra Leitor 
void entLeitor(){
    pthread_mutex_lock(&mutex);
    /* printf("Quer ler\n"); */
    while (escr > 0){
        pthread_cond_wait(&cond_leit,&mutex);
    }
    leit++;
    pthread_mutex_unlock(&mutex);
}

// sai Leitor
void saiLeitor(){
    pthread_mutex_lock(&mutex);
    /* printf("terminou de ler\n"); */
    leit--;
    if(leit==0){pthread_cond_signal(&cond_escr);}
    pthread_mutex_unlock(&mutex);
}

// entra Escritor
void entEscritor(){
    pthread_mutex_lock(&mutex);
    /* printf("Quer escrever\n"); */

    while ((leit>0) || (escr>0)){
        pthread_cond_wait(&cond_escr,&mutex);
    }
    escr++;
    pthread_mutex_unlock(&mutex);
}

// sai Escritor
void saiEscritor(){
    pthread_mutex_lock(&mutex);
    /* printf("Terminou de escreve\n"); */
    escr--;
    pthread_cond_signal(&cond_escr);
    pthread_cond_broadcast(&cond_leit);
    pthread_mutex_unlock(&mutex);
}

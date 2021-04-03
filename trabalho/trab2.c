/* De:Lucas Tatsuya Tanaka */
/* DRE:118058149 */
/* Email:tanaka@dcc.ufrj.br */
/* Github:https://github.com/tatsutanka */
/* Data:03/04/2021*/


#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include"timer.h"

typedef struct{
    int id;
    int dim;
}tArgs;

// tarefa
    //multiplicao de matrizes
// main
int main(int argc,char *argv[]){

    //inicializacao das estruturas de dados
    //leitura e avaliacao dos parametros de entrada
    if(argc<3) {
        printf("Digite: %s <dimensao da matriz> < numero de threads>\n",argv[0]);
        return 1;
    }

        //inicializacao das estruturas vindo externamente
            // dimensoes da matriz
            // numero de threads
    //multiplicacao das matrizes
    //finalizacao de programas
 return 0;
}

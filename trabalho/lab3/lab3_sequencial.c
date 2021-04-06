/* De:Lucas Tatsuya Tanaka */
/* DRE:118058149 */
/* Email:tanaka@dcc.ufrj.br */
/* Github:https://github.com/tatsutanka */
/* Data:06/04/2021*/


#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"timer.h"

// main
int main(int argc,char * argv[]){
    long long int nSerie = 0; // o numero N do tamanho da serie expressa
    double sSerie = 0; // soma da serie

    // recebe e valida os paramentros de entrada
    if(argc < 2){
        fprintf(stderr,"Digite %s <Numero de elemntos N para a serie de pi>\n",argv[0]);
        return 1;
    }
    nSerie = atoll(argv[1]);

    //calculo da serie 
    for(int i = 0;i< nSerie;i++){
        sSerie += pow(-1,i)/((2*i)+1);
    }
    sSerie *= 4;
    // verificar resultado 
    printf("Contante M_PI: %.15f\n",M_PI);

    // imprimir resultado com 15 cassas decimais 
    printf("A soma adquirida: %.15f\n",sSerie);
    printf("A diferenca entre a soma: %.15f\n",M_PI - sSerie);

    return 0;
}

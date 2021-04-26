/* De:Lucas Tatsuya Tanaka */
/* DRE:118058149 */
/* Email:tanaka@dcc.ufrj.br */
/* Github:https://github.com/tatsutanka */
/* Data:23/04/2021*/

/*O objetivo do trabakho é o calculo do determinante de uma matriz atravez do
metodo de Sarrus e Laplace */

#include<stdio.h>
#include<stdlib.h>

double  det_laplace(int size_matriz , double * matriz){
    if(size_matriz == 1){
        printf("----sozinho: %f\n",matriz[0*size_matriz+0]);
        return matriz[0];
    }

    int lin,col;
    int j_aux,i_aux;
    double det = 0;

    //copiando os valores na matriz
    for(int i = 0; i < size_matriz;i++){
        if(matriz[0*size_matriz+i] != 0){
            double *aux ;
            aux = (double*)malloc(sizeof(double)*(size_matriz-1)*(size_matriz-1));
            if(aux == NULL){printf("ERRO -- malloc\n"); exit(0);}
            
            i_aux = 0;
            j_aux = 0;
            
            for(lin = 1;lin < size_matriz;lin++){
                for(col= 0;col < size_matriz;col++){
                    if(col != i){
                        aux[i_aux *size_matriz + j_aux] = matriz[lin*size_matriz+col];
                        j_aux++;
                    }
                }
                i_aux++;
                j_aux = 0;
            }   
            double factor = (i % 2==0)? matriz[0*size_matriz+i] : -matriz[0*size_matriz+i];
            printf("Factor:%f\n",factor);
            printf("Det:%f\n",det);
            det= det + (factor * det_laplace(size_matriz-1,aux)); //calculando de maneira recursiva
            //free(aux); //liberando valores alocados 
        }    
    }
    printf("***ReturnDet: %f\n",det);
    return det;
} 
// main
int main(int argc, char * argv[]){
    double *a;
    int size = 3;
    a = (double *)malloc(sizeof(double*)*size*size);
    if( a == NULL){printf("ERRO--malloc\n"); return 2;}
    
    for (int i=0;i<size;++i){
        for(int j=0;j<size;j++){
            a[i*size+j] = i*size+j;
        }
    }
    for (int i=0;i<size;i++){
        for(int j = 0 ;j<size;j++){
            printf("%f ",a[i*size+j]);
        }
        printf("\n");
    }
    printf("\n");
    
    printf("%f\n", det_laplace(size,a));

    free(a);
    printf("FINAL\n");
 return 0;
}


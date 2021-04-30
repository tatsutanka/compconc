/* De:Lucas Tatsuya Tanaka */
/* DRE:118058149 */
/* Email:tanaka@dcc.ufrj.br */
/* Github:https://github.com/tatsutanka */
/* Data:23/04/2021*/

/*O objetivo do trabakho é o calculo do determinante de uma matriz atravez do
metodo de Sarrus e Laplace */

#include<stdio.h>
#include<stdlib.h>

double detLaplace(int n, double a[n][n]){
    if(n == 1){ //Caso base: matriz 1x1
        printf("----sozinho: %f\n",a[0][0]);
        return a[0][0];
    }else{
        double det = 0;
        int i, row, col, j_aux, i_aux;
        
        //Escolhe a primeira linha para calcular os cofatores
        for(i = 0; i < n; i++){
            //ignora os zeros (zero vezes qualquer número é igual zero)
            if (a[0][i] != 0) {
                double aux[n - 1][n - 1];
                i_aux = 0;
                j_aux = 0;
                //Gera as matrizes para calcular os cofatores
                for(row = 1; row < n; row++){
                    for(col = 0; col < n; col++){
                        if(col != i){
                            aux[i_aux][j_aux] = a[row][col];
                            j_aux++;
                        }
                    }
                    i_aux++;
                    j_aux = 0;
                }
                double factor = (i % 2 == 0)? a[0][i] : -1 *a[0][i];
                printf(";;Fator:%f\n",factor);
                printf("**Det:%f\n",det);
                det = det + factor * detLaplace(n - 1, aux);
            }
        }
        return det;
    }
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
    
    printf("%lf\n", detLaplace(size,&a));

    free(a);
    printf("FINAL\n");
 return 0;
}


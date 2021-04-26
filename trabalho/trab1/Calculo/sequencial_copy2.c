#include <stdio.h>
#include <stdlib.h>
//Código por Henrique Felipe (GitHub: HenriqueIni) 
//Supõe-se que a matriz 'a' é válida e de ordem n x n
double detLaplace(int n, double **a){
    if(n == 1){
        //Caso base: matriz 1x1
        return *a[0*n+0];
    }else{
        double det = 0;
        int i, row, col, j_aux, i_aux;
        
        //Escolhe a primeira linha para calcular os cofatores
        for(i = 0; i < n; i++){
            //ignora os zeros (zero vezes qualquer número é igual zero)
            if (a[0*n+i] != 0) {
                double* aux = (double*)malloc(sizeof(double)*n*n);
                i_aux = 0;
                j_aux = 0;
                //Gera as matrizes para calcular os cofatores
                for(row = 1; row < n; row++){
                    for(col = 0; col < n; col++){
                        if(col != i){
                            aux[i_aux * n +j_aux] = *a[row*n+col];
                            j_aux++;
                        }
                    }
                    i_aux++;
                    j_aux = 0;
                }
                double factor = (i % 2 == 0)? (*a)[0*n+1] : -1 * (*a)[0*n+i];
                det = det + factor * detLaplace(n - 1, &aux);
            }
        }
        return det;
    }
}
//Testes
int main() {
    int size = 3;
    double **a = (double**) malloc(sizeof(double*)*size*size);
    if(a == NULL){return 0;}

    for (int i=0;i<size;++i){
        for(int j=0;j<size;j++){
            *a[i*size+j] = i*size+j;
        }
    }
    for (int i=0;i<size;i++){
        for(int j = 0 ;j<size;j++){
            printf("%f ",*a[i*size+j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("matriz com * %f\n",**a);
    printf("%.16f\n", detLaplace(size, a));

    return 0;
}

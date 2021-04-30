#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int determinant(int n,int *arr) 
{ 
    int i,j,k,sum=0,arr1[n-1][n-1]; 
    if(n>1){ 
        for(i=0;i<n;i++){ //iterating along the first row 
            for(j=0;j<n;j++){//creating the smaller matrix 
             
                if(j!=i) { 
                    for(k=1;k<n;k++) { 
                        if(j<i) 
                            arr1[k-1][j] = *(arr + j + n*k); 
                        else 
                            arr1[k-1][j-1] = *(arr + j + n*k); 
                    } 
                } 
            } 
        sum = sum + pow(-1,i)*(*(arr + i))*(determinant(n-1,*arr1)); 
        /*finally taking the sum, and passing the second matrix in another determinant function*/ 
		} 
        return sum; 
    } 
    else 
        return *arr; 
} 

int main(void){
    int size = 3;
    int *arr = (int*) malloc(sizeof(int)*size*size);

    for(int i = 0; i < size;i++){
        for(int j =0 ;j<size;j++){
            arr[i*size+j]=i*size+j;
        }
    }
    for(int i = 0; i < size;i++){

        for(int j =0 ;j<size;j++){
            printf("%d ",arr[i*size+j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("determinante:%d\n",determinant(size,arr));
    return 0;
}

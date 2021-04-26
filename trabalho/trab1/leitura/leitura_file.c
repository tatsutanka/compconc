#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int ler_matriz(int size,int* matriz,char* filename){
    FILE *fp;
    
    fp = fopen(filename,"r");
    if(fp == NULL){printf("ERRO --fopen\n"); return 0;}
    
    for(int i = 0;i < size;i++){
        for(int j = 0;j<size;j++){
                fscanf(fp,"%d",&matriz[i*size+j]);
        }
    }

    fclose(fp);
    return 1;
}




int main(int argv,char * argc[]){

    char file_name[30];
    int *matriz;
    int size = 10;

    if(argv < 2){
        printf("Digite:%s <caminho do arquivo>\n",argc[0]);
        return 0;
    }
    strcpy(file_name,argc[1]);

    matriz = (int*)malloc(sizeof(int)*size*size);
    if(matriz == NULL){printf("ERRO --malloc"); return 1;}

    ler_matriz(size,matriz,file_name);

    for(int i = 0;i < size ;i++){
            printf("\n");
            for(int j=0; j<size ;j++){
            printf("%d ",matriz[i*size+j]);
        }
    }
    printf("\n");

    free(matriz);
    return 0;
}

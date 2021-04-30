#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<math.h>

long int fatorial(long int arg){
    long long int resposta = 1;
    for(int i = 1;i<=arg;i++){
        resposta *=i;
    }
    return resposta;
}

int main(void){
    printf("fatorial:%ld\n",fatorial(10));
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<math.h>

double aux(int arg){
    double var;

    if(arg == 0 ){ return 0; }
    if(arg == 1){ return 6.0;}
    var = 34 * aux(arg-1) - aux(arg-2);
    return var;
}

int main(void){
    printf("O valor %f\n",aux(2));
    printf("O valor %f\n",aux(4));
    printf("O valor %f\n",aux(pow(2,7)));
    return 0;
}

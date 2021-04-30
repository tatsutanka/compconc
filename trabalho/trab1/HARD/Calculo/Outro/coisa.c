#include<stdio.h>
#include<stdlib.h>

int main(){
int i, j, n;
printf("Enter order of matrix: ");
scanf("%d", &n);
float* m=(float*)malloc(n*n*sizeof(float));
printf("Enter the matrix: n");
for(i = 0; i < n; i++){
for(j = 0; j < n; j++){
scanf("%f", &m[i*n+j]);
}
}
float ary[n-1];
float* subc=&ary[-1];
float det=m[0];
for(i=1;i<n;++i){
subc[i]=m[i]/det;
}
for(i=1;i<n-1;++i){
float dc=m[i*(n+1)]-subc[i];
for(j=i+1;j<n;++j){
subc[j]+=(m[j*n+i]-subc[j])/rc;
}
det*=dc;
}
det*=(m[i*(n+1)]-subc[i]);
free(m);
printf("The determinant of matrix is: %.2fnn", det);
return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int main(int argc, char **argv){

int i,n=4,*a,*b;

a=(int *)malloc(n*sizeof(int));
b=(int *)malloc(n*sizeof(int));

for(i=0;i<n;i++)
a[i]=1;

for(i=0;i<n;i++)
b[i]=2;
 
int sum=0;
#pragma omp parallel for reduction(+:sum)
for(i=0;i<4;i++)
sum=sum+(a[i]*b[i]);

printf("SUm=%d\n",sum);

return 0;
}

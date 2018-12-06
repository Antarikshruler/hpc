#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

long long factorial(long n)
{
long long out=1,i;

for(i=1;i<n+1;i++)
out*=i;
printf("%lld\n",out);
return (out);
}

int main(int argc, char *argv[]){

long long n=12;
int i,j;
long long *x;

x=(long long*)malloc(sizeof(long)*n);

#pragma omp parallel for firstprivate(x,j)
for(i=0;i<=n;i++)
x[i]=factorial(i);

for(i=0;i<=n;i++)
printf("%14lld\n",x[i]);

return 0;

}

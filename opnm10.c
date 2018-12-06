#include<stdio.h>
#include<omp.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{

int a[2],b[2],c[2];
int i,j,k;

for(i=0;i<2;i++)
a[i]=1;

for(i=0;i<2;i++)
b[i]=2;

#pragma omp parallel shared(a,b,c) private(i)
{




#pragma omp for schedule(static)

for(i=0;i<2;i++)
c[i]=a[i]+b[i];

}

for(i=0;i<2;i++)
printf("%d\n",c[i]);

return 0;

}

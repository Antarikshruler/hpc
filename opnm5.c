#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int main(int argc, char **argv){

int i,n=4,*a,*b,*c,*d;

a=(int *)malloc(n*sizeof(int));
b=(int *)malloc(n*sizeof(int));
c=(int *)malloc(n*sizeof(int));
d=(int *)malloc(n*sizeof(int));

for(i=0;i<n;i++)
a[i]=1;

for(i=0;i<n;i++)
b[i]=2;

for(i=0;i<n;i++)
c[i]=0;

for(i=0;i<n;i++)
d[i]=0;

#pragma omp parallel shared(a,b,c,d) private(i)
{

#pragma omp sections nowait
{
#pragma omp section
{
for(i=0;i<n;i++)
c[i]=a[i]+b[i];
}
#pragma omp section
{
for(i=0;i<n;i++)
d[i]=a[i]-b[i];
}
}

}

for(i=0;i<n;i++)
printf("%d\n",c[i]);

for(i=0;i<n;i++)
printf("%d\n",d[i]);

return 0;

}

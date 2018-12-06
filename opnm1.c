#include<stdio.h>
#include<omp.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{

int a[2][2],b[2][2],c[2][2];
int i,j,k;

int tid;

#pragma omp parallel shared(a,b,c) private(i,j,k,tid)
{

tid=omp_get_thread_num();

if(tid==0)
{
printf("First thread started....\n");
}

for(i=0;i<2;i++)
for(j=0;j<2;j++)
a[i][j]=i+j;

for(i=0;i<2;i++)
for(j=0;j<2;j++)
b[i][j]=i*j;

#pragma omp for schedule(static)

for(i=0;i<2;i++)
for(j=0;j<2;j++)
for(k=0;k<2;k++){
printf("Multiply done bt thread: %d\n",tid);
c[i][j]=a[i][k]*b[k][j];

}

}

for(i=0;i<2;i++)
for(j=0;j<2;j++)
printf("%d\n",c[i][j]);

return 0;

}

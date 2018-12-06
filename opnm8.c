#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int main(int argc, char **argv){
int i,max=-9999,*arr;

arr=(int *)malloc(5*sizeof(int));

arr[0]=1;
arr[1]=2;
arr[2]=3;
arr[3]=4;
arr[4]=5;

#pragma omp parallel shared(max)
{

#pragma omp critical
for(i=0;i<5;i++)
if(arr[i]>max)
max=arr[i];

}

printf("%d\n",max);
}

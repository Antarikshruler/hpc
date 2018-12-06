#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int main(){

omp_lock_t lock;

int *arr;

arr = (int *) malloc(sizeof(int) * 10);

arr[0]=1;
arr[1]=2;
arr[2]=3;
arr[3]=4;
arr[4]=5;
arr[5]=6;
arr[6]=7;
arr[7]=8;
arr[8]=9;
arr[9]=10;

omp_init_lock(&lock);

int i;

int max=-9999;

#pragma omp parallel for
for(i=0;i<=9;i++)
if(arr[i]>max)
{
omp_set_lock(&lock);
if(arr[i]>max)
max=arr[i];
omp_unset_lock(&lock);
}

omp_destroy_lock(&lock);

printf("%d\n",max);

return 0;

}



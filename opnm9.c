#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int a,b,x,tid;

#pragma omp threadprivate(a,x)

int main(int argc, char **argv){

#pragma omp parallel private(b,tid)
{
tid=omp_get_thread_num();
a=1;
b=2;
x=3;
printf("%d\t\t%d\t%d\t%d\n",tid,a,b,x);
}
printf("Second region:");
#pragma omp parallel private(tid) 
{

tid=omp_get_thread_num();
printf("%d\t\t%d\t%d\t%d\n",tid,a,b,x);
}
}

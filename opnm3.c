#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int main(int argc, char **argv){

int proc,numthread,tid;


#pragma omp parallel private(numthread,tid)
{

tid=omp_get_thread_num();
if(tid==0)
{

printf("%d\n",omp_get_num_threads());
printf("%d\n",omp_get_num_procs());
printf("%d\n",omp_get_dynamic());
printf("%d\n",omp_get_max_threads());
printf("%d\n",omp_in_parallel());
printf("%d\n",omp_get_nested());

}
}
}

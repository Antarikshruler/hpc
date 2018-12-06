#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>

void main(int argc, char **argv){

int i,rank,size,sendbuf,param[6];

MPI_Init(&argc,&argv);

MPI_Comm_rank(MPI_COMM_WORLD,&rank);
MPI_Comm_size(MPI_COMM_WORLD,&size);


sendbuf=23+rank;

if(rank==0)
printf("rank is 0\n");

MPI_Gather(&sendbuf,1,MPI_INT,param,1,MPI_INT,0,MPI_COMM_WORLD);

if(rank==0)
for(i=0;i<size;i++)
printf("%d\t%d\n",param[i],param[i]-23);

MPI_Finalize();

}



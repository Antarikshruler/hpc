#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>
#include<string.h>

void main(int argc, char **argv){

int size,rank;

MPI_Init(&argc,&argv);

MPI_Comm_rank(MPI_COMM_WORLD,&rank);
MPI_Comm_size(MPI_COMM_WORLD,&size);

printf("%d\n",size);

char message[12];

strcpy(message,"Hello MSRIT");

MPI_Bcast((void *)&message,12,MPI_CHAR,0,MPI_COMM_WORLD);

int i;
for(i=0;i<size;i++)
if(rank==i)
printf("%s\n",message);

MPI_Barrier(MPI_COMM_WORLD);

MPI_Finalize();

}

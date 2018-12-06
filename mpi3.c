#include<stdlib.h>
#include<stdio.h>
#include<mpi.h>

void main(int argc,char **argv){

int rank,size,sum=0,value,temp,i;

MPI_Status sta;

MPI_Init(&argc,&argv);

MPI_Comm_rank(MPI_COMM_WORLD,&rank);
MPI_Comm_size(MPI_COMM_WORLD,&size);

if(rank==0)
{


for(temp=1;temp<size;temp++){
MPI_Recv(&i,1,MPI_INT,temp,0,MPI_COMM_WORLD,&sta);
sum+=i;}

printf("%d\n",sum);

}
else{
value=1;
MPI_Send(&value,1,MPI_INT,0,0,MPI_COMM_WORLD);

}



MPI_Finalize();

}

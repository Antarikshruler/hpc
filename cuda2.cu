#include<stdio.h>

__global__ void local(float in){
float f;
f=in;
}

__global__ void global(float *a){
a[threadIdx.x]=2.0f*(float)threadIdx.x;
}

__global__ void shared(float *a){
int i,index=threadIdx.x;
float avg,sum=0.0f;
__shared__ float sh_a[128];
sh_a[index]=a[index];
__syncthreads();
//print(avg ther)
}

int main()
{
local<<<1,128>>>(2.0f);

float har[128];
float *dar;

cudaMalloc((void **)&dar,sizeof(float)*128);

cudaMemcpy((void *)dar,(void *)har,sizeof(float)*128,cudaMemcpyHostToDevice);

global<<<1,128>>>(dar);

cudaMemcpy((void *)har,(void *)dar,sizeof(float)*128,cudaMemcpyDeviceToHost);

shared<<<1,128>>>(dar);

cudaMemcpy((void *)har,(void *)dar,sizeof(float)*128,cudaMemcpyHostToDevice);

cudaDeviceSynchronize();
 return 0;

}

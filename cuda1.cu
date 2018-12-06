#include <stdio.h>

#include <stdlib.h>

#include <math.h>

//declare device and host
//alocate host
//alocate device
//initialise both
//memcopy

__global__ void vecAdd(double *a, double *b, double *c, int n)

{

    int id = blockIdx.x*blockDim.x+threadIdx.x;

    if (id < n)

        c[id] = a[id] + b[id];

}

 

int main( int argc, char* argv[] )

{


    int n = 100;

 


    double *h_a;

    double *h_b;


    double *h_c;


    double *d_a;

    double *d_b;


    double *d_c;

 

    // Allocate memory for each vector on host

    h_a = (double*)malloc(n*sizeof(double));

    h_b = (double*)malloc(n*sizeof(double));

    h_c = (double*)malloc(n*sizeof(double));

 

    // Allocate memory for each vector on GPU

    cudaMalloc(&d_a, n*sizeof(double));

    cudaMalloc(&d_b, n*sizeof(double));

    cudaMalloc(&d_c,n*sizeof(double));

 

    int i;

    // Initialize vectors on host

    for( i = 0; i < n; i++ ) {

        h_a[i] = i;

        h_b[i] = i;

    }

 

    // Copy host vectors to device

    cudaMemcpy( d_a, h_a, n*sizeof(double), cudaMemcpyHostToDevice);

    cudaMemcpy( d_b, h_b, n*sizeof(double), cudaMemcpyHostToDevice);


    vecAdd<<<1, 1024>>>(d_a, d_b, d_c, n);

 

    // Copy array back to host

    cudaMemcpy( h_c, d_c,n*sizeof(double), cudaMemcpyDeviceToHost );


    for(i=0; i<n; i++)

        printf(" %f + %f =%f\n",h_a[i],h_b[i],h_c[i]);


cudaDeviceSynchronize();

    cudaFree(d_a);

    cudaFree(d_b);

    cudaFree(d_c);

 
    free(h_a);

    free(h_b);

    free(h_c);

 

    return 0;

}


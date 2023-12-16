#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define TAM 32
void cria_matriz(float *M){
    int i;
    for(i=0; i<pow(TAM,2); i++){
        M[i] = (float)(rand() % 100)/100;
    }
 }


void multi_matriz(float *A,float *B,float *C){
    int i, j, k;

    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            C[i * TAM + j] = 0; // Inicializa o elemento C[i][j]

            for (k = 0; k < TAM; k++) {
                C[i * TAM + j] += A[i * TAM + k] * B[k * TAM + j];
            }
        }
    }
}

int main(){

    float *A;
    float *B;
    float *C;
    srand(time(NULL));

    A = malloc(pow(TAM,2)*sizeof(float));
    B = malloc(pow(TAM,2)*sizeof(float));
    C = malloc(pow(TAM,2)*sizeof(float));

    cria_matriz(A);

    cria_matriz(B);

    multi_matriz(A, B, C);

    free(A);
    free(B);
    free(C);
return 0;
}





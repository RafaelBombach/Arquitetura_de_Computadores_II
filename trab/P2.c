#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#define TAM 32

void cria_matriz(float ***M){
    int i;

    *M = (float **)malloc(TAM * sizeof(float *));
    for (i = 0; i < TAM; i++)
        (*M)[i] = (float *)malloc(TAM * sizeof(float));


}

void preenche_matriz(float **M) {
    int i, j;

    for (i = 0; i < TAM; i++)
        for (j = 0; j < TAM; j++)
            M[i][j] = (float)(rand() % 100) / 100;
}

void libera_matriz(float **M) {
    int i;

    for (i = 0; i < TAM; i++)
        free(M[i]);

    free(M);
}

void multiplica_matrizes(float **A, float **B, float **C){
    int i, j, k;

    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            C[i][j] = 0;

            for (k = 0; k < TAM; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {

    srand(time(NULL));
    float **A;
    float **B;
    float **C;


    cria_matriz(&A);
    cria_matriz(&B);
    cria_matriz(&C);

    preenche_matriz(A);
    preenche_matriz(B);

    multiplica_matrizes(A, B, C);

    libera_matriz(A);
    libera_matriz(B);
    libera_matriz(C);

    return 0;
}

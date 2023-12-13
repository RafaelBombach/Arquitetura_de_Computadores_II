#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define TAM 2
void cria_matriz(float *M){
    int i;
    for(i=0; i<pow(TAM,2); i++){
        M[i] = (float)(rand() % 100)/100;
    }
 }

void imprime_vetor(float *M){
    int i;
    for(i=0;i<pow(TAM,2);i++){
        printf("%.2f  ", M[i]);
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
    imprime_vetor(A);
    printf("\n \n");

    cria_matriz(B);
    imprime_vetor(B);
    printf("\n \n");

    imprime_vetor(C);
    printf("\n \n");
    multi_matriz(A, B, C);

    printf("\n \n");
    imprime_vetor(C);

    printf("\n \n");
    free(A);
    free(B);
    free(C);
return 0;
}



/*
int i, j, k;

    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            C[i * TAM + j] = 0; // Inicializa o elemento C[i][j]

            for (k = 0; k < TAM; k++) {
                C[i * TAM + j] += A[i * TAM + k] * B[k * TAM + j];
            }
        }
    }
}*/

/*
int i, j, k, l = 0, m = 0, indice = 0;

    for (i=0; i<=pow(TAM,2)-TAM; i+=TAM){
        for (j=0; j<TAM; j++){
            for (k=0;k<=pow(TAM,2);k++){
                indice = k % TAM;
                if (indice == l)
                    C[m] += A[j]*B[indice];
            }
            m++;
            l++;
        }
        l = 0;
    }
}
*/



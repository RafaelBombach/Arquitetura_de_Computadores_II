#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define TAM 32

float cria_matriz(float matriz[TAM][TAM]){
    int i, j;

    for(i=0; i <TAM; i++){
        for(j=0; j<TAM; j++){
            matriz[i][j] = (float)(rand() % 100)/100;
        }
    }

return matriz[TAM][TAM];
}

float multi_matriz(float matriz_A[TAM][TAM],float matriz_B[TAM][TAM], float matriz_C[TAM][TAM]){

    int i, j, k = 0;
    float acum = 0;

    for(i=0; i <TAM; i++){
        for(j=0; j<TAM; j++){
            for(k=0;k<TAM;k++){
                acum += (float)(matriz_A[i][k]*matriz_B[k][j]);
        }
        matriz_C[i][j] = acum;
        acum = 0;
        }
        printf("\n");
    }
return matriz_C[TAM][TAM];
}

int main(){

    float matriz_A[TAM][TAM];
    float matriz_B[TAM][TAM];
    float matriz_C[TAM][TAM] = {0};
    srand(time(NULL));

    matriz_A[TAM][TAM] = cria_matriz(matriz_A);
    matriz_B[TAM][TAM] = cria_matriz(matriz_B);


    matriz_C[TAM][TAM] = multi_matriz(matriz_A, matriz_B, matriz_C);
return 0;
}

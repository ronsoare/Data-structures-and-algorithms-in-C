#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void readvet(int *vet, unsigned length){
    unsigned i = 0;
    for (i; i < length; i++){
        scanf("%d%*c", &vet[i]);
    }
}
void showvet(int *vet, unsigned length){
    unsigned i = 0;
    for(i; i < length; i++){
        printf("%d ", vet[i]);
    }
    printf("\n");
}

void quick(int *vet, int inicio, int fim){
    int pivot, meio, tmp, i, j;
    if ( inicio <= fim){
        meio = (inicio + fim) / 2;
        pivot = vet[meio];
        i = inicio;
        j = fim;
        while ( i <= j){
            while (vet[i] < pivot){
                i++;
            }
            while (vet[j] > pivot){
                j--;
            }
            if (i <= j){
                tmp = vet[i];
                vet[i] = vet[j];
                vet[j] = tmp;
                i++;
                j--;
            }
        }
        quick(vet, inicio, j);
        quick(vet, i, fim);
    }
}

int main(){
    int tam;
    printf("Qual o tamanho do vetor:");
    scanf("%d%*c", &tam);
    int vet[tam];
    readvet(vet, tam);
    showvet(vet, tam);
    quick(vet, 0, tam-1);
    showvet(vet, tam);
}

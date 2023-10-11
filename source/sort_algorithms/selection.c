#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void selection(int *vetor, unsigned length){
    unsigned i, j, temp, index, penultimo;
    i = 0;
    penultimo = length - 1;
    while (i <  penultimo){
        index = i;
        j = i + 1;
        for (j; j < length; j++){
            if (vetor[j] < vetor[index]){
                index = j;
            }
        }
        temp = vetor[i];
        vetor[i] = vetor[index];
        vetor[index] = temp;
        i++;
    }
}

void readVetor(int *vetor, unsigned length){
    unsigned i = 0;
    for(i; i < length; i++){
        scanf("%d%*c", &vetor[i]);
    }
}
void showVetor(int *vetor, unsigned length){
    unsigned i = 0;
    for (i; i < length; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
}
int main(){
    unsigned length;
    printf("What's the size of the vector:");
    scanf("%d%*c", &length);
    int vetor[length];
    readVetor(vetor, length);
    selection(vetor, length);
    showVetor(vetor, length);

}

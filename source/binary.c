#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void readVetor(int *vetor, unsigned length){
    unsigned i;
    for (i=0; i < length; i++){
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

int binary(int *vetor, unsigned length, int value){
    unsigned begin, middle, end;
    begin = 0;
    end = length - 1;
    while (begin <= end){
        middle = (begin + end)/ 2;
        if (value == vetor[middle]){
            return 1;
        }
        else{
            if (value > vetor[middle]){
                begin = middle + 1;
            }
            else{
                end = middle - 1;
            }
        }
    }
    return 0;
}

int main(){
    unsigned tam;
    printf("Qual o tamanho fo vetor:");
    scanf("%d%*c",&tam);
    int vetor[tam];
    readVetor(vetor, tam);
    showVetor(vetor, tam);
    int value;
    printf("Qual valor você deseja buscar:");
    scanf("%d%*c", &value);
    int result = binary(vetor, tam, value);
    if (result){
        printf("Elemento encontrado!\n");
    }
    else{
        printf("Elemento não foi encontrado!\n");
    }

}

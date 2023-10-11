#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void readVector(int *vector, unsigned length){
    unsigned i = 0;
    for (i; i < length; i++){
        scanf("%d%*c", &vector[i]);
    }
}
void showVector(int *vector, unsigned length){
    unsigned i = 0;
    for (i; i < length; i++){
        printf("%d ", vector[i]);
    }
    printf("\n");
}
void insertion(int *vector, unsigned length){
    int i, j, pivo;
    i = 1;
    while (i < length){
        pivo = vector[i];
        j = i - 1;
        while( (j>=0) && (vector[j] > pivo) ){
            vector[j+1] = vector[j];
            j--;
        }
        vector[j+1] = pivo;
        i++;
    }
}
int main(){
    int vector[10];
    readVector(vector, 10);
    insertion(vector, 10);
    showVector(vector, 10);
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void mergeWords(char *word1, char *word2, char *word3){
    int len1, len2, i, j;
    len1 = strlen(word1);
    len2 = strlen(word2);
    i = j = 0;
    if (len1 == len2){
        while (j < len1){
            word3[i] = word1[j];
            word3[i+1] = word2[j];
            i+=2;
            j++;
        }
    }
    else{
        if (len1 < len2){
            while (j < len1){
                word3[i] = word1[j];
                word3[i+1] = word2[j];
                i+=2;
                j++;
            }
            while (j< len2){
                word3[i] = word2[j];
                i++;
                j++;
            }
        }
        else{
            while (j < len2){
                word3[i] = word1[j];
                word3[i+1] = word2[j];
                i+=2;
                j++;
            }
            while (j < len1){
                word3[i] = word1[j];
                i++;
                j++;
            }
        }
    }
}

int main(){
    char word1[100];
    char word2[100];
    char word3[200];
    printf("1° Palavra:");
    scanf("%[^\n]%*c",word1);
    printf("2° Palavra:");
    scanf("%[^\n]%*c",word2);
    mergeWords(word1, word2, word3);
    printf("Merge: %s\n",word3);

}

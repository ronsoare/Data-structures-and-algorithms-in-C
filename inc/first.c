#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Data{
    char name[50];
    int id;
} Data;
typedef struct No{
    Data data;
    struct No *next;
} No;
typedef struct List{
    No *first;
} List;
void inicialize( List *pont){
    pont -> first = NULL;
}
void insert( List *pont, Data info){
    No *aux = (No*) malloc(sizeof(No));
    aux -> data = info;
    aux -> next = pont -> first;
    pont -> first = aux;
}
void showList( List *pont){
    No *aux = pont -> first;
    while ( aux ){
        printf("name = %s\n", aux -> data.name);
        printf("id = %d\n", aux -> data.id);
        aux = aux -> next;
    }
}
void readStudent( Data data){
    printf("type the name: ");
    scanf("%[^\n]%*c", data.name);
    printf("Type the id: ");
    scanf("%d%*c", &data.id);
}
int main(){
    Data student;
    List lista;
    char name[100];
    scanf("%[^\n]%*c", name);
    printf("%s\n",name);
}

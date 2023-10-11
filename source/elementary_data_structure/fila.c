#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Student
{
    char name[100];
    int id;
}Student;

typedef struct No
{
    Student data;
    struct No * next;
}No;

typedef struct Fila
{
    No * first;
    No * last;
    unsigned length;
}Fila;

void inicialize( Fila *pont){
    pont -> first = NULL;
    pont -> last = NULL;
    pont -> length = 0;
}

void insertEnd(Fila *pont, Student *info){
    No *aux = (No*) malloc(sizeof(No));
    aux -> data = *info;
    aux -> next = NULL;
    if (pont -> last){
        pont -> last -> next = aux;
    }
    else{
        pont -> first = aux;
    }
    pont -> last = aux;
    pont -> length++;
}
void readStudent( Student *pont){
    printf("Name:");
    scanf("%[^\n]%*c",pont ->name);
    printf("Id:");
    scanf("%d%*c", &pont->id);
}
void showStudent( Student *pont){
    printf("Name:%s\n", pont->name);
    printf("Id:%d\n", pont->id);
}

void showFila(Fila *pont){
    if( pont -> first){
        No *aux = pont -> first;
        while(aux){
            showStudent(&aux -> data);
            aux = aux -> next;
        }
    }
}
Student * searchElement( Fila *pont, char *name){
    No *aux = pont -> first;
    while(aux){
        if (!strcasecmp(name, aux->data.name)){
            return &aux -> data;
        }
        aux = aux -> next;
    }
    return NULL;
}
void removeFirst( Fila *pont, char *name){
    if (pont -> first){
        No * tmp = pont -> first;
        if ( tmp -> next ){
            pont -> first = tmp -> next;
        }
        else{
            pont -> first = NULL;
            pont -> last = NULL;
        }
        free(tmp);
    }
}

int removeElement( Fila *pont, char *name){
    No *aux, *tmp;
    aux = pont -> first;
    if ( !strcasecmp(name, aux->data.name)){
        tmp = aux;
        pont -> first = tmp -> next;
        if ( !pont -> first){
            pont -> last = NULL;
        }
        free(tmp);
        return 1;
    }
    while(aux -> next){
        if ( !strcasecmp(name, aux -> next->data.name)){
                tmp = aux -> next;
                if ( !tmp -> next){
                    pont -> last = aux;
                }
                aux -> next = tmp -> next;
                free(tmp);
                return 1;
        }
        aux = aux -> next;
    }
    return 0;   
}

int main(){
    Student student, *result;
    Fila fila;
    inicialize(&fila);
    unsigned i;
    char name[100];
    for ( i = 0; i < 1; i++){
        readStudent(&student);
        insertEnd(&fila, &student); 
    }
    printf("A fila em ordem:\n");
    showFila(&fila);
    printf("Remova um nome da a partir do segundo elemento:\n");
    scanf("%[^\n]%*c",name);
    if (removeElement(&fila, name)){
        printf("Elemento removido.\n");
    }
    else{
        printf("Elemento não está presente na fila.\n");
    }
    showFila(&fila);
    printf("Primeiro elemento da fila: %s\n", fila.first->data.name);
    printf("Último elemento da fila:%s\n", fila.last->data.name);
}

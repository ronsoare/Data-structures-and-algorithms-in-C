#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Student{
    char name[100];
    unsigned id;
} Student;

typedef struct No
{
    Student data;
    struct No * next;
}No;

typedef struct Lista
{
    No *first;
    No * last;
    unsigned length;
}Lista;

void inicialize( Lista *pont){
    pont -> first = NULL;
    pont -> last = NULL;
    pont -> length = 0;
}
void inserElement(Lista *pont, Student *info ){
    No *aux = (No*) malloc(sizeof(No));
    aux -> data = *info;
    aux -> next = pont -> first;
    pont -> first = aux;
    if ( pont -> last == NULL){
        pont -> last = aux;
    }
    pont -> length ++;
}
void readStudent(Student *student){
    scanf("%[^\n]%*c", student -> name);
    scanf("%d%*c", &student -> id);
}
void showStudent( Student *student){
    printf("Name:%s\n", student -> name);
    printf("Id:%u\n", student -> id);
}
void showLista(Lista *pont){
    No *aux = pont -> first;
    while (aux){
        showStudent(&aux -> data);
        aux = aux -> next;
    }
}
int main(){
    Student student;
    Lista lista;
    inicialize(&lista);
    unsigned i = 0;
    for (i; i < 4; i++){
        readStudent(&student);
        inserElement(&lista, &student);
    }
    showLista(&lista);
    printf("lista -> first: %s e %d\n", lista.first->data.name, lista.first->data.id);
    printf("lista -> last: %s e %d\n", lista.last ->data.name, lista.last->data.id);
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// struct that of datas
typedef struct Data{
    char name[50];
    int id;
} Data;
// struct of Node
typedef struct Node{
    Data data;
    struct Node *next;
} Node;
// struct for linked list
typedef struct List{
    Node *first;
    int length;
} List;
// function that inicialize a list;
void inicialize( List *pont){
    pont -> first = NULL;
    pont -> length = 0;
}
// funciont that use to implement a inserction in a linked list;
void insert( List *pont, Data info){
    Node *aux = (Node*) malloc(sizeof(Node));
    aux -> data = info;
    aux -> next = pont -> first;
    pont -> first = aux;
    pont -> length += 1;
}
// function that show each element ( student and id) of linked list
void showList( List *pont){
    Node *aux = pont -> first;
    while ( aux ){
        printf("name = %s\n", aux -> data.name);
        printf("id = %d\n", aux -> data.id);
        aux = aux -> next;
    }
}
// function that read information about student, such as your name and id.
void readStudent( Data *data){
    printf("type the name: ");
    scanf("%[^\n]%*c", data -> name);
    printf("Type the id: ");
    scanf("%d%*c", &data -> id);
}
// fucntion that read a sequence of students.
void readList( List *pont, Data *data, unsigned length){
     unsigned i  = 0;
     for ( i; i < length; i++){
        readStudent(data);
        insert(pont,*data);
     }
}
int main(){
    Data student;
    List list;
    inicialize(&list);
    int num;
    printf("Hom many students would you like to read: ");
    scanf("%d%*c",&num);
    readList(&list, &student, num);
    printf("length of list: %d\n", list.length);
    showList(&list);
}

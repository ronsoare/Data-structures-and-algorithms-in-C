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
    Node *last;
    int length;
} List;
// function that inicialize a list;
void inicialize( List *pont){
    pont -> first = NULL;
    pont -> last = NULL;
    pont -> length = 0;
}
// funciont that use to implement a inserction in a linked list;
void insert( List *pont, Data info){
    Node *aux = (Node*) malloc(sizeof(Node));
    aux -> data = info;
    aux -> next = pont -> first;
    if ( !pont -> first ){
        pont -> last = aux;
    }
    pont -> first = aux;
    pont -> length += 1;
}
void insertEnd( List *pont, Data info){
    Node *aux = (Node*) malloc(sizeof(Node));
    aux -> data = info;
    aux -> next = NULL;
    if ( pont -> last ){
        pont -> last -> next = aux;
    }
    else{
        pont -> first = aux;
    }
    pont -> last = aux;
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
        insertEnd(pont,*data);
     }
}
// first way to verifiy if one especific element to be in list.
Data  * searchElementInList( List *pont, char *name){
    Node * aux = pont -> first;
    while ( aux ){
        if ( !strcasecmp(name, aux->data.name) ){
            return &aux ->data;
        }
        aux = aux -> next;
    }
    return NULL;
}   
int removeElement( List *point, int id){
    if ( point -> first ){
        Node *aux, *tmp;
        if ( point -> first->data.id == id ){
            tmp = point -> first;
            point -> first = tmp -> next;
            if ( !point -> first ){
                point -> last = NULL;
            }
            free(tmp);
            return 1;
        }
        aux = point -> first;
        while ( aux -> next ){
            if ( aux -> next -> data.id == id ){
                tmp = aux -> next;
                if ( tmp == point -> last ){
                    point -> last = aux;
                }
                aux -> next = tmp -> next;
                free(tmp);
                return 1;
            }
            aux = aux -> next;
        }
    }
    return 0;
}   
int main(){
    Data student;
    int result, id, num, i;
    List list;
    char name[50];
    inicialize(&list);
    printf("Hom many students would you like to read: ");
    scanf("%d%*c",&num);
    readList(&list, &student, num);
    i = 1;
    showList( &list);
    printf("Length of list = %d \nid of last element = %d \nid of the first element = %d \n", list.length, list.last->data.id, list.first->data.id);
}

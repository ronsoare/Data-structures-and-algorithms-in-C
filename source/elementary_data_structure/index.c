#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Student{
    char name[100];
    unsigned id;
}Student; 

typedef struct No
{
    Student data;
    struct No *next;
}No;

typedef struct Stack
{
    No *first;
}Stack;

void inicialize( Stack *pont){
    pont -> first = NULL;
}

void insertElement(Stack *pont, Student *info){
    No *aux = (No*) malloc(sizeof(No));
    aux -> data = *info;
    aux -> next = pont -> first;
    pont -> first = aux; 
}
void showStack( Stack *pont){
    if ( pont -> first != NULL){
        No *aux = pont -> first;
        while( aux != NULL){
            printf("Nome: %s\n", aux ->data.name);
            printf("Id: %d\n", aux -> data.id);
            aux = aux -> next;
        }
    }
}
void insertStudent( Student *student){
    scanf("%[^\n]%*c", student -> name);
    scanf("%d%*c", &student -> id);
}
void showStudent( Student *student){
    printf("%s\n", student -> name);
    printf("%d\n",student -> id);
}

int searchElement( Stack *pont, char *name){
    No *aux = pont -> first;
    while ( aux ){
        if ( !strcmp(name, aux -> data.name)){
            return 1;
        }
        aux = aux -> next;
    }
    return 0;    
}
int removeElement( Stack *pont, char *name){
    if( pont -> first){
        No *aux, *tmp;
        aux = pont -> first;
        if ( !strcasecmp(name, pont -> first -> data.name) ){
            tmp = pont -> first;
            pont -> first = tmp -> next;
            free(tmp);
            return 1;
        }
        while( aux -> next ){
            if ( !strcasecmp(name, aux ->next->data.name)){
                tmp = aux -> next;
                aux -> next = tmp -> next;
                return 1;
            }
            aux = aux -> next;
        }
    }
    return 0;
}
float average(Stack *pont){
    No *aux = pont ->  first;
    float sum = 0.0;
    int qtd = 0;
    while ( aux ){
        sum += aux -> data.id;
        qtd++;
        aux =  aux -> next;
    }
    if (qtd){
        sum =  sum /  qtd;
    }
    return sum;
}
unsigned countName(Stack *pont, char letter){
    No *aux = pont -> first;
    unsigned count = 0;
    while( aux ){
        if ( aux -> data.name[0] == letter){
            count++;
        }
        aux = aux -> next;
    }
    return count;
}

int main(){
    Student a;
    Stack stack;
    inicialize(&stack);
    unsigned i = 0;
    for (i; i < 5; i++){
        insertStudent(&a);
        insertElement(&stack, &a);
    }
    //showFila(&stack);
    char *name = (char*) malloc(sizeof(char)*20);
    printf("Digite o nome para a busca:");
    scanf("%[^\n]%*c", name);
    int result_search = searchElement(&stack, name);
    if ( result_search ){
        printf("Aluno está na pilha\n");
    }
    else{
        printf("Aluno não está na pilha\n");
    }
    printf("A média das ids é %.2f\n", average(&stack));
    printf("Qunatidade de alunos com a letra r:%d\n", countName(&stack, 'r'));
}


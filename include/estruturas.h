#include <stdio.h>
#include <stdlib.h>

typedef struct Elemento{
    int x;
    int peso;
}Elemento;

typedef struct Celula{
    Elemento e;
    struct Celula *prox;
}Celula;

typedef struct Queue{
    Celula *comeco;
    Celula *fim;
    int tam;
}Queue;

Queue *criarQueue();
Celula *novaCelula(Elemento e);
void enqueue(Queue *fila, int x, int peso);
Elemento dequeue(Queue *fila);
void printQueue(Queue *fila);

typedef struct Stack{
    int elementos[30];
    int topo;
}Stack;

Stack *criarStack();
void push(Stack *pilha, int x);
int pop(Stack *pilha);

typedef struct ListCell{
    Elemento e;
    struct ListCell *prox;
    struct ListCell *ant;
}ListCell;

typedef struct List{
    ListCell *comeco;
    ListCell *fim;
    int tam;
}List;

ListCell *novaListCell(Elemento e);
List *criarList();
void insertComeco(List *lista, int x, int peso);
void insertFim(List *lista, int x, int peso);
void insert(List *lista, int x, int peso, int pos);
Elemento removeComeco(List *lista);
Elemento removeFim(List *lista);
Elemento removeCell(List *lista, int pos);
void printList(List *lista);

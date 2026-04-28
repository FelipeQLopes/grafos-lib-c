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
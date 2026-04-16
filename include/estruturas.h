#include <stdio.h>
#include <stdlib.h>

typedef struct Queue{
    int elementos[30];
    int comeco;
    int fim;
}Queue;

Queue *criarQueue();
void enqueue(Queue *fila, int x);
int dequeue(Queue *fila);

typedef struct Stack{
    int elementos[30];
    int topo;
}Stack;

Stack *criarStack();
void push(Stack *pilha, int x);
int pop(Stack *pilha);
#include "../include/estruturas.h"

Queue *criarQueue(){
    Queue *fila = malloc(sizeof(Queue));
    fila->comeco = 0;
    fila->fim = 0;
    return fila;
}

void enqueue(Queue *fila, int x){
    fila->elementos[fila->fim] = x;
    fila->fim = fila->fim % (sizeof(fila->elementos)/sizeof(fila->elementos[0])) + 1;
}

int dequeue(Queue *fila){
    int elemento = fila->elementos[fila->comeco];
    fila->elementos[fila->comeco] = -1;
    fila->comeco = fila->comeco % (sizeof(fila->elementos)/sizeof(fila->elementos[0])) + 1;;
    return elemento;
}

Stack *criarStack(){
    Stack *pilha = malloc(sizeof(Stack));
    pilha->topo = 0;
    return pilha;
}

void push(Stack *pilha, int x){
    pilha->elementos[++pilha->topo] = x;
}

int pop(Stack *pilha){
    return pilha->elementos[pilha->topo--];
}
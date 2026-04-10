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
    fila->comeco++;
    return elemento;
}
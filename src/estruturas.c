#include "../include/estruturas.h"

Queue *criarQueue(){
    Queue *fila = malloc(sizeof(Queue));
    fila->comeco = 0;
    fila->fim = 0;
    fila->tam = 0;
    return fila;
}

void enqueue(Queue *fila, int x){
    fila->elementos[fila->fim].x = x;
    fila->fim = (fila->fim + 1) % (sizeof(fila->elementos)/sizeof(fila->elementos[0]));
    fila->tam++;
}

void prioEnqueue(Queue *fila, int x, int peso){
    Elemento e1, temp;
    e1.x = x;
    e1.peso = peso;
    int i, j, cont, cont1;
    int tamanho = sizeof(fila->elementos)/sizeof(fila->elementos[0]);
    
    fila->tam++;
    for(i = 0; i < fila->tam; i++){
        cont = (fila->comeco + i) % tamanho;
        if(e1.peso < fila->elementos[cont].peso){
            for(int j = fila->tam; j > i; j--){
                cont1 = (fila->comeco + j) % tamanho;
                fila->elementos[cont1] = fila->elementos[cont1 - 1];
            }
            break;
        }
    }
    fila->elementos[cont] = e1;
    fila->fim = (fila->fim + 1) % tamanho;
}

Elemento dequeue(Queue *fila){
    Elemento e1 = fila->elementos[fila->comeco];
    fila->comeco = (fila->comeco + 1) % (sizeof(fila->elementos)/sizeof(fila->elementos[0]));
    fila->tam--;
    return e1;
}

void printQueue(Queue *fila){
    Queue f = *fila;
    for(int i = 0; i < fila->tam; i++){
        Elemento e = dequeue(&f);
        printf("%d - %d\n", e.x, e.peso);
    }
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
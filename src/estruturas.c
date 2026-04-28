#include "../include/estruturas.h"

Queue *criarQueue(){
    Queue *fila = malloc(sizeof(Queue));
    Elemento e; e.x = -1;
    fila->comeco = novaCelula(e);
    fila->fim = fila->comeco;
    fila->tam = 0;
    return fila;
}

Celula *novaCelula(Elemento e){
    Celula *nova = (Celula*)malloc(sizeof(Celula*));
    nova->e = e;
    nova->prox = NULL;
    return nova;
}

void enqueue(Queue *fila, int x, int peso){
    Elemento e1;
    e1.x = x; e1.peso = peso;
    Celula *temp;
    temp = fila->comeco;
    Celula *inserido = novaCelula(e1);
    for(Celula* c = temp->prox; c != NULL; c = c->prox){
        if(c->e.x == x){
            if(c->e.peso <= peso){
                return;
            }
            temp->prox = c->prox;
            c->prox = NULL;
            free(c);
        }else{
            temp = c;
        }
    }
    
    temp = fila->comeco;

    for(Celula *c = temp->prox; c != NULL; c = c->prox){
        if(inserido->e.peso < c->e.peso){
            temp->prox = inserido;
            inserido->prox = c;
            break;
        }
        temp = c;
    }

    if(temp->prox == NULL){
        fila->fim->prox = inserido;
        fila->fim = fila->fim->prox;
    }
    fila->tam++;

}    

Elemento dequeue(Queue *fila){
    Celula *temp;
    Elemento e;

    temp = fila->comeco->prox;
    fila->comeco->prox = temp->prox;
    temp->prox = NULL;
    e = temp->e;
    free(temp);
    fila->tam--;
    if(fila->tam == 0){
        fila->fim = fila->comeco;
    }

    return e;
}

void printQueue(Queue *fila){
    Queue f = *fila;
    for(Celula *c = fila->comeco->prox; c != NULL; c = c->prox){
        Elemento e = c->e;
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
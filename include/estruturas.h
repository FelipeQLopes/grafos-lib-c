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
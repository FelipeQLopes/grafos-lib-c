#include <stdio.h>
#include <stdbool.h>
#include "../include/grafos.h"


int main(){
    /*
    Grafo *g = criarGrafo("Grafo Direcionado", 6, true);
    addAresta(g, 'A', 'B');
    addAresta(g, 'D', 'A');
    addAresta(g, 'B', 'E');
    addAresta(g, 'E', 'C');
    addAresta(g, 'C', 'A');
    addAresta(g, 'D', 'F');
    addAresta(g, 'A', 'F');
    printGrafo(g);
    */
    
    Queue *fp = criarQueue();

    prioEnqueue(fp, 0, 5);
    prioEnqueue(fp, 1, 4);
    prioEnqueue(fp, 2, 7);
    prioEnqueue(fp, 3, 3);
    prioEnqueue(fp, 4, 6);
    prioEnqueue(fp, 5, 0);
    prioEnqueue(fp, 6, 2);

    printQueue(fp);
}
#include <stdio.h>
#include <stdbool.h>
#include "../include/grafos.h"

int main(){

    Grafo *g = criarGrafo("Grafo Direcionado", 6, true);
    addAresta(g, 'A', 'B');
    addAresta(g, 'D', 'A');
    addAresta(g, 'B', 'E');
    addAresta(g, 'E', 'C');
    addAresta(g, 'C', 'A');
    addAresta(g, 'D', 'F');
    addAresta(g, 'A', 'F');
    printGrafo(g);
    char vertices[4] = {'A', 'B', 'C', 'E'};
    fusaoVertices(g, vertices, 4);
    printGrafo(g);

    return 0;
}

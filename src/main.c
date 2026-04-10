#include <stdio.h>
#include <stdbool.h>
#include "../include/grafos.h"

int main(){

    Grafo *g = criarGrafo("Teste", 5, true);
    addVertice(g);
    addAresta(g, 'A', 'B');
    addAresta(g, 'D', 'A');
    addAresta(g, 'B', 'E');
    addAresta(g, 'E', 'C');
    addAresta(g, 'C', 'A');
    addAresta(g, 'D', 'F');
    addAresta(g, 'A', 'F');
    addAresta(g, 'F', 'F');

    Grafo *gt = criarGrafoTransposto(g);
    Grafo *gl = criarGrafoLinha(g);
    
    printGrafo(g);
    printGrafo(gt);
    printGrafo(gl);
    return 0;
}

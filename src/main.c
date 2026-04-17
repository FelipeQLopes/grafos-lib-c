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

    int scc = contarSCC(g);
    printf("\n%d SCCs", scc);

    fusaoVertices(g, "ABCE", 4);
    printGrafo(g);
}

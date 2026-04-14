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

    Fecho *fechoTD = fechoTransitivoD(g, 'A');
    Fecho *fechoTI = fechoTransitivoI(g, 'A');

    printf("\nFecho Transitivo Direto: ");
    for(int i = 0; i < fechoTD->qtd; i++){
        printf("%c ", g->V[fechoTD->fecho[i]].nome);
    }
    
    printf("\nFecho Transitivo Indireto: ");
    for(int i = 0; i < fechoTI->qtd; i++){
        printf("%c ", g->V[fechoTI->fecho[i]].nome);
    }

    return 0;
}

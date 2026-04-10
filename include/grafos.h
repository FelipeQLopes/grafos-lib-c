#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Vertice{
    char nome;
    char label[30];
    float peso;
    int grauEntrada;
    int grauSaida;
}Vertice;

typedef struct Aresta{
    int u;
    int v;
    char label[30];
    float peso;
}Aresta;

typedef struct Grafo {
    char nome[30];
    Vertice V[30];
    Aresta E[225];
    int qtdArestas;
    int qtdComponentes;
    int qtdVertices;
    bool isCiclico;
    bool isConexo;
    bool isDirecionado;
    bool isSimples;
    int Euleriano;
    int Hamiltoniano;
    char ultimoVertice;
}Grafo;

Grafo *criarGrafo(char nomeGrafo[], int qtdVertice, bool direcionado);
Grafo *criarGrafoTransposto(Grafo *g);
Grafo *criarGrafoLinha(Grafo *g);
void addAresta(Grafo *g, char u, char v);
void delArestaUV(Grafo *g, char u, char v, bool todos);
void delArestaNum(Grafo *g, int indice);
void addVertice(Grafo *g);
void delVertice(Grafo *g, char u);
int acharVertice(Grafo *g, char nome);
void printGrafo(Grafo *g);
void premissas(Grafo *g);
void limparLW(Grafo *g);
void buscaProfundidade(Grafo *g);
void buscaProfundidade_rec(Grafo *g, int i);
void buscaProfundidade_rec_print(Grafo *g, int i);
void buscaLargura(Grafo *g);
int verificarEuleriano(Grafo *g);
int verificarHamiltoniano(Grafo *g);
void isConexo(Grafo *g);
void isSimples(Grafo *g);
void isCiclico(Grafo *g);

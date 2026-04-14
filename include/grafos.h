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
    Vertice V[25];
    Aresta E[300];
    int qtdArestas;
    int qtdVertices;
    bool isCiclico;
    bool isConexo;
    bool isDirecionado;
    bool isSimples;
    int Euleriano;
    int Hamiltoniano;
    char ultimoVertice;
}Grafo;

typedef struct Fecho{
    int fecho[25];
    int qtd;
}Fecho;

Grafo *criarGrafo(char nomeGrafo[], int qtdVertice, bool direcionado);  //Função de Criar o Grafo Direcionado ou Não direcionado
Grafo *criarGrafoTransposto(Grafo *g);                                  //Cria um Grafo Transposto de G
Grafo *criarGrafoLinha(Grafo *g);                                       //Cria um Grafo Linha de G
Grafo *clonarGrafo(Grafo *g, char *nome, bool direcionado);             //Faz um clone do Grafo G corretamente com um construtor bem definido
void addAresta(Grafo *g, char u, char v);                               //Função que adiciona uma aresta de u para v
void delArestaUV(Grafo *g, char u, char v, bool todos);                 //Deleta aresta u -> v, e deleta v -> u também no caso de um Grafo Direcionado, opcao de apagar todos as arestas ou apenas a primeira delas
void delArestaNum(Grafo *g, int indice);                                //Função que de fato deleta as arestas
void addVertice(Grafo *g);                                              //Adiciona um vertice ao Grafo G
void delVertice(Grafo *g, char u);                                      //Deleta o Vertice u do Grafo G e deleta todas as arestas relacionadas a ele
int acharVertice(Grafo *g, char nome);                                  //Função para achar o vertice nome no Grafo G e retornar o indice dele
void printGrafo(Grafo *g);                                              //Printa o Grafo G e suas características
void premissas(Grafo *g);                                               //Função que executa todas as funções de cálculo das características de G
void limparLW(Grafo *g);                                                //Limpa a label e o peso de todos os vértices e arestas
void buscaProfundidade(Grafo *g);                                       //Faz uma busca por profundidade recursiva
void buscaProfundidade_rec(Grafo *g, int i);                            //Parte recursiva da busca por profundidade sem imprimir nada na tela
void buscaProfundidade_rec_print(Grafo *g, int i);                      //Parte recursiva da busca por profundidade que imprime o caminho visitado
void buscaLargura(Grafo *g);                                            //Faz uma busca em largura e imprime o caminho visitado
int verificarEuleriano(Grafo *g);                                       //Verifica se o Grafo é Euleriano ou Semi-Euleriano ou não
int verificarHamiltoniano(Grafo *g);                                    //Verifica se o Grafo é Hamiltoniano utilizando a função verificarEuleriano no Grafo Linha de G
void isConexo(Grafo *g);                                                //Verifica se o Grafo g é conexo ou não
void isSimples(Grafo *g);                                               //Verifica se o Grafo é simples ou não
void isCiclico(Grafo *g);                                               //Verifica se o Grafo é Cíclico ou Acíclico
void fusaoVertices(Grafo *g, char *vert, int tamanho);                  //Funde Vertices do array recebido
Fecho *fechoTransitivoD(Grafo *g, char u);                              //Retorna os indices dos vertices que o vertice u atinge (Fecho Transitivo Direto)
Fecho *fechoTransitivoI(Grafo *g, char u);                              //Retorna os indices dos vertices que atingem u (Fecho Transitivo Inverso)
void fecho_rec(Grafo *g, int i, Fecho *fecho);                          //Função Recursiva de busca por profundidade para calcular os fechos
//int contarSCC(Grafo *g);                                              //Contar componentes fortemente conexos
//int contarCiclos(Grafo *g);                                           //Contar a quantidade de ciclos do Grafo



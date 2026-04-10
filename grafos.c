#include "grafos.h"
#include "estruturas.h"

Grafo *criarGrafo(char nomeGrafo[], int qtdVertice, bool direcionado){
    Grafo *g = malloc(sizeof(Grafo));
    strcpy(g->nome, nomeGrafo);
    int i;
    g->qtdArestas = 0;
    g->qtdComponentes = 0;
    g->qtdVertices = 0;
    g->isCiclico = false;           //Acíclico
    g->isConexo = false;            //Desconexo
    g->isDirecionado = direcionado; 
    g->Euleriano = 0;               //Não-euleriano
    g->Hamiltoniano = 0;            //Não-hamiltoniano
    g->isSimples = true;            //Simples


    qtdVertice = qtdVertice < 1 ? 1 : qtdVertice;

    g->ultimoVertice = 65;

    for(i = 0; i < qtdVertice; i++){
        addVertice(g);
    }


    return g;
}

Grafo *criarGrafoTransposto(Grafo *g){
    Grafo *gt = criarGrafo("Grafo Transposto", g->qtdVertices, g->isDirecionado);
    for(int i = 0; i < g->qtdArestas; i++){
        char u = 65 + g->E[i].u;
        char v = 65 + g->E[i].v;
        addAresta(gt, v, u);
    }
    return gt;
}

Grafo *criarGrafoLinha(Grafo *g){
    Grafo *gl = criarGrafo("Grafo Linha", g->qtdArestas, g->isDirecionado);
    for(int i = 0; i < g->qtdArestas; i++){
        char u = (char)65 + i;
        for(int j = 0; j < g->qtdArestas; j++){
            char v = (char)65 + j;
            if(i == j) continue;
            if(g->E[i].v == g->E[j].u){
                addAresta(gl, u, v);
            }
            if(!(g->isDirecionado) && (i < j) && (g->E[i].u == g->E[j].u || g->E[i].v == g->E[j].v)){
                addAresta(gl, u, v);
            }
        }
    }
    return gl;
}

void printGrafo(Grafo *g){
    printf("Esse é o Grafo %s\n|\t", g->nome);
    premissas(g);
    for(int i = 0; i < g->qtdVertices; i++){
        printf("%c, ", g->V[i].nome);
    }
    printf("}\n|\n|\tE = {");
    if(g->isDirecionado){
        for(int i = 0; i < g->qtdArestas; i++){
            printf("(%c->%c), ", g->V[g->E[i].u].nome,  g->V[g->E[i].v].nome);
        }
    }else{
        for(int i = 0; i < g->qtdArestas; i++){
            printf("{%c--%c}, ", g->V[g->E[i].u].nome,  g->V[g->E[i].v].nome);
        }
    }
    printf("}\n|\nFim do Grafo\n");
}

void addVertice(Grafo *g){
    int qtd = g->qtdVertices;
    g->V[qtd].nome = (char)g->ultimoVertice;
    g->ultimoVertice++;
    g->qtdVertices++;
    g->V[qtd].grauEntrada = 0;
    g->V[qtd].grauSaida = 0;
}

void delVertice(Grafo *g, char u){
    int indice = acharVertice(g, u);
    if(indice != -1){
        for(int i = 0; i < g->qtdArestas; i++ ){
            if(g->E[i].u == indice || g->E[i].v == indice){
                delArestaUV(g, g->V[g->E[i].u].nome, g->V[g->E[i].v].nome, true);
                i--;
            }
        }
        for(int i = 0; i < g->qtdArestas; i++ ){
            g->E[i].u -= g->E[i].u > indice ? 1 : 0;
            g->E[i].v -= g->E[i].v > indice ? 1 : 0;
        }
        for(int i = indice; i < g->qtdVertices; i++){
            g->V[i] = g->V[i + 1];
        }
        g->qtdVertices--;   
    }
}

void addAresta(Grafo *g, char u, char v){
    int v1, v2;
    v1 = acharVertice(g, u);
    v2 = acharVertice(g, v);
    int qtd = g->qtdArestas;
    g->E[qtd].u = v1;
    g->E[qtd].v = v2;
    if(g->isDirecionado){
        g->V[v1].grauSaida++;
        g->V[v2].grauEntrada++;
    }else{
        g->V[v1].grauEntrada++;
        g->V[v1].grauSaida++;
        g->V[v2].grauEntrada++;
        g->V[v2].grauSaida++;
    }

    g->qtdArestas++;
}

void delArestaUV(Grafo *g, char u, char v, bool todos){
    if(g->isDirecionado){
        for(int i = 0; i < g->qtdArestas; i++){
            if(g->V[g->E[i].u].nome == u && g->V[g->E[i].v].nome == v){
                g->V[g->E[i].u].grauSaida--;
                g->V[g->E[i].v].grauEntrada--;
                delArestaNum(g, i);
                if(!todos){
                    break;
                }
                i--;
            }
        }
    }else{
        for(int i = 0; i < g->qtdArestas; i++){
            if((g->V[g->E[i].u].nome == u && g->V[g->E[i].v].nome == v) || (g->V[g->E[i].u].nome == v && g->V[g->E[i].v].nome == u)){
                g->V[g->E[i].u].grauEntrada--;
                g->V[g->E[i].u].grauSaida--;
                g->V[g->E[i].v].grauEntrada--;
                g->V[g->E[i].v].grauSaida--;
                delArestaNum(g, i);
                if(!todos){
                    break;
                }
                i--;
            }
        }
    }
}

void delArestaNum(Grafo *g, int indice){
    int i;
    for(i = indice; i < g->qtdArestas; i++ ){
        g->E[i] = g->E[i + 1];
    }
    g->qtdArestas--;
}

int acharVertice(Grafo *g, char nome){
    int i = nome - 65;
    i = i < g->qtdVertices - 1 ? i : g->qtdVertices - 1;
    while(i > 0 && nome < g->V[i].nome){
        i--;
    }
    if(nome == g->V[i].nome){
        return i;
    }else{
        return -1;
    }
}

void premissas(Grafo *g){
    isSimples(g);
    isCiclico(g);
    isConexo(g);
    g->Euleriano = verificarEuleriano(g);
    g->Hamiltoniano = verificarHamiltoniano(g);
    char premissa[150] = "";
    strcat(premissa, g->isDirecionado ? "Direcionado" : "Não-direcionado");
    strcat(premissa, g->isSimples ? ", Simples" : "");
    strcat(premissa, g->isCiclico ? ", Cíclico" : ", Acíclico");
    strcat(premissa, g->isConexo ? ", Conexo" : ", Desconexo");
    strcat(premissa, g->Euleriano == 0 ? "" : g->Euleriano == 1 ? ", Semi-Euleriano" : ", Euleriano");
    strcat(premissa, g->Hamiltoniano == 0 ? "" : g->Hamiltoniano == 1 ? ", Semi-Hamiltoniano" : ", Hamiltoniano");

    printf("%s = (V, E), sendo %s um grafo %s\n|\n|\tV = {", g->nome, g->nome, premissa);
}

void limparLW(Grafo *g){
    for(int i = 0; i < g->qtdVertices; i++){
        strcpy(g->V[i].label,"");
        g->V[i].peso = 0;
    }
    for(int i = 0; i < g->qtdArestas; i++){
        strcpy(g->E[i].label,"");
        g->E[i].peso = 0;
    }
}

void buscaProfundidade(Grafo *g){
    limparLW(g);
    printf("\nBusca por Profundidade : ");
    for(int i = 0; i < g->qtdVertices; i++){
        if(strcmp(g->V[i].label, "") == 0){
            buscaProfundidade_rec_print(g, i);
        }
    }
    printf("\n");
}

void buscaProfundidade_rec_print(Grafo *g, int i){
    int cont = 0;
    printf("%c %s ", g->V[i].nome, g->isDirecionado ? "->" : "--");
    strcpy(g->V[i].label ,"Em andamento");
    for(int j = 0; j < g->qtdArestas; j++){
        if(cont > g->V[i].grauSaida) break;
        if(g->E[j].u == i){
            cont++;
            if(strcmp(g->V[g->E[j].v].label, "") == 0){
                buscaProfundidade_rec_print(g, g->E[j].v);
            }
        }else if(!g->isDirecionado && g->E[j].v == i){
            cont++;
            if(strcmp(g->V[g->E[j].u].label, "") == 0){
                buscaProfundidade_rec_print(g, g->E[j].u);
            }
        }
    }
    strcpy(g->V[i].label, "Visitado");
    printf("%c' | ", g->V[i].nome);
}

void buscaProfundidade_rec(Grafo *g, int i){
    int cont = 0;
    strcpy(g->V[i].label ,"Em andamento");
    for(int j = 0; j < g->qtdArestas; j++){
        if(cont > g->V[i].grauSaida) break;
        if(g->E[j].u == i){
            cont++;
            if(strcmp(g->V[g->E[j].v].label, "") == 0){
                buscaProfundidade_rec(g, g->E[j].v);
            }
        }else if(!g->isDirecionado && g->E[j].v == i){
            cont++;
            if(strcmp(g->V[g->E[j].u].label, "") == 0){
                buscaProfundidade_rec(g, g->E[j].u);
            }
        }
    }
    strcpy(g->V[i].label, "Visitado");
}

void buscaLargura(Grafo *g){
    limparLW(g);
    Queue *fila = criarQueue();
    int *x = &fila->comeco;
    printf("\nBusca por Largura : ");
    for(int i = 0; i < g->qtdVertices; i++){ //Loop que vai pegar os vertices para "iniciar" a busca
        if(strcmp(g->V[i].label, "") == 0){
            enqueue(fila, i);
            printf("%c %s ", g->V[fila->elementos[*x]].nome, g->isDirecionado ? "->" : "--");
            do{
                int cont = 0;
                if(strcmp(g->V[fila->elementos[*x]].label, "") == 0){
                    strcpy(g->V[fila->elementos[*x]].label, "Em Andamento");
                    for(int j = 0; j < g->qtdArestas; j++){ //Loop para ver as arestas ligadas a V[i] e achar os V ligados a V[i]
                        if(cont > g->V[fila->elementos[*x]].grauSaida) break;
                        if(g->E[j].u == fila->elementos[*x]){
                            if(strcmp(g->V[g->E[j].v].label, "") == 0){
                                enqueue(fila, g->E[j].v);
                                printf("%c %s ", g->V[g->E[j].v].nome, g->isDirecionado ? "->" : "--");
                            }
                            cont++;
                        }else if(!g->isDirecionado && g->E[j].v == fila->elementos[*x]){
                            if(strcmp(g->V[g->E[j].u].label, "") == 0){
                                enqueue(fila, g->E[j].u);
                                printf("%c %s ", g->V[g->E[j].u].nome, g->isDirecionado ? "->" : "--");
                            }
                            cont++;
                        }
                    }
                }
                strcpy(g->V[fila->elementos[*x]].label,"Visitado");
                printf("%c' | ", g->V[dequeue(fila)].nome);
            }while(fila->comeco != fila->fim);
        }
    }
}

void isConexo(Grafo *g){
    g->isConexo = true;
    Grafo gnd = *g;
    if(g->isDirecionado){
        for(int i = 0; i < g->qtdArestas; i++){
            addAresta(&gnd, g->V[g->E[i].v].nome, g->V[g->E[i].u].nome);
        }
    }

    buscaProfundidade_rec(&gnd, 0);

    for(int i = 0; i < gnd.qtdVertices; i++){
        if(strcmp(gnd.V[i].label, "") == 0){
            g->isConexo = false;
            break;
        }
    }
    
}

void isSimples(Grafo *g){
    bool simples = true;
    if(g->isDirecionado){
        for(int i = 0; i < g->qtdArestas && simples; i++){
            for(int j = 0; j < g->qtdArestas && simples; j++){
                simples = g->E[j].u != g->E[j].v;
                if(i == j) continue;
                if(g->E[i].u == g->E[j].u && g->E[i].v == g->E[j].v){
                    simples = false;
                    break;
                    
                }
            }
        }
    }else{
        for(int i = 0; i < g->qtdArestas && simples; i++){
            for(int j = 0; j < g->qtdArestas && simples; j++){
                simples = g->E[j].u != g->E[j].v;
                if(i == j) continue;
                if((g->E[i].u == g->E[j].u && g->E[i].v == g->E[j].v) || (g->E[i].u == g->E[j].v && g->E[i].v == g->E[j].u)){
                    simples = false;
                    break;
                }
            }
        }
    }
    g->isSimples = simples;
}

void isCiclico(Grafo *g){
    if(g->isDirecionado){
        Grafo g1 = *g;
        bool removido = true;
        while(removido){
            removido = false;
            for(int i = 0; i < g1.qtdVertices; i++){
                if(g1.V[i].grauEntrada == 0){
                    delVertice(&g1, g1.V[i].nome);
                    removido = true;
                    break;
                }
            }
        }
        g->isCiclico = g1.qtdVertices > 0 ? true : false; 
    }else if(!(g->qtdArestas == 0)){
        g->isCiclico = false;
    }else{
        g->isCiclico = true;
    }
}

int verificarEuleriano(Grafo *g){
    int euleriano = 0, par = 0, impar = 0;

    if(g->isConexo){
        for(int i = 0; i < g->qtdVertices; i++){
            if(g->V[i].grauEntrada % 2 == 0 && g->V[i].grauSaida % 2 == 0 && g->V[i].grauEntrada == g->V[i].grauSaida){
                par++;
            }else{
                impar++;
            }
        }
        if(impar == 2){
            euleriano = 1;
        }else if(impar == 0){
            euleriano = 2;
        }
    }
    return euleriano;
}

int verificarHamiltoniano(Grafo *g){
    Grafo *gl = criarGrafoLinha(g);
    int hamiltoniano = verificarEuleriano(gl);
    return hamiltoniano;
}
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
    Celula *nova = malloc(sizeof(Celula));
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

ListCell *novaListCell(Elemento e){
    ListCell *nova = malloc(sizeof(ListCell));
    nova->e = e;
    nova->ant = NULL;
    nova->prox = NULL;
    return nova;
}

List *criarList(){
    List *lista = malloc(sizeof(List));
    Elemento e;
    e.x = -1; e.peso = 1;
    lista->comeco = novaListCell(e);
    lista->fim = lista->comeco;
    lista->tam = 0;

    return lista;
}

void insertComeco(List *lista, int x, int peso){
    Elemento e;
    e.x = x;
    e.peso = peso;
    if(lista->tam == 0){
        insertFim(lista, x, peso);
    }else{
        ListCell *nova = novaListCell(e);
        nova->prox = lista->comeco->prox;
        lista->comeco->prox = nova;
        nova->ant = lista->comeco;
        nova->prox->ant = nova;
        lista->tam++;
    }
}

void insertFim(List *lista, int x, int peso){
    Elemento e;
    e.x = x;
    e.peso = peso;
    ListCell *temp = lista->fim;
    lista->fim = novaListCell(e);
    temp->prox = lista->fim;
    lista->fim->ant = temp;
    lista->tam++;
}

void insert(List *lista, int x, int peso, int pos){
    Elemento e;
    e.x = x;
    e.peso = peso;
    if(pos <= 0){
        return insertComeco(lista, x, peso);
    }else if(pos > lista->tam-1){
        return insertFim(lista, x, peso);
    }

    ListCell *posAnterior, *posPosterior;
    ListCell *nova = novaListCell(e);

    if(pos < (lista->tam / 2)){
        posAnterior = lista->comeco->prox;
        for(int i = 1; i < pos; i++){
            posAnterior = posAnterior->prox;
        }
    }else{
        posAnterior = lista->fim->ant;
        for(int i = lista->tam-1; i > pos; i--){
            posAnterior = posAnterior->ant;
        }
    }
    posPosterior = posAnterior->prox;
    posAnterior->prox = nova;
    posPosterior->ant = nova;
    nova->ant = posAnterior;
    nova->prox = posPosterior;
    lista->tam++;
}

Elemento removeComeco(List *lista){
    ListCell *excluido = lista->comeco->prox;
    Elemento e = excluido->e;
    if(lista->tam == 1){
        lista->fim = lista->comeco;
        lista->comeco->prox = NULL;
    }else{
        ListCell *temp = excluido->prox;
        temp->ant = lista->comeco;
        lista->comeco->prox = temp;
    }
    
    excluido->prox = NULL;
    excluido->ant = NULL;
    free(excluido);

    lista->tam--;


    return e;
}

Elemento removeFim(List *lista){
    if(lista->tam == 1) return removeComeco(lista);
    ListCell *excluido = lista->fim;
    Elemento e = excluido->e;
    ListCell *temp = excluido->ant;

    lista->fim = temp;
    temp->prox = NULL;
    excluido->prox = NULL;
    excluido->ant = NULL;
    free(excluido);

    lista->tam--;

    return e;
}

Elemento removeCell(List *lista, int pos){
    if(pos == 0){
        return removeComeco(lista);
    }else if(pos == lista->tam-1){
        return removeFim(lista);
    }

    ListCell *excluido;

    if(pos < lista->tam/2){
        excluido = lista->comeco->prox;
        for(int i = 1; i < pos; i++){
            excluido = excluido->prox;
        }
    }else{
        excluido = lista->fim->ant;
        for(int i = lista->tam-2; i > pos; i--){
            excluido = excluido->ant;
        }
    }
    
    Elemento e = excluido->e;
    
    excluido->ant->prox = excluido->prox;
    excluido->prox->ant = excluido->ant;
    excluido->ant = NULL;
    excluido->prox = NULL;
    free(excluido);
    lista->tam--;
    
    return e;

}

void printList(List *lista){
    ListCell *temp = lista->comeco->prox;
    printf("Print Lista:\n");
    int i = 0;

    for(i = 0; i < lista->tam; i++){
        printf("%d ", temp->e.x);
        temp = temp->prox;
    }

    if(i == 0) printf("Lista Vazia");
    printf("\n");
}

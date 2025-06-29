#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int dado;
    struct No* proximo;
}tipoNo;

typedef struct pilha{
    tipoNo* topo;
}tipoPilha;

void inicializar(tipoPilha* pilha){
    pilha->topo = NULL;
}

void push(tipoPilha* pilha, int valor){
    tipoNo* novoNo = malloc(sizeof(tipoNo));
    novoNo->dado = valor;
    novoNo->proximo = pilha->topo;
    pilha->topo = novoNo;
}

void pop(tipoPilha* pilha){
    if(!pilha->topo) return -1;
    tipoNo* temp = pilha->topo;
    int valor = temp->dado;
    pilha->topo = temp->proximo;
    free(temp);
    return valor;
}

void exibir(tipoPilha pilha){
    tipoNo* atual = pilha->topo;
    while(atual){
        printf("[%d] ", atual->dado);
        atual = atual->proximo;
    }
}
void liberarPilha(tipoPilha* pilha){
    while(pilha->topo){
        pop(pilha);
    }
}

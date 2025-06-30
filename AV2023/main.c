#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No{
    char nome[30];
    float pesoAt;
    float altAt;
    struct No *proximo;
}tipoNo;

typedef struct pilha{
    tipoNo* topo;
}tipoPilha;

void push(tipoPilha* pilha, const char* nome, float peso, float altura){
    tipoNo* novoNo = malloc(sizeof(tipoNo));
    strcpy(novoNo->nome, nome);
    novoNo->pesoAt = peso;
    novoNo->altAt = altura;
    if(!pilha->topo){
        novoNo->proximo = novoNo;
        pilha->topo = novoNo;
    }else{
        novoNo->proximo = pilha->topo->proximo;
        pilha->topo->proximo = novoNo;
        pilha->topo = novoNo;
    }
}

int pop(tipoPilha* pilha, tipoNo* removido){
    if(!pilha->topo)return 0;
    tipoNo* topo = pilha->topo;
    tipoNo* primeiro = topo->proximo;

    if(topo == primeiro){
        *removido = *topo;
        free(topo);
        pilha->topo = NULL;
        return 1;
    }
    tipoNo* atual = primeiro;
    while(atual->proximo !=topo){
        atual = atual->proximo;
    }
    atual->proximo = topo->proximo;
    *removido = *topo;
    free(topo);
    pilha->topo = atual;
    return 1;


}

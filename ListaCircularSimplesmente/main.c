#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int dado;
    struct No* proximo;
}tipoNo;

typedef struct ListaCircular{
    tipoNo* inicio;
}tipoLista;

void Inicializar(tipoLista* lista){
    lista->inicio = NULL;
}

void InserirInicio(tipoLista* lista, int valor){
    tipoNo* novoNo = malloc(sizeof(tipoNo));
    novoNo->dado = valor;
    if(!lista->inicio){
        novoNo->proximo = novoNo;
        lista->inicio = novoNo;
        return;
    }
    tipoNo* atual = lista->inicio;
    while(atual->proximo != lista->inicio) atual = atual->proximo;
    atual->proximo = novoNo;
    novoNo->proximo = lista->inicio;
}

void InserirFim(tipoLista* lista, int valor){
    tipoNo* novoNo = malloc(sizeof(tipoNo));
    novoNo->dado = valor;
    if(!lista->inicio){
        novoNo->proximo = novoNo;
        lista->inicio = novoNo;
        return;
    }
    tipoNo* atual = lista->inicio;
    while(atual->proximo != lista->inicio) atual = atual->proximo;

    atual->proximo = novoNo;
    novoNo->proximo = lista->inicio;
}

void Exibir(tipoLista lista){
    if(!lista->inicio) return;
    tipoNo* atual = lista->inicio;
    do {
        printf("%d", atual->dado);
        atual = atual->proximo;
    }while(atual != lista->inicio);
    printf("Cabouuu");
}

void Liberar(tipoLista* lista){
    if(!lista->inicio) return;
    tipoNo *atual = lista->inicio->proximo, *inicio = lista->inicio;
    while(atual !=inicio){

        tipoNo* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    free(inicio);
    lista->inicio = NULL;
}

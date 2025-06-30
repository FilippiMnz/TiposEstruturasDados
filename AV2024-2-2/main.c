#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No{
    char nome[50];
    int matricula;
    float notaFinal;
    struct No* anterior;
    struct No* proximo;
}tipoNo;

typedef struct Lista{
    tipoNo* inicio;
}tipoLista;


void InserirOrd(tipoLista* lista, int matricula, const char* nome, float nota){
    tipoNo* novoNo = malloc(sizeof(tipoNo));
    strcpy(novoNo->nome, nome);
    novoNo->matricula = matricula;
    novoNo->notaFinal = nota;
    novoNo->anterior = NULL;
    novoNo->proximo = NULL;

    if(!lista->inicio){
        lista->inicio = novoNo;
        return;
    }
    tipoNo* atual = lista->inicio;
    if(matricula < atual->matricula){
        novoNo->proximo = atual;
        atual->anterior = novoNo;
        lista->inicio = novoNo;
        return;
    }
    while(atual->proximo && matricula > atual->proximo->matricula){
        atual = atual->proximo;
    }

    novoNo->proximo = atual->proximo;
    novoNo->anterior = atual;
    if(atual->proximo){
        atual->proximo->anterior = novoNo;
    }
    atual->proximo = novoNo;


}



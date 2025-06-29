#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int dado;
    struct No* anterior;
    struct No* proximo;
}tipoNo;

typedef struct Lista{
    tipoNo* inicio;
}TipoLista;

void Inicializar(TipoLista* lista){
    lista->inicio = NULL;
}

void InserirInicio(TipoLista* lista, int valor){
    tipoNo* novoNo = malloc(sizeof(tipoNo));
    novoNo->dado = valor;
    novoNo->anterior = NULL;
    novoNo->proximo = lista->inicio;

    if(lista->inicio != NULL){
        lista->inicio->anterior = novoNo;
    }

    lista->inicio =novoNo;
}

void InserirFinal(TipoLista* lista, int valor){
    tipoNo* novoNo = malloc(sizeof(tipoNo));
    novoNo->dado = valor;
    novoNo->proximo = NULL;
    novoNo->anterior = NULL;

    if(!lista->inicio){
        lista->inicio = novoNo;
        return;
    }
    tipoNo* atual = lista->inicio;
    while(atual->proximo) atual = atual->proximo;
    atual->proximo = novoNo;
    novoNo->anterior = atual;
}

void removerValor(TipoLista* lista, int valor){
    tipoNo* atual = lista->inicio;
    while(atual && atual->dado !=  valor) atual = atual->proximo;
    if(!atual) return;
    if(atual-> anterior) atual->anterior->proximo = atual->proximo;
    else lista->inicio = atual->proximo;
    if(atual->proximo) atual->proximo->anterior = atual->anterior;

    free(atual);
}

void exibir(TipoLista lista){
    tipoNo* atual = lista->inicio;
    while(atual){
        printf("%d ", atual->dado);
        atual = atual->proximo;
    }
    printf("NULL");
}

void Liberar(TipoLista* lista){
    tipoNo* atual = lista->inicio;
    while(atual){
        tipoNo* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    lista->inicio = NULL;
}

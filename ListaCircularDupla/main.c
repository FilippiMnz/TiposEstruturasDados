#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int dado;
    struct No* proximo;
    struct No* anterior;
}tipoNo;

typedef struct lista{
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
        novoNo->anterior = novoNo;
        lista->inicio = novoNo;
        return;
    }
    tipoNo* ultimo = lista->inicio->anterior;
    novoNo->proximo = lista->inicio;
    novoNo->anterior = ultimo;
    lista->inicio->anterior = novoNo;
    ultimo->proximo = novoNo;
    lista->inicio = novoNo;
}
void InserirFinal(tipoLista* lista, int valor){
    tipoNo* novoNo = malloc(sizeof(tipoNo));
    novoNo->dado = valor;
    if(!lista->inicio){
        novoNo->proximo = novoNo;
        novoNo->anterior = novoNo;
        lista->inicio = novoNo;
        return;
    }
    tipoNo* ultimo = lista->inicio->anterior;
    novoNo->proximo = lista->inicio;
    novoNo->anterior = ultimo;
    ultimo->proximo = novoNo;
    lista->inicio->anterior = novoNo;
}

void Exibir(tipoLista lista){
    if(!lista->inicio){
        return;
    }
    tipoNo* atual = lista->inicio;
    do{
        printf("%d", atual->dado);
        atual = atual->proximo;
    }while(atual!=lista->inicio);
    printf("finalizamos");
}

void remover(tipoLista* lista, int valor){
    if(!lista->inicio) return;
    tipoNo* atual = lista->inicio;
    do{
        if(atual->dado == valor){
            if(atual->proximo == atual){
                free(atual);
                lista->inicio = NULL;
                return;
            }
            atual->anterior->proximo = atual->proximo;
            atual->proximo->anterior = atual->anterior;
            if(atual == lista->inicio){
                lista->inicio = atual->proximo;
            }
            free(atual);
            return;
        }
        atual = atual->proximo;
    }while(atual != lista->inicio);
}

void Liberar(tipoLista* lista){
    if(!lista->inicio) return;
    tipoNo* atual = lista->inicio->proximo;
    while(atual != lista->inicio){
        tipoNo* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    free(lista->inicio);
    lista->inicio = NULL;
}




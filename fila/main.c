#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int dado;
    struct No* proximo;
}tipoNo;
typedef struct Fila{
    tipoNo* inicio;
    tipoNo* fim;
}tipoFila;

void inicializar(tipoFila* fila){
    fila->inicio = fila->fim = NULL;
}

void enfileirar(tipoFila* fila, int valor){
    tipoNo* novoNo = malloc(sizeof(tipoNo));
    novoNo->dado = valor;
    novoNo->proximo = NULL;
    if(fila->fim){
        fila->fim->proximo = novoNo;
    }else{
        fila->inicio = novoNo;
    }
    fila->fim = novoNo;
}

int retirar(tipoFila* fila){
    if(!fila->inicio) return -1;
    tipoNo* temp = fila->inicio;
    int valor = temp->dado;
    fila->inicio = temp->proximo;
    if(!fila->inicio)fila->fim = NULL;
    free(temp);
    return valor;
}

void exibir(tipoFila fila){
    tipoNo* atual = fila->inicio;
    while(atual){
        printf("%d", atual->dado);
        atual = atual->proximo;
    }
    printf("cabou");
}

void liberar(tipoFila* fila){
    while(fila->inicio){
    retirar(fila);
    }
}

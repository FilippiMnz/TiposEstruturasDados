#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int dado;
    struct No* proximo;
}tipoNo;

typedef struct Lista{
    tipoNo* inicio;
}tipoLista;

void Inicializar(tipoLista* lista){
    lista->inicio = NULL;
}

void InserirInicio(tipoLista* lista, int valor){
    tipoNo* novoNo = malloc(sizeof(tipoNo));
    novoNo->dado = valor;
    novoNo->proximo = lista->inicio;
    lista->inicio = novoNo;
}
void InserirFinal(tipoLista* lista, int valor){
    tipoNo* novoNo = malloc(sizeof(tipoNo));
    novoNo->dado = valor;
    novoNo->proximo = NULL;
    if(lista->inicio == NULL){
        lista->inicio = novoNo;
        return;
    }
    tipoNo* noAtual = lista->inicio;
    while(noAtual->proximo != NULL){
        noAtual = noAtual->proximo;
    }
    noAtual->proximo =novoNo;
}

void remover(tipoLista* lista, int valor){
    tipoNo *atual = lista->inicio, *anterior = NULL;
    while(atual && atual->dado !=valor){
        anterior = atual;
        atual = atual->proximo;
    }
    if(!atual) return;
    if(!anterior) lista->inicio = atual->proximo;
    else anterior->proximo = atual->proximo;
    free(atual);
}

void exibir(tipoLista lista){
    tipoNo* atual =lista->inicio;
    while(atual){
        printf("%d ->", atual->dado);
        atual = atual->proximo;
    }
    printf("NULL");
}

void LiberarLista(tipoLista* lista){
    tipoNo* atual = lista->inicio;
    while(atual){
        tipoNo* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    lista->inicio = NULL;
}

int main(){
    return 0;
}

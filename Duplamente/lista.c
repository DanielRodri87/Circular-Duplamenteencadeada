#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

Elemento *criaLista(){
    return NULL;
}

Elemento *addInicio(Elemento *l){
    //criar novo elemento
    Elemento *novo = (Elemento*) malloc(sizeof(Elemento));
    //ajustar o valor do ponteiro para o prox elemento
    novo->prox = l;
    novo->ant = NULL;
    if (l != NULL){
        l->ant=novo;
    }
    scanf("%d", &novo->info);
    return novo;
}

void mostrarLista(Elemento *l)
{
    if (l == NULL)
        printf("Lista vazia ");
    else
    {
        Elemento *aux = l;
        while (aux != NULL)
        {
            printf("%d ", aux->info);
            aux = aux->prox;
        }
    }
}

void mostrarListaInverso(Elemento *l)
{
    if (l == NULL)
        printf("Lista vazia");
    else
    {
        Elemento *aux = l;
        while (aux != NULL)
        {
            aux = aux->prox;
        }

        Elemento *fim = aux->prox;
        while(fim != l)
        {
            printf("%d ", fim->info);
            fim = fim->ant;
        }

    }
}

void addFinal(Elemento *l){
    Elemento *novo = (Elemento*) malloc(sizeof(Elemento));
    scanf("%d", &novo->info);
    novo->prox = NULL;
    if (l == NULL)
    {
        l = novo;
        novo->ant = NULL;
    }
    else{
        Elemento *aux = l;
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = novo;
        novo->ant = aux;
    }
}

Elemento *addOrdeandoCrescente(Elemento *l)
{
    Elemento *novo = (Elemento*) malloc(sizeof(Elemento));
    scanf("%d", &novo->info);
    if (l == NULL)
    {
        novo->prox = NULL;
        return novo;
    }
    else
    {
        Elemento *ant = NULL;
        Elemento *atual = l;
        while (atual != NULL && atual->info < novo->info)
        {
            ant = atual;
            atual = atual->prox;
        }
        if (ant == NULL)
        {
            novo->prox = l;
            return novo;
        }
        else
        {
            novo->prox = ant->prox;
            ant->prox = novo;
            return l;
        }
    }
}

Elemento *removerElemento(Elemento *l)
{
    int valor;
    scanf("%d", &valor);
    Elemento *ant = NULL;
    Elemento *atual = l;
    while (atual != NULL && atual->info != valor)
    {
        ant = atual;
        atual = atual->prox;
    }
    if (atual == NULL)
    {
        printf("Elemento nao encontrado\n");
        return l;
    }
    if (ant == NULL)
    {
        l = atual->prox;
    }
    else
    {
        ant->prox = atual->prox;
    }
    free(atual);
    return l;
}

int tamanhoDaLista(Elemento *l)
{
    int count = 0;
    Elemento *aux = l;
    while (aux != NULL)
    {
        count++;
        aux = aux->prox;
    }

    return count;
    
}
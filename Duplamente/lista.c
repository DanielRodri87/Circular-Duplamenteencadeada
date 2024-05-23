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
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        while (aux != NULL)
        {
            printf("%d ", aux->info);
            aux = aux->ant;
        }
    }
}

// daniel, faça
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

Elemento *addOrdeandoCrescente(Elemento *l) {
    Elemento *novo = (Elemento *) malloc(sizeof(Elemento));
    if (!novo)
    {
        printf("erro ao alocar memoria.\n");
        return l;
    }

    scanf("%d", &novo->info);
    novo->prox = NULL;
    novo->ant = NULL;

    if (l == NULL)  
        return novo;
    else
    {
        Elemento *atual = l;
        Elemento *anterior = NULL;

        while (atual != NULL && atual->info < novo->info)
        {
            anterior = atual;
            atual = atual->prox;
        }

        if (anterior == NULL)
        { 
            novo->prox = l;
            l->ant = novo;
            return novo;
        } else
        { 
            novo->prox = atual;
            novo->ant = anterior;
            anterior->prox = novo;
            if (atual != NULL) {
                atual->ant = novo;
            }
            return l;
        }
    }
}


Elemento *removerElemento(Elemento *l)
{
    Elemento *aux = l;
    int valor;
    printf("Digite o valor a ser removido: ");
    scanf("%d", &valor);

    if (l == NULL)
    {
        printf("Lista vazia\n");
        return l;
    }
    else
    {
        while (aux != NULL && aux->info != valor)
        {
            aux = aux->prox;
        }

        if (aux == NULL)
        {
            printf("Elemento não encontrado\n");
            return l;
        }
        else
        {
            if (aux->ant == NULL)
            {
                l = aux->prox;
                if (l != NULL)
                {
                    l->ant = NULL;
                }
            }
            else
            {
                aux->ant->prox = aux->prox;
                if (aux->prox != NULL)
                {
                    aux->prox->ant = aux->ant;
                }
            }
            free(aux);
            return l;
        }
    }
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
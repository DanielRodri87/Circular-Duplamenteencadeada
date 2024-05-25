#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

Elemento *criaLista(){
    return NULL;
}

Elemento *addInicio(Elemento *l)
{

    Elemento *novo = (Elemento *)malloc(sizeof(Elemento));

    scanf("%d", &novo->info);
    if (l == NULL)
    {
        novo->prox = novo;
        novo->ant = novo;
        l = novo;
    }
    else
    {
        Elemento *aux = l->ant;

        novo->prox = l;
        novo->ant = aux;

        l->ant = novo;
        aux->prox = novo;

        l = novo;
    }

    return novo;
}

void mostrarLista(Elemento *l)
{
    if (l == NULL)
        printf("Lista vazia ");
    else
    {
        Elemento *aux = l;
        do
        {
            printf("%d ", aux->info);
            aux = aux->prox;
        } while (aux != l);
    }
}

void mostrarListaInverso(Elemento *l) {
    if (l == NULL) {
        printf("Lista vazia\n");
        return;
    }

    Elemento *ultimo = l->ant;

    Elemento *aux = ultimo;
    do {
        printf("%d ", aux->info);
        aux = aux->ant;
    } while (aux != ultimo);
    printf("%d\n", ultimo->info); 
}



void addFinal(Elemento **l) {
    Elemento *novo = (Elemento*) malloc(sizeof(Elemento));
    scanf("%d", &novo->info);

    if (*l == NULL) {
        novo->prox = novo;
        novo->ant = novo;
        *l = novo;
    } else {
        Elemento *aux = *l;
        while (aux->prox != *l) {
            aux = aux->prox;
        }
        aux->prox = novo;
        novo->ant = aux;
        novo->prox = *l;
        (*l)->ant = novo;
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

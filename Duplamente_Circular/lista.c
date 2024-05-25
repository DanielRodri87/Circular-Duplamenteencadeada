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
    if (!novo) {
        printf("Erro ao alocar memória\n");
        return l;
    }

    scanf("%d", &novo->info);
    if (l == NULL) {
        novo->prox = novo;
        novo->ant = novo;
        return novo;
    } else {
        Elemento *atual = l;
        do {
            if (novo->info < atual->info) break;
            atual = atual->prox;
        } while (atual != l);

        novo->prox = atual;
        novo->ant = atual->ant;
        atual->ant->prox = novo;
        atual->ant = novo;

        if (atual == l && novo->info < l->info) {
            return novo;
        } else {
            return l;
        }
    }
}

Elemento *removerElemento(Elemento *l) {
    if (l == NULL) {
        printf("Lista vazia\n");
        return l;
    }

    int valor;
    printf("Digite o valor a ser removido: ");
    scanf("%d", &valor);

    Elemento *aux = l;
    do {
        if (aux->info == valor) break;
        aux = aux->prox;
    } while (aux != l);

    if (aux->info != valor) {
        printf("Elemento não encontrado\n");
        return l;
    }

    if (aux->prox == aux) {
        free(aux);
        return NULL;
    } else {
        aux->ant->prox = aux->prox;
        aux->prox->ant = aux->ant;
        if (aux == l) {
            l = aux->prox;
        }
        free(aux);
        return l;
    }
}

int tamanhoDaLista(Elemento *l) {
    if (l == NULL) {
        return 0;
    }

    int count = 0;
    Elemento *aux = l;
    do {
        count++;
        aux = aux->prox;
    } while (aux != l);

    return count;
}
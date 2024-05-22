#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

Elemento *criaLista()
{
    return NULL;
}

Elemento *addInicio(Elemento *l)
{
    // criar novo elemento
    Elemento *novo = (Elemento *)malloc(sizeof(Elemento));
    scanf("%d", &novo->info);
    if (l == NULL)
    {
        l = novo;
        novo->prox = l;
    }
    else
    {
        novo->prox = l->prox;
        l->prox = novo;
    }
    // ajustar o valor do ponteiro para o prox elemento

    return novo;
}

void mostrarLista(Elemento *l)
{

    Elemento *aux = l->prox;

    do
    {
        printf("%d -> ", aux->info);
        aux = aux->prox;
    } while (aux != l->prox);
    printf("\n");
}

void addFinal(Elemento *l)
{
    Elemento *novo = (Elemento *)malloc(sizeof(Elemento));
    scanf("%d", &novo->info);
    novo->prox = NULL;
    if (l == NULL)
    {
        l = novo;
        novo->prox = l;
    }
    else
    {
        novo->prox = l->prox;
        l->prox = novo;
    }
}

// Elemento *addOrdeandoCrescente(Elemento *l)
// {
//     Elemento *novo = (Elemento *)malloc(sizeof(Elemento));
//     scanf("%d", &novo->info);

//     if (l == NULL)
//     {
//         novo->prox = novo;
//         return novo;
//     }
//     else if (novo->info < l->prox->info)
//     {
//         novo->prox = l->prox;
//         l->prox = novo;
//         return l;
//     }
//     else
//     {
//         Elemento *atual = l->prox;
//         while (atual != l && atual->prox->info < novo->info)
//         {
//             atual = atual->prox;
//         }
//         novo->prox = atual->prox;
//         atual->prox = novo;
//         if (atual == l)
//         {
//             l = novo;
//         }
//         return l;
//     }
// }

Elemento *addOrdeandoCrescente(Elemento *l)
{
    Elemento *novo = (Elemento *)malloc(sizeof(Elemento));
    scanf("%d", &novo->info);

    if (l == NULL)
    {
        novo->prox = novo;
        return novo;
    }
    else if (novo->info < l->prox->info)
    {
        novo->prox = l->prox;
        l->prox = novo;
        return l;
    }
    else
    {
        Elemento *atual = l->prox;
        while (atual != l && atual->prox->info < novo->prox->info)
        {
            atual = atual->prox;
        }
        novo->prox = atual->prox;
        atual->prox = novo;

        if (atual == l)
        {
            l = novo;
        }
        
    }
    
}

Elemento *removerElemento(Elemento *l)
{
    int valor;
    scanf("%d", &valor);
    Elemento *ant = l;
    Elemento *atual = l->prox;
    do
    {
        if (atual->info == valor)
        {
            if (atual == l)
            {
                if (atual->prox == l)
                {
                    free(atual);
                    return NULL;
                }
                else
                {
                    ant->prox = atual->prox;
                    free(atual);
                    l = ant;
                }
            }
            else
            {
                ant->prox = atual->prox;
                free(atual);
            }
            return l;
        }

        ant = atual;
        atual = atual->prox;

    } while (atual != l->prox);

    return l;
}

int tamanhoDaLista(Elemento *l)
{
    if(l==NULL) return 0;

    int count = 0;
    Elemento *aux = l->prox;
    do
    {
        count++;
        aux = aux->prox;
    } while (aux!= l->prox);
    return count;
}

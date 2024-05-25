#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{

    Elemento *lista;
    Elemento *lista_ord;
    lista_ord = criaLista();
    lista = criaLista();

    printf("Elementos da lista nao ordenada: \n");
    lista = addInicio(lista);
    lista = addInicio(lista);
    lista = addInicio(lista);
    lista = addInicio(lista);
    printf("Elemento ao final\n");
    addFinal(&lista);

    printf("\nLista normal\n");
    mostrarLista(lista);

    printf("\nElementos da lista ordenada: \n");
    lista_ord = addOrdeandoCrescente(lista_ord);
    lista_ord = addOrdeandoCrescente(lista_ord);
    lista_ord = addOrdeandoCrescente(lista_ord);
    lista_ord = addOrdeandoCrescente(lista_ord);
    printf("\nMostrar lista ordenada: \n");
    mostrarLista(lista_ord);

    
    // printf("\nMostrar lista inversa\n");
    // mostrarListaInverso(lista);

    // printf("\nMostrar lista ordenada inversa\n");
    // mostrarListaInverso(lista_ord);

    int op;
    printf("\n1 - Remover Elemento Lista\n2 - Remover Elemento Lista Ordenada\n");
    scanf("%d", &op);

    if (op == 1)
    {
        printf("Remover elemento normal\n");
        lista = removerElemento(lista);

        mostrarLista(lista);
    }
    else
    {
        printf("Remover elemento ordenado\n");
        lista_ord = removerElemento(lista_ord);
        mostrarLista(lista_ord);
    
    }

    printf("\nO tamanho da lista nao ordenada eh: %d\n", tamanhoDaLista(lista));
    printf("\nO tamanho da lista ordenada eh: %d\n", tamanhoDaLista(lista_ord));

    return 0;
}
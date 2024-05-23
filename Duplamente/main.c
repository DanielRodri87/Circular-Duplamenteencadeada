#include "lista.h"
#include <stdio.h>
#include <stdlib.h>


int main(){

    Elemento *lista;
    Elemento *lista_ord;
    lista_ord = criaLista();
    lista = criaLista();

    printf("Elementos da lista não ordenada: \n");
    lista = addInicio(lista);
    lista = addInicio(lista);
    lista = addInicio(lista);
    lista = addInicio(lista);
    printf("Elemento ao final\n");
    addFinal(lista);
    printf("Lista inversa: \n");
    mostrarListaInverso(lista);
    printf("\nLista normal\n");
    mostrarLista(lista);
    
    printf("\nElementos da lista ordenada: \n");
    lista_ord = addOrdeandoCrescente(lista_ord);
    lista_ord = addOrdeandoCrescente(lista_ord);
    lista_ord = addOrdeandoCrescente(lista_ord);
    lista_ord = addOrdeandoCrescente(lista_ord);
    printf("Mostrar lista norma: \n");
    mostrarLista(lista_ord);
    printf("Mostrar lista inversa: \n");
    mostrarListaInverso(lista_ord);

    // mostrarLista(lista_ord);
    printf("Remover elemento normal\n");

    lista = removerElemento(lista);

    printf("\n");
    mostrarListaInverso(lista);

    mostrarLista(lista);

    // printf("\n%d\n", tamanhoDaLista(lista));
    // printf("\n%d\n", tamanhoDaLista(lista_ord));

    return 0;
}
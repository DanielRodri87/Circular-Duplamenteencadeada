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
    addFinal(lista);
    mostrarLista(lista);


    printf("\nElementos da lista ordenada: \n");
    lista_ord = addOrdeandoCrescente(lista_ord);
    lista_ord = addOrdeandoCrescente(lista_ord);
    lista_ord = addOrdeandoCrescente(lista_ord);
    lista_ord = addOrdeandoCrescente(lista_ord);

    mostrarLista(lista_ord);
    printf("\n");
    lista = removerElemento(lista);

    mostrarLista(lista);

    printf("\n%d\n", tamanhoDaLista(lista));
    printf("\n%d\n", tamanhoDaLista(lista_ord));

    return 0;
}
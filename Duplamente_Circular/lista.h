typedef struct elemento{
    int info;
    struct elemento *prox;
    struct elemento *ant;
}Elemento;

Elemento *criaLista();
Elemento *addInicio(Elemento *l);
void addFinal(Elemento **l);
Elemento *addOrdeandoCrescente(Elemento *l);
Elemento *removerElemento(Elemento *l);
int tamanhoDaLista(Elemento *l);
void mostrarLista(Elemento *l);
void mostrarListaInverso(Elemento *l);
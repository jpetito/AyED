//1.

#include <iostream>
#include <stdio.h>
using namespace std;

struct Nodo{
    int info;
    Nodo *sig;
};

Nodo *union(Nodo *colaFnte, Nodo *colaFin, Nodo *pila);
void insertarOrdenado(Nodo* &lista, int valor);
Nodo *buscar(Nodo* &lista, int valor);

int main(){

    return 0;
}

Nodo *union(Nodo *colaFnte, Nodo* colaFin, Nodo *pila){
    Nodo* lista = NULL;

    while(colaFnte != NULL){
        int valor = colaFnte ->info;
        insertarOrdenado(lista, valor);
    }


    while(pila != NULL){
        insertarOrdenado(lista, pop(pila));
    }
}
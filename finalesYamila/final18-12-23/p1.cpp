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

int main(){

    return 0;
}

Nodo *union(Nodo *colaFnte, Nodo *colaFin, Nodo *pila){
    Nodo *auxColaFnte = colaFnte;
    Nodo *auxPila = pila;
    Nodo *resultado = NULL;

    while(auxPila != NULL){
        int valor = pop(auxPila);
        insertarOrdenado(resultado, valor);
    }


    while(auxColaFnte != NULL){
        int valor = suprimir(auxColaFnte, colaFin);
        insertarOrdenado(resultado, valor);
    }

    return resultado;

}




//1.

#include <iostream>
#include <stdio.h>
using namespace std;

struct Nodo{
    int info;
    Nodo* sig;
};

Nodo *union(Nodo* colaFte, Nodo* colaFin, Nodo* pila){
    Nodo* lista;

    while(colaFte != NULL){
        int valor = suprimir(colaFte, colaFin);
        insertarOrdenado(lista, valor);
    }

    while(pila != NULL){
        int valor = pop(pila);
        insertarOrdenado(lista, valor);
    }
    return lista;
}

//2. 

Nodo *interseccion(Nodo* listaA, Nodo* listaB){
    Nodo* auxA = listaA;
    Nodo* auxB = listaB;
    
    Nodo* lista;

    while(auxA != NULL){
        while(auxB != NULL){
            if(auxB->info == auxA->info){
                insertar(lista, auxA->info);
            }
            auxB = auxB->sig;
        }
        auxA = auxA->sig;
    }

    return lista;
}

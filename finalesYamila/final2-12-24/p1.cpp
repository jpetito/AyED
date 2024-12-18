#include <iostream>
#include <stdio.h>
using namespace std;

struct Nodo{
    int info;
    Nodo *sig;
};

Nodo *union(Nodo *colaFnte, Nodo *colaFin, int vec[], int len);
void insertarOrdenado(Nodo* &lista, int valor);
Nodo *buscar(Nodo* &lista, int valor);

int main(){

    return 0;
}

Nodo *union(Nodo *colaFnte, Nodo *colaFin, int vec[], int len){
    Nodo *auxColaFnte = colaFnte;
    Nodo *auxColaFin = colaFin;
    Nodo *resultado = NULL;
    
    while(auxColaFnte != NULL){
        int valor = suprimir(auxColaFnte, auxColaFin);
        insertarOrdenado(resultado, valor);
    }

    for(int i=0; i<len; i++){
        int valor = vec[i];
        insertarOrdenado(resultado, valor);
    }

    return resultado;
}



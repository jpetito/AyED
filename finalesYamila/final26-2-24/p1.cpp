//1.

#include <iostream>
#include <stdio.h>
using namespace std;

struct Nodo{
    int info;
    Nodo* sig;
};

void insertarOrdenado(Nodo* &lista, int valor);
Nodo *interseccion(Nodo* &lista, Nodo* &pila);
int pop(Nodo* &pila);
Nodo *buscar(Nodo* &lista, int valor);

int main(){

return 0;
}

//precondicion: tanto la lista como la pila deben estar previamente ordenadas antes de ejecutar la funcion,
// de caso contrario no funcionaria correctamente

Nodo *interseccion(Nodo* lista, Nodo* pila){
    Nodo *resultado = NULL;
   
    Nodo *auxLista = lista;
    Nodo *auxPila = pila;


    while(auxPila != NULL){
        int elemento = pop(auxPila);

        while(auxLista != NULL){
            if(auxLista->info == elemento){
                insertarOrdenado(resultado, elemento);
            }
        } auxLista = auxLista->sig;

    }

    return resultado;
}

#include <iostream>
#include <stdio.h>
using namespace std;

struct Producto{
    int id;
    char tipo;
    int unidades;
};

struct Pedido{
    int idProducto;
    int idCliente;
    int unidadesRequeridas;
};

struct Nodo{
    Pedido info;
    Nodo *sig;
};

void insertarOrdenado(Nodo* &lista, int valor);
Nodo *buscar(Nodo* &lista, int valor);

int main(){

    Producto vec[50];
    Nodo *Pedidos;

    Nodo *aux = Pedidos;

    while(aux != NULL){
        for(int i; i < 50; i++){
            if(aux->info.idProducto == vec[i].id){
                vec[i].unidades -= aux->info.unidadesRequeridas;
            }
        }
        aux = aux->sig;
    }

    return 0;
}










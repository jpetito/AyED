//3.

#include <iostream>
#include <stdio.h>

using namespace std;


struct Producto {
    int codProd;
    int peso;
    char tipo;
    int cantStock;
};


struct Nodo{
    Producto info;
    Nodo* sig;
};

void insertarOrdenadoPorProducto(Nodo*&lista, Producto valor);
void insertar(Nodo*&lista, Producto valor);
void mostrar(Nodo * lista);
void liberar(Nodo * &lista);


int main(){
    FILE *archivo;
    archivo = fopen("STOCK.DAT", "rb");

    Producto raux;

    Nodo *ListaProd = NULL;
    Nodo *ListaSinStock = NULL;
    Nodo *ListaProdPesados = NULL;

    fread(&raux, sizeof(struct Producto), 1, archivo);
    while(!feof){
        insertarOrdenadoPorProducto(ListaProd, raux);

            if(raux.cantStock == 0){
                insertar(ListaSinStock, raux);
            }

            if(raux.peso >= 100 && raux.tipo == 'B'){
                insertar(ListaProdPesados, raux);
            }

        fread(&raux, sizeof(struct Producto), 1, archivo);
    }

    fclose(archivo);

    archivo = fopen("STOCK.DAT", "wb");
//PUNTO A
    Nodo* aux = ListaProd;

    while(aux != NULL){
        fwrite(&aux->info, sizeof(struct Producto), 1, archivo);
        aux = aux->sig;
    }

    fclose (archivo);
    liberar(ListaProd);

//PUNTO B

    mostrar(ListaSinStock);
    liberar(ListaSinStock);
    mostrar(ListaProdPesados);
    liberar(ListaProdPesados);

    return 0;
}

void insertarOrdenadoPorProducto(Nodo*&lista, Producto valor){
    Nodo* nuevo = new Nodo();
    
    nuevo->info.cantStock = valor.cantStock;
    nuevo->info.codProd = valor.codProd;
    nuevo->info.peso = valor.peso;
    nuevo->info.tipo = valor.tipo;

    Nodo *aux = lista;
    Nodo *ant= NULL;

    while(aux!= NULL && aux->info.codProd < valor.codProd){
        ant = aux;
        aux = aux->sig;

        if(ant == NULL){
            lista = nuevo;
        }else {
            ant->sig = nuevo;
        } aux = aux->sig;
    }
}

void liberar(Nodo* &lista){
    Nodo *aux = lista;

    while(aux != NULL){
        aux = lista;
        lista = aux->sig;
        delete(aux);
    }
    
}
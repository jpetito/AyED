#include <iostream>
#include <stdio.h>

using namespace std;

struct vendedores{ //max 10
    int id;
    char apynombre [60];
};

struct modelos{ //max 15
    int id;
    char descrip[70];
};

struct ventas{ //archivo sin ordenar
    int idModelo;
    int idVendedor;
    int fecha;
    char cliente[60];
};

struct NodoVentas{
    ventas info;
    NodoVentas* sig;
};

struct NodoVendedores{
    vendedores info;
    NodoVendedores *sig;
}

//prototipos
void cargarModelos(modelos vec[]);
void imprimirListado(modelos vec[], NodoVentas *ventas, FILE *ventas);
vendedores busquedaVendedor(NodoVentas *vendedores, int id);

int main(){
}

void cargarModelos(modelos vec[]){
    for (int i=0, i<15, i++){
        cout<<"ingrese el id del modelo(0 para finalizar): "<<endl;
        cin>>vec[i].id;
        if (vec[i].id == 0){
            i=15
        }else{
        cout<<"ingrese la descripcion del modelo: "<<endl;
        cin>>vec[i].descrip;
        }
    }
}

vendedores busquedaVendedor(NodoVendedores *vendedores, int id){
   while (vendedores != NULL){
    if (vendedores->info.id == id){
        return vendedor->info;
    }
    vendedores=vendedores->sig;
   }
}

//listado agrupado por modelo y ordenado por id vendedor
//MODELO
//idvendedor  nombrevendedor   cliente   fecha
void imprimirListado(modelos vec[], NodoVendedores *vendedores){
    FILE *archivo=fopen("VENTAS.dat", "rb");  
    ventas aux;
    NodoVentas *lista=NULL;

    while(fread(&aux),sizeof(ventas),1,VENTAS){ //
      insertarOrdenado(lista,aux); //inserta en la lista y la deja ordenada por modelo y vendedor
    }
    while (lista!=NULL){
        int modelo=lista->info.idModelo;
        cout<<modelo<<endl;
        while (lista!=NULL && lista->info.idModelo == modelo){
          cout<<lista->info.idVendedor<<"  "<<busquedaVendedor(vendedores, lista->info.idVendedor).apynombre<<"  ";
          cout<<lista->info.cliente<<"  "<<lista->info.fecha<<endl;
          lista=lista->sig;
        }
     
    }

}

void insertarOrdenado(NodoVentas* lista, venta info){
    if(lista==NULL || lista->info.idModelo > info.idModelo || (lista->info.idModelo == info.idMolelo && lista->info.idVendedor > info.idVendedor)){
        NodoVentas* nuevo=new NodoVentas;
        nuevo->info=info;
        nuevo->sig=lista;
        lista=nuevo;
    }else {
        NodoVentas*aux=lista;
        while (aux->sig!=NULL && aux->sig->info.idModelo<info.idModelo || aux->sig->info.idModelo==info.idModelo && aux->sig->info.idVendedor>info.idVendedor){
        aux=aux->sig;
        }
        nuevo->sig=aux->sig;
        aux->sig=nuevo;
    }
}
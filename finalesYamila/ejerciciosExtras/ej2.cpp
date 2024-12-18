// Se tiene un archivo de disponibilidad para las habitaciones de un hotel en 
// la costa de verano 2021 sin orden

// - Número de Habitación: 99999
// - Tipo: 's', 'd', 't' o 'c' (Single, Doble, Triple o Cuádruple)
// - Días disponibles de la temporada: 999
// - Precio por día de la habitación: 999 (entero)
// Se pide:

// a) Ordenar el archivo Verano2021.DAT por precio de habitación
// b) Armar una lista, ordenada por numero de habitacion y mostrarla por pantalla si el 
// numero de dias disponibles es menor a 50 y son habitaciones singles o dobles.

#include <iostream>
#include <stdio.h>
using namespace std;

struct tInfo{
    int numHab;
    char tipo; //'s', 'd', 't' o 'c' (Single, Doble, Triple o Cuádruple)
    int diasDisponibles;
    int precioPorDia;
};

struct Nodo{
    tInfo info;
    Nodo* sig;
};

void insertarOrdenadoSegunDisponibilidad(Nodo* &lista, tInfo valor);
void insertarOdenadoSegunNumeroHab(Nodo* &lista, tInfo valor);
void mostrar(Nodo* &lista);
void liberar(Nodo* &lista);

int main(){
    FILE *archivo;

    Nodo* listaA = NULL;
    Nodo* listaB = NULL;

    tInfo raux;

    archivo = fopen("Verano2021.dat", "rb");

    fread(&raux, sizeof(struct tInfo), 1, archivo);

    while(!feof(archivo)){
        insertarOrdenadoSegunDisponibilidad(listaA, raux); //puntoA
        if(raux.diasDisponibles < 50 && raux.tipo == 'S' || raux.tipo == 'D'){
            insertarOdenadoSegunNumeroHab(listaB, raux); //puntoB
        }

        fread(&raux, sizeof(struct tInfo), 1, archivo);
    
    }

    fclose(archivo);

//sobreescribo el archivo para terminar el punto A

    Nodo* aux = listaA;
    archivo = fopen("Verano2021.dat", "wb");

    if(aux != NULL){
        fwrite(&aux->info, sizeof(struct tInfo), 1, archivo);
        aux = aux -> sig;    
    }

    fclose(archivo);

    liberar(listaA);

    mostrar(listaB); //finalizo el punto B

    liberar(listaB);

}

void insertarOrdenadoSegunDisponibilidad(Nodo* &lista, tInfo valor){
    Nodo* nuevo = new Nodo();  

    nuevo->info.numHab = valor.numHab;
    nuevo->info.tipo = valor.tipo;
    nuevo->info.diasDisponibles = valor.diasDisponibles;
    nuevo->info.precioPorDia = valor.precioPorDia;

    Nodo* aux = lista;
    Nodo* ant = NULL;

    while(aux != NULL && aux->info.precioPorDia < valor.precioPorDia){
        ant = aux;
        aux = aux->sig;
    }
    if(ant == NULL){
        lista = nuevo;
    } else{ 
        ant->sig = nuevo;
    }
        aux = aux->sig;

}

void insertarOdenadoSegunNumeroHab(Nodo* &lista, tInfo valor){
    Nodo* nuevo = lista;

    nuevo->info.numHab = valor.numHab;
    nuevo->info.tipo = valor.tipo;
    nuevo->info.diasDisponibles = valor.diasDisponibles;
    nuevo->info.precioPorDia = valor.precioPorDia;

    Nodo* aux = lista;
    Nodo* ant = NULL;

    while(aux != NULL && aux->info.numHab < valor.numHab){
        ant = aux;
        aux = aux -> sig;
    }
    if(ant == NULL){
        lista = nuevo;
    }else ant -> sig = nuevo;
        aux = aux->sig;

}

void liberar(Nodo* &lista){
    Nodo* aux = lista;
     
    while(aux != NULL){
        aux = lista;
        lista = aux ->sig;
        delete(aux);   
    }
}

void mostrar(Nodo* &lista){
    Nodo* aux = lista;

    while(aux != NULL){
        cout<<"Numero de habitacion: "<<aux->info.numHab<<endl;
        cout<<"Tipo de habitacion: "<<aux->info.tipo<<endl;
        cout<<"dias disponibles: "<<aux->info.diasDisponibles<<endl;
        cout<<"precio por dia: "<< aux-> info.precioPorDia<<endl;
        
        aux=aux->sig;
    }
}
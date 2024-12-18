//Dado un archivo de registro (codPrd; tipodeProd) generar 2 archivos ordenados (segun el tip'A' o 'B') por el codigo de producto
#include <iostream>
#include <stdio.h>
using namespace std;


    Nodo* listaA = NULL;
    Nodo* listaB = NULL;
    
    FILE *arch; //archivo general
    FILE *archA;
    FILE *archB;


    arch = fopen("arch.dat", "rb");
    archA = fopen("archA.dat", "wb");
    archB = fopen("archB.dat", "wb");

    tInfo raux;

    fread(&raux, sizeof(struct tInfo), 1, arch);

    while (!feof(arch)) {

        if(raux.tipoProd == 'A'){
            insertarOrdenado(listaA, raux);
        } else{ 
            insertarOrdenado(listaB, raux);
        } //aca abri el archivo, lo ordene en las listas

        fread(&raux, sizeof(struct tInfo), 1, arch);
    }

    fclose(arch); // cierro el archivo

    //primero escribo el archivo A
    archA = fopen("archA.dat", "wb");
    Nodo* aux = listaA;

    while(aux != NULL){

        fwrite(&aux->info, sizeof(struct tInfo), 1, archA);
        aux = aux ->sig;
    }
    fclose(archA);

    liberar(listaA);

    //ahora lo hago con la lista B
    archB = fopen("archB.dat", "wb");
    Nodo* aux = listaB;

    while(aux!= NULL){

        fwrite(&aux->info, sizeof(struct tInfo), 1, archB);
            aux = aux->sig;
    }
    fclose(archB);

    liberar(listaB);


    return 0;
}

void insertarOrdenado(Nodo* &lista, tInfo valor){
    Nodo* nuevo = new Nodo();

    nuevo->info.codProd = valor.codProd;
    nuevo->info.tipoProd = valor.tipoProd;
    nuevo->sig = NULL;

    Nodo* aux = lista;
    Nodo* ant = NULL;

    while(aux!=NULL && aux->info.codProd < valor.codProd){
        ant = aux;
        aux = aux->sig;
    }

    if(ant == NULL){
        lista = nuevo;
    }else {
        ant->sig = nuevo;
    }
        aux = aux->sig;

}

void liberar(Nodo* &lista){
    Nodo* aux = lista;

    while(aux!=NULL){
        aux = lista;
        lista = aux->sig;
        delete(aux);
    }
}


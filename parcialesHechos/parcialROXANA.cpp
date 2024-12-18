#include <iostream>
#include <stdio.h>

using namespace std;

struct envios{
    char direccion[100];
    int dni;
    char palabra[15];
};

struct ListaEnvios{
    envios info;
    ListaEnvios *sig;
};

struct comuna{
    int CantEnvios=0;
    ListaEnvios *lista1=NULL;
    ListaEnvios *lista2=NULL;
};

comuna vector [15];
//PROTOTIPOS 
void procedimiento (comuna vec[], envios pedido, int num);
void InsertarOrdenado (ListaEnvios *lista, envios pedido);

void procedimiento(comuna vec[], envios pedido, int num){
    int cont1=0;
    int cont2=0;

    ListaEnvios *aux1=vec[num-1].lista1;
    ListaEnvios *aux2=vec[num-1].lista2;

    while (aux1 != NULL){
        cont1++;
        aux1=aux1->sig;
    }

    while (aux2 != NULL){
        cont2++;
        aux2=aux2->sig;
    }

    if (cont1<cont2){
        InsertarAtras(vec[num-1].lista1, pedido);
    }else {
        InsertarAtras(vec[num-1].lista2, pedido);
    }

    vec[num-1].CantEnvios++;
}

void procedimiento2 (comuna vec[], char nombreArchivo){
    //que agregue al final del archivo todos los pedidos que ya fueron entregados
    FILE * f;

    f = fopen(nombreArchivo, "rb+");
    fseek(f, 0, SEEK_END); //abro el archivo en lectura y lo ubico al final

    for (int i=0; i<15; i++){
        
        int cont1=0;
        int cont2=0;

        ListaEnvios *aux1=vec[i].lista1;
        ListaEnvios *aux2=vec[i].lista2;

        while (aux1 != NULL){ //cuento la cantidad de envios
            cont1++;
            aux1=aux1->sig;
        }

        while (aux2 != NULL){
            cont2++;
            aux2=aux2->sig;
        }

        if ((cont1+cont2)==vec[i].CantEnvios){ 
            //si la cantidad de envios son la misma a la cantidad de envios entregados
            //significa que todos fueron entregados
            //debo guardarlos al final del archivo
            aux1=vec[i].lista1;
            aux2=vec[i].lista2;
            ListaEnvios *ant1;
            ListaEnvios *ant2;

            while (aux1 != NULL){
                ant1=aux1;
                fwrite(&aux1->info, sizeof(envios), 1, f);
                pop(ant1->info);
                aux1=aux1->sig;
            }

           while (aux2 != NULL){
                ant2=aux2;
                fwrite(&aux2->info, sizeof(envios), 1, f);
                pop (ant2->info);
                aux2=aux2->sig;
            }
        }
    }
}
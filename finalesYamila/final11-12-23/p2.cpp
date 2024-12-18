//2.

#include <iostream>
#include <stdio.h>
using namespace std;

struct Hotel{
    int codHotel;
    int cantReservas;
    int cantDiasDisp;
};

struct Reserva{
    int codHotel;
    int cantDiasReserv;
};

struct Nodo{
    Reserva info;
    Nodo* sig;
};

int main(){
    Hotel vec[50];
    Nodo *lista;

    Nodo *aux = lista;

    while(aux != NULL){
        for(int i=0 ; i<50 ; i++){
            if(vec[i].codHotel == aux->info.codHotel){
                vec[i].cantDiasDisp -= aux->info.cantDiasReserv;
                vec[i].cantReservas++;
            }
        }
        aux = aux->sig;
    }

    return 0;
}
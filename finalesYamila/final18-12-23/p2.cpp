//2.
#include <iostream>
#include <stdio.h>
using namespace std;

struct alumno{
    int legajo;
    int nota1;
    int nota2;
};

struct recus{
    int legajo;
    int nota2Recu;
};

struct Nodo{
    recus info;
    Nodo *sig;
};

int main(){

    alumno vec[1500];
    Nodo *auxLista;

    while (auxLista != NULL){
        for(int i; i<1500 ; i++){
            if(vec[i].legajo == auxLista->info.legajo && auxLista->info.nota2Recu >= 6){
                vec[i].nota2 == auxLista->info.nota2Recu;
            }
        }
    }

    return 0;
}
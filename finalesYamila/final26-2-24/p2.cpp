//2.

#include <iostream>
#include <stdio.h>
using namespace std;

struct Nodo{
    int info;
    Nodo* sig;
};

struct cuenta{
    int numCuenta;
    int cantTrans;
    int saldo;
};

struct transaccion{
    int numCuenta;
    int monto;
};

struct Nodo{
    transaccion info;
    Nodo* sig;
};


int main(){

    cuenta vec[150];
    Nodo *auxLista;

    while(auxLista != NULL){
        for(int i; i < 150 ; i++){
            if(auxLista->info.numCuenta == vec[i].numCuenta){
                vec[i].saldo += auxLista->info.monto;
                vec[i].cantTrans++;
            } else auxLista = auxLista->sig;
            }
    }

    return 0;
}

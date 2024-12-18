//2. 

#include <iostream>
#include <stdio.h>
using namespace std;

struct cliente{
    int nroCliente;
    int nroCuenta;
    int saldo;
    transaccion ultMovimiento;
};

struct transaccion{
    int nroCuenta;
    int monto;
};

struct Nodo{
    transaccion info;
    Nodo *sig;
};

void insertarOrdenado(Nodo* &lista, int valor);
Nodo *buscar(Nodo* &lista, int valor);

int main(){

    cliente vec[200];
    Nodo *lista; //de ultimas transacciones

    Nodo* aux = lista;

    while(aux != NULL){
        for(int i=0; i<200; i++){
            if(aux->info.nroCuenta == vec[i].nroCuenta){
                vec[i].saldo += aux->info.monto;
                vec[i].ultMovimiento = aux->info;
            }
        }
        aux = aux->sig;
    }

    return 0;
}
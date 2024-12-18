#include <iostream>
#include <stdio.h>

using namespace std;

struct vendedores{ //vector 10
    int id;
    char apyNombre[20];
};

struct modelos{ //vector 15
    int id;
    char descrip[20];
};

struct ventas{ //1<n<100
    int idModelo;
    int idVendedor;
    int fecha;
    char cliente[20];
};

int N; //tamanio del vector
vendedores vecVendedores[10];
modelos vecModelos[15];
ventas vecVentas[N];

//PROTOTIPOS
vendedores buscar (vendedores vec[], int tam, int id);
modelos buscar (modelos vec[], int tam, int id);

int cantVentasDelDia(ventas vector[], int tam, int fecha){
   int cont=0;
   
    for (int i=0; i<tam; i++){
        if (vector[i].fecha == fecha){
            cont++;
        }
    }
    return cont; //cantidad de ventas ese dia
}

void emitirListado(vendedores vecVendedores[],modelos vecModelos[], ventas vecVentas[], int n){//n es el tamanio del vector

    for(int i=0; i<n; i++){
        cout<<"fecha: "<<vecVentas[i].fecha<<endl;
        cout<<"cantidad de ventas del dia: "<<cantVentasDelDia(vecVentas, n, vecVentas[i].fecha)<<endl;
        cout<<vecVentas[i].cliente<<"    "<<buscar(vecVendedores, 10, vecVentas[i].idVendedor).apyNombre<<"     "<<buscar(vecModelos, 15, vecVentas[i].idModelo).descrip<<endl;
    }
}

#include <iostream>
#include <stdio.h>

using namespace std;

struct paciente{
    char nombre[50];
    char apellido[50];
    int dni;
};

struct tarjeta{ //archivo ordenado por dni
    int idLab;
    int idTarj;
    paciente paciente;
};

struct compras{ //archivo de compras del mes de marzo 
    int dia;
    int idTarj;
    int unidades;
    int idProd;
    int precio;
    float descuento;
};

struct NodoCompra{
    int dia;
    int vendidas;
    int id_prod;
    float descuento;
    NodoCompra *sig;
};

struct NodoTarj{
    int idTarj;
    NodoLab *sig;
};

struct NodoLab{
    int idLab;
    NodoTarj *tarjetas=NULL;
    NodoCompra *compras=NULL;
    NodoLab *sig;
};

void imprimirListado (FILE *tarjetas, FILE *compras);

int main(){

}
/*LABORATORIO
DIA
idProducto cantidad vendida	importe total de descuento
(sumatoria de bonificaciones por todas las ventas realizadas para este producto)

Ejemplo

LABORATORIO PFIZER
1
Idproducto	cantidad	importe dcto
100		   55		  990 		
(ese producto sale $120 se venden 55 unidades y el descuento es de 15%=> 55*120=6600, $6600 * 0.15 = 990)*/

void insertarTarj(NodoTarj *&lista, int id){
    NodoTarj* nuevo = new NodoTarj;
    nuevo->idTarj=id;
    nuevo->sig=lista;
    lista=nuevo;
}

void insertarEnLab(NodoLab *&lista, tarjeta *aux){
    if (lista==NULL){
        NodoLab* nuevo=new NodoLab();
        lista->idLab=tarjeta.idLab;
        lista->sig=nuevo;
        insertarTarj(lista->tarjetas, aux->idLab);
    } else{
        NodoLab* aux = lista;
        while (aux->sig != NULL && aux->sig->idLab >= tarjeta.idLab){
            aux=aux->sig; //que avance
        }
        if (aux->idLab == tarjeta.idLab){
            insertarTarj(lista->tarjetas, aux->idLab);
        }else{
        NodoLab* nuevo=new NodoLab();
        lista->idLab=tarjeta.idLab;
        lista->sig=nuevo;
        insertarTarj(lista->tarjetas, aux->idLab);
        }
    }
}

NodoCompra* buscarLab

void imprimirListado (FILE *tarjetas, FILE *compras){
    NodoLab *laboratorios=NULL;
    tarjeta tarj;
    compras comp;

    while (fread(&tarj, sizeof (tarjeta), 1, tarjetas)){
        insertarEnLab(laboratorios, tarj);
    }
    while (fread(&comp, sizeof (compras), 1, tarjetas)){
        insertarEnLab(laboratorios, tarj);
    }
}

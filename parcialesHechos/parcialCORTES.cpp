#include <iostream>
#include <stdio.h>

using namespace std;

//tengo un archivo con estos datos;
struct Cortes{
    int hora_inicial;
    int hora_final;
    int id_subestacion; 
    int dia;
    int mes;
    int id_localidad;
};

struct NodoCortes{
    Cortes info;
    NodoCortes *sig;
};

//se cuenta con un vector completo y ordenado de localidades;
struct Localidades{
    char nombre[50];
    int cant_habitantes;
};

/* LISTADO ORDENADO POR MES Y POR LOCALIDAD 

MES 

cantidad de horas promedio de corte por mes (tendria que sumar todas las horas que se cortaron en ese mes) 

localidad(nombre)   total de horas de cortes  unidades de la multa 
lomas de zamora       3                         no se cuenta
lomas de zamora       3 y 6                     8 unidades 
lomas de zamora       6+                        12 unidades 

*/
int n; //cantidad de localidades (lo sabe el archivo)
Localidades vector[n];

void imprimirListado(FILE *archivo, Localidades vector[], n){

NodoCortes *Lista=NULL;
Cortes raux;

while(fread(&raux), sizeof(Cortes), 1, archivo){
    insertarOrdenado(Lista, raux); //ordeno por mes y localidad
}
while (Lista!=NULL){    //corte de control
    cout<<Lista->info.mes<<endl; //muestro el mes

    int mes=Lista->info.mes;
    int cont=0;
    int sumaHoras=0;
    float promedio;

    cout<<"localidad(nombre)    total de horas de cortes    unidades de la multa"<<endl;
    while (Lista!=NULL && mes == Lista->info.mes){
    cont++;
    sumaHoras+=(Lista->info.hora_final - Lista->info.hora_inicial);

    cout<<buscadorLocalidades(Lista->info.id_localidad, vector[], n).nombre<<"    "<<sumaHoras<<"     "<<unidadesMulta(sumaHoras)<<" unidades"<<endl;
    }

    promedio= (sumaHoras/cont);
    cout<<"Cantidad de horas promedio de corte por mes: "<<promedio<<endl;

}
}

void insertarOrdenado(NodoCortes &Lista, Cortes Registro){

NodoCortes *nuevo=new NodoCortes();

nuevo->info=Registro; //cargo el nodo

NodoCortes *aux=Lista;
NodoCortes *ant=NULL;
//busco
while (aux!= NULL && (aux->info.mes<= Registro.mes && Lista->info.id_localidad <= Registro.id_localidad)){
    ant=aux;
    aux=aux->sig;
}
if (ant==NULL){
    Lista=nuevo;
}else{
    ant->sig=nuevo;
}
 nuevo->sig=aux;
}

Localidades buscadorLocalidades(NodoCortes *Lista->info.id_localidad, Localidades vector[],int n){
    for (int i=0; i<n; i++){
        if(listaA->info.id_localidad = i)
		return vector[i]; 
	}
}

int unidadesMulta(int horas){ 
    if (horas<3){
        return 0;
    }else if(horas<=6){
        return(horas * 8);
    }else{
       return(horas * 12);
    }
}
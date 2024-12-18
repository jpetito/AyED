#include <iostream>
using namespace std;

struct Cortes{
	int inicio; //hhmm 
	int final;
	int id_subestacion;
	int dia;
	int mes;
	int id_localidad;
};  //archivo sin orden 

struct Nodo_Cortes{
	Cortes info;
	Nodo_Cortes* sgte;
};

struct Localidades{
	char nombre[50];
	int habitantes;
}; 
//el vector es Localidades vector[id_localidad] ordenado por id_localidad
Localidades vector[id_localidad]; 

/* LISTADO ORDENADO POR MES Y POR LOCALIDAD 

MES 

cantidad de horas promedio de corte por mes (tendria que sumar todas las horas que se cortaron en ese mes) 

localidad(nombre)   total de horas de cortes  unidades de la multa 
lomas de zamora       3                         no se cuenta
lomas de zamora       3 y 6                     8 unidades 
lomas de zamora       6+                        12 unidades 

*/
int main(){
		
	return 0; 
}

void imprimir_listado(FILE* archivo_corte, Localidades vector[], int n){

    Nodo_Cortes* listaA=NULL; 
	Cortes raux;
	while(fread(&raux,sizeof(Cortes),1,archivo_corte){ //leo el archivo y lo ordeno por mes y por localidad
		InsertarOrdenado(listaA,raux); 
	} 
	
	while(listaA!=NULL){ //corte de control.... 
		
		cout << listaA->info.mes << endl; // muestro el mes
		
		int mes= listaA->info.mes; 
		int sumador=0;
		int cant=0;
		int resultado=0;
	
		while(listaA!=NULL && mes = listaA->info.mes){
			// cantidad de horas promedio por cada mes
			sumador= sumador + (listaA->info.final - listaA->info.inicio); 
			cant++;  
			cout << buscar(vector[], listaA->info.id_localidad).nombre << endl;
			cout << resultado = (listaA->info.final - listaA->info.inicio) << endl;
			if(resultado < 3){
				cout << "sin multas " << endl;
			}
			else if(resultado >= 3 && resultado =< 6){
				cout << resultado * 8; 
			}
			else if(resultado > 6){ 
			   cout << resultado * 12;
			}
			listaA=listaA->sgte;
		}	
		cout << "cantidad de horas promedio por mes: " << sumador/cant << endl; // no me termina de cerrar me quedo abajo 
	}
}



void InsertarOrdenado(Nodo_Cortes* listaA, Cortes raux){
	
	Nodo_Cortes* nuevo= new Nodo_Cortes;
	nuevo->info=raux;
	
	if(listaA==NULL || listaA->info.mes > raux.mes || listaA->info.mes == raux.mes && listaA->info.id_localidad > raux.id_localidad){
		nuevo->sgte=listaA;
		listaA=nuevo;
	}
	else{
		Nodo_Cortes* aux=listaA; 
		while(aux->sgte!=NULL && (aux->sgte->info.mes < raux.mes || aux->sgte->info.mes == raux.mes &&  aux->sgte->info.id_localidad < raux.id_localidad){
			aux=aux->sgte;
		}
		nuevo->sgte=aux->sgte;
		aux->sgte=nuevo; 
	}
}

Localidades buscar(Localidades vector[], Nodo_Cortes* listaA->info.id_localidad){
	//n es la cantidad de posiciones que tiene el vector que en realidad son las id_localidad
	for(int i=0;i<n;i++){
		if(listaA->info.id_localidad = i)
		return vector[i]; 
	}
}
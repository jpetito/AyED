#include <iostream>
using namespace std;

struct pacientes{
	int id;
	char nombre[50];
	char apellido[50];
	int edad;
	int diagnostico; 
}; // archivo ordenado por id 

struct NodolistaP{
	pacientes info;
	NodolistaP* sgte; 	
};

struct medicamentos{
	int ean;
	char nombregenerico[50];
	int dosis;
}; //archivo sin orden

struct NodolistaM{
	medicamentos info;
	NodolistaM* sgte;
}; 

struct prescripciones{
	int id;
	int ean;
	int intervalo;
	int inicio;
}; prescripciones vector[]; 


int main(){

	return 0;
}
/* agarraria el vector de prescripciones lo ordenaria por id; 
id nombre apellido (lo busco pasandole el id) ean ya esta le paso ean a archivo y me traiga el nombre 
generico y dosis, hora ya esta en el vector*/ 

void imprimirprescipciones(FILE* archivo_pacientes, FILE* archivo_medicamentos, prescripciones vector[], int n){

    pacientes raux; 
    NodolistaP* listaP=NULL; 
	 
    while(fread(&raux,sizeof(pacientes),1,archivo_pacientes)){
    	insertarordenado(listaP,raux);
	}
    
    medicamentos raux; 
    NodolistaM* listaM=NULL;
    
    while(fread(&raux,sizeof(medicamentos),1,archivo_medicamentos)){
    	insertarordenado(listaM,raux);
	}

	int aux;
	
	for(int i=0;i<n;i++){ //METODO BURBUJA ordene el vector por id de paciente
		for(int j=0; j<n;j++){
			if(vector[j] > vector[j+1]){
				aux=vector[j];
				vector[j]=vector[j+1];
				vector[j+1]=aux;
			}
		}
	}
	
	for(int i=0;i<n;i++){
		cout << vector[i].id << endl;
		cout << buscar(ListaP, vector[i].id).nombre << endl; //mandas a busccar a la lista los datos que coincidan con ese nombre y los traes
		cout << buscar(ListaP, vector[i].id).apellido << endl;
		cout << vector[i].ean << endl;
		cout << buscarM(listaM,vector[i].ean).nombregenerico << endl;
		cout << buscarM(listaM,vector[i].ean).dosis << endl;
		cout << vector[i].inicio << endl;
	}
	
}

pacientes buscar(NodoListaP* listaP, int id){
	
	while(listaP!=NULL){
		if(listaP->info.id == id){
			return listaP->info;
		}
		listaP=listaP->sgte;
	}
}

medicamentos buscarM(NodoListaM* listaM, int ean){
	
	while(listaM!=NULL){
		if(listaM->info.ean == ean){
			return listaM->info;
		}
		listaM=listaM->sgte;
	}
} 

void NoInscriptos()

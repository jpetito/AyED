#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

//archivo ordenado por id
struct pacientes{
    int id;
    char nombre [50];
    char apellido[50];
    int edad;
    int diagnostico;
};

struct medicamentos{ //archivo
    int ean;
    char nombreGen[50];
    int dosis;
};

struct prescrip{ //vector desordenado
    int id_paciente;
    int ean;
    int intervalo;
    int hora_inicio;
};

struct infoLista{
    int id;
    char nombre[50];
    char apellido[50];
    int ean;
    char nombreGen[50];
    int dosis;
    int hora;
};

struct infoLista2{
    int id;
    char nombre[50];
    char apellido[50];
};

struct ListaPrescrip{
    infoLista info;
    ListaPrescrip *sig;
};

struct ListaNoPrescrip{
    infoLista2 info;
    ListaNoPrescrip *sig;
};

struct ListaPac{
    pacientes info;
    ListaPac *sig;
};
//PROTOTIPOS

void MetodoBurbuja(prescrip vec[], int tamVec); //ordena el vector por id
void prescripciones(FILE *archivoPacientes, FILE *archivoMedicamentos, prescrip vec[], int tamVec);
void listarPrescripciones(ListaPrescrip &lista);
void buscarNoPrescriptos(FILE *archivoPacientes, ListaPrescrip &ista);
void listarNoPrescrip(ListaNoPrescrip &lista);
void insertarOrdenado(ListaNoPrescrip lista, pacientes dato);

//Su tarea es hacer una función (xxx prescripciones(…)) que liste las prescripciones 
//del dia ordenadas por paciente con los siguientes datos:
//Id 	Nombre 	Apellido	 EAN 	nombre genérico 	dosis 	HORA
void prescripciones(FILE *archivoPacientes, FILE *archivoMedicamentos, prescrip vec[], int tamVec){
    pacientes paciente;
    medicamentos medicamento;
    ListaPrescrip *lista=NULL;

    MetodoBurbuja(vec, tamVec); //ordeno el vector por id del paciente

    while (fread(&paciente, sizeof (pacientes), 1, archivoPacientes)){
        for (int i; i<tamVec; i++){
            if (paciente.id==vec[i].id_paciente){ //si tienen el mismo id,
               lista->info.id=paciente.id; //lo guardo en la lista, con sus datos correspondientes
               stringcpy(lista->info.nombre, paciente.nombre);
               stringcpy(lista->info.apellido, paciente.apellido);
               lista->info.hora=vec[i].hora_inicio;
            }
        }
    }
    while (fread(&medicamento, sizeof (medicamentos), 1, archivoMedicamentos)){
        for (int i; i<tamVec; i++){
            if (medicamento.ean==vec[i].ean){
                lista->info.ean=medicamento.ean;
                stringcpy(lista->info.nombreGen, medicamento.nombreGen);
                lista->info.dosis=medicamento.dosis;
            }
        }
    }
}

void listarPrescripciones(ListaPrescrip &lista){
    ListaPrescrip *aux;

    while (aux != NULL){

    cout<<aux->info.id<<"   "<<aux->info.nombre<<"   "<<aux->info.apellido<<"   ";
    cout<<aux->info.ean<<"   "<<aux->info.nombreGen<<"   "<<aux->info.dosis<<"   ";
    cout<<aux->info.hora<<endl;

    aux=aux->sig;
    }
}
//Emita un listado de los pacientes (id, apellido y nombre) que
//aun no tienen prescripción
void listarNoPrescrip(ListaNoPrescrip &lista){
    ListaNoPrescrip *aux;

    while (aux != NULL){

    cout<<aux->info.id<<"   "<<aux->info.nombre<<"   "<<aux->info.apellido<<"   ";
    cout<<aux->info.ean<<"   "<<aux->info.nombreGen<<"   "<<aux->info.dosis<<"   ";
    cout<<aux->info.hora<<endl;

    aux=aux->sig;
    }
}

void buscarNoPrescriptos(FILE *archivoPacientes, ListaPrescrip &lista){
    pacientes paciente;
    ListaPac *listaPac=NULL;
    ListaPrescrip *presc;
    presc=lista;
    ListaNoPrescrip *lista2=NULL;
//tengo que comparar los pacientes con la lista, si NO estan en la lista 
//no estan prescriptos y los guardo en la lista de los no prescriptos..
    while(fread(&paciente, sizeof(pacientes), 1, "archivoPacientes")){
        insertarOrdenado(listaPac, paciente); //por id
    }

    while (listaPac != NULL){
        
        if(buscar(presc, listaPac->info.id)==NULL){//si no encuentra el id en las prescripciones 
            insertarOrdenado (lista2, listaPac->info); //entonces lo inserta en la lista 
        }
        listaPac=listaPac->sig;
    }

}

void listarNoPrescrip(ListaNoPrescrip &lista){
 ListaNoPrescrip *aux;

    while (aux != NULL){

    cout<<aux->info.id<<"   "<<aux->info.nombre<<"   "<<aux->info.apellido<<"   "<<endl;

    aux=aux->sig;
    }
}
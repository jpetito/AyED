#include <iostream>
#include <stdio.h>

using namespace std;

struct reparaciones{ //archivo
    char tipo[4];
    int id;
    char nombreDuenio[50];
    int dia;
    int mes;
    int idEmpleado;
    int presupuesto;
    int diaEntrega;
    int mesEntrega;
};

struct terminados{ //archivo
    int id;
    int mes;
    int fechaRealesEntrega;
    int importeReal;
    int idEmpleado;
};

struct empleados{ //archivo
    int id;
    char nombre[50];
};

struct listaRep{
    reparaciones info;
    listaRep *sig;
};

struct listaTer{
    terminados info;
    listaTer *sig;
};

struct listaEmp{ 
    empleados info;
    listaEmp *sig;
};

//PROTOTIPOS
reparaciones buscar(listaRep *lista, int id);
terminados buscar(listaTer *lista, int id);
int calcularImporte(listaTer *lista, int idEmpleado);
empleados buscar (listaEmp *lista, int id);

int calcularImporte(listaTer *lista, int idEmpleado){
   int importe=0;
    while(lista != NULL){
        if (lista->info.idEmpleado == idEmpleado){
        importe+=lista->info.importeReal;
        }
     lista=lista->sig;
    } return importe;
}

void imprimirDatos(int numTrabajo, FILE *archivoReparaciones, FILE *archivoTerminados, FILE *archivoEmpleados){
    reparaciones aux1;
    terminados aux2;
    empleados aux3;
    listaRep *listaA=NULL;
    listaTer *listaB=NULL;
    listaEmp *listaC=NULL;

    //paso archivos a lista
    while(fread(&aux1, sizeof(reparaciones), 1, "archivoReparaciones")){
        insertarOrdenado(listaA, aux1);
    }
    while(fread(&aux2, sizeof(terminados), 1, "archivoTerminados")){
        insertarOrdenado(listaB, aux2);
    }
    while(fread(&aux3, sizeof(empleados), 1, "archivoEmpleados")){
        insertarOrdenado(listaC, aux3); //ordenado por empleado
    }

    while (listaA != NULL ){
        if (listaA->info.id == numTrabajo){
            cout<<buscar(listaA, numTrabajo).tipo;
            cout<<buscar(listaA, numTrabajo).presupuesto;
            cout<<buscar(listaA, numTrabajo).nombreDuenio;
            cout<<buscar(listaA, numTrabajo).diaEntrega;
            if (buscar(listaB, listaA->info.id) == NULL){ //si el id del trabajo no se encuentra en terminados..
            cout<<"PENDIENTE"<<endl;
            }else {
                cout<<listaB->info.importeReal<<endl;
            }
        }
        listaA=listaA->sig;
    }
}

/*- Crear una función que dado el id de trabajo ,la fecha de entrega real y 
el importe a cobrar real actualice con dicho registro el archivo de TT.dat.*/

void actualizarArchivo (int idTrabajo, int fecha, int importe, int idEmpleado){
    FILE * f = fopen("TT.dat", "rb+");
    fseek(f, 0, SEEK_END);
    terminados aux;

    aux.id=idEmpleado;
    aux.fecha=fecha;
    aux.importeReal=importe;
    aux.idEmpleado=idEmpleado;

    fwrite(&aux, sizeof(terminados), 1, "TT.dat");

    fclose(TT.dat);
}
//Nombre del empleado – Importe total acumulado de los trabajos
//Id del trabajo	Fecha de entrega

void trabajosTerminadosDeEmpleados (listaEmp *empleados, listaTer *terminados){
   
   while (empleados != NULL){

    cout<<empleados->info.nombre<<"   "<<calcularImporte(terminados, empleados->info.id);
    cout<<buscar(terminados, empleados->info.id).id<<"    "<<buscar(terminados, empleados->info.id).fechaRealesEntrega;

    empleados=empleados->sig;
    }
}
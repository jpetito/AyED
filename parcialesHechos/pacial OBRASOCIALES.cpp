#include <iostream>
#include <stdio.h>

using namespace std;

struct hisopado{  //archivo desordenado y a veces aparecen archivos repetidos

   int dni; //es unico por paciente
   char apynombre[50];
   char domicilio [50];
   int fecha;
   int centro;
   char tipo [50];
   char obra [50];
   int cant;
   int fechaContacto;
   char resultado[50];
};

struct paciente{
    char apynombre[50];
    int dni;
    int fecha;
    char domicilio[50];
    paciente *sig; 
};

struct resultado{
    char tipo[50];
    paciente* datos;
    resultado *sig;
};

struct ObraSocial{
    char nombre[50];
    resultado vector[2];
    ObraSocial *sig;
};


/*Desarrolle la función cargarEstructura que recibe el archivo “hisopados.dat” ya abierto y debe retornar la estructura sugerida.*/
void cargarEstructura (FILE *archivohisopados){
hisopado lectura;

    while(fread(&lectura, sizeof(hisopado), 1, "hisopados.dat" )){

    }

}


/*Nombre obra social: Total hisopados para la obra social

Casos positivos: Total casos positivos para la obra social
⦁	Antígenos: Porcentaje de pruebas de antígenos sobre el total de casos positivos
⦁	DNI – Apellido y Nombre – Fecha de Nacimiento – Domicilio
⦁	PCR: Porcentaje de pruebas PCR sobre el total de casos positivos
⦁	DNI - Apellido y Nombre – Fecha de Nacimiento – Domicilio

Casos negativos: Total casos negativos para la obra social
⦁	Antígenos: Porcentaje de pruebas de antígenos sobre el total de casos negativos
⦁	DNI - Apellido y Nombre – Fecha de Nacimiento – Domicilio

⦁	PCR: Porcentaje de pruebas PCR sobre el total de casos negativos
⦁	DNI - Apellido y Nombre – Fecha de Nacimiento – Domicilio

*/
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

struct Usuarios{ //archivo ordenado por idUsuario "usuarios.dat"
    int idUsuario;
    char nombreUsuario[251];
    char mail [101];
};

struct infoVisualizacion{ //info del nodo de visualizaciones
    int idPelicula;
    char nombrePelicula[101];
    int idUsuario;
};

struct NodoCola{
    infoVisualizacion info;
    NodoCola *sig;
};

struct SubListaPelis{
    char nombrePeli[50];
    int idPeli;
    SubListaPelis* sig;
};

struct infoListaUsuarios{
    int idUsuario;
    char nombreUsuario[50];
    int cantPelisVistas; 
};

struct ListaUsuarios{
    infoListaUsuarios info;
    SubListaPelis *sublista=NULL;
    ListaUsuarios *sig;
};

void insertarOrdenado (ListaUsuarios &lista, Usuarios aux){
    ListaUsuarios *nuevo =new ListaUsuarios();
    Usuarios aux;

    nuevo->info.idUsuario = aux.idUsuario;
    strcpy(nuevo->info.nombreUsuario, aux.idUsuario);

    if (lista==NULL || lista.info.idUsuario > aux.idUsuario){
        nuevo->sig=lista;
        lista=nuevo;
    }else {
        ListaUsuarios *aux=lista;
        while (aux->sig!=NULL && aux->sig->info.idUsuario < aux->info.idUsuario){
            aux=aux->sig;
        }
        nuevo->sig = aux->sig;
        aux->sig = nuevo;
    } 
}

ListaUsuarios* obtenerListaUsuarios (FILE *archivoUsuarios){  //punto 2
    Usuarios usuarios;
    ListaUsuarios *lista=NULL;

    while (fread(&usuarios, sizeof(Usuarios), 1, archivoUsuarios)){
        insertarOrdenado (lista, usuarios); //lo ordena por id de usuario y lo inserta en la lista
    }
    return lista;
}

/* Se dispone de un procedimiento que usando la lista de visualizaciones completa los datos en la lista armada 
en el punto anterior. Para ello llama a la funcion cargarPelicula que ud. debe codificar y que debe cumplir con lo siguiente:
-Recibe 2 parametros: la lista de usuarios(ya cargada en el punto anterior) y una estructura infoVisualizacion
-Agregar la pelicula en la lista de peliculas vistas del usuario correspondiente
-Actualiza la cantidad de total de peliculas vistas del usuario correspondiente 
*/

void cargarPelicula (ListaUsuarios &lista, infoVisualizacion &listaVisualizacion){
    ListaUsuarios *aux=lista;
    infoVisualizacion *visual=listaVisualizacion;
    int contador=0;

    while (aux !=NULL){
        if(aux->info.idUsuario==visual->idUsuario){
            contador++; //cuenta la cantidad de pelis vistas por el usuario
            SubListaPelis *nuevo=new SubListaPelis();
            nuevo->idPeli = visual->idPelicula;
            strpy(nuevo->nombrePeli, visual->nombrePelicula);

            if (aux->sublista==NULL){
                nuevo->sig=aux->sublista;
                aux->sublista= nuevo;
            }else {SubListaPelis *auxx = aux->sublista;
                while (auxx->sig!=NULL && auxx->idPeli<aux->sublista->idPeli){
                    auxx=auxx->sig;
                }
                nuevo->sig=auxx->sig;
                auxx->sig=nuevo;
            }
            aux->info.cantPelisVistas=contador; //actualizo la cantidad de pelis vistas por el usuario
        }
        aux=aux->sig;
    }

}

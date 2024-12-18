#include <iostream>

using namespace std;

struct Usuarios{
	int idUsuario;
	char nombreUsuario[251];
	char mail[101];
}; //archivo ordenado por idUsuario 

struct infoVisualizacion{
	int idPelicula;
	char nombrePelicula[101];
	int idUsuario; 
};// cola de visualizaciones que contiene las peliculas que miran los usuarios. 

struct NodoCola{
	infoVisualizacion info;
	NodoCola* sgte;
}; 

struct peliculas{
	char nombrePelicula[101];
	int idPelicula; 
}; 

struct NodoB{
	peliculas info;
	NodoB* sgte;
};

struct datos{
	int idUsuario; 
	char nombreUsuario[251];
	int cantidad_peliculas; 
};
	
struct NodoA{ //lista usuarios
	datos info;
	NodoA* sgte;
	NodoB* listaB=NULL;
}; //nodo de la lista principal que va a apuntar a la sublista 

void insertarOrdenado(NodoA*& listaA, Usuarios raux);

int main(){
	
	return 0;
}

NodoA* obtenerListaUsuarios(FILE* archivoA){
	
	NodoA* listaA=NULL; //cree la lista donde voy a guardar todo 
	Usuarios raux; //auxiliar para leer el archivo, tiene que ser del mismo tipo que lo que tiene 
	while(fread(&raux,sizeof(Usuarios),1,archivoA)){
		insertarOrdenado(listaA,raux); //inserto ordenado a la lista de usuario el id y el nombre y nada mas 
	}
	return listaA; //no se como retornar bien esto ??????
}

/* Se dispone de un procedimiento que usando la lista de visualizaciones completa los datos en la lista armada 
en el punto anterior. Para ello llama a la funcion cargarPelicula que ud. debe codificar y que debe cumplir con lo siguiente:
-Recibe 2 parametros: la lista de usuarios(ya cargada en el punto anterior) y una estructura infoVisualizacion
-Agregar la pelicula en la lista de peliculas vistas del usuario correspondiente
-Actualiza la cantidad de total de peliculas vistas del usuario correspondiente 
*/

//1) TENGO UQE PASAR ESA COLA A UNA LISTA PRIMERO 

void cargarPelicula(NodoA* listaA, infoVisualizacion aux){
	
	while(listaA!=NULL){ //voy a recorrer la lista 
	
		if(listaA->info.idUsuario=aux.idUsuario){
			
			NodoB* nuevo=new NodoB();
	        strcpy(nuevo->info.nombrePelicula=aux.nombrePelicula); 
	        nuevo->info.idPelicula=aux.idPelicula;
	        
	        if(listaA->listaB==NULL){
	        	nuevo->sgte=listaA->listaB;
	        	listaA->listaB=nuevo;
			}
			else{
				NodoB* auxx=listaA->listaB;
				while(auxx->sgte!=NULL && auxx->sgte.info.idPelicula < aux.idPelicula){
					auxx=auxx->sgte;
				}
				nuevo->sgte=auxx->sgte;
				auxx->sgte=nuevo;
			}
	     listaA->info.cantidad_peliculas= listaA->info.cantidad_peliculas + 1;  
		}
		listaA=listaA->sgte;
	}
}


void insertarOrdenado(NodoA* listaA, Usuarios raux){
	
	NodoA* nuevo=new NodoA();
	nuevo->info.idUsuario=raux.idUsuario;
	strcpy(nuevo->info.nombreUsuario=raux.nombreUsuario);  //COMO ES CHAR CREO QUE TENDRIA QUE USAR STRCPY 
	nuevo->listaB=NULL; //??? por las dudas 
	
	if(listaA==NULL || listaA->info.idUsuario > raux.idUsuario){
		nuevo->sgte=listaA;
		listaA=nuevo;
	}
	else{
		NodoA* aux=listaA; 
		while(aux->sgte!=NULL && aux->sgte->info.idUsuario < raux.idUsuario){
			aux=aux->sgte;
		}
		nuevo->sgte=aux->sgte;
		aux->sgte=nuevo; 
	}
}

// o sino poner NodoB * listaB
/* 
desarrolle la funcion tienenGustosSimilares que recibe 2 parametros correspondientes a las sublistas de peliculas
de 2 usuarios diferentes y retorna true si tienen al menos 5 peliculas en comun, sino retorna false 
*/

bool tieneGustosSimilares(NodoB* usuario1, NodoB* usuario2){
	
	int contador=0;
	NodoB* aux1=usuario1; 
	NodoB* aux2=usuario2; 
	
	while(aux1!=NULL && aux2!=NULL ){
	
	if(aux1->info.idPelicula==aux2->info.idPelicula){
	   contador++; 
	   aux1=aux1->sgte;
	   aux2=aux2->sgte;
	}
	else if(aux1->info.idPelicula < aux2->info.idPelicula){
		aux1=aux1->sgte;
	}
	else{
		aux2=aux2->sgte;
	}
	}
	
	//una vez que ya pude recorrer la lista 
	if(contador >= 5){
		return true;
	}
	else{
		return false;
		
	}
}   


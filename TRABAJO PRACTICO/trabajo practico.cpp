#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

struct Carta{
    int numero;
    char tipo;
};

struct Mazo{
    Carta carta;
    bool robada=false;
};

struct Conjunto{
    Carta carta;
    Conjunto* sig;
};

struct Puntaje{
    int total=0;
    int cant_siete_oros=0;
    int cant_sietes=0;
    int cant_cartas=0;
    int cant_oros=0;
    int escobas=0;
};


void inicializar(Mazo mazo[]){
    for(int i=0; i<10;i++){
        mazo[i].carta.numero=i+1;
        mazo[i].carta.tipo='o';
        mazo[i+10].carta.numero=i+1;
        mazo[i+10].carta.tipo='e';
        mazo[i+20].carta.numero=i+1;
        mazo[i+20].carta.tipo='b';
        mazo[i+30].carta.numero=i+1;
        mazo[i+30].carta.tipo='c';
    }
}

 /* Carta repartir(Mazo mazo[]){
    while(true){
        int eleccion = rand()%(40);
        // cout<<"Encontro una carta ya robada"<<endl;
        if(!mazo[eleccion].robada){
            mazo[eleccion].robada=true;
            return mazo[eleccion].carta;
        }
    }
}  */ 

Carta repartir(Mazo mazo[]){
    while(true){
    	int limite_inferior= 0; 
		int limite_superior= 39;
        int eleccion = limite_inferior + rand() % (limite_superior +1 - limite_inferior); 
        // cout<<"Encontro una carta ya robada"<<endl;
        if(!mazo[eleccion].robada){
            mazo[eleccion].robada=true;
            return mazo[eleccion].carta;
        }
    } 
  } 
    
void push (Conjunto* &conjunto, Carta carta){
    Conjunto* nuevo = new Conjunto;
    nuevo->carta=carta;
    nuevo->sig=conjunto;
    conjunto=nuevo;
}

Carta pop(Conjunto*&mano, int pos){
    if(mano){
        if(mano->sig==NULL || pos <2){
            
            Carta carta= mano->carta;
            Conjunto* aux = mano;
            mano=mano->sig;
            delete(aux);
            return carta;
        } else {
            Conjunto* aux = mano;
                Conjunto* aux_ant = mano;
                while(aux->sig!=NULL && pos >= 2){
                    aux_ant=aux;
                    pos--;
                    aux=aux->sig;
                }
                Carta dato = aux->carta;
                aux_ant->sig=aux->sig;
                delete(aux);
                return dato;
        }
    }
}

void llenarMesa(Conjunto* &mesa, Mazo mazo[]){
    for(int i=0;i<4;i++){
        push(mesa,repartir(mazo));
    }
}

void llenarMano(Conjunto* &mesa, Mazo mazo[]){
    for(int i=0;i<3;i++){
        push(mesa,repartir(mazo));
    }
}

void reiniciar(Mazo mazo[]){
    for(int i=0;i<40;i++){
        mazo[i].robada=false;
    }
}

void llevarse2Cartas(Conjunto* & coleccion,Carta mano, Carta mesa ){
    push(coleccion,mesa);
    push(coleccion,mano);
}

void llevarse3Cartas(Conjunto* & coleccion, Carta mano, Carta mesa1, Carta mesa2){
    push(coleccion,mesa1);
    push(coleccion,mesa2);
    push(coleccion,mano);
}

void llevarse4Cartas(Conjunto* & coleccion, Carta mano, Carta mesa1, Carta mesa2, Carta mesa3){
    push(coleccion,mesa1);
    push(coleccion,mesa2);
    push(coleccion,mesa3);
    push(coleccion,mano);
}

void llevarse5Cartas(Conjunto* & coleccion, Carta mano, Carta mesa1, Carta mesa2, Carta mesa3,Carta mesa4){
    push(coleccion,mesa1);
    push(coleccion,mesa2);
    push(coleccion,mesa3);
    push(coleccion,mesa4);
    push(coleccion,mano);
}

void mostrarLista(Conjunto* lista){
    while(lista!=NULL){
        cout<<lista->carta.numero<<" "<<lista->carta.tipo<<" ";
        lista=lista->sig;
    }
}

void logica (Puntaje &puntaje, Conjunto* &coleccion, Conjunto* &mesa, Conjunto* &mano){
    int contador_mano=0,contador_mesa=0;
    Conjunto* conteo = mesa;
    while(conteo!=NULL){
            contador_mesa++;
            conteo=conteo->sig;
        }
        
    int* cartas_mesa = new int[contador_mesa];
    Conjunto* aux = mano;
    while(aux!=NULL){
        contador_mano++;
        aux=aux->sig;
    } 
    int* cartas_mano = new int [contador_mano];

    aux=mano;
    int i=0;
    while(aux!=NULL){
        cartas_mano[i]=aux->carta.numero;
        aux=aux->sig;
    }

    int acumulador=0;
    bool tiro = false;
    for(int i=0;i< contador_mano ;i++){
        if(contador_mesa==4){
            if(cartas_mano[i]+cartas_mesa[0]==15){
                llevarse2Cartas(coleccion,pop(mano,i),pop(mesa,1));
                if(mesa==NULL){
                    puntaje.escobas++;
                tiro=true;
                i=10; 
				}
            } else if (cartas_mano[i]+cartas_mesa[1]==15){
                llevarse2Cartas(coleccion,pop(mano,i),pop(mesa,2));
                if(mesa==NULL){
                    puntaje.escobas++;
                tiro=true;
                i=10; 
				}
            } else if (cartas_mano[i]+cartas_mesa[2]==15){
                llevarse2Cartas(coleccion,pop(mano,i),pop(mesa,3));
                if(mesa==NULL){
                    puntaje.escobas++;
                tiro=true;
                i=10; 
				}
            } else if (cartas_mano[i]+cartas_mesa[3]==15){
                llevarse2Cartas(coleccion,pop(mano,i),pop(mesa,4));   
                if(mesa==NULL){
                    puntaje.escobas++;
                tiro=true;
                i=10; 
				}
            } else if (cartas_mano[i]+cartas_mesa[0]+cartas_mesa[1]==15){
                llevarse3Cartas(coleccion,pop(mano,i),pop(mesa,1),pop(mesa,2));  
                if(mesa==NULL){
                    puntaje.escobas++;
                tiro=true;
                i=10; 
				}
            } else if (cartas_mano[i]+cartas_mesa[0]+cartas_mesa[2]==15){
                llevarse3Cartas(coleccion,pop(mano,i),pop(mesa,1),pop(mesa,3));
                if(mesa==NULL){
                    puntaje.escobas++;
                tiro=true;
                i=10; 
				}
            } else if (cartas_mano[i]+cartas_mesa[0]+cartas_mesa[3]==15){
                llevarse3Cartas(coleccion,pop(mano,i),pop(mesa,1),pop(mesa,4));
                if(mesa==NULL){
                    puntaje.escobas++;
                tiro=true;
                i=10; 
				}
            } else if (cartas_mano[i]+cartas_mesa[1]+cartas_mesa[2]==15){
                llevarse3Cartas(coleccion,pop(mano,i),pop(mesa,2),pop(mesa,3));
                if(mesa==NULL){
                    puntaje.escobas++;
                tiro=true;
                i=10; 
				}
            } else if (cartas_mano[i]+cartas_mesa[1]+cartas_mesa[3]==15){
                llevarse3Cartas(coleccion,pop(mano,i),pop(mesa,2),pop(mesa,4));
                if(mesa==NULL){
                    puntaje.escobas++;
                tiro=true;
                i=10; 
				}
            } else if (cartas_mano[i]+cartas_mesa[2]+cartas_mesa[3]==15){
                llevarse3Cartas(coleccion,pop(mano,i),pop(mesa,3),pop(mesa,4));
                if(mesa==NULL){
                    puntaje.escobas++;
                tiro=true;
                i=10; 
				}
            } else if (cartas_mano[i]+cartas_mesa[0]+cartas_mesa[1]+cartas_mesa[2]==15){
                llevarse4Cartas(coleccion,pop(mano,i),pop(mesa,1),pop(mesa,2),pop(mesa,3));
                if(mesa==NULL){
                    puntaje.escobas++;
                tiro=true;
                i=10; 
				}
            } else if (cartas_mano[i]+cartas_mesa[0]+cartas_mesa[1]+cartas_mesa[3]==15){
                llevarse4Cartas(coleccion,pop(mano,i),pop(mesa,1),pop(mesa,2),pop(mesa,4));
                if(mesa==NULL){
                    puntaje.escobas++;
                tiro=true;
                i=10; 
				}
            } else if (cartas_mano[i]+cartas_mesa[1]+cartas_mesa[2]+cartas_mesa[3]==15){
                llevarse4Cartas(coleccion,pop(mano,i),pop(mesa,2),pop(mesa,3),pop(mesa,4));
                if(mesa==NULL){
                    puntaje.escobas++;
                tiro=true;
                i=10; 
				}
            } else if (cartas_mano[i]+cartas_mesa[2]+cartas_mesa[3]+cartas_mesa[0]==15){
                llevarse4Cartas(coleccion,pop(mano,i),pop(mesa,3),pop(mesa,4),pop(mesa,1));
                if(mesa==NULL){
                    puntaje.escobas++;
                tiro=true;
                i=10; 
				}
            } else if (cartas_mano[i]+cartas_mano[1]+cartas_mano[2]+cartas_mano[3]+cartas_mano[0]);{
                llevarse5Cartas(coleccion,pop(mano,i),pop(mesa,1),pop(mesa,2),pop(mesa,3),pop(mesa,4)); 
                if(mesa==NULL){
                    puntaje.escobas++;
                tiro=true;
                i=10; 
				}
            }
		}
		else if(contador_mesa==3){
        	 if(cartas_mano[i]+cartas_mesa[0]==15){
                llevarse2Cartas(coleccion,pop(mano,i),pop(mesa,1));
                if(mesa==NULL){
                    puntaje.escobas++;
                tiro=true;
                i=10; 
				}
            } else if (cartas_mano[i]+cartas_mesa[1]==15){
                llevarse2Cartas(coleccion,pop(mano,i),pop(mesa,2));
                if(mesa==NULL){
                    puntaje.escobas++;
                tiro=true;
                i=10; 
				}
            } else if (cartas_mano[i]+cartas_mesa[2]==15){
                llevarse2Cartas(coleccion,pop(mano,i),pop(mesa,3));   
                if(mesa==NULL){
                    puntaje.escobas++;
                tiro=true;
                i=10; 
				}
            } else if (cartas_mano[i]+cartas_mesa[0]+cartas_mesa[1]==15){
                llevarse3Cartas(coleccion,pop(mano,i),pop(mesa,0),pop(mesa,1)); 
				if(mesa==NULL){
                    puntaje.escobas++;
                tiro=true;
                i=10; 
				}  
            } else if (cartas_mano[i]+cartas_mesa[0]+cartas_mesa[2]==15){
                llevarse3Cartas(coleccion,pop(mano,i),pop(mesa,0),pop(mesa,2));
                if(mesa==NULL){
                    puntaje.escobas++;
                tiro=true;
                i=10; 
				}
            } else if (cartas_mano[i]+cartas_mesa[1]+cartas_mesa[2]==15){
                llevarse3Cartas(coleccion,pop(mano,i),pop(mesa,1),pop(mesa,2));
                if(mesa==NULL){
                    puntaje.escobas++;
                tiro=true;
                i=10; 
				}
            } else if (cartas_mano[i]+cartas_mesa[0]+cartas_mesa[1]+cartas_mesa[2]==15){
                llevarse4Cartas(coleccion,pop(mano,i),pop(mesa,0),pop(mesa,1),pop(mesa,2)); 
                if(mesa==NULL){
                    puntaje.escobas++;
                tiro=true;
                i=10; 
				}
		}}else if (contador_mesa==2){
			 if(cartas_mano[i]+cartas_mesa[0]==15){
                llevarse2Cartas(coleccion,pop(mano,i),pop(mesa,1));
                if(mesa==NULL){
                    puntaje.escobas++;
                tiro=true;
                i=10; 
				}
            } else if (cartas_mano[i]+cartas_mesa[1]==15){
                llevarse2Cartas(coleccion,pop(mano,i),pop(mesa,2)); 
                if(mesa==NULL){
                    puntaje.escobas++;
                tiro=true;
                i=10; 
				}
            } else if (cartas_mano[i]+cartas_mesa[0]+cartas_mesa[1]==15){
                llevarse3Cartas(coleccion,pop(mano,i),pop(mesa,0),pop(mesa,1)); 
				if(mesa==NULL){
                    puntaje.escobas++;
                tiro=true;
                i=10; 
				}   
        }
        }else if(contador_mesa==1){
        	 if(cartas_mano[i]+cartas_mesa[0]==15){
              llevarse2Cartas(coleccion,pop(mano,i),pop(mesa,1)); 
              if(mesa==NULL){
                    puntaje.escobas++;
                tiro=true;
                i=10; 
				}
		}
        }
    }
    
    if(!tiro){
        push(mesa,pop(mano,0));
    }
}


bool fin(Mazo mazo[]){
    for(int i=0;i<40;i++){
        if(mazo[i].robada==false){
            return true;
        }
    }
    return false;
}


void contarPuntaje(Conjunto* &coleccion, Puntaje &puntaje){
    while(coleccion!=NULL){
        if(coleccion->carta.numero==7 && coleccion->carta.tipo=='o')
            puntaje.cant_siete_oros++;
        if(coleccion->carta.numero==7)
            puntaje.cant_sietes++;
        if(coleccion->carta.tipo=='o')
            puntaje.cant_oros++;
        puntaje.cant_cartas++;
        coleccion=coleccion->sig;
    }
    puntaje.total+=puntaje.cant_siete_oros+puntaje.escobas;
}



int main(){
    
    srand(time(NULL)); 
    
    Mazo mazo[40];
    
    int numJugadores=2;
    cout << "¿Cuantos jugadores van a jugar?" << endl;
    cin >> numJugadores;
    while(numJugadores>3 || numJugadores<2){
        cout<<"El juego es para 2 o 3 jugadores"<<endl;
        cin >> numJugadores;
    }
    inicializar(mazo);
    
    Conjunto* mesa = NULL;
    Conjunto* mano1 = NULL;
    Conjunto* mano2 = NULL;
    Conjunto* mano3 = NULL; 
    Conjunto* coleccion1 = NULL;
    Conjunto* coleccion2 = NULL;
    Conjunto* coleccion3 = NULL;

    Puntaje puntaje1;
    Puntaje puntaje2;
    Puntaje puntaje3;
    llenarMesa(mesa,mazo);
    if(numJugadores==2){
        bool turno = true;
        while(fin(mazo)){
            if(turno){
                if(mano1==NULL)
                    llenarMano(mano1,mazo);
                logica(puntaje1,coleccion1,mesa,mano1);
                turno=false;
            } else {
                if(mano2==NULL)
                    llenarMano(mano2,mazo);
                logica(puntaje2,coleccion2,mesa,mano2);
                turno=true;
            }
        }
        contarPuntaje(coleccion1,puntaje1);
        contarPuntaje(coleccion2, puntaje2);
        if(puntaje1.cant_cartas>puntaje2.cant_cartas)
            puntaje1.total++;
        else if (puntaje2.cant_cartas > puntaje1.cant_cartas){
            puntaje2.total++;
        }
        if(puntaje1.cant_oros > puntaje2.cant_oros){
            puntaje1.total++;
        } else if (puntaje2.cant_oros > puntaje1.cant_oros){
            puntaje2.total++;
        }
        if(puntaje1.cant_sietes > puntaje2.cant_sietes){
            puntaje1.total++;
        } else if (puntaje2.cant_sietes > puntaje1.cant_sietes){
            puntaje2.total++;
        }
        
        cout << "El puntaje total del Jugador 1: " << puntaje1.total << endl;
        cout << "El puntaje total del Jugador 2: " << puntaje2.total << endl; 
        
        if(puntaje1.total > puntaje2.total){
            cout<<"Gana el jugador 1"<<endl;
        } else if (puntaje2.total > puntaje1.total){
            cout<<"Gana el jugador 2"<<endl;
        } else {
            cout<<"Empate"<<endl;
        }
    } else {
        
		int turno =1;
        while(fin(mazo)){
            if(turno==1){
                if(mano1==NULL)
        	        llenarMano(mano1,mazo);
                logica(puntaje1,coleccion1,mesa,mano1);
                turno=2;
            } else if (turno==2){
                if(mano2==NULL)
                    llenarMano(mano2,mazo);
                logica(puntaje2,coleccion2,mesa,mano2);
                turno=3;
            } else {
                if(mano3==NULL)
        	        llenarMano(mano3,mazo);
                logica(puntaje3,coleccion3,mesa,mano3);
                turno=1;
            }
        }
        
        contarPuntaje(coleccion1,puntaje1);
        contarPuntaje(coleccion2, puntaje2);
        contarPuntaje(coleccion3, puntaje3);
        
        if(puntaje1.cant_cartas > puntaje2.cant_cartas && puntaje1.cant_cartas > puntaje3.cant_cartas){
            puntaje1.total++;
        } else if (puntaje2.cant_cartas>puntaje1.cant_cartas && puntaje2.cant_cartas > puntaje3.cant_cartas){
            puntaje2.total++;
        } else if (puntaje3.cant_cartas > puntaje1.cant_cartas && puntaje3.cant_cartas > puntaje2.cant_cartas){
            puntaje3.total++;
        }
        if(puntaje1.cant_oros > puntaje2.cant_oros && puntaje1.cant_oros > puntaje3.cant_oros){
            puntaje1.total++;
        } else if (puntaje2.cant_oros>puntaje1.cant_oros && puntaje2.cant_oros > puntaje3.cant_oros){
            puntaje2.total++;
        } else if (puntaje3.cant_oros > puntaje1.cant_oros && puntaje3.cant_oros > puntaje2.cant_oros){
            puntaje3.total++;
        }
         if(puntaje1.cant_sietes > puntaje2.cant_sietes && puntaje1.cant_sietes > puntaje3.cant_sietes){
            puntaje1.total++;
        } else if (puntaje2.cant_sietes>puntaje1.cant_sietes && puntaje2.cant_sietes > puntaje3.cant_sietes){
            puntaje2.total++;
        } else if (puntaje3.cant_sietes > puntaje1.cant_sietes && puntaje3.cant_sietes > puntaje2.cant_sietes){
            puntaje3.total++;
        }
        
        cout << "El puntaje total del Jugador 1: " << puntaje1.total << endl;
        cout << "El puntaje total del Jugador 2: " << puntaje2.total << endl; 
        cout << "El puntaje total del Jugador 3: " << puntaje3.total << endl;
        
        if(puntaje1.total > puntaje2.total && puntaje1.total > puntaje3.total){
            cout<<"Gana el jugador 1"<<endl;
        } else if (puntaje2.total > puntaje1.total && puntaje2.total > puntaje3.total){
            cout<<"Gana el jugador 2"<<endl;
        } else if(puntaje3.total > puntaje1.total && puntaje3.total > puntaje2.total){
            cout<<"Gana el jugador 3"<<endl;
        } else {
            cout<<"Empate"<<endl;
        }
    }
}
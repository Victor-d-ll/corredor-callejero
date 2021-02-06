#include "Enemigo2.h"
#include "Conio2.h"
#include <iostream>
#include <cstdlib>

//Constructor
Enemigo2::Enemigo2(int velocidad, int color) : Movil(velocidad, color) {	
	this->color = color;
	activado = false;	//Por defecto no está activado
	direccion = rand()%100;
}

//Destructor
Enemigo2::~Enemigo2() {}

/*Método que acelera el paso*/
void Enemigo2::acelerar(){
	velocidad +=5;
	paso=CLOCKS_PER_SEC/velocidad;	
}

//Retorna si el enemigo esta activo
bool Enemigo2::getEstaActivo(){
	return activado;
}

/*Método que se llama para activar al objeto*/
void Enemigo2::setActivar(){
	activado = true;
}
//Método update
void Enemigo2::update ( ) {
	
	if(tempo+paso<clock()) {				
		if(activado){
			borrar();	//Borra 				
			/*Va hacia abajo*/
			if(y<28) {//Sino toca el limite inferior				
				y+=1;	  //Se mueve una posicion
				/*Va hacia derecha o izquierda*/
				if(direccion%2==0) { //Se mueve a la izquierda			
					if(x>11) x -=1;					
				}else{		//Se mueve a la derecha
					//reiniciar();	
					if(x<70) x +=1;	
				}	
				dibujar();//Dibuja en la pantalla		
			}else{			
				reiniciar();				
			}				
			tempo=clock(); 				
		}
	}		
}

//Método para setear la posicion
void Enemigo2::setPosicion (int x, int y) {
	this->x = x;
	this->y = y;
}

//Método que debe ser llamado cuando hay colision
void Enemigo2::kill ( ) {
	activado = false;
	borrar();
	reiniciar();
}

/*Método que reinicia los parametros de inicio de la clase*/  
void Enemigo2::reiniciarParametros(){
	activado = false;
	direccion = rand()%100;
	velocidad = 10;
	paso=CLOCKS_PER_SEC/velocidad;	
}

//Método que borra el dibujo en pantalla totalmente
void Enemigo2::borrar(){
	for(int fila=0; fila<3; fila++){
		for(int columna=0; columna<5; columna++){	
			gotoxy(x+columna,y+fila);
			std::cout<<" ";	
		}
	}
}

//Método que reinicia las posiciones del auto
void Enemigo2::reiniciar(){	
	y=1;
	activado = false;	
	//color = (COLORES)rand()%15;	
	direccion = rand()%100;	
	borrar();
}

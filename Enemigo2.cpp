#include "Enemigo2.h"
#include "Conio2.h"
#include <iostream>
#include <cstdlib>

//Constructor
Enemigo2::Enemigo2(int velocidad, int color) : Vehiculo(velocidad, color) {
	
	this->color = color;
	activado = false;
	direccion = rand()%100;
}

//Constructor copia
Enemigo2::Enemigo2(const Enemigo2 &arg) {
	
}
//Destructor
Enemigo2::~Enemigo2() {
	
}

void Enemigo2::acelerar(){
	velocidad +=1;
	paso=CLOCKS_PER_SEC/velocidad;	
}

//Retorna si el enemigo esta activo
bool Enemigo2::getEstaActivo(){
	return activado;
}

void Enemigo2::setActivar(){
	activado = true;
}
//Método update
void Enemigo2::update ( ) {
	if(!activado) {
		return; //Si no esta activado retorna
	}else{
		if(tempo+paso<clock()) {
			borrar();	//Borra 
			
			/*Va hacia abajo*/
			if(y!=28) {//Sino toca el limite inferior				
				y+=1;	  //Se mueve una posicion
			}else{			
				reiniciar();				
			}
			
			/*Va hacia derecha o izquierda*/
			if(direccion%2==0) { //Se mueve a la izquierda			
				if(x!=11) {				
					x -=1;	
				}
			}else{		//Se mueve a la derecha
				//reiniciar();	
				if(x!=70) x +=1;	
			}	
			
			/*Si esta activado dibuja en pantalla y mide el tiempo*/
			if(activado) {
				dibujar();//Dibuja en la pantalla		
				tempo=clock(); 
			}			
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

/*TODO ESTE METODO DEBE IR A LA CLASE BASE*/
//Metodo para dibujar
void Enemigo2::dibujar(){
	/*Dibuja*/
	textcolor(color);
	for(int fila=0; fila<3; fila++){
		for(int columna=0; columna<5; columna++){	
			gotoxy(x+columna,y+fila);
			std::cout<<dibujoAuto[fila][columna];	
		}
	}
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
	color = (COLORES)rand()%15;	
	direccion = rand()%100;	
	borrar();
}

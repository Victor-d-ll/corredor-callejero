#include "Enemigo1.h"
#include "conio2.h"
#include <iostream>
//Constructor
Enemigo1::Enemigo1(int velocidad, int color):Vehiculo(velocidad, color) {
	activado = false;
}

//Constructor copia
Enemigo1::Enemigo1(const Enemigo1 &arg) {}

Enemigo1::~Enemigo1() {}

//Método update del enemigo
void Enemigo1::update ( ) {
	if(!activado) return; //Si no esta activado retorna
	if(tempo+paso<clock()){
		
		if(y!=28) {
			borrar(); //Borra la pantalla
			y+=1;	  //Se mueve una posicion
		}else{		
			reiniciar();			
		}
		
		if(activado) {
			dibujar();//Dibuja en la pantalla	
			tempo=clock(); 
		}		
	}
}

void Enemigo1::acelerar(){
	velocidad +=1;
	paso=CLOCKS_PER_SEC/velocidad;	
}
//Retorna si el enemigo esta activo
bool Enemigo1::getEstaActivo(){
	return activado;
}

void Enemigo1::setPosicion (int x, int y) {
	this->x = x;
	this->y = y;
}

/*Método que dibuja al auto en pantalla*/
void Enemigo1::dibujar(){
	/*Dibuja*/
	textcolor(color);
	for(int fila=0; fila<3; fila++){
		for(int columna=0; columna<5; columna++){	
			gotoxy(x+columna,y+fila);
			std::cout<<dibujoAuto[fila][columna];	
		}
	}
}

void Enemigo1::setActivar(){
	activado = true;
}

//Aumenta la velocidad 
void Enemigo1::aumentarVelocidad(){
	velocidad+=1;
}

//Borra la pantalla
void Enemigo1::borrar(){
	gotoxy(x,y);
	std::cout<<"     ";
}

//Método que reinicia al enemigo
void Enemigo1::reiniciar(){
	activado = false;
	//Bucle que limpia la pantalla
	for(int fila=0; fila<3; fila++){
		for(int columna=0; columna<5; columna++){	
			gotoxy(x+columna,y+fila);
			std::cout<<" ";	
		}
	}
	y=1;	//Se vuelve a posicionar en y	
	/*TODO CORREGIR POSICIONAMIENTO*/
	x=rand()%60+11;	//Se elige una posición al azar en x (dentro del rango)
}

//Método pñublico que se llama al existir una colision
void Enemigo1::kill(){
	reiniciar();
}

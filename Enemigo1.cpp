#include "Enemigo1.h"
#include "conio2.h"
#include <iostream>
//Constructor
Enemigo1::Enemigo1(int velocidad, int color):Vehiculo(velocidad, color) {
	activado = false; //Por defecto no est� activado
}

Enemigo1::~Enemigo1() {}

//M�todo update del enemigo
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

/*M�todo que acelera el paso*/
void Enemigo1::acelerar(){
	/*TODO VERIFICAR SI ES MULTIPLO DE 20 y AUMENTAR VELOCIDAD*/
	velocidad +=1;
	paso=CLOCKS_PER_SEC/velocidad;	
}
//Retorna si el enemigo esta activo
bool Enemigo1::getEstaActivo(){
	return activado;
}

/*M�todo que setea la posicion en x e y del objeto*/
void Enemigo1::setPosicion (int x, int y) {
	this->x = x;
	this->y = y;
}

/*M�todo que se llama para reiniciar parametros*/
void Enemigo1::reiniciarParametros(){
	activado = false;
	velocidad = 10;
	paso=CLOCKS_PER_SEC/velocidad;	
}
	
//Activa una flag que permite activar el dibujado del enemigo
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

//M�todo que reinicia al enemigo
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
	x=rand()%60+11;	//Se elige una posici�n al azar en x (dentro del rango)
}

//M�todo p�ublico que se llama al existir una colision
void Enemigo1::kill(){
	reiniciar();
}

#include "AutoEnemigo.h"
#include <cstdlib>

//Este constructor le pasa los argumentos para inicializar la clase base Auto
AutoEnemigo::AutoEnemigo(): Auto(15,1) {
	direccion = rand() % 10; //Este auto se mueve aleatoriamente
}

AutoEnemigo::~AutoEnemigo() {
	
}

//Update de la clase AutoEnemigo
//limpiar pantalla, mueve el auto y dibuja segun el tiempo 
void AutoEnemigo::update ( ) {
	if(tempo+paso<clock()){	
		limpiar();
		moverse();
		dibujar();	
		tempo = clock();		
	}		
}

//Funcion que ejecuta el movimiento diagonal del auto
void AutoEnemigo::moverse(){	
	if(y==30-alto) {	//Si llega al limite inferior
		reiniciar();	//Reinicia
		return;			//retorna
	}
	y++;				//Se mueve en y hacia abajo
	if(direccion % 2 == 0) { //Se mueve hacia la izquierda
		if(x==limite_derecho-ancho) return;		//Si tocó el limite retorna
		x++;
	
	}else{ //Hacia la derecha
		if(x==limite_izquierdo) return;	//Si tocó el limite retorna
		x--;
	}	
}


void AutoEnemigo::reiniciar(){ 
	direccion = rand() % 10;
	x = rand() % 40 + 11;
	y = 1;
}

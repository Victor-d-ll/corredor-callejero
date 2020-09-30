#include "AutoJugador.h"

//Constructor
AutoJugador::AutoJugador() : Auto(60,1) {
	
}

//Destructor
AutoJugador::~AutoJugador() {
	
}

//Funcion que chequea el tiempo y actualiza si corresponde
void AutoJugador::update(){	
	if(tempo+paso<clock()){		
		dibujar();	
		tempo = clock();		
	}		
}

//Metodo que mueve el auto en x
void AutoJugador::moverse(char direccion){		
	if (direccion == 'D') {		
		if(x==limite_derecho-ancho) return; //Si ya esta en el borde derecho retorna		
		limpiar(); //Si se mueve a la derecha limpia un espacio hacia izquierda
		x++;		
	}else{		
		if(x==limite_izquierdo) return; //Si ya esta en el borde izquierdo retorna
		limpiar(); //Si se mueve a la derecha limpia un espacio hacia derecha
		x--;		
	}	
}


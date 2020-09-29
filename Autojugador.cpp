#include "Autojugador.h"

//Constructor
Autojugador::Autojugador() : Auto(60,1) {
	
}

//Destructor
Autojugador::~Autojugador() {
	
}

//Funcion que chequea el tiempo y actualiza si corresponde
void Autojugador::update(){	
	if(tempo+paso<clock()){		
		dibujar();	
		tempo = clock();		
	}		
}

//Metodo que mueve el auto en x
void Autojugador::moverse(char direccion){		
	if (direccion == 'D') {		
		if(x==115) return; //Si ya esta en el borde derecho retorna		
		limpiar(); //Si se mueve a la derecha limpia un espacio hacia izquierda
		x++;		
	}else{		
		if(x==limite_izquierdo) return; //Si ya esta en el borde izquierdo retorna
		limpiar(); //Si se mueve a la derecha limpia un espacio hacia derecha
		x--;		
	}	
}



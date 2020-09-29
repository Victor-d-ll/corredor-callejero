#include "Limites.h"
#include <conio2.h>
#include <iostream>

Limites::Limites() {
}

//Constructor recibe ancho y alto para crear una pared lateral
Limites::Limites(int alto, int ancho, int x) {
	this->alto = alto;
	this->ancho = ancho;
	this->x = x;
	y = 1;
}
/*
void Limites::update() {	
	dibujar();	
}*/

//Funcion que dibuja las paredes
void Limites::dibujar(){
	textcolor(BROWN);
	for(int i=0; i<alto; i++){
		for(int j=0; j<ancho; j++){
			gotoxy(x+j,y+i);
			std::cout<<char(219);			
		}			
	}
}

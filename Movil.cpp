#include "Movil.h"

#include <iostream>
#include <conio2.h>
//Destructor virtual
Movil::~Movil(){};

//Constructor vacío
Movil::Movil(){};

//Constructor 
Movil::Movil(int velocidad, int color) {
	
	/*Dibujo del auto*/
	dibujo [0][0] = char(219);
	dibujo [0][1] = char(254);
	dibujo [0][2] = char(254);
	dibujo [0][3] = char(254);
	dibujo [0][4] = char(219);
	
	dibujo [1][0] = ' ';
	dibujo [1][1] = ' ';
	dibujo [1][2] = char(219);
	dibujo [1][3] = ' ';
	dibujo [1][4] = ' ';
	
	dibujo [2][0] = char(219);
	dibujo [2][1] = char(254);
	dibujo [2][2] = char(254);
	dibujo [2][3] = char(254);
	dibujo [2][4] = char(219);
	
	/*Variables*/
	this->velocidad = velocidad;	
	this->color = color;
	tempo=clock(); 
	paso=CLOCKS_PER_SEC/velocidad;	
	y = 1;
	x = 15;
}

//Método que retorna la posicion x del vehículo
int Movil::getPosicionX(){
	return x;
}
//Método que retorna la posicion y del vehículo
int Movil::getPosicionY(){
	return y;
}

/*Método que dibuja al auto en pantalla*/
void Movil::dibujar(){
	/*Dibuja*/
	textcolor(color);
	for(int fila=0; fila<3; fila++){
		for(int columna=0; columna<5; columna++){	
			gotoxy(x+columna,y+fila);
			std::cout<<dibujo[fila][columna];	
		}
	}
}


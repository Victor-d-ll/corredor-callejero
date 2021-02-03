#include "Vehiculo.h"

#include <iostream>
//Destructor virtual
Vehiculo::~Vehiculo(){};

//Constructor vacío
Vehiculo::Vehiculo(){};

//Constructor 
Vehiculo::Vehiculo(int velocidad, int color) {
	
	/*Dibujo del auto*/
	dibujoAuto [0][0] = char(219);
	dibujoAuto [0][1] = char(254);
	dibujoAuto [0][2] = char(254);
	dibujoAuto [0][3] = char(254);
	dibujoAuto [0][4] = char(219);
	
	dibujoAuto [1][0] = ' ';
	dibujoAuto [1][1] = ' ';
	dibujoAuto [1][2] = char(219);
	dibujoAuto [1][3] = ' ';
	dibujoAuto [1][4] = ' ';
	
	dibujoAuto [2][0] = char(219);
	dibujoAuto [2][1] = char(254);
	dibujoAuto [2][2] = char(254);
	dibujoAuto [2][3] = char(254);
	dibujoAuto [2][4] = char(219);
	
	/*Variables*/
	this->velocidad = velocidad;	
	this->color = color;
	tempo=clock(); 
	paso=CLOCKS_PER_SEC/velocidad;	
	y = 1;
	x = 15;
}

//Método que retorna la posicion x del vehículo
int Vehiculo::getPosicionX(){
	return x;
}
//Método que retorna la posicion y del vehículo
int Vehiculo::getPosicionY(){
	return y;
}






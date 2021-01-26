#include "Player.h"
#include <iostream>
#include <conio2.h> //gotoxy, textcolor, etc

//Aqui debe inicializarse el constructor de la clase base
Player::Player() {
	
}

//El siguiente constructor esta mal 
Player::Player(int velocidad, int color):Vehiculo(velocidad, color) {	
}


void Player::update () {	

	for(int fila=0; fila<3; fila++){
		for(int columna=0; columna<5; columna++){	
			gotoxy(x+columna,y+fila);
			std::cout<<dibujoAuto[fila][columna];	
		}
	}
}

void Player::setPosicion (int x, int y) {
	this->x = x;
	this->y = y;
}


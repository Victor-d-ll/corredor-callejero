#include "Auto.h"
#include <conio2.h>
#include <iostream>

Auto::Auto(int velocidad, int color) {
	
	this->velocidad = velocidad;
	paso=CLOCKS_PER_SEC/velocidad;
	tempo=clock(); 
	
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
	
	x = 1;
	y = 1;	
	
	this->color = color;
}

//Metodo que dibuja el auto en pantalla
void Auto::dibujar(){
	int posx;
	int posy;
	posx = x;	
	posy = y;
	textbackground(GREEN);
	textcolor(color);
	for (int i=0; i<3; i++){	
		for (int j=0; j<5; j++){
			
			gotoxy(posx,posy);
			std::cout<<dibujoAuto [i][j];			
			posx++;
		}	
		posx = x;
		posy++;
	}	
}

//Metodo que mueve el auto en x
void Auto::moverse(char direccion){
	if (direccion == 'D') x++;
	else x--;
}

//Metodo que actualiza al objeto segun el tiempo transcurrido
void Auto::update(){	
	if(tempo+paso<clock()){
		clrscr();
		dibujar();	
		tempo = clock();
	}
	
}

//Metodo que pone al auto en una posicion x e y
void Auto::setPosition(int x, int y){
	this->x = x;
	this->y = y;
}

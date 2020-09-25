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
	
	textbackground(GREEN);
	textcolor(color);   
	for (int i=0; i<3; i++){	
		for (int j=0; j<5; j++){			
			gotoxy(x+j,y+i);
			std::cout<<dibujoAuto [i][j];	
		}			
	}	
}

//Metodo que limpia la pantalla para que no se dibujen mal los caracteres
//De esta manera evito usar clrscr debido a que parpadea demasiado
void Auto::limpiar(){	
	gotoxy(x-1,y);
	std::cout<<' ';	
	gotoxy(x-1,y+2);	
	std::cout<<' ';
	gotoxy(x+5,y);
	std::cout<<' ';	
	gotoxy(x+5,y+2);	
	std::cout<<' ';	
}

//Metodo que mueve el auto en x
void Auto::moverse(char direccion){	
	if (direccion == 'D') {
		if(x==115) return; //Si ya esta en el borde derecho retorna
		x++;
	}else{
		if(x==2) return; //Si ya esta en el borde izquierdo retorna
		x--;
	}
}

//Metodo que actualiza al objeto segun el tiempo transcurrido
void Auto::update(){	
	if(tempo+paso<clock()){
		limpiar();
		dibujar();	
		tempo = clock();		
	}		
}

//Metodo que recibe int x e int y que indican la posición del auto 
void Auto::setPosition(int x, int y){
	this->x = x;
	this->y = y;
}

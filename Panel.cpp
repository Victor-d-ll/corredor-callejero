#include "Panel.h"
#include <conio2.h>
#include <iostream>

Panel::Panel() {
	puntaje = -10;	
	autosEsquivados = -1;
	tempo=clock(); 
	paso=CLOCKS_PER_SEC/10;		//Se actualiza 10 veces por segundo
}

//Update del panel
void Panel::update(){		
	if(tempo+paso<clock()){
		mostrarPuntaje();	//Muestra en pantalla el puntaje
		tempo=clock(); 
	}
}

//Método que muestra en pantalla el puntaje
void Panel::mostrarPuntaje(){
	textbackground(WHITE);
	textcolor(RED);
	gotoxy(80, 10);
	std::cout<<"              ";
	gotoxy(80, 10);
	std::cout<<"PUNTOS: "<<puntaje;
	gotoxy(80, 11);
	std::cout<<"Autos Esquivados: "<<autosEsquivados;
	textbackground(GREEN);
}

/*Método que aumenta el puntaje del jugador*/
void Panel::aumentarPuntaje(){
	puntaje+=10;
	autosEsquivados++;
}

/*Método que resta el puntaje del jugador cuando choca*/
void Panel::restarPuntaje(){
	if(puntaje - 30 < 0) puntaje = 0;
	else puntaje-=30;	
}

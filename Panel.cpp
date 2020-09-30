#include "Panel.h"
#include <conio2.h>
#include <iostream>

Panel::Panel() {
	puntaje = -1;
	puntajeActual = 0;
	autosEsquivados = 0;
}


//Update del panel
void Panel::update(){	
	if(puntaje != puntajeActual) {	//Solo se actualiza cuando cambia el puntaje
		puntaje = puntajeActual;	
		mostrarPuntaje();	//Muestra en pantalla el puntaje
	}
}

//Funcion que muestra en pantalla el puntaje
void Panel::mostrarPuntaje(){
	textbackground(WHITE);
	textcolor(RED);
	gotoxy(80, 10);
	std::cout<<"PUNTOS: "<<puntaje;
	textbackground(GREEN);
}

void Panel::setPuntaje(int puntaje){
	puntajeActual = puntaje;
}

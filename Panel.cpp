#include "Panel.h"
#include <conio2.h>
#include <iostream>

Panel::Panel() {
	puntaje = -10;	
	autosEsquivados = -1;
	tempo=clock(); 
	paso=CLOCKS_PER_SEC/20;		//Se actualiza 10 veces por segundo
	vidas = 3;	
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
	for(int i=0; i<22;i++){
		for(int j=0; j<5; j++)
		{
			textbackground(BLUE);
			gotoxy(87+i, 9+j);
			std::cout<<" ";
		}		
	}	
	textcolor(WHITE);
	gotoxy(88,10);
	std::cout<<"              ";
	gotoxy(88, 10);
	std::cout<<"PUNTOS: "<<puntaje;
	gotoxy(88, 11);
	std::cout<<"AUTOS ESQUIVADOS: "<<autosEsquivados;
	gotoxy(88, 12);
	std::cout<<"VIDAS: "<<vidas;	
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
	vidas -=1;
}

//Devuelve el puntaje del jugador
int Panel::getPuntaje(){
	return puntaje;
}

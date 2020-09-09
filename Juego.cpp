#include "Juego.h"
#include <conio2.h>


Juego::Juego() {	
	autoJugador = new Auto(60,1);
	autoJugador->setPosition(10,27);
}

void Juego::start() {
	limpiar();
	while(true){
		capturaEvento();
		update();		
	}	
}

void Juego::limpiar(){
	textbackground(GREEN);
	clrscr ();	
}

void Juego::capturaEvento(){
	if(kbhit()){
		int tecla = getch();		
		if(tecla==77) autoJugador->moverse('D');
		if(tecla==75) autoJugador->moverse('I');
	}
}

void Juego::update(){
	autoJugador->update();
}

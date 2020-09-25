#include "Juego.h"
#include <conio2.h>
#include <windows.h> 

Juego::Juego() {	
	autoJugador = new Auto(60,1);
	autoEnemigo = new Auto(60,1);
	
	autoJugador->setPosition(10,27);
	autoEnemigo->setPosition(15, 8);
	paredes = new Limites(30, 3,1);
	hidecursor();
}

void Juego::start() {
	limpiar();
	while(true){		
		capturaEvento();
		update();		
	}	
}

/*Este metodo esta a ser visto*/
/*TODO*/
void Juego::hidecursor()
{
	return;
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

void Juego::limpiar(){
	textbackground(GREEN);
	clrscr();	
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
	autoEnemigo->update();
	paredes->update();
}

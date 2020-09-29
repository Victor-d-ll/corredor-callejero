#include "Juego.h"
#include <conio2.h>
#include <windows.h> 

Juego::Juego() {	
	autoJugador = new Autojugador();
	autoJugador->setPosition(20,27);
	autoEnemigo = new AutoEnemigo();
	autoEnemigo->setPosition(15, 8);
	//paredes = new Limites(30, 10,1);
	paredes[0] = new Limites(30,10,1);
	paredes[1] = new Limites(30,45,75);
	hidecursor();
}

Juego::~Juego() {	
	delete autoJugador;
	delete autoEnemigo;
	for (int i = 0; i < 6; i++)
	{
		delete paredes[i];
	}	
}

void Juego::start() {
	limpiar();
	paredes[0]->update();
	paredes[1]->update();
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
}

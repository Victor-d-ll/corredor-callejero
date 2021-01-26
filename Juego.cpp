#include "Juego.h"
#include <conio2.h> //gotoxy, textcolor, etc
#include <windows.h> 
#include "Player.h"

Juego::Juego() {	
	
	paredes[0] = new Limites(30,10,1);
	paredes[1] = new Limites(30,45,75);
	panel = new Panel();
	player = new Player(10,1);
	player->setPosicion(35,28);
	hidecursor();
}

Juego::~Juego() {	
	
	delete panel;
	for (int i = 0; i < 2; i++)
	{
		delete paredes[i];
	}	
}

void Juego::start() {
	limpiar();
	paredes[0]->dibujar();
	paredes[1]->dibujar();
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
	
}

void Juego::update(){
	
	chequearColisiones();	//Función que chequea si los autos chocaron		
	panel->update();
	player->update();
}

//Detecta colisiones
//Distancia es igual a la absoluta de x2-x1 + absoluta de y2-y1
void Juego::chequearColisiones(){

}




#include "Juego.h"
#include <conio2.h>
#include <windows.h> 

Juego::Juego() {	
	autoJugador = new AutoJugador();
	autoJugador->setPosition(20,27);
	autoEnemigo = new AutoEnemigo();
	autoEnemigo->setPosition(15, 8);
	//paredes = new Limites(30, 10,1);
	paredes[0] = new Limites(30,10,1);
	paredes[1] = new Limites(30,45,75);
	panel = new Panel();
	hidecursor();
}

Juego::~Juego() {	
	delete autoJugador;
	delete autoEnemigo;
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
	if(kbhit()){
		int tecla = getch();		
		if(tecla==77) autoJugador->moverse('D');
		if(tecla==75) autoJugador->moverse('I');
	}
}

void Juego::update(){
	autoJugador->update();
	autoEnemigo->update();	
	chequearColisiones();	//Función que chequea si los autos chocaron	
	panel->setPuntaje(autoEnemigo->getPasadas()); //Le envia el puntaje al panel
	panel->update();
}

//Detecta colisiones
//Distancia es igual a la absoluta de x2-x1 + absoluta de y2-y1
void Juego::chequearColisiones(){
	int distancia = abs(autoJugador->getPositionX() - autoEnemigo->getPositionX())
		+ abs(autoJugador->getPositionY() - autoEnemigo->getPositionY());
	if (distancia >= 0 && distancia <=5){	
		//Congela la ejecución por un segundo
		//Reinicia al objeto enemigo
	
	}
}




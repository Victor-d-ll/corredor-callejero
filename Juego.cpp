#include "Juego.h"
#include "Player.h"
#include "Enemigo1.h"
#include "Enemigo2.h"
#include <conio2.h> //gotoxy, textcolor, etc
#include <windows.h> //En gnu/linux no funcionará

/*TODO poner enemigos en arreglos*/
Juego::Juego() {		

	paredes[0] = new Limites(30,10,1);
	paredes[1] = new Limites(30,45,75);
	panel = new Panel();
	player = new Player(10,1);
	player->setPosicion(35,28);
	enemigo1 = new Enemigo1(10, 5);
	enemigo1->setPosicion(35,1);
	enemigo2 = new Enemigo2(10, rand()%15);
	enemigo2->setPosicion(35,1);
	activarEnemigo(false);
	hidecursor();
}

Juego::~Juego() {		
	delete panel;
	for (int i = 0; i < 2; i++)	{
		delete paredes[i];
	}	
	delete player;
	delete enemigo1;
	delete enemigo2;
}

void Juego::start() {
	mostrarIntro();
	limpiar();
	for (int i=0;i<2;i++){
		paredes[i]->dibujar();
	}	
	while(player->getEstaActivo()){		//Mientras que el jugador tenga vidas
		update();			
	}	
}

void Juego::mostrarIntro(){
	std::string textos[] = {
		"**************",
		"Street Racer X",
		"**************",
		"Instrucciones",
		"-------------",
		"Puede mover su auto hacia la izquierda o hacia la derecha",
		"Usando las flechas de direccion", 
		"Reglas del juego", 
		"-----------------",
		"1 - Evadir los autos que vienen hacia nosotros",
		"2 - Sumar la mayor cantidad de puntos (evadiendo) - 10 ptos",
		"3 - Si colisiona con el enemigo se perderan 30 ptos",
		"4 - Si se pierden todas las vidas se pierde el juego",
		"PRESIONE UNA TECLA PARA INICIAR EL JUEGO"};	
	
	mostrarTextos(0,3,3, textos);
	mostrarTextos(3,7,7, textos);
	mostrarTextos(7,13,12, textos);	
	
	while(!kbhit()){		
		mostrarTextos(13,14,19, textos);			
		Sleep(500);
	}	
}
/* inicio es la posicion inicial del arreglo
   final la posicion final del arreglo
   posicion_y la posicion para dibujar en y
   textos es el puntero del arreglo de textos */
void Juego::mostrarTextos(int inicio, int final, int posicion_y, std::string* textos){	
	textcolor(rand()%15+1);
	for(int i=inicio; i< final; i++){
		int x= (120/2) - (textos[i].length()/2); //Centramos el texto
		gotoxy(x,++posicion_y);		
		std::cout<<textos[i];
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

//Método que limpia el background
void Juego::limpiar(){
	textbackground(GREEN);
	clrscr();	
}

//Aquí van los updates del juego
void Juego::update(){	
	pista.update();
	panel->update();
	player->update();
	/*TODO METER EN ARREGLO*/
	enemigo1->update();
	enemigo2->update();	
	chequearColisiones(enemigo2);	//Función que chequea si los autos chocaron		
	chequearColisiones(enemigo1);	//Función que chequea si los autos chocaron	
	activarEnemigo(false);
}

//Detecta colisiones
//Distancia es igual a la absoluta de x2-x1 + absoluta de y2-y1
void Juego::chequearColisiones(Vehiculo *enemigo){
	if(player->getPosicionX() < enemigo->getPosicionX() + 5 &&
	   player->getPosicionX() + 5 > enemigo->getPosicionX() &&
	   player->getPosicionY() < enemigo->getPosicionY() + 3 &&
	   player->getPosicionY() + 3 > enemigo->getPosicionY()){
		Sleep(1300);
		enemigo->kill();
		/*AQUI METODO PARA MODIFICAR EL PUNTAJE CUANDO SE MUERE*/
		activarEnemigo(true);
		restarPuntaje();
	}									 
}

//Método que verifica si el enemigo esta activado o no
void Juego::activarEnemigo(bool hayColision){	
	//Si ninguno de los dos enemigos esta activado, se activa alguno al azar
	if(!enemigo1->getEstaActivo() && !enemigo2->getEstaActivo()){
		enemigo1 ->acelerar();
		enemigo2->acelerar();
		if(!hayColision) {
			aumentarPuntaje();
		}
		int opcion = rand()%100;		
		if(opcion%2==0){
			enemigo1->setActivar();
		}else{
			enemigo2->setActivar();
		}
	}	
}

/*Método que aumenta el puntaje en el panel*/
void Juego::aumentarPuntaje(){
	panel->aumentarPuntaje();
}

/*Método que resta el puntaje en el panel*/
void Juego::restarPuntaje(){
	panel->restarPuntaje();
}

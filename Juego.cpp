#include "Juego.h"
#include "Player.h"
#include "Enemigo1.h"
#include "Enemigo2.h"
#include "Bloque.h"
#include <conio2.h> //gotoxy, textcolor, etc
#include <windows.h> //En gnu/linux no funcionará

/*Constructor*/
Juego::Juego() {	
	
	paredes[0] = new Limites(30,10,1);
	paredes[1] = new Limites(30,45,75);
	panel = new Panel();
	player = new Player(10,1);
	player->setPosicion(35,28);
	enemigo1 = new Enemigo1(10, 14);	
	enemigo1->setPosicion(35,1);
	bloque = new Bloque(10, 15);
	enemigo2 = new Enemigo2(10, 11); //CAMBIE EL ROJO POR EL CYAN PARA MEJOR VISUALIZACIÖN
	enemigo2->setPosicion(35,1);
	pista = new Pista();
	activarEnemigo(false);	
	valorViejo = 0;
}

/*Destructor*/
Juego::~Juego() {	
	for (int i = 0; i < 2; i++)	{
		delete paredes[i];
	}	
	delete panel;	
	delete player;
	delete enemigo1;
	delete enemigo2;
	delete bloque;
	delete pista;
}

/*Método que da inicio al juego*/
void Juego::start() {
	mostrarIntro(); //Muestra intro
	limpiar();		//Limpia pantalla
	dibujarParedes();	//Dibuja las "paredes
	buclePrincipal();			//Se actualiza (esto es un bucle)
	mostrarOutro();	//Muestra mensaje de salida
}


void Juego::dibujarParedes(){
	for (int i=0;i<2;i++){
		paredes[i]->dibujar();
	}	
}
/*Muestra un texto de despedida con opciones*/
void Juego::mostrarOutro(){
	std::string textos[] = {	/*Defino los textos a mostrar*/
		"******************",
			"Gracias por jugar!",
			"******************",
			"Su puntaje ha sido de",
			std::to_string(panel->getPuntaje()) + " y evito " +
			std::to_string(panel->getEvitados()) + " autos"	,
			"Presione",
			"S para salir",
			"R para reiniciar el juego"			
	};	
	/*Seleciono color de fondo y borro pantalla*/
	textbackground(BLACK);
	clrscr();	
	/*Muestro textos*/
	mostrarTextos(0,3,3, textos);
	mostrarTextos(3,5,6, textos);	
	
	//Esto irá en color para remarcar que hay que elegir opciones
	/*El usuario debe elegir continuar o no*/
	int opcion;
	while(true)
	{
		mostrarTextos(5,8,9, textos);
		if(kbhit()){
			opcion = getch();		
			if(opcion==115||opcion==114) break; //Si toca S o Q (115) sale			
		}
		Sleep(500);
	}	
	reiniciarJuego(opcion); //Se llama al método que reinicia el juego
}

//Método que reinicia el juego, recibe un int 115 para si o 113 para no
void Juego::reiniciarJuego(int opcion){
	if(opcion==114) {
		clrscr();
		player->reiniciarParametros(); //Reactiva al jugador
		
		enemigo1->reiniciarParametros();
		enemigo2->reiniciarParametros();
		bloque->reiniciarParametros();
		panel->reiniciarPanel();//Se reinicia el panel de puntos
		valorViejo = 0;
		start(); //Vuelve a iniciar el bucle		
	}
}
/*Muestra un texto de bienvenida con reglas de juego*/
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
		"2 - Cada vez que evite 20 obstaculos la velocidad aumentara",
		"3 - Sumara 10 puntos evadiendo",
		"4 - Si colisiona con el enemigo perdera 30 ptos",
		"5 - Si se pierden todas las vidas se pierde el juego",		
		"6 - Hay autos y un bloque que se mueven en vertical, hay otro auto que se mueve diagonalmente, aparecen al azar",
		"PRESIONE UNA TECLA PARA INICIAR EL JUEGO"};		
	
	/*Muestro los textos*/
	mostrarTextos(0,3,3, textos);
	mostrarTextos(3,7,7, textos);
	mostrarTextos(7,15,12, textos);	
	/*Espero que presione una tecla para continuar*/
	while(!kbhit()){		
		mostrarTextos(15,16,21, textos);			
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

//Método que limpia el background
void Juego::limpiar(){
	textbackground(GREEN); //Color de fondo de la pista
	clrscr();	
}

//Aquí van los bucle Principal del juego
void Juego::buclePrincipal(){	
	while(player->getEstaActivo()){		//Mientras que el jugador tenga vidas
		pista->update();
		panel->update();
		player->update();
		/*TODO METER EN ARREGLO*/
		enemigo1->update();
		bloque->update();
		enemigo2->update();	
		chequearColisiones(enemigo2);	//Método que chequea si los autos chocaron		
		chequearColisiones(enemigo1);	//Método que chequea si los autos chocaron	
		chequearColisiones(bloque);	//Método que chequea si los autos chocaron	
		activarEnemigo(false);			//Método que activa a un nuevo enemigo
		chequearAceleracion();
	}
}
//Método que chequea si hay que acelerar a los moviles
void Juego::chequearAceleracion(){
	if(panel->getEvitados()%20==0 && valorViejo!=panel->getEvitados()){	
		valorViejo = panel->getEvitados();//Fix para evitar que se ejecute multiples veces
		enemigo1 ->acelerar();
		enemigo2->acelerar();
		bloque->acelerar();
	}
}

//Detecta colisiones
//Distancia es igual a la absoluta de x2-x1 + absoluta de y2-y1
void Juego::chequearColisiones(Movil* enemigo){
	/*Básicamente estoy chequeando las colisiones creando dos rectangulos
	y comprobando que se superpongan*/
	if(player->getPosicionX() < enemigo->getPosicionX() + 5 &&
	   player->getPosicionX() + 5 > enemigo->getPosicionX() &&
	   player->getPosicionY() < enemigo->getPosicionY() + 3 &&
	   player->getPosicionY() + 3 > enemigo->getPosicionY()){
		/*Si hay colision*/
		Sleep(500);
		enemigo->kill();		
		player->kill();
		activarEnemigo(true);	//Se activa el enemigo de manera que no lanza activarEnemigo()
		restarPuntaje();
	}									 
}

//Método que verifica si el enemigo esta activado o no
void Juego::activarEnemigo(bool hayColision){	
	//Si ninguno de los dos enemigos esta activado, se activa alguno al azar
	if(!enemigo1->getEstaActivo() && !enemigo2->getEstaActivo()&& !bloque->getEstaActivo()){		
		if(!hayColision) {		//Si hay colision no aumenta el puntaje
			aumentarPuntaje();
		}
		int opcion = rand()%3;		
		switch(opcion){
		case 0:
			enemigo1->setActivar();
			break;
		case 1:
			enemigo2->setActivar();
			break;
		default:
			bloque->setActivar();
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

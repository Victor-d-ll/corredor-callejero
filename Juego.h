#ifndef JUEGO_H
#define JUEGO_H
#include "Limites.h"
#include "Panel.h"
#include "Movil.h"
#include "Pista.h"
#include <iostream>
/*Esta es la clase que contiene al juego, su bucle principal, y metodos param_type
detectar colisiones, perdidas de vidas, principio y final del mismo*/
class Juego {
public:
	Juego();
	~Juego();	
	void start();
	
private:
	void limpiar();
	void capturaEvento();
	void buclePrincipal();	
	void chequearColisiones(Movil *enemigo);	
	void chequearAceleracion();
	void activarEnemigo(bool hayColision);
	void aumentarPuntaje();
	void restarPuntaje();
	void mostrarIntro();
	void mostrarTextos(int inicio, int final,int posicion_y, std::string* textos);	
	void mostrarOutro();
	void dibujarParedes();
	void reiniciarJuego(int opcion);
	//Variables
	Panel* panel;
	Limites*  paredes[2];
	Movil* player;
	Movil* enemigo1;
	Movil* enemigo2;
	Movil* bloque;
	Pista* pista;	
	int valorViejo;
};

#endif


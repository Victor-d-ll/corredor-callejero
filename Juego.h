#ifndef JUEGO_H
#define JUEGO_H
#include "Limites.h"
#include "Panel.h"
#include "Movil.h"
#include "Pista.h"
#include <iostream>

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
	void activarEnemigo(bool hayColision);
	void aumentarPuntaje();
	void restarPuntaje();
	void mostrarIntro();
	void mostrarTextos(int inicio, int final,int posicion_y, std::string* textos);	
	void mostrarOutro();
	void dibujarParedes();
	void reiniciarJuego(int opcion);
	Panel* panel;
	Limites*  paredes[2];
	Movil* player;
	Movil* enemigo1;
	Movil* enemigo2;
	Movil* bloque;
	Pista* pista;	
};

#endif


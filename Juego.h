#ifndef JUEGO_H
#define JUEGO_H
#include "Auto.h"
#include "Limites.h"
#include "AutoEnemigo.h"
#include "Autojugador.h"

class Juego {
public:
	Juego();
	~Juego();
	void start();
	
private:
	void limpiar();
	void capturaEvento();
	void update();
	void hidecursor();		
	Autojugador* autoJugador;
	AutoEnemigo* autoEnemigo;
	Limites*  paredes[2];
};

#endif


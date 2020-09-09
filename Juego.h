#ifndef JUEGO_H
#define JUEGO_H
#include "Auto.h"


class Juego {
public:
	Juego();
	void start();
	
private:
	void limpiar();
	void capturaEvento();
	void update();
	Auto* autoJugador;	
	int velocidad;
};

#endif


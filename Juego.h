#ifndef JUEGO_H
#define JUEGO_H
#include "Auto.h"
#include "Limites.h"

class Juego {
public:
	Juego();
	void start();
	
private:
	void limpiar();
	void capturaEvento();
	void update();
	void hidecursor();
	Auto* autoJugador;	
	Auto* autoEnemigo;
	int velocidad;
	Limites* paredes;
};

#endif


#ifndef JUEGO_H
#define JUEGO_H
#include "Auto.h"
#include "Limites.h"
#include "AutoEnemigo.h"
#include "AutoJugador.h"
#include "Panel.h"

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
	void chequearColisiones();
	AutoJugador* autoJugador;
	AutoEnemigo* autoEnemigo;
	Panel* panel;
	Limites*  paredes[2];
	
};

#endif


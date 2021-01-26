#ifndef JUEGO_H
#define JUEGO_H
#include "Limites.h"
#include "Panel.h"
#include "Vehiculo.h"

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
	Panel* panel;
	Limites*  paredes[2];
	Vehiculo* player;
	
};

#endif


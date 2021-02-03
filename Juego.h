#ifndef JUEGO_H
#define JUEGO_H
#include "Limites.h"
#include "Panel.h"
#include "Vehiculo.h"
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
	void update();
	void hidecursor();	
	void chequearColisiones(Vehiculo *enemigo);	
	void activarEnemigo(bool hayColision);
	void aumentarPuntaje();
	void restarPuntaje();
	void mostrarIntro();
	void mostrarTextos(int inicio, int final,int posicion_y, std::string* textos);	
	void mostrarOutro();
	Panel* panel;
	Limites*  paredes[2];
	Vehiculo* player;
	Vehiculo* enemigo1;
	Vehiculo* enemigo2;
	Pista pista;
	
};

#endif


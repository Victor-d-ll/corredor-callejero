#ifndef AUTOENEMIGO_H
#define AUTOENEMIGO_H
#include "Auto.h"

class AutoEnemigo : public Auto {
public:
	AutoEnemigo();
	~AutoEnemigo();
	void update ( ) override;
	int getPasadas(); 
private:
	int direccion;
	void moverse();
	void reiniciar();
	int contador; //Variable que guarda cuantas veces el auto fue sobrepasado
};

#endif

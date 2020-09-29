#ifndef AUTOJUGADOR_H
#define AUTOJUGADOR_H
#include "Auto.h"

class Autojugador : public Auto {
public:
	Autojugador();
	~Autojugador();
	void update();
	void moverse(char direccion);
	
private:
};

#endif


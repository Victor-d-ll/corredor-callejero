#ifndef AUTOJUGADOR_H
#define AUTOJUGADOR_H
#include "Auto.h"

class AutoJugador : public Auto {
public:
	AutoJugador();
	~AutoJugador();
	void update() override;
	void moverse(char direccion);
	
private:
};

#endif


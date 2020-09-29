#ifndef AUTOENEMIGO_H
#define AUTOENEMIGO_H
#include "Auto.h"

class AutoEnemigo : public Auto {
public:
	AutoEnemigo();
	~AutoEnemigo();
	void update ( ) override;
	
private:
	int direccion;
};

#endif


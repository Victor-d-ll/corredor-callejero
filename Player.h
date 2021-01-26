#ifndef PLAYER_H
#define PLAYER_H
#include "Vehiculo.h"

class Player : public Vehiculo {
public:
	Player();
	void update ( ) override;
	void setPosicion (int x, int y) override;
	
private:
};

#endif


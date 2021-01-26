#ifndef PLAYER_H
#define PLAYER_H
#include "Vehiculo.h"

class Player : public Vehiculo {
public:
	Player();
	Player(int velocidad, int color);	
	void update ( ) override;
	void setPosicion (int x, int y) override;
	
private:
};

#endif


#ifndef PLAYER_H
#define PLAYER_H
#include "Vehiculo.h"
#include <ctime>
class Player : public Vehiculo {
public:
	Player();
	Player(int velocidad, int color);	
	void update ();
	void setPosicion (int x, int y);
	void kill();
	void setActivar();
	void acelerar();
	bool getEstaActivo();
	
private:
	void dibujar(); 
	void capturarEntrada();
	int vidas;
	clock_t tempo;
	clock_t paso;	
};

#endif


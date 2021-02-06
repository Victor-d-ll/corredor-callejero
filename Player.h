#ifndef PLAYER_H
#define PLAYER_H
#include "Movil.h"
#include <ctime>

/*Esta clase, que hereda desde Movil, define el comportamiento del jugador*/
class Player : public Movil {
public:
	Player();
	Player(int velocidad, int color);	
	void update ();
	void setPosicion (int x, int y);
	void kill();
	void setActivar();
	void acelerar();
	bool getEstaActivo();
	void reiniciarParametros();
private:	
	void capturarEntrada();
	int vidas;	//Vidas del jugador
};

#endif


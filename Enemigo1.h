#ifndef ENEMIGO1_H
#define ENEMIGO1_H
#include "Vehiculo.h"

class Enemigo1 : public Vehiculo {
public:
	Enemigo1(int velocidad, int color);	
	~Enemigo1();	
	void update ( ) override;
	void setPosicion (int x, int y) override;
	void aumentarVelocidad();
	void kill();
	void acelerar();
	void setActivar();
	bool getEstaActivo();
	void reiniciarParametros();
	
private:
	void reiniciar();
	void borrar();
	bool activado;
};

#endif


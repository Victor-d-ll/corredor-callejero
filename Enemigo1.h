#ifndef ENEMIGO1_H
#define ENEMIGO1_H
#include "Movil.h"

class Enemigo1 : public Movil {
public:
	Enemigo1(int velocidad, int color);	
	~Enemigo1();	
	void update ( );
	void setPosicion (int x, int y) ;	
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


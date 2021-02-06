#ifndef ENEMIGO2_H
#define ENEMIGO2_H
#include "Movil.h"
/*Clase que determina el comportamiento del enemigo que va en diagonal.
  Hereda desde movil, como varios de sus miembros son virtuales se redefinen
  en la presente clase*/
class Enemigo2 : public Movil {
public:
	Enemigo2(int velocidad, int color);	
	~Enemigo2();
	void update ();
	void setPosicion (int x, int y);
	void kill ();
	void acelerar();
	void setActivar();	
	bool getEstaActivo();
	void reiniciarParametros();
private:
	bool activado;
	int direccion;
	void borrar();
	void reiniciar();	
};
#endif


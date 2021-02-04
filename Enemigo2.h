#ifndef ENEMIGO2_H
#define ENEMIGO2_H
#include "Vehiculo.h"

class Enemigo2 : public Vehiculo {
public:
	Enemigo2(int velocidad, int color);	
	~Enemigo2();
	void update ( ) override;
	void setPosicion (int x, int y) override;
	void kill ( ) override;
	void acelerar();
	void setActivar();	
	bool getEstaActivo();
	void reiniciarParametros();
private:
	bool activado;
	int direccion;
	void borrar();
	void dibujar();
	void reiniciar();	
};
#endif


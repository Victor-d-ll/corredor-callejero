#ifndef VEHICULO_H
#define VEHICULO_H
#include <ctime>

class Vehiculo {
public:
	
	Vehiculo(int velocidad, int color);	//Constructor
	Vehiculo();	//Constructor vac�o	
	int getPosicionX();
	int getPosicionY();
	virtual void update() = 0;	    //M�todos virtuales ser�n redefinidos en clases derivadas
	virtual void setPosicion(int x, int y) = 0;
	virtual ~Vehiculo(); //Destructor virtual
	
protected:
	int color;	
	int velocidad;
	int x;
	int y;	
	char dibujoAuto[3][5];
	clock_t tempo;
	clock_t paso;	
};

#endif


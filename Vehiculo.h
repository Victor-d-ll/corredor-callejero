#ifndef VEHICULO_H
#define VEHICULO_H
#include <ctime>

class Vehiculo {
public:
	
	Vehiculo(int velocidad, int color);	//Constructor
	Vehiculo();	//Constructor vacío	
	int getPosicionX();
	int getPosicionY();
	virtual void update() = 0;	    //Métodos virtuales serán redefinidos en clases derivadas
	virtual void setPosicion(int x, int y) = 0;
	virtual void setActivar() = 0;
	virtual bool getEstaActivo() = 0;
	virtual void kill()=0;
	virtual void acelerar()=0;
	virtual ~Vehiculo(); //Destructor virtual
	
protected:
	enum  	COLORES {
		BLACK, BLUE, CYAN,
		RED, MAGENTA, BROWN, LIGHTGRAY,
		DARKGRAY, LIGHTBLUE, LIGHTGREEN, LIGHTCYAN,
		LIGHTRED, LIGHTMAGENTA, YELLOW, WHITE
	};
	int color;	
	int velocidad;	 
	int x;
	int y;	
	char dibujoAuto[3][5];
	clock_t tempo;
	clock_t paso;	
};

#endif


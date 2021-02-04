#ifndef MOVIL_H
#define MOVIL_H
#include <ctime>

class Movil {
public:
	
	Movil(int velocidad, int color);	//Constructor
	Movil();	//Constructor vacío	
	int getPosicionX();
	int getPosicionY();
	virtual void update() = 0;	    //Métodos virtuales serán redefinidos en clases derivadas
	virtual void setPosicion(int x, int y) = 0;
	virtual void setActivar() = 0;
	virtual bool getEstaActivo() = 0;
	virtual void kill()=0;
	virtual void acelerar()=0;
	virtual void reiniciarParametros()=0;	
	virtual ~Movil(); //Destructor virtual
	
protected:
	enum  	COLORES {
		BLACK, BLUE, CYAN,
		RED, MAGENTA, BROWN, LIGHTGRAY,
		DARKGRAY, LIGHTBLUE, LIGHTGREEN, LIGHTCYAN,
		LIGHTRED, LIGHTMAGENTA, YELLOW, WHITE
	};
	void dibujar();
	int color;	
	int velocidad;	 
	int x;
	int y;	
	char dibujo[3][5];
	clock_t tempo;
	clock_t paso;	
};

#endif


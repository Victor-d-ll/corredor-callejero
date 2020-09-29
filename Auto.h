#ifndef AUTO_H
#define AUTO_H
#include <ctime>

class Auto {
public:
	Auto(int velocidad, int color);	
	virtual ~Auto();
	void setPosition(int x, int y);		
	virtual void update();
	
protected:
	enum direcciones{izquierda,arriba,derecha,abajo};
	void dibujar();
	char dibujoAuto[3][5];
	void limpiar();
	clock_t tempo;
	clock_t paso;
	int x;
	int y;
	int velocidad;
	int color;
	int alto;
	int ancho;
	int limite_izquierdo;
	int limite_derecho;
};

#endif


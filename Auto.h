#ifndef AUTO_H
#define AUTO_H
#include <time.h>

class Auto {
public:
	Auto(int velocidad, int color);	
	void setPosition(int x, int y);
	void update();
	void moverse(char direccion);
	
private:
	void dibujar();
	char dibujoAuto[3][5];
	void limpiar();
	clock_t tempo;
	clock_t paso;
	int x;
	int y;
	int velocidad;
	int color;
};

#endif


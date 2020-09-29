#ifndef AUTO_H
#define AUTO_H
#include <ctime>

class Auto {
public:
	Auto(int velocidad, int color);	
	virtual ~Auto();
	void setPosition(int x, int y);		
	virtual void update();
	int getPositionX();
	int getPositionY();
	
protected:
	enum direcciones{izquierda,arriba,derecha,abajo};
	void dibujar();
	char dibujoAuto[3][5];
	void limpiar();
	clock_t tempo;
	clock_t paso;
	int x; //Posicion x en la pantalla
	int y; //Posicion y en la pantalla
	int velocidad; 
	int color; //Color del auto
	int alto;  //Alto del auto
	int ancho; //Ancho del auto
	int limite_izquierdo;
	int limite_derecho;
};

#endif


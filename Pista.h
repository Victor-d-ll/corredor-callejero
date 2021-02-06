#ifndef PISTA_H
#define PISTA_H
#include <ctime>
/*Clase que se encarga de dibujar los detalles de la pista*/
class Pista {
public:
	Pista();
	void update();
private:
	clock_t tempo;
	clock_t paso;	
	int orden;
	void dibujarBordes();
	void dibujarLineaCentral();
};

#endif


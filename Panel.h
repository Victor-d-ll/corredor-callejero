#include <ctime>

#ifndef PANEL_H
#define PANEL_H


class Panel {
public:
	Panel();
	void update();	
	void aumentarPuntaje();
	void restarPuntaje();
	
private:
	int puntaje;
	int puntajeActual;
	int autosEsquivados;
	void mostrarPuntaje();
	clock_t tempo;
	clock_t paso;
};

#endif


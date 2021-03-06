#ifndef PANEL_H
#define PANEL_H
#include <ctime>
/*Esta clase representa el panel con el puntaje*/
class Panel {
public:
	Panel();
	void update();	
	void aumentarPuntaje();
	void restarPuntaje();
	int getPuntaje();
	int getEvitados();
	void reiniciarPanel();
private:
	int puntaje;
	int puntajeActual;
	int autosEsquivados;
	int vidas;
	void mostrarPuntaje();
	clock_t tempo;
	clock_t paso;
};

#endif




#ifndef PANEL_H
#define PANEL_H

class Panel {
public:
	Panel();
	void update();
	void setPuntaje(int puntaje);
private:
	int puntaje;
	int puntajeActual;
	int autosEsquivados;
	void mostrarPuntaje();
};

#endif


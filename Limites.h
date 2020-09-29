#ifndef LIMITES_H
#define LIMITES_H

class Limites {
public:
	Limites();
	Limites(int alto, int ancho, int pos_inicial);
	//void update();
	void dibujar();
	
private:
	int alto;
	int ancho;
	int x;
	int y;
	
};

#endif


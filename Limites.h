#ifndef LIMITES_H
#define LIMITES_H

class Limites {
public:
	Limites();
	Limites(int alto, int ancho, int pos_inicial);	
	void dibujar();
	
private:
	int alto;	//Alto de la pared
	int ancho; //Ancho de la pared
	int x; //Posicion x en la pantalla
	int y; //Posicion y en la pantalla
	
};

#endif


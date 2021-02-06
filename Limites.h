#ifndef LIMITES_H
#define LIMITES_H

/*Clase que dibuja los bloques verdes que se encuentran a la derecha y a la
  izquierda de la pista*/
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


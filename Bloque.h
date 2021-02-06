#ifndef BLOQUE_H
#define BLOQUE_H
#include "Enemigo1.h"

/*Clase que hereda desde enemigo1, es una suerte de contenedor de enemigo que 
  lo unico que hace es redefinir el dibujo*/
class Bloque : public Enemigo1 {
public:
	Bloque(int velocidad, int color);
private:
};

#endif


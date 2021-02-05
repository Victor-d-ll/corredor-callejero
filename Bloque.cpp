#include "Bloque.h"
#include <conio2.h>
Bloque::Bloque(int velocidad, int color):Enemigo1(velocidad, color)	 {
	/*Piso los valores del dibujo original para dibujar un bloque*/
	for(int i=0; i<3; i++){
		for(int j=0; j<5; j++){				
			dibujo[i][j]=char(219);	
		}
	}
}


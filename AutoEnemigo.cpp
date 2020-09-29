#include "AutoEnemigo.h"
#include <cstdlib>

AutoEnemigo::AutoEnemigo(): Auto(10,1) {
	direccion = rand() % 10;
}

AutoEnemigo::~AutoEnemigo() {
	
}

void AutoEnemigo::update ( ) {
	if(tempo+paso<clock()){		
		moverse();
		dibujar();	
		tempo = clock();		
	}		
}

void AutoEnemigo::moverse(){
	if(y==30-alto || x == 3 || x == 90) return;
	y++;
	limpiar(arriba);
	limpiar(abajo);
	if(direccion % 2 == 0) {
		
		limpiar(izquierda);
		x++;
	}else{
		limpiar(derecha);
		x--;
	}
}

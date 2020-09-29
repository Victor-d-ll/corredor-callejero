#include "AutoEnemigo.h"
#include <cstdlib>

AutoEnemigo::AutoEnemigo(): Auto(1,1) {
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
	limpiar();
	if(y==30-alto) {
		reiniciar();
		return;
	}
	y++;	
	
	//limpiar(abajo);
	/*if(direccion % 2 == 0) {
		if(x==90) return;		
		x++;
	//	limpiar(izquierda);
	}else{
		if(x==7) return;		
		x--;
		//limpiar(derecha);
	}	*/
}

void AutoEnemigo::reiniciar(){
	x = rand() % 30 + 3;
	y = 2;
}

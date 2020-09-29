#include "AutoEnemigo.h"
#include <cstdlib>

AutoEnemigo::AutoEnemigo(): Auto(30,1) {
	direccion = rand() % 2;
}

AutoEnemigo::~AutoEnemigo() {
	
}

void AutoEnemigo::update ( ) {
	dibujar();
}


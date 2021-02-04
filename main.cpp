#include<iostream>
#include<cstdlib>
#include "Juego.h"
#include <ctime>

using namespace std;

int main (int argc, char *argv[]) {
	srand (time(NULL)); //Inicio la semilla para generar valores al azar
	Juego *juego = new Juego();	
	juego->start();
	delete(juego);
	return 0;
}


#include<iostream>
#include <cstdlib>
#include "Juego.h"

using namespace std;

int main (int argc, char *argv[]) {
	srand (time(NULL));
	Juego *juego = new Juego();
	juego->start();
	delete(juego);
	return 0;
}


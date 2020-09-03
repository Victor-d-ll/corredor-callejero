#include<iostream>
#include "Juego.h"
using namespace std;

int main (int argc, char *argv[]) {
	Juego *juego = new Juego();
	juego->start();
	delete(juego);
	return 0;
}


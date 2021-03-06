#include "Player.h"
#include <iostream>
#include <conio2.h> //gotoxy, textcolor, etc

Player::Player() {}

//El constructor
Player::Player(int velocidad, int color):Movil(velocidad, color) {
	vidas = 3;
	tempo=clock(); 
	paso=CLOCKS_PER_SEC/50;		
}

/*M�todo update*/
void Player::update () {		
	if(tempo+paso<clock()){
		dibujar();//Dibuja en la pantalla
		capturarEntrada(); // Captura la entrada del teclado	
		tempo=clock(); 
	}	
}

void Player::setActivar() {} //Queda vac�o

/*Se llama para reiniciar al  jugador*/
void Player::reiniciarParametros(){
	vidas = 3;
	x=35;
}
//Si le quedan vidas retorna true
bool Player::getEstaActivo(){
	if(vidas!=0) return true;
	else return false;	
} 

void Player::acelerar(){} //Vacia

//M�todo que setea la posicion del auto
void Player::setPosicion (int x, int y) {
	this->x = x;
	this->y = y;
}

/*M�todo que detecta teclado*/
void Player::capturarEntrada(){	
	/*Restamos o sumamos en x para moverse horizontalmente*/
	if (kbhit()){
		int c = getch();
		if(c==75){
			if(x==11) return; //si esta en el tope izquierdo retorna
			putchxy(x+4,y,' ');	//Borramos
			putchxy(x+4,y+2,' ');
			x -= 1;			
		}
		if(c==77){
			if(x==70) return; //si esta en el tope izquierdo retorna
			putchxy(x,y,' ');	//Borramos
			putchxy(x,y+2,' ');
			x += 1;
		}
	}
}

//M�todo que se activa cada vez que choca
void Player::kill(){
	vidas -=1; //resto una vida	
}

#include "Pista.h"
#include "Conio2.h"
#include <iostream>
Pista::Pista() {			
	tempo=clock(); 
	paso=CLOCKS_PER_SEC/10;	
	orden = 0;
}

void Pista::update(){
	if(tempo+paso<clock()){
		dibujarBordes();	
		dibujarLineaCentral();
		tempo=clock();
	}	
}

/*Método que dibuja la linea central la pista*/
void Pista::dibujarLineaCentral(){
	for(int i=0;i<30; i++){			
		textbackground(GREEN);
		gotoxy(42,1+i);
		std::cout<<" ";	
	}
	for(int i=0;i<30; i++){	
		if(i%2==orden) continue;
		textbackground(WHITE);
		gotoxy(42,1+i);
		std::cout<<" ";	
	}
	textbackground(GREEN); //Dejo el color en verde para evitar errores al dibujarse
}

/*Método que dibuja bordes de la pista*/
void Pista::dibujarBordes(){
	for(int i=0;i<30; i++){
		if(i%2==orden) textbackground(RED);
		else textbackground(WHITE);
		gotoxy(11,1+i);
		std::cout<<" ";	
		
		gotoxy(74,1+i);
		std::cout<<" ";
	}		
	if(orden==0) orden =1;
	else orden = 0;
	textbackground(GREEN);
}

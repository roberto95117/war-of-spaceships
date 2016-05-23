#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include "funcGotoxy.h"
#include "Punteo.h"
#include "limitesPantalla.h"
#include "hideCursor.h"
#include "naveEnemiga.h"
#include "Bala.h"
#include "naveBuena.h"
#include "BalaB.h"
#include "gameOver.h"

int main(){
	ocultarCursor();	
	limites();
	
	Punteo pu;
	pu.puntos();
	
	naveEnemiga ne(3,4,3);
	ne.dibujar();
	ne.vidas();
	
	naveBuena nb(6,47,3);
	nb.dibujar();
	nb.vidas();
	
	Bala ba(ne);
	BalaB bab(nb);
	bool game=false;
	while(!game ){
		if(nb.getV()>0){
		ne.mover();
		ba.mover(ne);
		nb.mover();
		bab.mover(nb);	
		nb.muerte(ba);
		ne.muerte(bab.getX(),bab.getY(),pu);
		pu.puntos();
		Sleep(50);	
		}else
		{
			system("cls");
			ocultarCursor();	
			limites();
			gameOver();	
			Sleep(500);
		}	

	}
	return 0;
}

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include "funcGotoxy.h"
#include "naveEnemiga.h"
#include "Bala.h"
#include "naveBuena.h"
#include "limitesPantalla.h"
#include "hideCursor.h"
#include "gameOver.h"
int main(){
	ocultarCursor();	
	limites();
	
	naveEnemiga ne(3,4,3);
	ne.dibujar();
	
	naveBuena nb(7,47,3);
	nb.dibujar();
	nb.vidas();
	
	Bala ba(ne);

	bool game=false;
	while(!game ){
		if(nb.getV()>0){
		ne.mover();
		ba.mover(ne);
		nb.mover();
		nb.muerte(ba);
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

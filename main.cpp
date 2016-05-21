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
int main() {
	ocultarCursor();	
	limites();
	
	naveEnemiga ne(3,4,3);
	ne.dibujar();
	ne.vidas();
	
	naveBuena nb(7,47,3);
	nb.dibujar();
	nb.vidas();
	
	Bala ba(ne);
	bool game=false;
	while(!game){
		ne.mover();
		ba.mover(ne);
		nb.mover();
		nb.muerte(ba);	
		Sleep(50);	
	}	
	return 0;
}

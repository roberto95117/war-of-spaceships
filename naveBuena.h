class naveBuena{
	int x,y,v;
public:
	naveBuena(int x1,int y1,int v1);
	void dibujar();
	void borrar();
	void mover();
	void vidas();
	void muerte(class Bala &b);
	int getV(){
		return v;
	}
};

void naveBuena::dibujar(){
	system("COLOR A");
	 //primera linea
	 gotoxy(x,y-6); printf("/");
	 gotoxy(x+1,y-6); printf("\\");
	 
	 //2da linea
	 gotoxy(x,y-5); printf("X");
	 gotoxy(x+1,y-5); printf("X");
	 gotoxy(x+2,y-5); printf("|"); 
	 gotoxy(x-1,y-5); printf("|");
 	 
 	 //3ra linea
	 gotoxy(x,y-4); printf("X");
	 gotoxy(x+1,y-4); printf("X");
	 gotoxy(x+2,y-4); printf("|"); 
	 gotoxy(x-1,y-4); printf("|");
 	 
 	 //4ta linea
	 gotoxy(x,y-3); printf("X");
	 gotoxy(x+1,y-3); printf("X");
	 gotoxy(x+2,y-3); printf("\\"); 
	 gotoxy(x-1,y-3); printf("/");
 	 
 	 //5ta linea
	 gotoxy(x,y-2); printf("X");
	 gotoxy(x+1,y-2); printf("X");
	 gotoxy(x+3,y-2); printf("\\"); 
	 gotoxy(x+2,y-2); printf("X"); 
	 gotoxy(x-2,y-2); printf("/");
	 gotoxy(x-1,y-2); printf("X");
 	 
	 //6ta linea
	 gotoxy(x,y-1); printf("X");
	 gotoxy(x+1,y-1); printf("X");
	 gotoxy(x+4,y-1); printf("|");
	 gotoxy(x+3,y-1); printf("\\"); 
	 gotoxy(x+2,y-1); printf("X"); 
	 gotoxy(x-3,y-1); printf("|");
	 gotoxy(x-2,y-1); printf("/");
	 gotoxy(x-1,y-1); printf("X");

	//7ma linea
	 gotoxy(x,y); printf("|");
	 gotoxy(x+1,y); printf("|");
	 gotoxy(x+4,y); printf("|");
	 gotoxy(x+3,y); printf("\\"); 
	 gotoxy(x-3,y); printf("|");
	 gotoxy(x-2,y); printf("/");
	 
}
void naveBuena::borrar(){
	 gotoxy(x,y); printf("                                     ");
 	 gotoxy(x,y-6); printf("                              ");
	 gotoxy(x+1,y-6); printf("                                            ");
	 gotoxy(x,y-5);printf("                                               ");
	 gotoxy(x+1,y-5); printf("                                              ");
	 gotoxy(x+2,y-5); printf("                                               "); 
	 gotoxy(x-1,y-5); printf("                                             ");
 	 
	 gotoxy(x,y-4); printf("                                     ");
	 gotoxy(x+1,y-4); printf("                                     ");
	 gotoxy(x+2,y-4); printf("                                     "); 
	 gotoxy(x-1,y-4); printf("                                        ");
 	 
	 gotoxy(x,y-3); printf("                                   ");
	 gotoxy(x+1,y-3);printf("                                   ");
	 gotoxy(x+2,y-3); printf("                                   "); 
	 gotoxy(x-1,y-3); printf("                                   ");
 	 
	 gotoxy(x,y-2); printf("                                   ");
	 gotoxy(x+1,y-2); printf("                                   ");
	 gotoxy(x+3,y-2); printf("                                   "); 
	 gotoxy(x+2,y-2); printf("                                   "); 
	 gotoxy(x-2,y-2); printf("                                   ");
	 gotoxy(x-1,y-2); printf("                                  ");
 	 
	 
	 gotoxy(x,y-1); printf("                                  ");
	 gotoxy(x+1,y-1); printf("                                  ");
	 gotoxy(x+4,y-1); printf("                                  ");
	 gotoxy(x+3,y-1); printf("                                  "); 
	 gotoxy(x+2,y-1); printf("                                  "); 
	 gotoxy(x-3,y-1); printf("                                  ");
	 gotoxy(x-2,y-1); printf("                                  ");
	 gotoxy(x-1,y-1); printf("                                  ");
 	 
	 gotoxy(x,y); printf("                                   ");
	 gotoxy(x+1,y); printf("                                  ");
	 gotoxy(x+4,y); printf("                                  ");
	 gotoxy(x+3,y); printf("                                  "); 
	 gotoxy(x-3,y); printf("                                  ");
	 gotoxy(x-2,y); printf("                                 ");	 
}
void naveBuena::mover(){
		if(kbhit()){
		char tecla=getch();
		borrar();		
		if((tecla=='a' or tecla=='A') && x>6) x--;
		if((tecla=='d' or tecla=='D') && x+5 < 157 ){
		x++; //v--;
		};
		//if((tecla=='w' or tecla=='W') && y>10) y--;
		//if((tecla=='s' or tecla=='S') && y+4 <48)   y++;
			dibujar();	
			vidas();
		}
}

void naveBuena::vidas(){
	gotoxy(2,2);printf("Vidas :");
	gotoxy(10,2);printf("                                               ");
	for(int i=0;i<v;i++){
		gotoxy(10+i,2);printf("%c",3);
	}
}

void naveBuena::muerte(class Bala &b){
	if(v!=0 && b.getY()<=47 ){
		if(b.getY()>=y-2 &&  b.getX()>=x-3 && b.getX()<=x+5) {
			v--;
			b.setY(47);
			borrar();
			gotoxy(b.getX(),b.getY()-1);printf("     ");
			gotoxy(b.getX(),b.getY()-2);printf("     ");
			gotoxy(b.getX(),b.getY()-3);printf("     ");
			gotoxy(b.getX(),b.getY()-1);printf("  *  ");
			gotoxy(b.getX(),b.getY()-2);printf(" *** ");
			gotoxy(b.getX(),b.getY()-3);printf("  *  ");
			Sleep(3);
			borrar();
			gotoxy(b.getX(),b.getY()-1);printf("     ");
			gotoxy(b.getX(),b.getY()-2);printf("     ");
			gotoxy(b.getX(),b.getY()-3);printf("     ");			
			gotoxy(b.getX(),b.getY()-1);printf(" * * ");
			gotoxy(b.getX(),b.getY()-2);printf("*   *");
			gotoxy(b.getX(),b.getY()-3);printf(" * * ");
			Sleep(3);
			borrar();
			gotoxy(b.getX(),b.getY()-1);printf("     ");
			gotoxy(b.getX(),b.getY()-2);printf("     ");
			gotoxy(b.getX(),b.getY()-3);printf("     ");
			dibujar();
			vidas();
			
		}
		else if (b.getY()>=y-3 &&  b.getX()>=x-1 && b.getX()<x+4){
			v--;
			b.setY(47);
			borrar();
			gotoxy(b.getX(),b.getY()-1);printf("     ");
			gotoxy(b.getX(),b.getY()-2);printf("     ");
			gotoxy(b.getX(),b.getY()-3);printf("     ");
			gotoxy(b.getX(),b.getY()-1);printf("  *  ");
			gotoxy(b.getX(),b.getY()-2);printf(" *** ");
			gotoxy(b.getX(),b.getY()-3);printf("  *  ");
			Sleep(3);
			borrar();
			gotoxy(b.getX(),b.getY()-1);printf("     ");
			gotoxy(b.getX(),b.getY()-2);printf("     ");
			gotoxy(b.getX(),b.getY()-3);printf("     ");			
			gotoxy(b.getX(),b.getY()-1);printf(" * * ");
			gotoxy(b.getX(),b.getY()-2);printf("*   *");
			gotoxy(b.getX(),b.getY()-3);printf(" * * ");
			Sleep(3);
			borrar();
			gotoxy(b.getX(),b.getY()-1);printf("     ");
			gotoxy(b.getX(),b.getY()-2);printf("     ");
			gotoxy(b.getX(),b.getY()-3);printf("     ");
			dibujar();
			vidas();
		}
		else if (b.getY()>=y-6 &&  b.getX()>=x-1 && b.getX()<=x+2) {
			v--;
			b.setY(47);
			gotoxy(b.getX()-1,b.getY()+1);printf(" ");
			borrar();
			gotoxy(b.getX(),b.getY()-1);printf("     ");
			gotoxy(b.getX(),b.getY()-2);printf("     ");
			gotoxy(b.getX(),b.getY()-3);printf("     ");
			gotoxy(b.getX(),b.getY()-1);printf("  *  ");
			gotoxy(b.getX(),b.getY()-2);printf(" *** ");
			gotoxy(b.getX(),b.getY()-3);printf("  *  ");
			Sleep(3);
			borrar();
			gotoxy(b.getX(),b.getY()-1);printf("     ");
			gotoxy(b.getX(),b.getY()-2);printf("     ");
			gotoxy(b.getX(),b.getY()-3);printf("     ");			
			gotoxy(b.getX(),b.getY()-1);printf(" * * ");
			gotoxy(b.getX(),b.getY()-2);printf("*   *");
			gotoxy(b.getX(),b.getY()-3);printf(" * * ");
			Sleep(3);
			borrar();
			gotoxy(b.getX(),b.getY()-1);printf("     ");
			gotoxy(b.getX(),b.getY()-2);printf("     ");
			gotoxy(b.getX(),b.getY()-3);printf("     ");
			dibujar();
			vidas();
		}

		else{
		}
	}		
	else{
	}
}
naveBuena::naveBuena (int x1,int y1,int v1){
	x=x1;
	y=y1;
	v=v1;
}

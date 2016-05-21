class naveBuena{
	int x,y,v;
public:
	naveBuena(int x1,int y1,int v1);
	void dibujar();
	void borrar();
	void mover();
	void vidas();
	void muerte(class Bala &b);
};

void naveBuena::dibujar(){
	system("COLOR A");
	 gotoxy(x,y-6); printf("/");
	 gotoxy(x+1,y-6); printf("\\");
	 gotoxy(x,y-5); printf("X");
	 gotoxy(x+1,y-5); printf("X");
	 gotoxy(x+2,y-5); printf("|"); 
	 gotoxy(x-1,y-5); printf("|");
 	 
	 gotoxy(x,y-4); printf("X");
	 gotoxy(x+1,y-4); printf("X");
	 gotoxy(x+2,y-4); printf("|"); 
	 gotoxy(x-1,y-4); printf("|");
 	 
	 gotoxy(x,y-3); printf("X");
	 gotoxy(x+1,y-3); printf("X");
	 gotoxy(x+2,y-3); printf("\\"); 
	 gotoxy(x-1,y-3); printf("/");
 	 
	 gotoxy(x,y-2); printf("X");
	 gotoxy(x+1,y-2); printf("X");
	 gotoxy(x+3,y-2); printf("\\"); 
	 gotoxy(x+2,y-2); printf("X"); 
	 gotoxy(x-2,y-2); printf("/");
	 gotoxy(x-1,y-2); printf("X");
 	 
	 
	 gotoxy(x,y-1); printf("X");
	 gotoxy(x+1,y-1); printf("X");
	 gotoxy(x+4,y-1); printf("|");
	 gotoxy(x+3,y-1); printf("\\"); 
	 gotoxy(x+2,y-1); printf("X"); 
	 gotoxy(x-3,y-1); printf("|");
	 gotoxy(x-2,y-1); printf("/");
	 gotoxy(x-1,y-1); printf("X");
 	 
	 gotoxy(x,y); printf("|");
	 gotoxy(x+1,y); printf("|");
	 gotoxy(x+4,y); printf("|");
	 gotoxy(x+3,y); printf("\\"); 
	 gotoxy(x-3,y); printf("|");
	 gotoxy(x-2,y); printf("/");
	 
}
void naveBuena::borrar(){
	 gotoxy(x,y); printf("       ");
 	 gotoxy(x,y-6); printf("      ");
	 gotoxy(x+1,y-6); printf("      ");
	 gotoxy(x,y-5);printf("        ");
	 gotoxy(x+1,y-5); printf("       ");
	 gotoxy(x+2,y-5); printf("        "); 
	 gotoxy(x-1,y-5); printf("        ");
 	 
	 gotoxy(x,y-4); printf("       ");
	 gotoxy(x+1,y-4); printf("       ");
	 gotoxy(x+2,y-4); printf("       "); 
	 gotoxy(x-1,y-4); printf("          ");
 	 
	 gotoxy(x,y-3); printf(" ");
	 gotoxy(x+1,y-3);printf(" ");
	 gotoxy(x+2,y-3); printf(" "); 
	 gotoxy(x-1,y-3); printf(" ");
 	 
	 gotoxy(x,y-2); printf(" ");
	 gotoxy(x+1,y-2); printf(" ");
	 gotoxy(x+3,y-2); printf(" "); 
	 gotoxy(x+2,y-2); printf(" "); 
	 gotoxy(x-2,y-2); printf(" ");
	 gotoxy(x-1,y-2); printf(" ");
 	 
	 
	 gotoxy(x,y-1); printf(" ");
	 gotoxy(x+1,y-1); printf(" ");
	 gotoxy(x+4,y-1); printf(" ");
	 gotoxy(x+3,y-1); printf(" "); 
	 gotoxy(x+2,y-1); printf(" "); 
	 gotoxy(x-3,y-1); printf(" ");
	 gotoxy(x-2,y-1); printf(" ");
	 gotoxy(x-1,y-1); printf(" ");
 	 
	 gotoxy(x,y); printf(" ");
	 gotoxy(x+1,y); printf(" ");
	 gotoxy(x+4,y); printf(" ");
	 gotoxy(x+3,y); printf(" "); 
	 gotoxy(x-3,y); printf(" ");
	 gotoxy(x-2,y); printf(" ");	 
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
	gotoxy(20,2);printf("             ");
	for(int i=0;i<v;i++){
		gotoxy(10+i,2);printf("%c",3);
	}
}

void naveBuena::muerte(class Bala &b){
	if(v!=0){
		if( b.getY()+6>=y && b.getX()<=x+4  && b.getX()>=x-3) {
			borrar();
			gotoxy(x,y-6);  printf("  **  ");
			gotoxy(x,y-5);printf(" **** ");
			gotoxy(x,y-4);printf("  **  ");
			Sleep(25);
			borrar();
			gotoxy(x,y-6);  printf("**  **");
			gotoxy(x,y-5);printf("*    *");
			gotoxy(x,y-4);printf("**  **");
			Sleep(25);
			borrar();
			dibujar();
		}
		else
		{
			if(y<=b.getY()+4 && b.getX()<=x+3  && b.getX()>=x-2 ){
				borrar();
				gotoxy(x,y);  printf("  **  ");
				gotoxy(x,y+1);printf(" ****  ");
				gotoxy(x,y+2);printf("  **   ");
				Sleep(200);
				borrar();
				gotoxy(x,y);  printf(" * ** *  ");
				gotoxy(x,y+1);printf("  ****  ");
				gotoxy(x,y+2);printf(" * ** *  ");
				Sleep(200);
				borrar();
				dibujar();
			}	
		}			
	}
	else
	{
		v=3;
	}
}
naveBuena::naveBuena (int x1,int y1,int v1){
	x=x1;
	y=y1;
	v=v1;
}

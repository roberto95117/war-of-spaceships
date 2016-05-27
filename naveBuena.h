class naveBuena{
	int x,y,v,dis;
public:
	//sobrecarga de methodos
	naveBuena(int x1,int y1,int v1);
	//constructor siempre tiene
	//el mismo nombre de la clase
	naveBuena();
	void dibujar();
	void borrar();
	void mover();
	void vidas();
	void muerte(class Bala &b);
	int getV();
	int getX();
	int getY();
	void setV(int v1);
	void setX(int x1);
	void setY(int y1);	
	void muerteNor();
	int posX();
	int posY();
	int dispa();
};
     //obtener numero de vidas
int naveBuena::getV(){
	return v;
}
int naveBuena::getX(){
	return x;
}
int naveBuena::getY(){
	return y;
}
	//establecer numero de vidas
void naveBuena::setV(int v1){
	v=v1;
}
void naveBuena::setX(int x1){
	x=x1;
}

void naveBuena::setY(int y1){
	y=y1;
}

int naveBuena::posX(){
	return x;
}
int naveBuena::posY(){
	return y;
}
int naveBuena::dispa(){
	return dis;
}


void naveBuena::dibujar(){
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
	 //primera linea
	 gotoxy(x-1,y-6); printf(" ");
	 gotoxy(x,y-6); printf(" ");
	 gotoxy(x+1,y-6); printf(" ");
	 gotoxy(x+2,y-6); printf(" ");
	 
	 //2da linea
	 gotoxy(x,y-5); printf(" ");
	 gotoxy(x+1,y-5); printf(" ");
	 gotoxy(x+2,y-5); printf(" "); 
	 gotoxy(x-1,y-5); printf(" ");
 	 
 	 //3ra linea
	 gotoxy(x,y-4); printf(" ");
	 gotoxy(x+1,y-4); printf(" ");
	 gotoxy(x+2,y-4); printf(" "); 
	 gotoxy(x-1,y-4); printf(" ");
 	 
 	 //4ta linea
	 gotoxy(x,y-3); printf(" ");
	 gotoxy(x+1,y-3); printf(" ");
	 gotoxy(x+2,y-3); printf(" "); 
	 gotoxy(x-1,y-3); printf(" ");
 	 
 	 //5ta linea
	 gotoxy(x,y-2); printf(" ");
	 gotoxy(x+1,y-2); printf(" ");
	 gotoxy(x+3,y-2); printf(" "); 
	 gotoxy(x+2,y-2); printf(" "); 
	 gotoxy(x-2,y-2); printf(" ");
	 gotoxy(x-1,y-2); printf(" ");
 	 
	 //6ta linea
	 gotoxy(x,y-1); printf(" ");
	 gotoxy(x+1,y-1); printf(" ");
	 gotoxy(x+4,y-1); printf(" ");
	 gotoxy(x+3,y-1); printf(" "); 
	 gotoxy(x+2,y-1); printf(" "); 
	 gotoxy(x-3,y-1); printf(" ");
	 gotoxy(x-2,y-1); printf(" ");
	 gotoxy(x-1,y-1); printf(" ");

	//7ma linea
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
		if((tecla=='a' or tecla=='A') && x>6){
			PlaySound(TEXT("Sonidos/muevebuena.wav"), NULL, SND_FILENAME | SND_ASYNC );
			x--;
		} 
		if((tecla=='d' or tecla=='D') && x+5 < 157 ){
			PlaySound(TEXT("Sonidos/muevebuena.wav"), NULL, SND_FILENAME | SND_ASYNC );
			x++;
		}
		dis=0;
		if((tecla=='w' or tecla=='W')){
			dis=1;
		};
		//if((tecla=='s' or tecla=='S') && y+4 <48)   y++;
			dibujar();	
			vidas();
		}
}

void naveBuena::vidas(){
	gotoxy(2,1);printf("Mi nave :");
	gotoxy(2,2);printf("Vidas :");
	gotoxy(10,2);printf("                         ");
	for(int i=0;i<v;i++){
		gotoxy(10+i,2);printf("%c",3);
	}
}

void naveBuena::muerte(class Bala &b){
	if(v!=0 && b.getY()<=46 ){
		if(b.getY()>=y-2 &&  b.getX()>=x-3 && b.getX()<=x+5) {
			PlaySound(TEXT("Sonidos/mataMala.wav"), NULL, SND_FILENAME | SND_ASYNC );
			v--;
			b.setY(46);
			borrar();
			gotoxy(b.getX(),b.getY()-1);printf("     ");
			gotoxy(b.getX(),b.getY()-2);printf("     ");
			gotoxy(b.getX(),b.getY()-3);printf("     ");
			gotoxy(b.getX(),b.getY()-1);printf("  *  ");
			gotoxy(b.getX(),b.getY()-2);printf(" *** ");
			gotoxy(b.getX(),b.getY()-3);printf("  *  ");
			Sleep(20);
			borrar();
			gotoxy(b.getX(),b.getY()-1);printf("     ");
			gotoxy(b.getX(),b.getY()-2);printf("     ");
			gotoxy(b.getX(),b.getY()-3);printf("     ");			
			gotoxy(b.getX(),b.getY()-1);printf(" * * ");
			gotoxy(b.getX(),b.getY()-2);printf("*   *");
			gotoxy(b.getX(),b.getY()-3);printf(" * * ");
			Sleep(20);
			borrar();
			gotoxy(b.getX(),b.getY()-1);printf("     ");
			gotoxy(b.getX(),b.getY()-2);printf("     ");
			gotoxy(b.getX(),b.getY()-3);printf("     ");
			dibujar();
			vidas();
			
		}
		else if (b.getY()>=y-3 &&  b.getX()>=x-1 && b.getX()<x+4){
			PlaySound(TEXT("Sonidos/mataMala.wav"), NULL, SND_FILENAME | SND_ASYNC );
			v--;
			b.setY(46);
			borrar();
			gotoxy(b.getX(),b.getY()-1);printf("     ");
			gotoxy(b.getX(),b.getY()-2);printf("     ");
			gotoxy(b.getX(),b.getY()-3);printf("     ");
			gotoxy(b.getX(),b.getY()-1);printf("  *  ");
			gotoxy(b.getX(),b.getY()-2);printf(" *** ");
			gotoxy(b.getX(),b.getY()-3);printf("  *  ");
			Sleep(20);
			borrar();
			gotoxy(b.getX(),b.getY()-1);printf("     ");
			gotoxy(b.getX(),b.getY()-2);printf("     ");
			gotoxy(b.getX(),b.getY()-3);printf("     ");			
			gotoxy(b.getX(),b.getY()-1);printf(" * * ");
			gotoxy(b.getX(),b.getY()-2);printf("*   *");
			gotoxy(b.getX(),b.getY()-3);printf(" * * ");
			Sleep(20);
			borrar();
			gotoxy(b.getX(),b.getY()-1);printf("     ");
			gotoxy(b.getX(),b.getY()-2);printf("     ");
			gotoxy(b.getX(),b.getY()-3);printf("     ");
			dibujar();
			vidas();
		}
		else if (b.getY()>=y-6 &&  b.getX()>=x-1 && b.getX()<=x+2) {
			PlaySound(TEXT("Sonidos/mataMala.wav"), NULL, SND_FILENAME | SND_ASYNC );
			v--;
			b.setY(46);
			gotoxy(b.getX()-1,b.getY()+1);printf(" ");
			borrar();
			gotoxy(b.getX(),b.getY()-1);printf("     ");
			gotoxy(b.getX(),b.getY()-2);printf("     ");
			gotoxy(b.getX(),b.getY()-3);printf("     ");
			gotoxy(b.getX(),b.getY()-1);printf("  *  ");
			gotoxy(b.getX(),b.getY()-2);printf(" *** ");
			gotoxy(b.getX(),b.getY()-3);printf("  *  ");
			Sleep(20);
			borrar();
			gotoxy(b.getX(),b.getY()-1);printf("     ");
			gotoxy(b.getX(),b.getY()-2);printf("     ");
			gotoxy(b.getX(),b.getY()-3);printf("     ");			
			gotoxy(b.getX(),b.getY()-1);printf(" * * ");
			gotoxy(b.getX(),b.getY()-2);printf("*   *");
			gotoxy(b.getX(),b.getY()-3);printf(" * * ");
			Sleep(20);
			borrar();
			gotoxy(b.getX(),b.getY()-1);printf("     ");
			gotoxy(b.getX(),b.getY()-2);printf("     ");
			gotoxy(b.getX(),b.getY()-3);printf("     ");
			dibujar();
			vidas();
		}
	}
}

void naveBuena::muerteNor(){
		borrar();
		gotoxy(x,y-1);printf("     ");
		gotoxy(x,y-2);printf("     ");
		gotoxy(x,y-3);printf("     ");
		gotoxy(x,y-1);printf("  *  ");
		gotoxy(x,y-2);printf(" *** ");
		gotoxy(x,y-3);printf("  *  ");
		Sleep(200);
		borrar();
		gotoxy(x,y-1);printf("     ");
		gotoxy(x,y-2);printf("     ");
		gotoxy(x,y-3);printf("     ");			
		gotoxy(x,y-1);printf(" * * ");
		gotoxy(x,y-2);printf("*   *");
		gotoxy(x,y-3);printf(" * * ");
		Sleep(200);
		borrar();
		gotoxy(x,y-1);printf("     ");
		gotoxy(x,y-2);printf("     ");
		gotoxy(x,y-3);printf("     ");
		dibujar();
		v--;
		vidas();
}

naveBuena::naveBuena (int x1,int y1,int v1){
	x=x1;
	y=y1;
	v=v1;
}
naveBuena::naveBuena (){
	x=0;
	y=0;
	v=0;
}

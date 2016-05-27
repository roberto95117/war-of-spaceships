class naveEnemiga{
	int x,y,v,n;
	char dir;
public:
	naveEnemiga(int x1,int y1,int v1,int n1);
	int getY(){
		return y;
	}
	int getX(){
		return x;
	}
	int getV(){
		return v;
	}
	int getN(){
		return n;
	}
	void setX(int x1);
	void setV(int v1);
	void setN(int n1);
	void dibujar();
	void borrar();
	void mover();
	void vidas();
	void muerte(int x1,int y1, class Punteo &p);
};

void naveEnemiga::setX(int x1){
	x=x1;
}

void naveEnemiga::setV(int v1){
	v=v1;
}
void naveEnemiga::dibujar(){

	//linea 1
		gotoxy(x+2,y);printf("|");
		gotoxy(x+3,y);printf("*");
		gotoxy(x+4,y);printf("*");
		gotoxy(x+5,y);printf("*");
		gotoxy(x+6,y);printf("*");
		gotoxy(x+7,y);printf("|");
		//linea 2
		gotoxy(x+1,y+1);printf("|");
		gotoxy(x+2,y+1);printf("*");
		gotoxy(x+3,y+1);printf("O");
		gotoxy(x+4,y+1);printf("*");
		gotoxy(x+5,y+1);printf("*");
		gotoxy(x+6,y+1);printf("O");
		gotoxy(x+7,y+1);printf("*");
		gotoxy(x+8,y+1);printf("|");
		//linea 3
		gotoxy(x,y+2);printf("|");
		gotoxy(x+1,y+2);printf("*");
		gotoxy(x+2,y+2);printf("*");
		gotoxy(x+3,y+2);printf("_");
		gotoxy(x+4,y+2);printf("*");
		gotoxy(x+5,y+2);printf("*");
		gotoxy(x+6,y+2);printf("_");
		gotoxy(x+7,y+2);printf("*");
		gotoxy(x+8,y+2);printf("*");
		gotoxy(x+9,y+2);printf("|");
		//linea 4
		gotoxy(x+1,y+3);printf("\\");
		gotoxy(x+2,y+3);printf("/");
		gotoxy(x+3,y+3);printf(" ");
		gotoxy(x+4,y+3);printf("\\");
		gotoxy(x+5,y+3);printf("/");
		gotoxy(x+6,y+3);printf(" ");
		gotoxy(x+7,y+3);printf("\\");
		gotoxy(x+8,y+3);printf("/");

}
void naveEnemiga::borrar(){
	//linea 1
	gotoxy(x+2,y);printf(" ");
	gotoxy(x+3,y);printf(" ");
	gotoxy(x+4,y);printf(" ");
	gotoxy(x+5,y);printf(" ");
	gotoxy(x+6,y);printf(" ");
	gotoxy(x+7,y);printf(" ");
	//linea 2
	gotoxy(x+1,y+1);printf(" ");
	gotoxy(x+2,y+1);printf(" ");
	gotoxy(x+3,y+1);printf(" ");
	gotoxy(x+4,y+1);printf(" ");
	gotoxy(x+5,y+1);printf(" ");
	gotoxy(x+6,y+1);printf(" ");
	gotoxy(x+7,y+1);printf(" ");
	gotoxy(x+8,y+1);printf(" ");
	//linea 3
	gotoxy(x,y+2);printf(" ");
	gotoxy(x+1,y+2);printf(" ");
	gotoxy(x+2,y+2);printf(" ");
	gotoxy(x+3,y+2);printf(" ");
	gotoxy(x+4,y+2);printf(" ");
	gotoxy(x+5,y+2);printf(" ");
	gotoxy(x+6,y+2);printf(" ");
	gotoxy(x+7,y+2);printf(" ");
	gotoxy(x+8,y+2);printf(" ");
	gotoxy(x+9,y+2);printf(" ");
	//linea 4
	gotoxy(x+1,y+3);printf(" ");
	gotoxy(x+2,y+3);printf(" ");
	gotoxy(x+3,y+3);printf(" ");
	gotoxy(x+4,y+3);printf(" ");
	gotoxy(x+5,y+3);printf(" ");
	gotoxy(x+6,y+3);printf(" ");
	gotoxy(x+7,y+3);printf(" ");
	gotoxy(x+8,y+3);printf(" ");


}

void naveEnemiga::mover(){	
	//	if((tecla=='a' or tecla=='A') && x>3) x--;
		if(v>0){
		borrar();	
			if(dir=='r'){
				if(x+10<157 ){
					x++;
				}
				else{
					dir='l';
					PlaySound(TEXT("Sonidos/muevemala.wav"), NULL, SND_FILENAME | SND_ASYNC );				
				}
			}
			if(dir=='l'){
				if(x>3 ){
					x--;
				}
				else{
					dir='r';
					PlaySound(TEXT("Sonidos/muevemala.wav"), NULL, SND_FILENAME | SND_ASYNC );
				}
			}
			dibujar();	
			vidas();			
		}	
}

void naveEnemiga::vidas(){
	gotoxy(136,1);printf("Nave Enemiga :");
	gotoxy(136,2);printf("Vidas :");
	gotoxy(144,2);printf("          ");
	for(int i=0;i<v;i++){
		gotoxy(144+i,2);printf("%c",3);
	}
}

void naveEnemiga::muerte(int x1,int y1,class Punteo &p){
	if(v!=0 && y1>=y+3 ){
		if(y1<=y+3 &&  (x1==x or x1==x+1 or  x1==x+2 or  x1==x+3 or  x1==x+4 or  x1==x+5 or x1==x+6 or  x1==x+7 or x1==x+8 )) {
			v--;	
			if(n==2){
				p.setP(p.getP()+2);	
			}
			if(n==4){
				p.setP(p.getP()+4);	
			}
			if(n==6){
				p.setP(p.getP()+6);	
			}
			if(n==8){
				p.setP(p.getP()+8);	
			}
			if(n==10){
				p.setP(p.getP()+10);	
			}
			borrar();
			gotoxy(x1,y1-1);printf("     ");
			gotoxy(x1,y1-2);printf("     ");
			gotoxy(x1,y1-3);printf("     ");
			gotoxy(x1,y1-1);printf("  *  ");
			gotoxy(x1,y1-2);printf(" *** ");
			gotoxy(x1,y1-3);printf("  *  ");
			Sleep(50);
			borrar();
			gotoxy(x1,y1-1);printf("     ");
			gotoxy(x1,y1-2);printf("     ");
			gotoxy(x1,y1-3);printf("     ");			
			gotoxy(x1,y1-1);printf(" * * ");
			gotoxy(x1,y1-2);printf("*   *");
			gotoxy(x1,y1-3);printf(" * * ");
			Sleep(50);
			borrar();
			gotoxy(x1,y1-1);printf("     ");
			gotoxy(x1,y1-2);printf("     ");
			gotoxy(x1,y1-3);printf("     ");
			dibujar();
			vidas();
		}		
	}
	if(v<=0){
		PlaySound(TEXT("Sonidos/gano.wav"), NULL, SND_FILENAME | SND_ASYNC );
	}
}
naveEnemiga::naveEnemiga (int x1,int y1,int v1,int n1){
	x=x1;
	y=y1;
	v=v1;
	dir='r';
	n=n1;
}

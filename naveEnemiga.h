class naveEnemiga{
	int x,y,v;
	char dir='r';
public:
	naveEnemiga(int x1,int y1,int v1);
	int getY(){
		return y;
	}
	int getX(){
		return x;
	}
	int getV(){
		return v;
	}
	void setV(int v1);
	void dibujar();
	void borrar();
	void mover();
	void vidas();
	void muerte();
};

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
				}
			}
			if(dir=='l'){
				if(x>3 ){
					x--;
				}
				else{
					dir='r';
				}
			}
			dibujar();	
		//	vidas();			
		}	
}

void naveEnemiga::vidas(){
	gotoxy(2,2);printf("Vidas :");
	gotoxy(20,2);printf("             ");
	for(int i=0;i<v;i++){
		gotoxy(10+i,2);printf("%c",3);
	}
}

void naveEnemiga::muerte(){
	if(v==0){
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
		v=3;
	}
}
naveEnemiga::naveEnemiga (int x1,int y1,int v1){
	x=x1;
	y=y1;
	v=v1;
}

class naveEnemiga2{
	int x,y,v;
	int Rax1,Rax2;
	int Ray1,Ray2;
public:
	naveEnemiga2(int x1,int y1,int v1);
	int llego();
	int RX1();
	int RX2();
	int RY1();
	int RY2();
	void dibujar();
	void borrar();
	void mover();
	void fin();
	void vidas();
	void muerte();
	void bala(int x,int y,int f);
};
void naveEnemiga2::dibujar(){
	//linea 1
	y++;
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
	Ray1=y+2;
	//linea 4
	gotoxy(x+1,y+3);printf("\\");
	Rax1=x+1;
	gotoxy(x+2,y+3);printf("/");
	gotoxy(x+3,y+3);printf(" ");
	gotoxy(x+4,y+3);printf("\\");
	gotoxy(x+5,y+3);printf("/");
	gotoxy(x+6,y+3);printf(" ");
	gotoxy(x+7,y+3);printf("\\");
	gotoxy(x+8,y+3);printf("/");
	Rax2=x+8;
	Ray2=y+3;
}

int naveEnemiga2::llego(){
	return y;
}
//Rango X
int naveEnemiga2::RX1(){
	return Rax1;
}
int naveEnemiga2::RX2(){
	return Rax2;
}
//Rango Y
int naveEnemiga2::RY1(){
	return Ray1;
}
int naveEnemiga2::RY2(){
	return Ray2;
}

void naveEnemiga2::borrar(){
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

void naveEnemiga2::mover(){	
	if(v>0){
		PlaySound(TEXT("Sonidos/muevemala.wav"), NULL, SND_FILENAME | SND_ASYNC );
		borrar();	
		dibujar();	
		vidas();	
	}	
}

void naveEnemiga2::fin(){	
	v=0;
}

void naveEnemiga2::vidas(){
}

void naveEnemiga2::muerte(){
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
		gotoxy(x,y);  printf("         ");
		borrar();
		dibujar();
}
naveEnemiga2::naveEnemiga2 (int x1,int y1,int v1){
	x=x1;
	y=y1;
	v=v1;
}

void naveEnemiga2::bala(int fil, int col,int fincol){
	while(1){
		Sleep(50);
		gotoxy(fil,col);printf(" ");
		col++;
		gotoxy(fil,col);printf("*");
		if(col>=fincol){
			gotoxy(fil,col);printf(" ");
			break;
		}
	}
}

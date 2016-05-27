class BalaB{
	int x,y,yIni;
public:
	BalaB(class naveBuena &n);
	BalaB(int x1,int y1);
	int getX(){return x;}
	int getY(){return y;}
	int posX();
	int posY();
	void setY(int y1);
	void dibujar();
	void mover(class naveBuena &n);
	void mover();
	void borrar();
};

int BalaB::posX(){
	return x;
}

int BalaB::posY(){
	return y;
}

void BalaB::setY(int y1){
	y=y1;
}
void BalaB::mover(class naveBuena &n){
	gotoxy(x,y); printf(" ");
	y--;
	if(y<4){
		PlaySound(TEXT("Sonidos/disparo.wav"), NULL, SND_FILENAME | SND_ASYNC );
		x=n.getX();
		y=40;
	}
	dibujar();	
}

void BalaB::mover(){
	gotoxy(x,y); printf(" ");
	if(y==3){
		//x=rand()%153+4;
		//y=yIni;
		gotoxy(x,y); printf(" ");
	}else{
		y--;
	}
	dibujar();
}

void BalaB::dibujar(){
	gotoxy(x,y);
	printf("%c",193);
}

BalaB::BalaB(class naveBuena &n){
	x=n.getX();
	y=40;
		PlaySound(TEXT("Sonidos/disparo.wav"), NULL, SND_FILENAME | SND_ASYNC );
}

BalaB::BalaB(int x1,int y1){
	x=x1;
	y=y1;
	yIni=y1;
}

void BalaB::borrar(){
	if(y==3){
		gotoxy(x,y);printf("%c",205);
	}else{
		gotoxy(x,y); printf(" ");
	}
}

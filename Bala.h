class Bala{
	int x,y;
public:
	Bala(class naveEnemiga &n);
	int getX(){return x;}
	int getY(){return y;}
	void setY(int y1);
	void dibujar();
	void mover(class naveEnemiga &n);
};

void Bala::setY(int y1){
	y=y1;
}
void Bala::mover(class naveEnemiga &n){
	gotoxy(x,y); printf(" ");
	y++;
	if(y>47){
		PlaySound(TEXT("Sonidos/disparoMalo2.wav"), NULL, SND_FILENAME | SND_ASYNC );
		x=n.getX()+3;
		y=7;
	}
	dibujar();
}
void Bala::dibujar(){
	gotoxy(x,y);
	printf("%c",184);
}
Bala::Bala(class naveEnemiga &n){
	PlaySound(TEXT("Sonidos/disparoMalo2.wav"), NULL, SND_FILENAME | SND_ASYNC );
	x=n.getX()+3;
	y=5;
	
}

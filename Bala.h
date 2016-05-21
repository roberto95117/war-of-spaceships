class Bala{
	int x,y;
public:
	Bala(class naveEnemiga &n);
	int getX(){return x;}
	int getY(){return y;}
	void dibujar();
	void mover(class naveEnemiga &n);
};
void Bala::mover(class naveEnemiga &n){
	gotoxy(x,y); printf(" ");
	y++;
	if(y>47){
		x=n.getX()+3;
		y=5;
	}
	dibujar();
}
void Bala::dibujar(){
	gotoxy(x,y);
	printf("%c",184);
}
Bala::Bala(class naveEnemiga &n){
	x=n.getX()+3;
	y=5;
}

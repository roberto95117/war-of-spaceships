class BalaB{
	int x,y;
public:
	BalaB(class naveBuena &n);
	int getX(){return x;}
	int getY(){return y;}
	void setY(int y1);
	void dibujar();
	void mover(class naveBuena &n);
};

void BalaB::setY(int y1){
	y=y1;
}
void BalaB::mover(class naveBuena &n){
	gotoxy(x,y); printf(" ");
	y--;
	if(y<4){
		x=n.getX();
		y=40;
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
}

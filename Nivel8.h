class Nivel8{
	naveBuena nb;
	Punteo pu;	
public:
	Nivel8(int x,int y,int v,int p);
	naveBuena getNb(){
		return nb;
	}
	Punteo getPu(){
		return pu;
	}
	void Play();
};
Nivel8::Nivel8(int x,int y,int v,int p){
	nb.setV(v);
	nb.setX(x);
	nb.setY(y);
	pu.setP(p);
}
void Nivel8::Play(){
	int inter=0;
	pu.puntos();
	naveEnemiga ne(3,4,8,8);
	ne.dibujar();
	ne.vidas();
	nb.dibujar();
	nb.vidas();
	Bala ba(ne);
	BalaB bab(nb);
	bool game=false;
	while(!game ){
		if(nb.getV()>0){
		inter++;
		if(inter==4){
			ne.mover();
			ba.mover(ne);
			nb.muerte(ba);
			inter=0;
		}
		nb.mover();
		bab.mover(nb);	
		ne.muerte(bab.getX(),bab.getY(),pu);
		pu.puntos();
		Sleep(50);	
		}
		if(nb.getV()<=0 || ne.getV()<=0 ) game=true;
	}
}

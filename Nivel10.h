class Nivel10{
	naveBuena nb;
	Punteo pu;
public:
	Nivel10(int x,int y,int v,int p);
	Nivel10();
	naveBuena getNb(){
		return nb;
	}
	Punteo getPu(){
		return pu;
	}
	void Play();
};
Nivel10::Nivel10(){
}
Nivel10::Nivel10(int x,int y,int v,int p){
	nb.setV(v);
	nb.setX(x);
	nb.setY(y);
	pu.setP(p);
}
void Nivel10::Play(){
	int inter=0;
	pu.puntos();
	naveEnemiga ne(3,4,10,10);
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
		if(inter==2){
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

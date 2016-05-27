class Nivel7{
	naveBuena nb;
	Punteo pu;	
public:
	Nivel7(int x,int y,int v,int p);
	naveBuena getNb(){
		return nb;
	}
	Punteo getPu(){
		return pu;
	}
	void Play();
};


void Nivel7::Play(){
	int ix=1,naMal=1,sig=0,inter=0,vid=nb.getV(),sidis=0;	
	pu.puntos();
	nb.dibujar();
	nb.vidas();
	ix=rand()%160;
	naveEnemiga2 ne1(ix,4,3);
	BalaB ba(0,0);
	bool game=false;
	while(!game){
		if(sig==1){
			ne1.fin();
			ne1.borrar();
			if(naMal<=9){
				ix=rand()%150;
				naveEnemiga2 ne(ix,4,3);
				ne1=ne;
				ne1.dibujar();
				ne1.vidas();
			}
		}
		nb.mover();
		//Dispara Bala
		if(nb.dispa()==1){
			PlaySound(TEXT("Sonidos/disparoBueno.wav"), NULL, SND_FILENAME | SND_ASYNC );
			ba.borrar();
			BalaB ba1(nb.posX(),nb.posY()-5);
			ba=ba1;
			sidis=1;
		}
		if(sidis==1){
			ba.mover();
		}
		sig=0;
		if(ne1.llego()==42){
			//Game over
			vid--;
			if(vid>0){
				ne1.fin();
				ne1.borrar();
				nb.muerteNor();
				sig=1;
			}else{
				nb.muerteNor();
				system("cls");
				//guarda(getAlias(),74);
				PlaySound(TEXT("Sonidos/gameover.wav"), NULL, SND_FILENAME | SND_ASYNC );
				//ix=1,naMal=1,sig=0,inter=0,vid=3,sidis=0;
				break;
			}
		};
		inter++;
		if(inter==4){
			ne1.mover();
			inter=0;
		}
		//Mata enemigo
		if(ne1.RX1()<=ba.posX() && ne1.RX2()>=ba.posX()){
			if(ne1.RY1()<=ba.posY() && ne1.RY2()>=ba.posY()){
				PlaySound(TEXT("Sonidos/mataMala.wav"), NULL, SND_FILENAME | SND_ASYNC );
				sig=1;
				ba.borrar();
				ne1.fin();
				ne1.borrar();
				ne1.muerte();
				naMal++;
				pu.setP(pu.getP()+1);
				sidis=0;
			}
		}
		if(naMal==9){
			system("cls");
			//siguiente nivel
			PlaySound(TEXT("Sonidos/gano.wav"), NULL, SND_FILENAME | SND_ASYNC );
			break;
		}
		Sleep(50);	
	}
}
Nivel7::Nivel7(int x,int y,int v,int p){
	nb.setV(v);
	nb.setX(x);
	nb.setY(y);
	pu.setP(p);
}

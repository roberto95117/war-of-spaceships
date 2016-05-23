using namespace std;
class Punteo{
	int p;
public:
	Punteo();
	void setP(int _p);
	int getP(){
		return p;
	}
	void puntos();
};

void Punteo::setP(int _p){
	p=_p;
}

Punteo::Punteo(){	
}

void Punteo::puntos(){
	gotoxy(70,1);printf("Punteo :");
	gotoxy(80,1);cout<<p;
}

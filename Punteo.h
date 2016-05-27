using namespace std;
class Punteo{
	int p;
public:
	Punteo();
	void setP(int p1);
	int getP();
	void puntos();
};

int Punteo::getP(){
	return p;
}
void Punteo::setP(int p1){
	p=p1;
}
Punteo::Punteo(){	
	p=0;
}
void Punteo::puntos(){
	gotoxy(70,1);printf("Punteo :");
	gotoxy(80,1);cout<<p;
}

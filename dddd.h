#include <stdio.h>
#include <conio.h>
#inude <Windows.h>
#include <mmsystem.h>
#include <string>
int opc=0;

FILE *leerAl;
FILE *escrAl;
char al;
char sn;
char nueAli[50];
int op,con=1;
 //Menu Principal
int main() {
	//PlaySound(TEXT("Sonidos/fondo.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	do{
		con++;
		Sleep(100);
		if(con==1){
			system("COLOR 6");
		}else if(con==2){
			system("COLOR 4");
		}else if(con==3){
			system("COLOR 1");
			con=0;
		}
		
		titulo();
		
		gotoxy(120,12);	cout<<"1) Iniciar"<<endl;
		gotoxy(120,13);	cout<<"2) Alias"<<endl;
		gotoxy(120,14);	cout<<"3) Punteo"<<endl;
		gotoxy(120,15);	cout<<"0) Salir"<<endl;
		if(kbhit()){
			gotoxy(90,16);  cout<<"Ingrese Opcion:";cin>>opc;
	
			if(opc>3){
				gotoxy(5,7);	cout<<"Ingrese una Opcion Valida\n";
				system("cls");
			}else if(opc==1){
				system("cls");
				//guarda("Tale",74);
				PlaySound(TEXT("Sonidos/inicio.wav"), NULL, SND_FILENAME | SND_ASYNC );
				Principal();
			}else if(opc==2){
				alias();
				system("cls");
			}else if(opc==3){
				system("cls");
				Imprime();
				gotoxy(5,7);	cout<<"Presione Cualquier tecla para Continuar...";	
				getch();
				system("cls"); 
			}
		}
	}while(true);
	return 0;
}
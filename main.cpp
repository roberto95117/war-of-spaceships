#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <windows.h>
#include <mmsystem.h>
#include <string>
#include <stdlib.h>
#include "Puntuacion.h"
#include "funcGotoxy.h"
#include "titulo.h"
#include "cambioAlias.h"
#include "Punteo.h"
#include "limitesPantalla.h"
#include "hideCursor.h"
#include "gameOver.h"
#include "naveEnemiga.h"
#include "Bala.h"
#include "naveBuena.h"
#include "naveEnemiga2.h"
#include "BalaB.h"
#include "Nivel1.h"
#include "Nivel2.h"
#include "Nivel3.h"
#include "Nivel4.h"
#include "Nivel5.h"
#include "Nivel6.h"
#include "Nivel7.h"
#include "Nivel8.h"
#include "Nivel9.h"
#include "Nivel10.h"
using namespace std;
void Principal(){
	system("COLOR A");
	//nivel 1
	ocultarCursor();	
	limites();
	naveBuena nb(6,47,5);	
	Punteo pu;
	Nivel1	n1(nb.getX(),nb.getY(),nb.getV(),pu.getP());
	n1.Play();	
	if(n1.getNb().getV()>=1){
		system("cls");
		ocultarCursor();	
		limites();
		Nivel2 n2(n1.getNb().getX(),n1.getNb().getY(),n1.getNb().getV()+1,n1.getPu().getP());
		n2.Play();
		if(n2.getNb().getV()>=1){
			//nivel 3
			system("cls");
			ocultarCursor();	
			limites();
			Nivel3 n3(n2.getNb().getX(),n2.getNb().getY(),n2.getNb().getV()+1,n2.getPu().getP());
			n3.Play();
			if(n3.getNb().getV()>=1){
				//nivel 4
				system("cls");
				ocultarCursor();	
				limites();
				Nivel4 n4(n3.getNb().getX(),n3.getNb().getY(),n3.getNb().getV()+1,n3.getPu().getP());
				n4.Play();
				if(n4.getNb().getV()>=1){
					//nivel 5
					system("cls");
					ocultarCursor();	
					limites();
					Nivel5 n5(n4.getNb().getX(),n4.getNb().getY(),n4.getNb().getV()+1,n4.getPu().getP());
					n5.Play();	
					if(n5.getNb().getV()>=1){
						system("cls");
						ocultarCursor();	
						limites();
						Nivel6 n6(n5.getNb().getX(),n5.getNb().getY(),n5.getNb().getV()+1,n5.getPu().getP());
						n6.Play();
						if(n6.getNb().getV()>=1){
							//nivel 8
							system("cls");
							ocultarCursor();	
							limites();
							Nivel7 n7(n6.getNb().getX(),n6.getNb().getY(),n6.getNb().getV()+1,n6.getPu().getP());
							n7.Play();								
							if(n7.getNb().getV()>=1){
								//nivel 8
								system("cls");
								ocultarCursor();	
								limites();
								Nivel8 n8(n7.getNb().getX(),n7.getNb().getY(),n7.getNb().getV()+1,n7.getPu().getP());
								n8.Play();								
								if(n8.getNb().getV()>=1){
									//nivel 8
									system("cls");
									ocultarCursor();	
									limites();
									Nivel9 n9(n8.getNb().getX(),n8.getNb().getY(),n8.getNb().getV()+1,n8.getPu().getP());
									n9.Play();								
									if(n9.getNb().getV()>=1){
										//nivel 8
										system("cls");
										ocultarCursor();	
										limites();
										Nivel10 n10(n9.getNb().getX(),n9.getNb().getY(),n9.getNb().getV()+1,n9.getPu().getP());
										n10.Play();								
									}else{
										gameOver();
									}
								}else{
									gameOver();
								}
							}else{
								gameOver();
							}							
						}else{
							gameOver();
						}							
					}else{
						gameOver();
					}	
											
				}else{
					gameOver();
				}								
			}else{
				gameOver();
			}
		}else{
			gameOver();
		}	
	}else{
		gameOver();
	}
}

void menuPrincipal(){
	int opc=0;
	int con=0;
	PlaySound(TEXT("Sonidos/background.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
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
		ocultarCursor();
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
				system("cls");
				menuPrincipal();
			}else if(opc==2){
				CambioAlias();
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
}

int main(){
	menuPrincipal();
	return 0;
}

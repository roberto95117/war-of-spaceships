#include <fstream>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <mmsystem.h>
#include <string.h>
#include <stdlib.h>

#include<ctype.h>
#include<vector>

using namespace std;
char* arregloAlias[11];
int arregloPuntos[11];
int tmpLong;
char* tmpChar;
void guarda(char* alias,int punteo){
	struct ARCHIVO {
    	int PUNTOS;
    	char* NOMBRE;
    } JUGA;

	if(punteo==0){
		for(int i=1;i<=10;i++){
   			arregloPuntos[i]=i;
   			//arregloAlias[i]= "Tuhombre";
		}
	}else{
   		arregloPuntos[11]=punteo;
   		arregloAlias[11]=alias;
	}
	ifstream DATOS("DATOS.DAT");
	int con=1;
    while(! DATOS.eof()){
    	DATOS.read((char *) &JUGA,sizeof(ARCHIVO));
    	if(con<11){
      		arregloAlias[con]=JUGA.NOMBRE;
	  		arregloPuntos[con]=JUGA.PUNTOS;
	  	}
	  	con++;
    }
    DATOS.close();

    //Ordena Puntuaciones
    for(int i=1;i<=11;i++){
		for(int j=1;j<=11;j++){
			cout<<arregloPuntos[i]<<endl;
			if (arregloPuntos[j]>arregloPuntos[i]){
				tmpLong=arregloPuntos[i];
				arregloPuntos[i]=arregloPuntos[j];
				arregloPuntos[j]=tmpLong;
				
				tmpChar=arregloAlias[i];
				arregloAlias[i]=arregloAlias[j];
				arregloAlias[j]=tmpChar;
			}
		}
	}
    //guarda la nueva lista
    
   	ofstream DATOSG("DATOS.DAT");
   	for(int i=1;i<=10;i++){
   		JUGA.NOMBRE=arregloAlias[i];
    	JUGA.PUNTOS=arregloPuntos[i];
		DATOSG.write((char *)&JUGA,sizeof(ARCHIVO));	
	}
    DATOSG.close();
}
// Imprime las Puntuaciones
void Imprime(){
	system("COLOR 6");
	cout<<".+´´´+...+´´´+...+´´´+...+´´´+.\n";
	cout<<"**                             **\n";
	cout<<"**    WAR                      **\n";
	cout<<"**        OF                   **\n";
	cout<<"**	     SPACESHIPS        **\n";
	cout<<"**                             **\n";
	cout<<"´´+..+´´+..´+..+´´+..´+..+´´+..´\n";
	cout<<"Alias ------------------Puntuacion\n";
    int cont=0;
    struct ARCHIVO {
    	int PUNTOS;
    	char* NOMBRE;
    } JUGA; 
    ifstream DATOS("DATOS.DAT");
    int con=1;
    while(! DATOS.eof()){
    	DATOS.read((char *) &JUGA,sizeof(ARCHIVO));
    	if(con<11){
    		cout<<JUGA.NOMBRE<<"------------------"<<JUGA.PUNTOS<<endl;
    	}
    	con++;
    }
    DATOS.close();
	cout<<endl;
}

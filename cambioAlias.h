//Alias
FILE *leerAl;
FILE *escrAl;
char al;
char sn;
char nueAli[50];

void CambioAlias(){
	system("COLOR F");
	cout<<endl;
	do{
		system("cls");
		titulo();
		leerAl = fopen("ALIAS.txt","r");
		al = fgetc(leerAl);
		cout<<"Su Alias Actual es: ";
		while ( al!=EOF ){
			printf("%c",al);
			al = fgetc(leerAl);
		} 
		fclose(leerAl);
		cout<<endl;
		cout<<"Desea Cambiar su Alias (S/N) ";
		cin>>sn;
		if(sn=='S' or sn=='s'){
			cout<<"Ingrese Nuevo Alias de 6 Caracteres: ";
			cin>>nueAli;
			escrAl = fopen("ALIAS.txt","w");
			fprintf(escrAl,"%s \n",nueAli);
			fclose(escrAl);
		}
	}while(sn=='S' or sn=='s');
}
//fin Alias
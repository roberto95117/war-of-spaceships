char getAlias(){
	FILE *leerAl;
	char al;
	leerAl = fopen("ALIAS.txt","r");
	al = fgetc(leerAl);
	while ( al!=EOF ){
		printf("%c",al);
		al = fgetc(leerAl);
	} 
	fclose(leerAl);
	return al;
}


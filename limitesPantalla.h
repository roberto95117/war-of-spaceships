void limites(){

	for(int i=2;i<158;i++ ){
		gotoxy(i,3);printf("%c",205);
		gotoxy(i,48);printf("%c",205);
}
	for(int i=4;i<48;i++){
		gotoxy(2,i);printf("%c",186);
		gotoxy(157,i);printf("%c",186);
	}
	gotoxy(2,3);printf("%c",201);
	gotoxy(2,48);printf("%c",200);
	gotoxy(157,3);printf("%c",187);
	gotoxy(157,48);printf("%c",188);			
}

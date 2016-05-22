void gameOver(){
	for(int i=40;i<107;i++){
		gotoxy(i,22);printf("#");	
		gotoxy(i,32);printf("#");
	}
	for(int i=22;i<32;i++){
		gotoxy(40,i);printf("#");
		gotoxy(106,i);printf("#");
	}
	
	gotoxy(45,24);printf("*");
	gotoxy(46,24);printf("*");
	gotoxy(47,24);printf("*");
	gotoxy(48,24);printf("*");
	gotoxy(49,24);printf("*");
	
	gotoxy(45,25);printf("*");

	gotoxy(45,26);printf("*");
	gotoxy(48,26);printf("*");
	gotoxy(49,26);printf("*");
	
	gotoxy(45,27);printf("*");

	gotoxy(45,28);printf("*");	
	gotoxy(49,28);printf("*");

	gotoxy(45,29);printf("*");
	gotoxy(46,29);printf("*");
	gotoxy(47,29);printf("*");
	gotoxy(48,29);printf("*");
	gotoxy(49,29);printf("*");
	
}

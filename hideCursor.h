void ocultarCursor(){
	HANDLE hcon;
	hcon=GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize=100;
	cci.bVisible=false;	
	SetConsoleCursorInfo(hcon,&cci);
}


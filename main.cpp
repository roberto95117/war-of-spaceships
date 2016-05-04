#include <iostream>
#include <windows.h>

int main() {

	printf("*");
	HANDLE hcon;
	hcon=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos; 
	dwPos.X=4;
	dwPos.Y=5;
	SetConsoleCursorPosition(hcon,dwPos);
	printf("*");
	return 0;
}

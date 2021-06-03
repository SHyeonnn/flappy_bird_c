#include <stdio.h>
#include <windows.h>

void gotoxy(int x, int y) {
	COORD pos = { 0, 25 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int main() {
	system("mode con cols=50 lines=50");
	gotoxy(0, 25);
}
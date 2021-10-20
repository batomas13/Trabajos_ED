// Proyecto_1B.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "windows.h"
using namespace std;

typedef struct tico_chapeadora_Tesla {
	char chapeadora = 'H';
	int x = 4;
	int y = 3;
};

void gotoxy(int x, int y)
{
	COORD posicion;
	posicion.X = x;
	posicion.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), posicion);
}

void map() {   // Imprime la cancha que se quiere cortar
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //selecciona el color verde
	cout <<"þþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþ\n"
		<< "þþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþ\n"
		<< "þþþþvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvþþþþ\n"
		<< "þþþþvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvþþþþ\n"
		<< "þþþþvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvþþþþ\n"
		<< "þþþþvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvþþþþ\n"
		<< "þþþþvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvþþþþ\n"
		<< "þþþþvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvþþþþ\n"
		<< "þþþþvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvþþþþ\n"
		<< "þþþþvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvþþþþ\n"
		<< "þþþþvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvþþþþ\n"
		<< "þþþþvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvþþþþ\n"
		<< "þþþþvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvþþþþ\n"
		<< "þþþþvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvþþþþ\n"
		<< "þþþþvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvþþþþ\n"
		<< "þþþþvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvþþþþ\n"
		<< "þþþþvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvþþþþ\n"
		<< "þþþþvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvþþþþ\n"
		<< "þþþþvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvþþþþ\n"
		<< "þþþþvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvþþþþ\n"
		<< "þþþþvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvþþþþ\n"
		<< "þþþþvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvþþþþ\n"
		<< "þþþþvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvþþþþ\n"
		<< "þþþþvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvþþþþ\n"
		<< "þþþþvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvþþþþ\n"
		<< "þþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþ\n"
		<< "þþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþþ\n" << endl;
}

void primer_algoritmo_decorte(tico_chapeadora_Tesla chapeadora) {  // Primer algoritmo de corte 
	bool borde_abajo = false;
	for (int t = 0; t < 1250; t++) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Lo pone de color blanco
		if (chapeadora.y == 25) {  // Cuando llega al final de la cancha se mueve de posicion 
			borde_abajo = true;
			if (chapeadora.x % 2 == 0) {                    // Si tiene que cortar 
				gotoxy(chapeadora.x, chapeadora.y - 1);
				cout << " " << endl;
			}
			else {                                         // Si no tiene que cortar
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				gotoxy(chapeadora.x, chapeadora.y - 2);
				cout << "v" << endl;
				gotoxy(chapeadora.x, chapeadora.y - 1);
				cout << "v" << endl;
			}
			chapeadora.x++;
			chapeadora.y -= 2;
		}
		if (chapeadora.y == 3 && borde_abajo == true) { // Cuando llega al tope de la cancha
			borde_abajo = false;
			if (chapeadora.x % 2 == 0) {
				gotoxy(chapeadora.x, chapeadora.y + 1);
				cout << " " << endl;
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				gotoxy(chapeadora.x, chapeadora.y + 2);
				cout << "v" << endl;
				gotoxy(chapeadora.x, chapeadora.y + 1);
				cout << "v" << endl;
			}
			chapeadora.x++;
		}
		if (chapeadora.x == 46) { // Cuando termina de cortar
			chapeadora.x = 4;
			chapeadora.y = 3;
			return;
		}
		gotoxy(chapeadora.x, chapeadora.y);          // El movimiento de la tico_chapeadora_tesla
		cout << chapeadora.chapeadora << endl;
		if (borde_abajo == true) {
			chapeadora.y--;
		}
		else {
			chapeadora.y++;
		}
		if (chapeadora.x % 2 == 0) {
			gotoxy(chapeadora.x, chapeadora.y - 2);
			cout << " " << endl;
		}
		else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				gotoxy(chapeadora.x, chapeadora.y + 2);
				cout << "v" << endl;
		}
		Sleep(100);
	}
}

int main()
{ 
	bool game = true;
	tico_chapeadora_Tesla chapeadora;
	while (game) {
		map();
		primer_algoritmo_decorte(chapeadora);
		system("cls");
	}
}
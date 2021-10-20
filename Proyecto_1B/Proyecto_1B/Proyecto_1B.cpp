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

void primer_algoritmo_decorte_vertical(tico_chapeadora_Tesla chapeadora) {  // Primer algoritmo de corte 
	bool borde_abajo = false;
	for (int i = 0; i < 1250; i++) {
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
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); 
				gotoxy(chapeadora.x, chapeadora.y + 2);
				cout << "v" << endl;
		}
		//Sleep(100);
	}
}

void segundo_algoritmo_decorte_horizontal(tico_chapeadora_Tesla chapeadora) {
	bool borde_derecha = false;
	bool cortar = false;
	int contador = 0;
	for (int i = 0; i < 1250; i++) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		if (i == 1) {
			gotoxy(chapeadora.x + 2, chapeadora.y - 1);
			
		}
		else
		{
			gotoxy(chapeadora.x, chapeadora.y - 1);
		}

		cout << chapeadora.chapeadora << endl;

		if (contador == 2) {            // Determina cuando hay que cortar
			cortar = !cortar;
			contador = 0;
		}

		if (borde_derecha == false) {   // Mientras no llegue al borde se mueve de izquierda a derecha
			if (cortar == true) {
				if (chapeadora.x != 4) {
					gotoxy(chapeadora.x - 1, chapeadora.y - 1);
					cout << " " << endl;
					gotoxy(chapeadora.x - 2, chapeadora.y - 1);
					cout << " " << endl;
				}
			}
			else{
				if (chapeadora.x != 4) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
					gotoxy(chapeadora.x - 1, chapeadora.y - 1);
					cout << "v" << endl;
					
				}
			}
			chapeadora.x++;
		}

		else {                // Cuando llega al borde se mueve de derecha a izquierda 
			if (cortar == true) {
				
					gotoxy(chapeadora.x + 1, chapeadora.y - 1);
					cout << " " << endl;
					gotoxy(chapeadora.x + 2, chapeadora.y - 1);
					cout << " " << endl;
				
			}
			else {
				
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
					gotoxy(chapeadora.x + 1, chapeadora.y - 1);
					cout << "v" << endl;
					gotoxy(chapeadora.x + 2, chapeadora.y - 1);
					cout << "v" << endl;
				
			}
			chapeadora.x--;
		}

		if (chapeadora.x == 46) {                                                           // Llega al final derecho dela cancha 
			borde_derecha = true;
			chapeadora.x = 43;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
			if (cortar == true) {                                                           // Lo corta
				gotoxy(chapeadora.x + 2, chapeadora.y - 1);
				cout << " " << endl;
			}
			else {                                                                         // Deja el sacate
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				gotoxy(chapeadora.x+ 2, chapeadora.y - 1);
				cout << "v" << endl;
				
			}
			contador++;
			chapeadora.y++;
		}

		if (chapeadora.x == 3 && borde_derecha == true) {                                          // Llega al final izquierdo de la cancha
			borde_derecha = false;
			chapeadora.x = 6;
			if (cortar == true) {                                                                 // Lo corta
				gotoxy(chapeadora.x - 2, chapeadora.y - 1);
				cout << " " << endl;
				
			}
			else {                                                                              // Deja el sacate
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				gotoxy(chapeadora.x - 2, chapeadora.y - 1);
				cout << "v" << endl;
				
			}
			contador++;
			chapeadora.y++;
		}

		if (chapeadora.y == 26) {           // Cuando termina el programa
			return;
		}
		//Sleep(100);
	}
}

void tercer_algoritmo_decorte_diagonal(tico_chapeadora_Tesla chapeadora){}

int main()
{ 
	bool game = true;
	tico_chapeadora_Tesla chapeadora;
	while (game) {
		map();
		primer_algoritmo_decorte_vertical(chapeadora);
		system("cls");
		map();
		segundo_algoritmo_decorte_horizontal(chapeadora);
		system("cls");
		/*map();
		tercer_algoritmo_decorte_diagonal(chapeadora);
		system("cls");*/
	}
}
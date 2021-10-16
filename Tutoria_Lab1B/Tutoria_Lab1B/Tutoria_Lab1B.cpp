// Lab 2 2012.cpp: define el punto de entrada de la aplicaci&#65533;n de consola.
//

#include <iostream>
#include <conio.h>
#include "milibreria.h"
using namespace std;


void main()
{ 
	int opc;
	bool menu = true;
	while (menu) {
		system("CLS");
		cout << " ********* Menu semana 1 *********" << endl << endl;
		cout << "  1. AreaRectangulo(2,6)" << endl;
		cout << "  2. PerimetroRectangulo(2,6,Perim)" << endl;
		cout << "  3. VolumenRectangulo(2,4,6)" << endl;
		cout << "  4. Cierto=EsCuadrado(base, altura)" << endl;
		cout << "  5. Salir" << endl;
		cout << endl << "	Digite la opcion: ";
		cin >> opc;
		switch (opc) {
		case 1: {
			system("CLS");
			cout << "Opcion 1" << endl << endl << endl;
			//Primera funcion
			int Area = AreaRectangulo(2, 6);
			cout << "Area: " << Area << endl;
			system("pause");
			break;
		}
		case 2: {
			system("CLS");
			cout << "Opcion 2" << endl << endl << endl;
			//Segunda Funcion
			int Perim = 0;
			PerimetroRectangulo(2, 6, Perim);
			cout << "Perimetro: " << Perim << endl << endl;
			system("pause");
			break;
		}
		case 3: {
			system("CLS");
			cout << "Opcion 3" << endl << endl << endl;
			//Tercera Funcion
			VolumenRectangulo(2, 4, 6);
			system("pause");
			break;
		}
		case 4: {
			system("CLS");
			cout << "Opcion 4" << endl << endl << endl;
			//Cuarta funcion
			int base = 0;
			int altura = 2;
			cout << "Ingrese la base: " << endl;
			cin >> base;
			printf("Ingrese la altura: ");
			scanf_s("%i", &altura);
			bool Cierto = EsCuadrado(base, altura);
			cout << Cierto << endl;
			system("pause");
			break;
		}
		case 5: {
			menu = false;
			system("CLS");
			cout << "Opcion 5: salir" << endl << endl << endl;
			cout << "Viva e TEC" << endl;
			system("Pause");
			break;
		}
		}
	}
}
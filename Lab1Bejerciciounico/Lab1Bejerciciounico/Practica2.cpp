#include <iostream>
#include <conio.h>
#include "milibreria.h"
using namespace std;

void main()
{
	int opc;
	bool menu = true;
	while (menu) {                                                          // Inicia un bucle para que se siga despegando el menui
		system("CLS");
		cout << " ********* Menu semana 1 *********" << endl << endl;
		cout << "  1. AreaRectangulo(a,b)" << endl;
		cout << "  2. PerimetroRectangulo(a,b,Perim)" << endl;              // Despliega el menu en pantalla 
		cout << "  3. VolumenRectangulo(a,b,c)" << endl;
		cout << "  4. Cierto=EsCuadrado(base, altura)" << endl;
		cout << "  5. Salir" << endl;
		cout << "  6. Suma(a,b)" << endl;
		cout << endl << "	Digite la opcion: ";
		cin >> opc;                                                      // Pregunta por cual opcion el usuario va a elegir
		switch (opc) {
		case 1: {  // Si el usuario elige la primera opcion
			system("CLS");    // Limpia la pantalla de lo anterior
			cout << "Opcion 1" << endl << endl << endl;
			int a;
			int b;
			cin >> a;
			cin >> b;
			//Primera funcion
			int Area = AreaRectangulo(a, b); // Utiliza la primera funcion
			cout << "Area: " << Area << endl;
			system("pause");
			break;
		}
		case 2: {
			system("CLS");
			cout << "Opcion 2" << endl << endl << endl;
			//Segunda Funcion
			int Perim = 0;
			int a;
			int b;
			cin >> a;
			cin >> b;
			PerimetroRectangulo(a, b, Perim);  // Utiliza la segunda funcion
			cout << "Perimetro: " << Perim << endl << endl;
			system("pause");
			break;
		}
		case 3: {
			system("CLS");
			cout << "Opcion 3" << endl << endl << endl;
			int a;
			int b;
			int c;
			cin >> a;
			cin >> b;
			cin >> c;
			//Tercera Funcion
			VolumenRectangulo(a, b, c);  // Utiliza la tercera funcion
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
			cin >> base;               // Pregunta por la base
			printf("Ingrese la altura: ");
			scanf_s("%i", &altura);
			bool Cierto = EsCuadrado(base, altura);  // Hace la cuarta funcion
			cout << Cierto << endl;
			system("pause");
			break;
		}
		case 5: {
			menu = false;
			system("CLS");
			cout << "Opcion 5: salir" << endl << endl << endl;
			cout << "Viva el TEC" << endl;
			system("Pause");
			break;
		}
		case 6:
		{
			system("CLS");
			int num1;
			int num2;
			int resut = 0;
			cin >> num1;
			cin >> num2;
			suma(num1, num2, resut);
			cout << "El resultado es: " << resut << endl;
			system("pause");
		}
		}
	}
}
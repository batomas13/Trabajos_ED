#include <iostream>
#include <conio.h>
using namespace std;

bool EsCuadrado(int base, int altura) {
	if (base == altura) {   // Es la forma de usar if y else
		return true;  // Al ser de tipo bool retorna True o False
	}
	else
	{
		return false;
	}
}

void main()
{
	int base = 0;
	int altura = 2;
	cout << "Ingrese la base: " << endl;
	cin >> base; // es la forma de hacer que el usuario tenga que digitar un digito
	printf("Ingrese la altura: ");
	scanf_s("%i", &altura); // Esto lo que hace es que inserta el dato en donde se especificó
	bool Cierto = EsCuadrado(base, altura);
	cout << Cierto << endl;
	system("pause");
}


/*
Ingrese la base:
5
Ingrese la altura: 2
0
Presione una tecla para continuar . . .

Funcionamiento:
	Lo que hace es primero preguntar al usuario que numeros son los que desea usar y despues analiza si son o no son cuadrados. En este caso al no ser cuadrado retorna un 0 de false
*/

/*
Ingrese la base:
4
Ingrese la altura: 4
1
Presione una tecla para continuar . . .

Funcionamiento:
	Al ser un numero cuadrado retorna un 1 de true
*/
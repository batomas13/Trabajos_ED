#include <iostream>
#include <conio.h>
using namespace std;

void PerimetrosRectangulo(int largo, int ancho, int& perimetro) { // Al ser de tipo void no retorna nada
	perimetro = (2 * largo) + (2 * ancho);
}

void main()
{
	// segunda funcion
	int Perim = 0;
	PerimetrosRectangulo(2, 6, Perim);
	cout << "Perimetro: " << Perim << endl << endl;
	system("pause");
}


/*
Perimetro: 16

Presione una tecla para continuar . . .

Funcionamiento:
	Crea una funcion que hace que uno de sus parametros sea el resultado, sin embargo esta funcion no retorna nada. En el codigo principal imprime el parametro con el resultado
*/
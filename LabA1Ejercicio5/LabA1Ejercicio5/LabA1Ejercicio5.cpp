#include <iostream>
#include <conio.h>
using namespace std;

void VolumenRectangulo(float largo, float ancho, float alto) {
	float Volumen = largo * ancho * alto;
	cout << "El volumen del rectangulo es: " << Volumen << endl; // Al ser un void no retorna nada sin embargo, en este caso imprime el mensaje dentro de la funcion

}

void main()
{
	VolumenRectangulo(2, 4, 6);
	system("pause");
}

/*
El volumen del rectangulo es: 48
Presione una tecla para continuar . . .

Funcionamiento
	En este caso lo que hace es que no retorna nada pero el resultado de la funcion es impreso dentro de la funcion
*/

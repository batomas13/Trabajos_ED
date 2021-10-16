#include <iostream>
#include <conio.h>
using namespace std;
void main()
{
	int a = 2;   // Es la forma de crear variables, en este caso "a" es un int que vale 2
	float b = 3.5; //  En este caso "b" es un float que vale 3.5
	float c = a + b; // en este caso "c" vale "a" + "b"
	cout << "El valor de a + b es: " << c << "centimetros." << endl;
	printf("el valor de a+b es: %f \n", c);
	system("pause");
}

/*
El valor de a + b es: 5.5centimetros.
el valor de a+b es: 5.500000
Presione una tecla para continuar . . .

Funcionamiento:
	En este caso lo que hace es que suma los valores de  a + b y muestra el resultado en pantalla. Además muestr la diferencia entre cout y printf
*/

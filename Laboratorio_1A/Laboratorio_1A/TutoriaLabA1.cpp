#include <iostream>
#include <conio.h>
using namespace std;

int AreaRectangulo(int base, int altura) {  // Es la forma de crear una funcion
	int area = base * altura;   // Para crear una variable se tiene que definir el tipo
	return area;
	// otra forma: return base*altura	
}


void main()
{
	// La forma de llamar las funciones
	int Area = AreaRectangulo(2, 6); // El 2 y el 6 son los parametros
	cout << "Area: " << Area << endl; // cout es una forma de mostrar los datos (es como un print)
	system("pause");
}




/* La forma de mostrar los resultados es la siguiente
Area: 12
Presione una tecla para continuar . . .

*/
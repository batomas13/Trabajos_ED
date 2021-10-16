#include <iostream>
#include <conio.h>
using namespace std;
int AreaRectangulo(int base, int altura) {  // Es la forma de crear funciones (el tipo de dato que retorna la funcion tiene que ser igual al tipo de funcion
	int area = base * altura;
	return area;
	// otra forma: return base*altura

}

void main()
{
	// A continuacion se llaman las funciones
	// Primera funcion
	int Area = AreaRectangulo(2, 6);  // Asi es como se llama a una funcion
	cout << "Area: " << Area << endl;
	system("pause");
}

/*
 Area: 12
Presione una tecla para continuar . . .

C:\Users\tcoto.DESKTOP-QAVAARJ\source\repos\LabA1Ejercicio3\Debug\LabA1Ejercicio3.exe (process 11240) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

Funcionamiento
	En este caso lo que hace es crea una funcion que retorna el area de un rectangulo.
*/

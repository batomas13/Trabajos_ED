#include <iostream>
#include <conio.h>
using namespace std;
struct alumno {
	int carnet;
	char nombre[50];
	char carrera[5];
	bool activo;
};
void main()
{
	const char* carreraq = "IMT";
	const char* Nombreq = "Jose";
	alumno Alumno100[1000];   // Crea una estructura llamada Alumno100 que es un arreglo
	Alumno100[1].activo = 1;  // Al primer dato le agrega el estado de activo
	Alumno100[1].carnet = 201563645;  // y un numero de carnet
	strcpy_s(Alumno100[1].carrera, carreraq);
	strcpy_s(Alumno100[1].nombre, Nombreq);
	cout << "El alumno " << Alumno100[1].nombre << " fue resgistrado con el numero de carnet " << Alumno100[1].carnet << endl;
	cout << "en la carrera " << Alumno100[1].carrera << "." << endl;
	system("pause");
}


/*
El alumno Jose fue resgistrado con el numero de carnet 201563645
en la carrera IMT.
Presione una tecla para continuar . . .

Funcionamiento:
	En este caso se imprime en pantalla el primer dato del una estructura que esta compuesta por un arreglo.
*/


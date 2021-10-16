#include <iostream>
#include <conio.h>
using namespace std;

struct alumno {  //definiendo el tipo de dato 
	int carnet;
	char nombre[50];
	char carrera[5];
	bool activo;
};

void main()
{
	const char* carreraq = "IMT";
	const char* Nombreq = "Jose";
	alumno Alumno100;     //Definiendo la variable como una estructura
	Alumno100.activo = 1;    // A la estructura 
	Alumno100.carnet = 201563645;
	strcpy_s(Alumno100.carrera, carreraq); // Hace que la informacion en carreraq se agregue a la estructura alumno
	strcpy_s(Alumno100.nombre, Nombreq);  // Hace que la informacion en Nombreq se agregue a la estructura alumno
	cout << "El alumno " << Alumno100.nombre << " fue resgistrado con el numero de carnet " << Alumno100.carnet << endl;
	cout << "en la carrera " << Alumno100.carrera << "." << endl;
	system("pause");
}


/*
El alumno Jose fue resgistrado con el numero de carnet 201563645
en la carrera IMT.
Presione una tecla para continuar . . .

Funcionamiento:
	Crea una estructura e imprime los datos dentro de la misma.
*/
#include <iostream> // Para poder utilizar el cout y cin  se ocupa esta linea
#include <conio.h>  
using namespace std;  // Con esta linea se evita tener que escribir stdcout
void main()   // Es lo que c++ va a correr ya que es el main
{
	printf("Hola a todos \n");  // Es la forma de mostrar una salida en c 
	cout << "hola mundo" << endl; // Es la forma de mostrar informacion en c++
	system("pause");                //  Pone una pausa en el programa haciendo que solo se pueda continuar después de que el usuario pulse alguna tecla
}

/*
Hola a todos
hola mundo
Presione una tecla para continuar . . .

C:\Users\tcoto.DESKTOP-QAVAARJ\source\repos\LabA1ejercicio1\Debug\LabA1ejercicio1.exe (process 28372) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

Funcionamiento:
	En este caso lo que hace es que muestra en la pantalla "hola a todos" y "hola mundo"
*/
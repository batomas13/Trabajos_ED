// EstructuraEstatica.cpp : Defines the entry point for the console application.
//

//importa las librerias

#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <conio.h>
using namespace std;

/*esta es la estructura de los datos q poseen los Productos*/
typedef struct T_Producto {
	int Codigo;
	char Descripcion[50];
	float Precio;
	int Disponible;
	bool Activo;
} X;

const int Max = 100000;
int Ultimo = 0;

void CapturarElemento(T_Producto& Pieza) // En esta funcion el parametro es tipo T_Producto
{
	system("CLS");
	cout << "Captura de una Pieza" << endl;
	cout << "" << endl;

	system("CLS");                               // Permite agreagar datos a la estructura T_Producto
	cout << "Captura de una Pieza" << endl;
	cout << "" << endl;
	cout << "CodigoProducto:";
	cin >> Pieza.Codigo;  cout << "" << endl;
	cout << "DescripcionProducto:";
	cin >> Pieza.Descripcion;
	cout << "" << endl;
	cout << "PrecioProducto:";
	cin >> Pieza.Precio;
	cout << "" << endl;
	cout << "DisponibleProducto:";
	cin >> Pieza.Disponible;  cout << "" << endl;
	Pieza.Activo = true;

}

void Listar(T_Producto Inventario[Max]) {
	system("CLS");
	int conta = 0;
	cout << "Listado de  Productos" << endl;
	for (int i = 0; i < Ultimo; i++) {
		if (Inventario[i].Activo) {
			cout << Inventario[i].Codigo << " " << Inventario[i].Descripcion << " " << Inventario[i].Precio << " "   // Muestra en consola la informacion del producto
				<< Inventario[i].Disponible << " " << endl;
			conta++;
			if (conta == 7) {
				cout << "-----------------------------------" << endl;
				cout << "Presione cualquier tecla para continuar..." << endl;
				system("pause");
				system("CLS");

				conta = 0;
			}
		}
	}
	system("pause");
}



int BuscarElemento(T_Producto Inventario[Max], int Cual)
{
	bool Encontro = false;
	int Cont = 0;

	while ((!Encontro) && (Cont < Ultimo))
	{
		if ((Inventario[Cont].Activo == true) && (Inventario[Cont].Codigo == Cual)) // Si encuentra el elemento y está activo
			Encontro = true; // Rompe el bucle 
		else
			Cont++;
	}

	if (Encontro == true)
		return Cont;
	else
		return -1;

}
void InsertarElemento(T_Producto Inventario[Max], T_Producto Unidad)
{
	Inventario[Ultimo] = Unidad; // Agreaga la indormacion al inventario
	Ultimo++;
}

void BorrarElemento(T_Producto Inventario[Max], int Cual)
{
	int PorBorrar;
	PorBorrar = BuscarElemento(Inventario, Cual);  // Variable que busca en el inventario

	if (PorBorrar != -1)
		Inventario[PorBorrar].Activo = false;

}


void main() {

	T_Producto PiezasFerreteria[Max];
	T_Producto Elemento;
	int opcion = 0;

	while (opcion < 4) {          // Imprime el menu en la pantalla 

		system("cls");//limpia la pantalla
		cout << "******Menu principal******" << endl;
		cout << "1. Insertar Pieza" << endl;
		cout << "2. Listar Piezas " << endl;
		cout << "3. Borrar Piezas " << endl;
		cout << "4. Salir " << endl;
		cin >> opcion;//captura el numero introducido

		switch (opcion) {

		case 1:
			system("cls");
			CapturarElemento(Elemento);
			InsertarElemento(PiezasFerreteria, Elemento);
			break;

		case 2:
			system("cls");
			Listar(PiezasFerreteria);
			break;
		case 3:
			system("CLS");
			int CodigoEscogido;
			cout << "Digite el codigo del Producto a Borrar" << endl;
			cout << "" << endl;
			cout << "CodigoProducto:" << endl;
			cin >> CodigoEscogido;
			BorrarElemento(PiezasFerreteria, CodigoEscogido);
			break;

		}
	}
}


/*
Agregar elementos:
	Captura de una Pieza

	CodigoProducto:2

	DescripcionProducto:3

	PrecioProducto:4

	DisponibleProducto:5

Listar Elementos:
	Listado de  Productos
	1 1 1 1
	2 3 4 5
	Presione una tecla para continuar . . .

Borrar elementos
	Digite el codigo del Producto a Borrar

	CodigoProducto:
	1
	Despues de borrarlo y listarlo:
	Listado de  Productos
	2 3 4 5
	Presione una tecla para continuar . . .

Salir
******Menu principal******
1. Insertar Pieza
2. Listar Piezas
3. Borrar Piezas
4. Salir

4

C:\Users\tcoto.DESKTOP-QAVAARJ\source\repos\Coleccion_estatica\Debug\Coleccion_estatica.exe (process 40624) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .


*/
// punteros.cpp : Defines the entry point for the console application.
//


#include <stdio.h>


int main(int argc, char* argv[])
{


	//**********************************************
	int Numero;
	int* PtrNumero;


	Numero = 7;
	PtrNumero = &Numero;      // A PtrNumero se le asigna la direcion de Numero
	*PtrNumero = 33;         // A la direccion de Numero se le asigna el valor de 33
	printf("Numero Resultante %d\n", Numero);
	printf("Numero Resultante %d\n", *PtrNumero);
	//**********************************************

	PtrNumero = new(int);     // Se solicita al sistema operativo la memoria para la variable anonima
	*PtrNumero = 99;         //  A la dirrecion de PtrNumero se le asigna a el valor de 99 
	printf("Numero Resultante %d\n", *PtrNumero);
	//************************************************

	int** Ptr_Ptr_Numero;               // Crea un puntero del puntero
	Ptr_Ptr_Numero = &PtrNumero;       //  A ese puntero se le asigna la direccion del puntero PtrNumero
	**Ptr_Ptr_Numero = 15;            //   A la direccion del puntero Ptr_Ptr_Numero 15
	printf("Numero Resultante %d\n", **Ptr_Ptr_Numero);

	delete(PtrNumero);  //Se libera la memoria reservada x el new para la variable anonima
	//PtrNumero = null;
	//printf("Numero Resultante %d\n", *PtrNumero);
	//************************************************

	typedef struct TPersona
	{
		int Cedula;
		int Carnet;
		float Salario;
		TPersona* Siguiente;
	}x;

	TPersona Funcionario;

	Funcionario.Cedula = 1234567;
	Funcionario.Carnet = 20052;
	Funcionario.Siguiente = new(TPersona);   // Crea un nuevo nodo

	Funcionario.Siguiente->Cedula = 7654321;
	Funcionario.Siguiente->Carnet = 20002;
	Funcionario.Siguiente->Siguiente = new(TPersona);  // Crea un nuevo nodo
	
	printf("Cedula1 %d\n", Funcionario.Cedula);
	printf("Carnet1 %d\n", Funcionario.Carnet);
	printf("Cedula2 %d\n", Funcionario.Siguiente->Cedula);
	printf("Carnet2 %d\n", Funcionario.Siguiente->Carnet);
	delete(Funcionario.Siguiente->Siguiente);//Se libera la memoria reservada x el new para la variable anonima Funcionario.Siguiente
	delete(Funcionario.Siguiente);//Se libera la memoria reservada x el new para la variable anonima Funcionario.Siguiente


	return 0;
}



/*
Numero Resultante 33
Numero Resultante 33
Numero Resultante 99
Numero Resultante 15
Cedula1 1234567
Carnet1 20052
Cedula2 7654321
Carnet2 20002

C:\Users\tcoto.DESKTOP-QAVAARJ\source\repos\1-1 Punteros-Inicio.cpp\Debug\1-1 Punteros-Inicio.cpp.exe (process 41332) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .


*/
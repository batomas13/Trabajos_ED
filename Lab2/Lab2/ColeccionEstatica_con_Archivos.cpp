
// itoa_ejemplo.cpp : Defines the entry point for the console application.
//

#include <stdlib.h>  
#include <string.h>  
#include <stdio.h>
using namespace std;
const int MAX = 100;

int main(void)
{
	char Texto[65];
	int contador;
	for (contador = 0; contador < MAX; contador++)
	{
		_itoa_s(contador, Texto, 65, 10);

		char NombreAutomatico[65] = "Pieza_";
		strcpy_s(NombreAutomatico, 65, Texto);

		printf("Para el entero %d: el texto es  %s\n", contador, Texto);
	}

	system("pause");

}

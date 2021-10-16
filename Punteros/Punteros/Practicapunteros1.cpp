int main() {
	int* Ptr;
	*Ptr = 20;
	delete(Ptr);
	Ptr = new(int);
	*Ptr = 20;
	delete(Ptr);
	*Ptr = 5;
	delete(Ptr);
}
#include <stdio.h>
#include <windows.h>
#include <iostream>






/*
El valor en memoria es : 70
El valor de la variable es : 40
El valor en variable es : 100
El valor en memoria es : -572662307

A PtrEntero2 ser un NULL e igualar PtrEntero1 muestra un error
*/
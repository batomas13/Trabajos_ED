int main() {
	/* Sean las siguientes variables :
	i.VE entera
		ii.Ptr1 y Ptr2 punteros compatibles con enteros
		(pueden apuntar a enteros)
		iii.PtrPtr es un puntero a puntero a entero
	*/
	int VE;
	int* Ptr1;
	int* Ptr2;
	int** PtrPtr;

	// b. A la variable est�tica llamada VE as�gnele 100
	VE = 100;

	// c. Al Ptr1(compatible con enteros) as�gnele la direcci�n de VE
	Ptr1 = &VE;

	// d. Acceda con Ptr2(compatible con enteros) as�enele la ubicaci�n de VE sin usar VE
	Ptr2 = Ptr1;

	//e. Cambie el valor del dato contenido en VE por 999 usando Ptr1
	*Ptr1 = 999;

	// f. Cambie el valor del dato contenido en VE por 444 usando Ptr2
	*Ptr2 = 444;

	// g. Cambie el valor del dato contenido en VE por 666 usando PtrPtr
	PtrPtr = &Ptr1;
	**PtrPtr = 666;

	// h. Cu�l es la diferencia entre * Ptr1 en la	declaraci�n del Puntero y* Ptr1 en el uso del Puntero
	// Son totalmente diferentes, En la declaracion lo que dice es que es de un salto y en el uso del puntero se refiere a la varible asociada.

	//i. Cree una variable an�nima y as�gnela a Ptr2 e inicial�cela con el valor 1000
	Ptr2 = new(int);
	*Ptr2 = 1000;
	//j. Copie el contenido de la variable an�nima a la	variable VE sin usar el identificador VE
	*Ptr1 = *Ptr2;
}
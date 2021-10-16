#include <stdio.h>
#include <windows.h>

int main(int argc, char* argv[])
{

	int tamano_en_bytes_entero;
	int tamano_en_bytes_punteroEntero;
	//****************************************************************************************************************************************************************************************
	//Ejemplo VARIABLE ANONIMA ENTERA**********************************************
	int* PtrNumero;
	//printf("La dirección donde apunta PtrNumero sin inicializar es:  %d\n", PtrNumero);  // Ojo .. si se intenta imprimir el puntero sin inicializar... no compila... da error Pruebelo

	PtrNumero = NULL;
	printf("La dirección donde apunta PtrNumero inicializado en NULL es:    hex %#x  \n", PtrNumero);

	PtrNumero = new(int);//Se solicita al sistema operativo la memoria para la variable anonima
	printf("La dirección donde apunta PtrNumero inicializado hacia la variable anonima es:    hex %#x  \n", PtrNumero);

	tamano_en_bytes_entero = sizeof(*PtrNumero);  // Tamaño que reserva la memoria para la variable que tiene asignada un puntero de tipo entero
	printf("tamano_en_bytes de Entero Anonimo apuntado por PtrNumero es:  %d\n", tamano_en_bytes_entero);

	tamano_en_bytes_punteroEntero = sizeof(PtrNumero);  //  Tamaño de reserava de la memoria para un puntero de tipo entero
	printf("tamano_en_bytes del Puntero a Entero es:  %d\n", tamano_en_bytes_punteroEntero);


	*PtrNumero = 33;  //inicializa el contenido de la variable anonima
	printf("Contenido Entero Anonimo %d\n", *PtrNumero);

	*PtrNumero = 7;  //cambia el contenido la variable anonima
	printf("Contenido Entero Anonimo %d\n", *PtrNumero);

	(*PtrNumero)++;  //incrementa en 1 el contenido de la variable anonima
	printf("Contenido Entero Anonimo %d\n", *PtrNumero);

	*PtrNumero = (*PtrNumero) + 1;  //incrementa en 1 el contenido de la variable anonima; 
	printf("Contenido Entero Anonimo %d\n\n\n", *PtrNumero);


	delete(PtrNumero);//Se libera la memoria reservada x el new para la variable anonima.  La direccion de la V.A. esta referenciada en el contenido del puntero
	PtrNumero = NULL; // de una vez hacemos que el puntero "olvide" donde apuntaba

	//****************************************************************************************************************************************************************************************
	//Ejemplo VARIABLE ANONIMA ENTERA a traves de puntero simple(Puntero a Enter) y de puntero indirecto(Puntero a Puntero a Entero)**********************************************

	int tamano_en_bytes_puntero_punteroEntero;

	int** Ptr_Ptr_Entero; // Sea un puntero que puede solamente apuntar a Puntero a Entero
	Ptr_Ptr_Entero = &PtrNumero; // De una vez apuntamos a la dirección del PtrNumero
	printf("La dirección donde apunta El Ptr_Ptr_Entero inicializado en &PtrNumero es:    hex %#x  \n", Ptr_Ptr_Entero);

	PtrNumero = NULL; // ya fue definido en el ejercicio anterior
	printf("La dirección donde apunta PtrNumero inicializado en NULL es:    hex %#x  \n", PtrNumero);

	PtrNumero = new(int);//Se solicita al sistema operativo la memoria para una nueva variable anonima
	printf("La dirección donde apunta PtrNumero inicializado hacia la variable anonima es:    hex %#x  \n", PtrNumero);

	tamano_en_bytes_puntero_punteroEntero = sizeof(Ptr_Ptr_Entero); // Tamaño en memoria para un puntero del puntero de tipo entero
	printf("tamano_en_bytes del Puntero a Puntero a Entero:  %d\n", tamano_en_bytes_puntero_punteroEntero);


	**Ptr_Ptr_Entero = 33;  //inicializa el contenido de la variable anonima desde 2 punteros atras
	printf("Contenido Entero Anonimo %d\n", **Ptr_Ptr_Entero);

	**Ptr_Ptr_Entero = 7;  //cambia el contenido la variable anonima
	printf("Contenido Entero Anonimo %d\n", **Ptr_Ptr_Entero);

	(**Ptr_Ptr_Entero)++;  //incrementa en 1 el contenido de la variable anonima
	printf("Contenido Entero Anonimo %d\n", **Ptr_Ptr_Entero);

	**Ptr_Ptr_Entero = (**Ptr_Ptr_Entero) + 1;  //incrementa en 1 el contenido de la variable anonima; 
	printf("Contenido Entero Anonimo %d\n\n\n", **Ptr_Ptr_Entero);



	delete(*Ptr_Ptr_Entero);//Se libera la memoria reservada x el new para la variable anonima
	//delete(PtrNumero);//Se libera la memoria reservada x el new para la variable anonima  ... POR QUE ES LO MISMO QUE LA LINEA ANTERIOR??

	//Ejemplo VARIABLE ANONIMA ESTRUCTURA**********************************************

	int tamano_en_bytes_Struct_TPersona;

	typedef struct TPersona
	{
		int Cedula;
		int Carnet;
		float Salario;
		TPersona* Siguiente;
	}x;

	TPersona* Ptr_TPersona;
	int tamano_en_bytes_punteroTPersona;


	tamano_en_bytes_punteroTPersona = sizeof(Ptr_TPersona);  // tamano en bytes de punteroTPersona
	printf("tamano_en_bytes del puntero Ptr_TPersona  es: : %d\n", tamano_en_bytes_punteroTPersona);

	tamano_en_bytes_Struct_TPersona = sizeof(*Ptr_TPersona); // tamano en bytes delñ Struct_TPersona
	printf("tamano_en_bytes de la veriable anonima de tipo Struct TPersona es: : %d\n", tamano_en_bytes_Struct_TPersona);

	Ptr_TPersona = new(TPersona);
	printf("La dirección donde apunta el puntero Ptr_TPersona es:    hex %#x  \n", Ptr_TPersona);

	//**********************************************

	Ptr_TPersona->Cedula = 123456;
	Ptr_TPersona->Carnet = 220817;
	Ptr_TPersona->Salario = 3500;
	Ptr_TPersona->Siguiente = new(TPersona);
	printf("La dirección donde apunta el puntero Ptr_TPersona->Siguiente es:    hex %#x  \n", Ptr_TPersona->Siguiente);
	Ptr_TPersona->Siguiente->Cedula = 654321;
	Ptr_TPersona->Siguiente->Salario = 4000;
	Ptr_TPersona->Siguiente->Carnet = 230817;
	Ptr_TPersona->Siguiente->Siguiente = NULL; // Termina el arreglo
	printf("La dirección donde apunta el puntero Ptr_TPersona->Siguiente->Siguiente es NULL:    hex %#x  \n", Ptr_TPersona->Siguiente->Siguiente);


	printf("Valor de Cedula en el primer elemento :  %d\n", Ptr_TPersona->Cedula);
	printf("Valor del Carnet en el primer elemento :  %d\n", Ptr_TPersona->Carnet);
	printf("Valor de la Cedula en el segundo elemento: %d\n", Ptr_TPersona->Siguiente->Cedula);
	printf("Valor del Carnet en el segundo elemento:  %d\n\n\n", Ptr_TPersona->Siguiente->Carnet);
	delete(Ptr_TPersona->Siguiente);//Se libera la memoria reservada x el new para la variable anonima Funcionario->Siguiente
	delete(Ptr_TPersona);//Se libera la memoria reservada x el new para la variable anonima Funcionario.Siguiente


	return 0;
}



/*
La direcci¾n donde apunta PtrNumero inicializado en NULL es:    hex 0
La direcci¾n donde apunta PtrNumero inicializado hacia la variable anonima es:    hex 0x1396e08
tamano_en_bytes de Entero Anonimo apuntado por PtrNumero es:  4
tamano_en_bytes del Puntero a Entero es:  4
Contenido Entero Anonimo 33
Contenido Entero Anonimo 7
Contenido Entero Anonimo 8
Contenido Entero Anonimo 9


La direcci¾n donde apunta El Ptr_Ptr_Entero inicializado en &PtrNumero es:    hex 0xdffdb8
La direcci¾n donde apunta PtrNumero inicializado en NULL es:    hex 0
La direcci¾n donde apunta PtrNumero inicializado hacia la variable anonima es:    hex 0x1396e08
tamano_en_bytes del Puntero a Puntero a Entero:  4
Contenido Entero Anonimo 33
Contenido Entero Anonimo 7
Contenido Entero Anonimo 8
Contenido Entero Anonimo 9


tamano_en_bytes del puntero Ptr_TPersona  es: : 4
tamano_en_bytes de la veriable anonima de tipo Struct TPersona es: : 16
La direcci¾n donde apunta el puntero Ptr_TPersona es:    hex 0x1396e08
La direcci¾n donde apunta el puntero Ptr_TPersona->Siguiente es:    hex 0x1395830
La direcci¾n donde apunta el puntero Ptr_TPersona->Siguiente->Siguiente es NULL:    hex 0
Valor de Cedula en el primer elemento :  123456
Valor del Carnet en el primer elemento :  220817
Valor de la Cedula en el segundo elemento: 654321
Valor del Carnet en el segundo elemento:  230817

*/

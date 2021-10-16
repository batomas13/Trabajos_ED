// Raizbb.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include "iostream"
#include <stdio.h>


typedef struct NodoBB
{
	int llave;
	NodoBB* HijoIzquierdo;
	NodoBB* HijoDerecho;
}X;


bool Insertar(NodoBB*& Raiz, int cualllave)
{
	if (Raiz == NULL) // Sí estaba vacío creaba un nuevo nodo
	{
		Raiz = new(NodoBB); //nuevo nodo 
		Raiz->llave = cualllave; //El valor de la llave
		Raiz->HijoIzquierdo = NULL;//Crea el hijo izquierdo como null
		Raiz->HijoDerecho = NULL;//Crea el hijo derecho como null
		return true;
	}
	else
	{
		if (cualllave == Raiz->llave) return false;// No permite llaves iguales, por lo que si hay una llave igual no deja crear una nueva igual
		else
			if (cualllave < Raiz->llave) return Insertar(Raiz->HijoIzquierdo, cualllave);//Si la llave nueva es menor que la llave raiz se inserta a la izquierda
			else return Insertar(Raiz->HijoDerecho, cualllave);// Caso contrario se inserta a la derecha
	}
}



void PodarHojas(NodoBB*& Raiz) {
	if (Raiz != NULL) // mientras que la raiz no sea nula elimina todo el arbol
	{
		PodarHojas(Raiz->HijoIzquierdo);// se hace un llamado recursivo y borra el hijo izquierdo
		PodarHojas(Raiz->HijoDerecho);// se hace un llamado recursivo y se borra el hijo derecho
		printf("Borro : %i \n", Raiz->llave);
		delete(Raiz); Raiz = NULL; //borra la raiz
	}
}

NodoBB* Buscar(NodoBB* Raiz, int cualllave) {
	if (Raiz == NULL) {
		return NULL;
	}
	else
	{
		if (cualllave == Raiz->llave) return Raiz;//si la llave concuerda con la raiz o con el nodo, lo retorna
		else
			if (cualllave < Raiz->llave) return Buscar(Raiz->HijoIzquierdo, cualllave);//Si es menor llama la funcion nuevamente para continuar por el nodo izquierdo
			else return Buscar(Raiz->HijoDerecho, cualllave);// caso contrario sigue por el nodo derecho
	}
}

void PreOrdenRID(NodoBB* Raiz) //Recorri preorden RID
{
	if (Raiz != NULL)
	{
		printf("%i  ", Raiz->llave);//Imprime el nodo actual
		PreOrdenRID(Raiz->HijoIzquierdo);//recorre hijo izquierdo e imprime la raiz 
		PreOrdenRID(Raiz->HijoDerecho);//recorre hijo derecho e imprime la raiz 
	}
}

void EnOrdenIRD(NodoBB* Raiz) //Imprime el nodo raiz en Izquierda, Raiz, Derecha
{
	if (Raiz != NULL)
	{
		EnOrdenIRD(Raiz->HijoIzquierdo);
		printf("%i  ", Raiz->llave);
		EnOrdenIRD(Raiz->HijoDerecho);
	}
}
void PosOrdenIDR(NodoBB* Raiz)//Recorre y muestra el nodo en recorrido izquierda, derecha, raiz
{
	if (Raiz != NULL) {
		PosOrdenIDR(Raiz->HijoIzquierdo);
		PosOrdenIDR(Raiz->HijoDerecho);
		printf("%i  ", Raiz->llave);
	}
}





int contar(NodoBB* Raiz, int& contador) {
	if (Raiz != NULL) {
		contador++; //R
		contar(Raiz->HijoIzquierdo, contador); //I
		contar(Raiz->HijoDerecho, contador); //D
	}
	return contador;
}


bool comparar(NodoBB* Raiz1, NodoBB* Raiz2) {
	if (Raiz1 != NULL && Raiz2 != NULL) {
		if (Raiz1->llave == Raiz2->llave) {
			return true && comparar(Raiz1->HijoIzquierdo, Raiz2->HijoIzquierdo) && comparar(Raiz1->HijoDerecho, Raiz2->HijoDerecho);
		}
		else {
			return false;
		}
	}
}



void clonar(NodoBB* Raiz1, NodoBB*& Raiz2) {
	NodoBB* Aux;
	if (Raiz1 != nullptr) {
		Aux = new(NodoBB); // 
		Aux->llave = Raiz1->llave;// 
		Raiz2 = Aux; // R
		
	}

	//clonar(Raiz1->HijoIzquierdo, Raiz2->HijoIzquierdo);  //I

	//clonar(Raiz1->HijoDerecho, Raiz2->HijoDerecho); //D
	}


int hojas(NodoBB* Raiz) {
	if (Raiz->HijoIzquierdo == NULL && Raiz->HijoDerecho == NULL) {
		printf("\n%i", Raiz->llave); //R
		return 1;
	}
	hojas(Raiz->HijoIzquierdo); // I
	hojas(Raiz->HijoDerecho); //D
}

bool completo(NodoBB* Raiz) {
	if (Raiz->HijoIzquierdo != NULL || Raiz->HijoDerecho != NULL) {
		return false;
	}
	completo(Raiz->HijoIzquierdo);
	completo(Raiz->HijoDerecho);
	return true;
}


void DesOrdenDRI(NodoBB* Raiz) {
	if (Raiz != NULL)
	{
		DesOrdenDRI(Raiz->HijoDerecho);//D

		printf("%i  ", Raiz->llave);//R

		DesOrdenDRI(Raiz->HijoIzquierdo);//I
	}
}





void main(int argc, char* argv[]) {
	int contador = 0;
	NodoBB* ArbolEnteros = NULL;
	NodoBB* ArbolEnteros2 = NULL;

	printf("\nINSERTANDO la secuencia de Elementos : 9, 6, 16, 3, 13, 8, 18 ");

	Insertar(ArbolEnteros, 10);
	Insertar(ArbolEnteros, 27);
	Insertar(ArbolEnteros, 29);
	Insertar(ArbolEnteros, 17);
	Insertar(ArbolEnteros, 25);
	Insertar(ArbolEnteros, 21);
	Insertar(ArbolEnteros, 15);
	Insertar(ArbolEnteros, 31);
	Insertar(ArbolEnteros, 13);
	Insertar(ArbolEnteros, 51);
	Insertar(ArbolEnteros, 20);
	Insertar(ArbolEnteros, 24);
	Insertar(ArbolEnteros, 48);
	Insertar(ArbolEnteros, 19);
	Insertar(ArbolEnteros, 60);
	Insertar(ArbolEnteros, 35);
	Insertar(ArbolEnteros, 66);




	Insertar(ArbolEnteros2, 9);
	Insertar(ArbolEnteros2, 6);
	Insertar(ArbolEnteros2, 16);
	Insertar(ArbolEnteros2, 4);
	Insertar(ArbolEnteros2, 13);
	Insertar(ArbolEnteros2, 8);
	Insertar(ArbolEnteros2, 18);


	DesOrdenDRI(ArbolEnteros);

	printf("\n\nRECORIENDO: ");
	printf("\nElementos en recorrido PreOrden: ");
	PreOrdenRID(ArbolEnteros2);

	printf("\nElementos en recorrido EnOrden: ");
	EnOrdenIRD(ArbolEnteros2);

	printf("\nElementos en recorrido PosOrden: ");
	PosOrdenIDR(ArbolEnteros2);


	printf("\nCantidad de Elementos: ");
	printf("%i  ", contar(ArbolEnteros2, contador));

	printf("\nHojas: ");
	hojas(ArbolEnteros2);

    clonar(ArbolEnteros2, ArbolEnteros);
	printf("%i  ", comparar(ArbolEnteros, ArbolEnteros2));
	printf("%i  ", completo(ArbolEnteros));

	printf("\nClonar elementos: ");
	clonar(ArbolEnteros, ArbolEnteros2);


	printf("\nElementos en recorrido EnOrden Arbol2: ");
	EnOrdenIRD(ArbolEnteros2);
	printf("\n\nBUSCANDO 1 x 1 : ");
	NodoBB* Aux;
	if ((Aux = Buscar(ArbolEnteros2, 18)) != NULL) printf("\nBusco %i y encontro %i ", 18, Aux->llave);
	if ((Aux = Buscar(ArbolEnteros2, 8)) != NULL) printf("\nBusco %i y encontro %i ", 8, Aux->llave);
	if ((Aux = Buscar(ArbolEnteros2, 13)) != NULL) printf("\nBusco %i y encontro %i ", 13, Aux->llave);
	if ((Aux = Buscar(ArbolEnteros2, 3)) != NULL) printf("\nBusco %i y encontro %i ", 3, Aux->llave);
	if ((Aux = Buscar(ArbolEnteros2, 16)) != NULL) printf("\nBusco %i y encontro %i ", 16, Aux->llave);
	if ((Aux = Buscar(ArbolEnteros2, 6)) != NULL) printf("\nBusco %i y encontro %i ", 6, Aux->llave);
	if ((Aux = Buscar(ArbolEnteros2, 9)) != NULL) printf("\nBusco %i y encontro %i ", 9, Aux->llave);

	printf("\n\nBUSCANDO ArbolEnteros 2 1 x 1 : ");
	NodoBB* Aux2;
	if ((Aux2 = Buscar(ArbolEnteros2, 18)) != NULL) printf("\nBusco %i y encontro %i ", 18, Aux2->llave);
	if ((Aux2 = Buscar(ArbolEnteros2, 8)) != NULL) printf("\nBusco %i y encontro %i ", 8, Aux2->llave);
	if ((Aux2 = Buscar(ArbolEnteros2, 13)) != NULL) printf("\nBusco %i y encontro %i ", 13, Aux2->llave);
	if ((Aux2 = Buscar(ArbolEnteros2, 3)) != NULL) printf("\nBusco %i y encontro %i ", 3, Aux2->llave);
	if ((Aux2 = Buscar(ArbolEnteros2, 16)) != NULL) printf("\nBusco %i y encontro %i ", 16, Aux2->llave);
	if ((Aux2 = Buscar(ArbolEnteros2, 6)) != NULL) printf("\nBusco %i y encontro %i ", 6, Aux2->llave);
	if ((Aux2= Buscar(ArbolEnteros2, 9)) != NULL) printf("\nBusco %i y encontro %i ", 9, Aux2->llave);

	printf("\n\nBORRANDO TODO ... de las hojas a la Raiz:\n");
	PodarHojas(ArbolEnteros);
	PodarHojas(ArbolEnteros2);
	system("pause");
}


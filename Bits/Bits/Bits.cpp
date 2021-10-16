// Bits.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <stdio.h>
#include <iostream>
using namespace std;
	bool BitEncendido(int Simbolo, int cual){
		int Mascara = 1;
		Mascara = Mascara << cual;
		if ((Simbolo & Mascara) == 0) {
			return false;    // Da 0 lo que significa que la posicion cual estaba en 0
		}
		else {
			return true;	// Da <>0 lo que significa que la posicion cual estaba en 1
		}
	}

	bool BitApagado(int Simbolo, int cual){
		int Mascara = 1;

		Mascara = Mascara << cual;
		
		if ((Simbolo & Mascara) == 0)
			return true; // Da 0 lo que significa que la posicion cual estaba en 0
		else return false;	// Da <>0 lo que significa que la posicion cual estaba en 1

	}

	void EncenderBit(int& Simbolo, int cual){
		int Mascara = 1;
		Mascara = Mascara << cual;   // Cambia el valor de mascara por el que tiene cual
		Simbolo = Simbolo | Mascara;  // cambia el valor de simbolo al multiplicar el valor de mascara por dos
	}


	void ApagarBit(int& Simbolo, int cual){
		int Mascara = 1;
		Mascara = Mascara << cual;  // Cambia el valor de la mascara por el de cual
		Mascara = ~Mascara;  // Convierte el valor de mascara en negativo y le suma -1
		Simbolo = Simbolo & Mascara;   // Controla que no se convierta en mascara
		cout << " " << endl;
	}

	void PinteBits(int Simbolo){
		int Uno = 1;
		int Cero = 0;
		for (int i = 7; i >= 0; --i){
			if (BitEncendido(Simbolo, i)) {  // Si el bit el bit es uno se muestra como uno
				printf("%d ", Uno);
			}
			else {
				printf("%d ", Cero);   // De lo contrario es 0
			}
		}

		printf("\n");
	}

	void InvertirTotalbits(int& Simbolo)
	{
		for (int i = 0; i < 7; i++) {
			int Mascara = 1;
			Mascara = Mascara << i;   // Cambia mascara por el valor de cual
			Simbolo = Simbolo ^ Mascara;  // Invierte el valor de Simbolo
		}
	}

	void Pinte_tablaASCII() {
		for (int i = 0; i <= 255; i++) {
			cout << "Simbolo: " << char(i) << " Codigo Decimal: " << i << " Codigo Binario: ";
			PinteBits(i);
		}
	}

	void InvertirPosicion(int& Numero) {
		int total = 7;
		for (int i = 0; i < 2; i++) {
			if (BitApagado(Numero, total) == true && BitEncendido(Numero, i) == true) {
				EncenderBit(Numero, total);
				ApagarBit(Numero, i);
				break;
			}
			if (BitApagado(Numero, i) == true && BitEncendido(Numero, total) == true) {
				EncenderBit(Numero, i);
				ApagarBit(Numero, total);
				break;
			}
			total -= 1;
		} 
	}

	int main(int argc, char* argv[])
	{
	
		Pinte_tablaASCII();
		//int j;

		//for (j = 0; j <= 7; j++)
		//{
		//	printf("%s \n", "------------------");
		//	EncenderBit(Prueba, j);       // Enciende el Bit en la posicion "j"
		//	printf("%d :", Prueba); PinteBits(Prueba);
		//	ApagarBit(Prueba, j);		// Apaga el Bit en la posicion "j"
		//	printf("%d :", Prueba); PinteBits(Prueba);//Queda en 0 porque apago el Bit encendido.
		//}

		//for (j = 0; j <= 255; j++)
		//{
		//	printf("Numero %d : ", j);
		//	PinteBits(j);   // Imprime j en binario
		//}
		/*Prueba = 0;
		PinteBits(Prueba);
		
		PinteBits(Prueba);*/
		return 0;
	}
	



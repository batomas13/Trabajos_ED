// Lectura-Escritura-Archivos-C-xBytes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

// Lectura-Escritura-Archivos-C-xBytes.cpp: define el punto de entrada de la aplicación de consola.
//


#include <stdio.h>
#include <iostream>
#include <string.h>




void InvertirBit(char& Simbolo, int cual)
{
	int Mascara = 1;

	Mascara = Mascara << cual;
	Simbolo = Simbolo ^ Mascara;
}



// A continuaci'on se definen los metodos Veneno_X y Antidoto_X que serviran para Encriptar y Desencriptar el archivo procesado 
// Ojo X puede ser 1,2,3,4...  y siempre el antidoto debera corresponder al veneno.  En este ejemplo solo se usa el 1
void Veneno_1(char Bloque[1000], int limite)
{
	int i;
	int posicion_a_invertir = 0;

	for (i = 0; i <= limite; i++) {
		InvertirBit(Bloque[i], posicion_a_invertir);
	}
}

void Antidoto_1(char Bloque[1000], int limite)
{
	int i;
	int posicion_a_invertir = 0;

	for (i = 0; i <= limite; i++) {
		InvertirBit(Bloque[i], posicion_a_invertir);
	}
}

void Veneno_2(char Bloque[1000], int limite)
{
	int pos = 0;
	for (int i = 0; i < limite; i++) {
		int Mascara = 1;
		Mascara = Mascara << pos;     // Se selecciona la posicion
		Mascara = ~Mascara;           // Se niega la mascara 
		Bloque[i] = Bloque[i] ^ Mascara;
	}
}

void Antidoto_2(char Bloque[1000], int limite)
{
	int pos = 0;
	for (int i = 0; i < limite; i++) {
		int Mascara = 1;
		Mascara = Mascara << pos;
		Mascara = ~Mascara;
		Bloque[i] = Bloque[i] ^ Mascara;
	}
}

void Veneno_3(char Bloque[1000], int limite)
{
	int pos = 0;
	for (int i = 0; i < limite; i++) {
		int Mascara = 1;
		Mascara = Mascara >> pos;     // Se selecciona la posicion haciendo un shift a la derecha
		Mascara = ~Mascara;           // Se niega la mascara 
		Bloque[i] = Bloque[i] ^ Mascara;
	}
}

void Antidoto_3(char Bloque[1000], int limite)
{
	int pos = 0;
	for (int i = 0; i < limite; i++) {
		int Mascara = 1;
		Mascara = Mascara >> pos;     
		Mascara = ~Mascara;           
		Bloque[i] = Bloque[i] ^ Mascara;
	}
}

void Veneno_4(char Bloque[1000], int limite)
{
	int pos = 0;
	for (int i = 0; i < limite; i++) {
		int Mascara = 1;
		Mascara = Mascara >> pos;     // Se selecciona la posicion haciendo un shift a la derecha
		Bloque[i] = Bloque[i] ^ Mascara;
	}
}
 
void Antidoto_4(char Bloque[1000], int limite)
{
	int pos = 0;
	for (int i = 0; i < limite; i++) {
		int Mascara = 1;
		Mascara = Mascara >> pos;     
		Bloque[i] = Bloque[i] ^ Mascara;
	}
}

void Veneno_5(char Bloque[1000], int limite)
{
	int pos = 0;
	int lim = 999;
	for (int i = 0; i < ((limite/2) - 1); i++) {  
		int Mascara = 1;
		Mascara = Mascara << pos;     // Se selecciona la posicion haciendo un shift a la derecha
		int Mascara_2 = 1;
		Mascara_2 = Mascara_2 << lim;  // Masacara_2 toma la posicion del lim
		Mascara_2 = ~Mascara_2;        // Se niega
		Bloque[i] = Bloque[i] ^ Mascara_2;   // Se utiliza la mascara de la posicion mas atras
		Bloque[lim] = Bloque[lim] ^ Mascara; // Se utiliza la mascara del pisicion mas adelante
		lim--;
	}
}

void Antidoto_5(char Bloque[1000], int limite)
{
	int pos = 0;
	int lim = 999;
	for (int i = 0; i < ((limite / 2) - 1); i++) {
		int Mascara = 1;
		Mascara = Mascara << pos;     
		int Mascara_2 = 1;
		Mascara_2 = Mascara_2 << lim;
		Mascara_2 = ~Mascara_2;
		Bloque[i] = Bloque[i] ^ Mascara_2;
		Bloque[lim] = Bloque[lim] ^ Mascara;
		lim--;
	}
}
using namespace std;
int main(int argc, char* argv[]) {

	//----------------------------------------------------------------------
	// Pintando a pantalla los argumentos que recibe el programa :  Se esperan en esta prueba 3: 
	// Ejecutable e/d FileOrigen FileDestino
	// e/d = e=encritar   d=desencriptar


	for (int i = 0; i < argc; ++i) {
		cout << "argumento " << i << ": " << argv[i] << "\n";
	}
	//----------------------------------------------------------------------

	// Archivos logicos : Buffers tipo FILE
	FILE* ArchivoOrigen, * ArchivoDestino;

	//----------------------------------------------------------------------
	// APERTURA DE ARCHIVO FUENTE Y DESTINO
	/* Apertura del archivo original, para lectura en binario*/
	fopen_s(&ArchivoOrigen, argv[2], "rb");
	if (ArchivoOrigen == NULL)
	{
		perror("No se puede abrir archivo origen ");//, argv[2]
		return -1;
	}

	/* Apertura del archivo destino, para escritura en binario*/
	fopen_s(&ArchivoDestino, argv[3], "wb");
	if (ArchivoDestino == NULL)
	{
		perror("No se puede abrir archivo destino"); // , argv[2]
		return -1;
	}

	//----------------------------------------------------------------------
	// PROCESAMIENTO DE ARCHIVOS FUENTE Y DESTINO

	/* Bloque de 1000 bytes, para meter lo que vamos leyendo del archivo */
	char buffer[1000];
	/* Para guardar el número de items leidos o si ha habido error */
	int leidos;
	char opcion = argv[1][0]; // (strcmp(opcion, 'e')
	if (opcion == 'e') // Da verdadero si se quiere "e"ncriptar, cualquier otro es desencriptar
	{  // ENCRIPTANDO

		leidos = fread(buffer, 1, 1000, ArchivoOrigen);

		/* Mientras se haya leido algo ... */
		while (leidos > 0)
		{

			Veneno_5(buffer, leidos); // Ojo esta usando el mismo metodo de desencriptar ya que solo INVIERTE el Bit 0

			/* ... meterlo en el fichero destino */
			fwrite(buffer, 1, leidos, ArchivoDestino);

			/* y leer siguiente bloque */
			leidos = fread(buffer, 1, 1000, ArchivoOrigen);
		}
	}
	else // DESENCRIPTANDO
	{
		leidos = fread(buffer, 1, 1000, ArchivoOrigen);

		/* Mientras se haya leido algo ... */
		while (leidos > 0)
		{

			Antidoto_5(buffer, leidos); // Ojo esta usando el mismo metodo de encriptar ya que solo INVIERTE el Bit 0

			/* ... meterlo en el fichero destino */
			fwrite(buffer, 1, leidos, ArchivoDestino);

			/* y leer siguiente bloque */
			leidos = fread(buffer, 1, 1000, ArchivoOrigen);
		}
	}



	fclose(ArchivoOrigen);
	fclose(ArchivoDestino);

	// Terminamos .. vaya a ver como quedo el archivo Encriptado o Desencriptado.. no olvide manejar estos nombre 
	// en Proyecto->Propiedades->Depuracion->Argumentos 
	// Ejemplo de parametros ... ojo el parametro "0" es el nombre del ejecutable, el parametro 1 es "e" o "d" 
	// el parametro 2 es el archivoOrigen y el parmetro 3 es el archivo destino  
	// Lectura-Escritura-Archivos-C-xBytes.exe e MiFotoOriginal.jpg MiFotoEncriptada.enc
	// Lectura-Escritura-Archivos-C-xBytes.exe d MiFotoEncriptada.enc MiFotoOriginal-restaurada.jpg
	// 

}


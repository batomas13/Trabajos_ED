#include <iostream>
#include <conio.h>
using namespace std;

int AreaRectangulo(int base, int altura) {
	int area = base * altura;
	return area;
	// otra forma: return base*altura;
}
void PerimetroRectangulo(int largo, int ancho, int& Perimetro) {
	Perimetro = (2 * largo) + (2 * ancho);
}
void VolumenRectangulo(float largo, float ancho, float alto) {
	float Volumen = largo * ancho * alto;
	cout << "El volumen del rectangulo es: " << Volumen << endl;
}
bool EsCuadrado(int base, int altura) {
	if (base == altura) {
		return true;
	}
	else {
		return false;
	}
}
int suma(int num1, int num2, int& result)
{
	result = num1 + num2;
	return result;
}
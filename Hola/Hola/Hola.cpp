#include <iostream>
using namespace std;

// Define la extensión máxima del arreglo
#define CANTIDAD_MAXIMA_SUMAR 100

struct celda // Estructura que usamos para definir las celdas
{
    int fila;
    int columna;
    int valor;

};

// Estructura que utilizamos para poder generar los valores de las celdas mediante sumas

struct sumas {
    int fila;
    int columna;
    celda celdasASumar[CANTIDAD_MAXIMA_SUMAR];
    int resultado;
    int tamanyoArreglo;
};

// Función para procesar el SpreedSheet

void procesarSpreadSheet(sumas celdasConSuma[], int pCantidadSumas) {

    int acumulador = 0; // Variable acumulador

    for (int i = 0; i < pCantidadSumas; i++) {  // Recorre cada celda que no ha sido procesada
        for (int x = 0; x < celdasConSuma[i].tamanyoArreglo; x++) { // Recorre cada celda la cúal la sumará para otorgar el valor
            acumulador += celdasConSuma[i].celdasASumar[x].valor; // Se añaden los valores a la variable acumulador
        }
        celdasConSuma[i].resultado = acumulador; // Definimos el resultado como el acumulador
        cout << "El valor de la celda " << celdasConSuma[i].columna << " , " << celdasConSuma[i].fila << " es: " << celdasConSuma[i].resultado << "\n"; // Imprimimos el resultado
        acumulador = 0; // Reiniciamos el acumulador y volvemos a repetir el proceso
    }
}

int main() {

    celda celdas[2]; // Celdas creadas

    celdas[0].columna = 5;
    celdas[0].fila = 7;
    celdas[0].valor = 7;

    celdas[1].columna = 3;
    celdas[1].fila = 5;
    celdas[1].valor = 2;

    celdas[2].columna = 9;
    celdas[2].fila = 11;
    celdas[2].valor = 3;

    sumas celdasSuma[2]; // Celdas las cuales necesitan ser procesadas para otorgarles el valor

    celdasSuma[0].columna = 14;
    celdasSuma[0].fila = 2;
    celdasSuma[0].resultado;
    celdasSuma[0].celdasASumar[0] = celdas[0];
    celdasSuma[0].celdasASumar[1] = celdas[1];
    celdasSuma[0].tamanyoArreglo = 2;

    celdasSuma[1].columna = 6;
    celdasSuma[1].fila = 8;
    celdasSuma[1].resultado;
    celdasSuma[1].celdasASumar[0] = celdas[0];
    celdasSuma[1].celdasASumar[1] = celdas[1];
    celdasSuma[1].celdasASumar[2] = celdas[2];
    celdasSuma[1].tamanyoArreglo = 3;

    celdasSuma[2].columna = 7;
    celdasSuma[2].fila = 1;
    celdasSuma[2].resultado;
    celdasSuma[2].celdasASumar[0] = celdas[1];
    celdasSuma[2].celdasASumar[1] = celdas[2];
    celdasSuma[2].tamanyoArreglo = 2;


    procesarSpreadSheet(celdasSuma, 3); // Llamamos a la función que procesa la funciones

    return 0;

}


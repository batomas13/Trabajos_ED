// Pila_Cola_ T_ArticuloDinamico.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
typedef struct T_ArticuloDinamico {
    int precio;
    int llaves;
    T_ArticuloDinamico* siguiente;
}*PtrT_ArticuloDinamico;

void push(PtrT_ArticuloDinamico& lista, PtrT_ArticuloDinamico articulo) {
    articulo->siguiente = lista;
    lista = articulo;
}

PtrT_ArticuloDinamico top(PtrT_ArticuloDinamico& lista) {
    return lista;
}

PtrT_ArticuloDinamico pop(PtrT_ArticuloDinamico &lista) {
    PtrT_ArticuloDinamico aux = lista;
    lista = lista->siguiente;
    aux->siguiente = NULL;
    return aux;
}


PtrT_ArticuloDinamico Crear(int precio, int llaves) {
    PtrT_ArticuloDinamico articulo = new(T_ArticuloDinamico);
    articulo->llaves = llaves;
    articulo->precio = precio;
    articulo->siguiente = NULL;
    return articulo;
}

void encolar(PtrT_ArticuloDinamico& lista, PtrT_ArticuloDinamico articulo) {
    PtrT_ArticuloDinamico Aux;
    Aux = lista;
    if (Aux != NULL)
    {
        while (Aux->siguiente != NULL)
        {
            Aux = Aux->siguiente;
        }
        Aux->siguiente = articulo;
    }
    else
    {
        lista = articulo;
    }
}

PtrT_ArticuloDinamico primero(PtrT_ArticuloDinamico & lista) {
        return lista;

}

PtrT_ArticuloDinamico descolar(PtrT_ArticuloDinamico& lista) {
    PtrT_ArticuloDinamico aux = lista;
    lista = lista->siguiente;
    aux->siguiente = NULL;
    return  aux;
}





int main(){
    PtrT_ArticuloDinamico dinamico;
    PtrT_ArticuloDinamico Nuevo1;


    // Pila
    dinamico = NULL;
    for (int i = 5; i <= 15; i+=2) {
        Nuevo1 = Crear(1, i);
        push(dinamico, Nuevo1);
    }
    cout << top(dinamico)->llaves << endl;
    for (int i = 0; i < 3; i++) {
        PtrT_ArticuloDinamico Aux = pop(dinamico);
        if (top(dinamico) != NULL)
            cout << "El top es: " << endl << top(dinamico)->llaves << endl;
    }
    cout << top(dinamico)->llaves << endl;
    Nuevo1 = Crear(1, 1);
    push(dinamico, Nuevo1);
    Nuevo1 = Crear(1, 3);
    push(dinamico, Nuevo1);
    Nuevo1 = Crear(1, 17);
    push(dinamico, Nuevo1);
    for (int i = 0; i < 5; i++) {
        PtrT_ArticuloDinamico Aux = pop(dinamico);
        if (top(dinamico) != NULL)
            cout << "El top es: " << endl << top(dinamico)->llaves << endl;
    }
   
    // Cola
    dinamico = NULL;
    for (int i = 5; i <= 15; i += 2) {
        Nuevo1 = Crear(1, i);
        encolar(dinamico, Nuevo1);
    }
    cout << primero(dinamico)->llaves << endl;
    for (int i = 0; i < 3; i++) {
        PtrT_ArticuloDinamico Aux = descolar(dinamico);
        if (primero(dinamico) != NULL)
            cout << "El primero es: " << endl << primero(dinamico)->llaves << endl;
    }
    cout << primero(dinamico)->llaves << endl;
    Nuevo1 = Crear(1, 1);
    encolar(dinamico, Nuevo1);
    Nuevo1 = Crear(1, 3);
    encolar(dinamico, Nuevo1);
    Nuevo1 = Crear(1, 17);
    encolar(dinamico, Nuevo1);
    for (int i = 0; i < 5; i++) {
        PtrT_ArticuloDinamico Aux = descolar(dinamico);
        if (primero(dinamico) != NULL)
            cout << "El primero es: " << endl << primero(dinamico)->llaves << endl;
    }


}



/*
3.Pila:
15
El top es:
13
El top es:
11
El top es:
9
9
El top es:
3
El top es:
1
El top es:
9
El top es:
7
El top es:
5


3.Cola:
5
El primero es:
7
El primero es:
9
El primero es:
11
11
El primero es:
13
El primero es:
15
El primero es:
1
El primero es:
3
El primero es:
17

*/

// Operaciones_Dinamicas.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
typedef struct T_Alumnos {
	int Carnet;
	int Edad;
	T_Alumnos* PtrSiguiente;
}*PtrT_Alumnos;


int main(){
	PtrT_Alumnos ListaV;
	ListaV = NULL;
	for (int i = 0; i < 500; i++) {
		PtrT_Alumnos Aux = new (T_Alumnos);
		Aux->PtrSiguiente = ListaV;
		ListaV = Aux;
		ListaV->Carnet = rand() % 100;
		ListaV->Edad = rand() % 100;
	}
	PtrT_Alumnos Aux;
	Aux = ListaV;
	int inicio = time(NULL);
	while (Aux != NULL) {
		cout << "Carnet: " << Aux->Carnet << " Edad: " << Aux->Edad << endl;
		Aux = Aux->PtrSiguiente;
	}
	int final = time(NULL);
	cout << "El tiempo fue: " << difftime(final, inicio)  << endl;
	system("pause");
	Aux = ListaV;
	while (Aux != NULL) {
		if (Aux->Edad < 17) {
			cout << "Menos de 17: " << "Carntet: " << Aux->Carnet << endl;
		}
		if (17 <= Aux->Edad < 22) {
			cout << "Entre 17 y 22: " << "Carntet: " << Aux->Carnet << " " << endl;
		}
		if (22 <= Aux->Edad <= 25) {
			cout << "Entre 22 y 27: " << "Carntet: " << Aux->Carnet << " " << endl;
		}
		if (Aux->Edad >= 26) {
			cout << "Carnet de oro: " << "Carntet: " << Aux->Carnet << " " << endl;
		}
		Aux = Aux->PtrSiguiente;
	}
}

/*
* Pruebas
* Cargar los datos y mostrar el tiempo:
* Carnet: 16 Edad: 49
Carnet: 86 Edad: 80
Carnet: 9 Edad: 93
Carnet: 50 Edad: 98
Carnet: 76 Edad: 29
Carnet: 68 Edad: 25
Carnet: 53 Edad: 95
Carnet: 33 Edad: 67
Carnet: 74 Edad: 71
Carnet: 71 Edad: 85
Carnet: 78 Edad: 0
Carnet: 28 Edad: 84
Carnet: 23 Edad: 63
Carnet: 41 Edad: 90
Carnet: 13 Edad: 8
Carnet: 56 Edad: 89
Carnet: 77 Edad: 32
Carnet: 73 Edad: 88
Carnet: 10 Edad: 98
Carnet: 15 Edad: 79
Carnet: 51 Edad: 41
Carnet: 80 Edad: 15
Carnet: 84 Edad: 74
Carnet: 85 Edad: 10
Carnet: 82 Edad: 54
Carnet: 12 Edad: 88
Carnet: 30 Edad: 39
Carnet: 55 Edad: 15
Carnet: 17 Edad: 15
Carnet: 71 Edad: 64
Carnet: 58 Edad: 0
Carnet: 37 Edad: 69
Carnet: 15 Edad: 69
Carnet: 59 Edad: 93
Carnet: 8 Edad: 61
Carnet: 61 Edad: 34
Carnet: 37 Edad: 10
Carnet: 22 Edad: 38
Carnet: 98 Edad: 89
Carnet: 85 Edad: 13
Carnet: 4 Edad: 92
Carnet: 45 Edad: 81
Carnet: 71 Edad: 3
Carnet: 8 Edad: 19
Carnet: 78 Edad: 59
Carnet: 31 Edad: 69
Carnet: 2 Edad: 23
Carnet: 74 Edad: 20
Carnet: 82 Edad: 53
Carnet: 89 Edad: 48
Carnet: 2 Edad: 61
Carnet: 43 Edad: 9
Carnet: 3 Edad: 76
Carnet: 61 Edad: 64
Carnet: 50 Edad: 55
Carnet: 18 Edad: 58
Carnet: 0 Edad: 80
Carnet: 9 Edad: 28
Carnet: 17 Edad: 13
Carnet: 48 Edad: 24
Carnet: 3 Edad: 56
Carnet: 3 Edad: 34
Carnet: 33 Edad: 54
Carnet: 8 Edad: 62
Carnet: 16 Edad: 52
Carnet: 93 Edad: 53
Carnet: 62 Edad: 34
Carnet: 90 Edad: 50
Carnet: 37 Edad: 86
Carnet: 25 Edad: 11
Carnet: 30 Edad: 41
Carnet: 15 Edad: 31
Carnet: 82 Edad: 55
Carnet: 36 Edad: 38
Carnet: 56 Edad: 52
Carnet: 14 Edad: 94
Carnet: 36 Edad: 41
Carnet: 65 Edad: 36
Carnet: 75 Edad: 93
Carnet: 26 Edad: 12
Carnet: 4 Edad: 5
Carnet: 73 Edad: 29
Carnet: 26 Edad: 6
Carnet: 48 Edad: 72
Carnet: 42 Edad: 96
Carnet: 75 Edad: 13
Carnet: 64 Edad: 42
Carnet: 84 Edad: 15
Carnet: 49 Edad: 96
Carnet: 55 Edad: 1
Carnet: 11 Edad: 25
Carnet: 18 Edad: 26
Carnet: 44 Edad: 55
Carnet: 57 Edad: 66
Carnet: 23 Edad: 59
Carnet: 24 Edad: 48
Carnet: 53 Edad: 29
Carnet: 85 Edad: 38
Carnet: 35 Edad: 26
Carnet: 36 Edad: 83
Carnet: 48 Edad: 67
Carnet: 30 Edad: 20
Carnet: 49 Edad: 43
Carnet: 46 Edad: 90
Carnet: 54 Edad: 88
Carnet: 21 Edad: 58
Carnet: 8 Edad: 60
Carnet: 88 Edad: 42
Carnet: 49 Edad: 81
Carnet: 9 Edad: 63
Carnet: 43 Edad: 37
Carnet: 47 Edad: 88
Carnet: 28 Edad: 43
Carnet: 15 Edad: 65
Carnet: 0 Edad: 69
Carnet: 23 Edad: 27
Carnet: 1 Edad: 3
Carnet: 70 Edad: 63
Carnet: 52 Edad: 87
Carnet: 32 Edad: 72
Carnet: 1 Edad: 23
Carnet: 18 Edad: 70
Carnet: 45 Edad: 8
Carnet: 65 Edad: 40
Carnet: 89 Edad: 44
Carnet: 19 Edad: 85
Carnet: 69 Edad: 62
Carnet: 46 Edad: 78
Carnet: 45 Edad: 12
Carnet: 13 Edad: 75
Carnet: 71 Edad: 64
Carnet: 84 Edad: 48
Carnet: 98 Edad: 47
Carnet: 3 Edad: 22
Carnet: 75 Edad: 39
Carnet: 50 Edad: 5
Carnet: 18 Edad: 32
Carnet: 91 Edad: 4
Carnet: 19 Edad: 13
Carnet: 64 Edad: 42
Carnet: 89 Edad: 40
Carnet: 10 Edad: 71
Carnet: 6 Edad: 63
Carnet: 21 Edad: 63
Carnet: 4 Edad: 3
Carnet: 87 Edad: 47
Carnet: 98 Edad: 70
Carnet: 75 Edad: 86
Carnet: 27 Edad: 84
Carnet: 70 Edad: 28
Carnet: 92 Edad: 59
Carnet: 24 Edad: 1
Carnet: 13 Edad: 92
Carnet: 15 Edad: 83
Carnet: 1 Edad: 77
Carnet: 13 Edad: 74
Carnet: 29 Edad: 40
Carnet: 67 Edad: 41
Carnet: 61 Edad: 27
Carnet: 49 Edad: 56
Carnet: 92 Edad: 97
Carnet: 75 Edad: 8
Carnet: 3 Edad: 29
Carnet: 64 Edad: 81
Carnet: 92 Edad: 5
Carnet: 35 Edad: 59
Carnet: 44 Edad: 58
Carnet: 51 Edad: 40
Carnet: 53 Edad: 14
Carnet: 90 Edad: 45
Carnet: 97 Edad: 89
Carnet: 85 Edad: 90
Carnet: 40 Edad: 88
Carnet: 69 Edad: 31
Carnet: 12 Edad: 95
Carnet: 17 Edad: 32
Carnet: 18 Edad: 10
Carnet: 75 Edad: 72
Carnet: 40 Edad: 13
Carnet: 96 Edad: 73
Carnet: 52 Edad: 43
Carnet: 24 Edad: 78
Carnet: 11 Edad: 77
Carnet: 42 Edad: 62
Carnet: 55 Edad: 55
Carnet: 13 Edad: 41
Carnet: 81 Edad: 0
Carnet: 62 Edad: 48
Carnet: 76 Edad: 5
Carnet: 56 Edad: 93
Carnet: 37 Edad: 34
Carnet: 93 Edad: 34
Carnet: 79 Edad: 1
Carnet: 50 Edad: 98
Carnet: 5 Edad: 83
Carnet: 26 Edad: 34
Carnet: 21 Edad: 70
Carnet: 59 Edad: 25
Carnet: 41 Edad: 75
Carnet: 54 Edad: 11
Carnet: 23 Edad: 42
Carnet: 75 Edad: 38
Carnet: 67 Edad: 48
Carnet: 11 Edad: 35
Carnet: 7 Edad: 83
Carnet: 32 Edad: 63
Carnet: 57 Edad: 69
Carnet: 54 Edad: 72
Carnet: 84 Edad: 34
Carnet: 53 Edad: 62
Carnet: 96 Edad: 55
Carnet: 59 Edad: 32
Carnet: 29 Edad: 65
Carnet: 23 Edad: 29
Carnet: 85 Edad: 41
Carnet: 17 Edad: 96
Carnet: 17 Edad: 12
Carnet: 96 Edad: 22
Carnet: 69 Edad: 61
Carnet: 37 Edad: 71
Carnet: 26 Edad: 57
Carnet: 26 Edad: 57
Carnet: 56 Edad: 16
Carnet: 23 Edad: 85
Carnet: 72 Edad: 50
Carnet: 35 Edad: 56
Carnet: 11 Edad: 4
Carnet: 5 Edad: 40
Carnet: 93 Edad: 84
Carnet: 60 Edad: 28
Carnet: 1 Edad: 50
Carnet: 13 Edad: 87
Carnet: 77 Edad: 8
Carnet: 57 Edad: 24
Carnet: 3 Edad: 60
Carnet: 58 Edad: 39
Carnet: 77 Edad: 0
Carnet: 65 Edad: 7
Carnet: 58 Edad: 78
Carnet: 0 Edad: 13
Carnet: 62 Edad: 29
Carnet: 40 Edad: 51
Carnet: 88 Edad: 63
Carnet: 90 Edad: 24
Carnet: 53 Edad: 20
Carnet: 11 Edad: 47
Carnet: 11 Edad: 71
Carnet: 30 Edad: 26
Carnet: 2 Edad: 16
Carnet: 64 Edad: 60
Carnet: 95 Edad: 25
Carnet: 37 Edad: 61
Carnet: 23 Edad: 96
Carnet: 2 Edad: 62
Carnet: 23 Edad: 20
Carnet: 29 Edad: 28
Carnet: 25 Edad: 27
Carnet: 77 Edad: 74
Carnet: 65 Edad: 87
Carnet: 82 Edad: 86
Carnet: 64 Edad: 9
Carnet: 43 Edad: 58
Carnet: 76 Edad: 27
Carnet: 70 Edad: 15
Carnet: 10 Edad: 57
Carnet: 60 Edad: 26
Carnet: 0 Edad: 87
Carnet: 19 Edad: 52
Carnet: 18 Edad: 64
Carnet: 51 Edad: 84
Carnet: 78 Edad: 93
Carnet: 71 Edad: 66
Carnet: 58 Edad: 2
Carnet: 76 Edad: 94
Carnet: 19 Edad: 25
Carnet: 95 Edad: 24
Carnet: 40 Edad: 94
Carnet: 85 Edad: 50
Carnet: 96 Edad: 67
Carnet: 11 Edad: 60
Carnet: 35 Edad: 33
Carnet: 70 Edad: 70
Carnet: 13 Edad: 74
Carnet: 87 Edad: 60
Carnet: 64 Edad: 0
Carnet: 22 Edad: 86
Carnet: 92 Edad: 42
Carnet: 25 Edad: 31
Carnet: 5 Edad: 93
Carnet: 3 Edad: 32
Carnet: 61 Edad: 81
Carnet: 23 Edad: 72
Carnet: 43 Edad: 24
Carnet: 27 Edad: 25
Carnet: 2 Edad: 99
Carnet: 13 Edad: 27
Carnet: 2 Edad: 80
Carnet: 92 Edad: 85
Carnet: 63 Edad: 68
Carnet: 73 Edad: 70
Carnet: 18 Edad: 77
Carnet: 87 Edad: 97
Carnet: 33 Edad: 70
Carnet: 72 Edad: 59
Carnet: 34 Edad: 74
Carnet: 14 Edad: 24
Carnet: 77 Edad: 14
Carnet: 2 Edad: 25
Carnet: 58 Edad: 91
Carnet: 87 Edad: 5
Carnet: 68 Edad: 18
Carnet: 74 Edad: 22
Carnet: 86 Edad: 13
Carnet: 45 Edad: 49
Carnet: 54 Edad: 10
Carnet: 53 Edad: 24
Carnet: 92 Edad: 39
Carnet: 44 Edad: 59
Carnet: 73 Edad: 66
Carnet: 35 Edad: 50
Carnet: 29 Edad: 61
Carnet: 96 Edad: 22
Carnet: 81 Edad: 44
Carnet: 46 Edad: 82
Carnet: 21 Edad: 58
Carnet: 13 Edad: 56
Carnet: 32 Edad: 45
Carnet: 12 Edad: 8
Carnet: 85 Edad: 53
Carnet: 13 Edad: 55
Carnet: 86 Edad: 63
Carnet: 16 Edad: 71
Carnet: 14 Edad: 1
Carnet: 55 Edad: 34
Carnet: 88 Edad: 82
Carnet: 86 Edad: 5
Carnet: 97 Edad: 16
Carnet: 93 Edad: 95
Carnet: 66 Edad: 49
Carnet: 49 Edad: 37
Carnet: 87 Edad: 29
Carnet: 79 Edad: 96
Carnet: 39 Edad: 23
Carnet: 18 Edad: 53
Carnet: 45 Edad: 60
Carnet: 41 Edad: 12
Carnet: 34 Edad: 49
Carnet: 25 Edad: 55
Carnet: 68 Edad: 92
Carnet: 76 Edad: 29
Carnet: 21 Edad: 89
Carnet: 69 Edad: 54
Carnet: 32 Edad: 32
Carnet: 17 Edad: 57
Carnet: 88 Edad: 26
Carnet: 82 Edad: 85
Carnet: 2 Edad: 85
Carnet: 55 Edad: 23
Carnet: 1 Edad: 89
Carnet: 61 Edad: 88
Carnet: 3 Edad: 69
Carnet: 0 Edad: 10
Carnet: 75 Edad: 12
Carnet: 92 Edad: 89
Carnet: 57 Edad: 76
Carnet: 21 Edad: 99
Carnet: 22 Edad: 51
Carnet: 81 Edad: 98
Carnet: 44 Edad: 16
Carnet: 69 Edad: 42
Carnet: 75 Edad: 33
Carnet: 62 Edad: 86
Carnet: 28 Edad: 46
Carnet: 72 Edad: 55
Carnet: 2 Edad: 34
Carnet: 56 Edad: 11
Carnet: 15 Edad: 88
Carnet: 58 Edad: 91
Carnet: 90 Edad: 57
Carnet: 38 Edad: 79
Carnet: 38 Edad: 92
Carnet: 72 Edad: 22
Carnet: 9 Edad: 57
Carnet: 89 Edad: 98
Carnet: 98 Edad: 81
Carnet: 80 Edad: 96
Carnet: 58 Edad: 18
Carnet: 48 Edad: 0
Carnet: 14 Edad: 3
Carnet: 23 Edad: 87
Carnet: 93 Edad: 43
Carnet: 95 Edad: 85
Carnet: 89 Edad: 2
Carnet: 44 Edad: 9
Carnet: 24 Edad: 8
Carnet: 98 Edad: 3
Carnet: 19 Edad: 56
Carnet: 0 Edad: 49
Carnet: 35 Edad: 51
Carnet: 9 Edad: 16
Carnet: 13 Edad: 14
Carnet: 10 Edad: 17
Carnet: 7 Edad: 21
Carnet: 48 Edad: 83
Carnet: 28 Edad: 93
Carnet: 27 Edad: 67
Carnet: 0 Edad: 88
Carnet: 18 Edad: 38
Carnet: 53 Edad: 99
Carnet: 81 Edad: 34
Carnet: 68 Edad: 84
Carnet: 48 Edad: 99
Carnet: 96 Edad: 21
Carnet: 74 Edad: 20
Carnet: 91 Edad: 36
Carnet: 2 Edad: 50
Carnet: 95 Edad: 41
Carnet: 48 Edad: 83
Carnet: 24 Edad: 37
Carnet: 10 Edad: 59
Carnet: 62 Edad: 55
Carnet: 0 Edad: 91
Carnet: 13 Edad: 68
Carnet: 6 Edad: 30
Carnet: 22 Edad: 46
Carnet: 21 Edad: 88
Carnet: 9 Edad: 58
Carnet: 45 Edad: 9
Carnet: 53 Edad: 83
Carnet: 57 Edad: 87
Carnet: 7 Edad: 37
Carnet: 7 Edad: 91
Carnet: 66 Edad: 30
Carnet: 41 Edad: 24
Carnet: 50 Edad: 50
Carnet: 31 Edad: 52
Carnet: 55 Edad: 74
Carnet: 55 Edad: 67
Carnet: 61 Edad: 36
Carnet: 86 Edad: 90
Carnet: 97 Edad: 12
Carnet: 77 Edad: 73
Carnet: 70 Edad: 29
Carnet: 24 Edad: 72
Carnet: 21 Edad: 45
Carnet: 73 Edad: 86
Carnet: 77 Edad: 6
Carnet: 4 Edad: 30
Carnet: 39 Edad: 58
Carnet: 33 Edad: 15
Carnet: 29 Edad: 41
Carnet: 18 Edad: 82
Carnet: 37 Edad: 38
Carnet: 26 Edad: 23
Carnet: 44 Edad: 39
Carnet: 31 Edad: 8
Carnet: 66 Edad: 76
Carnet: 56 Edad: 40
Carnet: 84 Edad: 54
Carnet: 29 Edad: 23
Carnet: 93 Edad: 48
Carnet: 6 Edad: 1
Carnet: 70 Edad: 50
Carnet: 90 Edad: 29
Carnet: 46 Edad: 5
Carnet: 64 Edad: 48
Carnet: 40 Edad: 42
Carnet: 88 Edad: 6
Carnet: 90 Edad: 42
Carnet: 16 Edad: 35
Carnet: 29 Edad: 78
Carnet: 23 Edad: 41
Carnet: 37 Edad: 59
Carnet: 62 Edad: 57
Carnet: 47 Edad: 44
Carnet: 53 Edad: 68
Carnet: 41 Edad: 11
Carnet: 73 Edad: 64
Carnet: 22 Edad: 33
Carnet: 3 Edad: 11
Carnet: 35 Edad: 94
Carnet: 67 Edad: 99
Carnet: 69 Edad: 12
Carnet: 71 Edad: 38
Carnet: 47 Edad: 26
Carnet: 18 Edad: 95
Carnet: 21 Edad: 16
Carnet: 92 Edad: 82
Carnet: 2 Edad: 53
Carnet: 91 Edad: 4
Carnet: 27 Edad: 36
Carnet: 95 Edad: 42
Carnet: 61 Edad: 91
Carnet: 81 Edad: 27
Carnet: 5 Edad: 45
Carnet: 62 Edad: 64
Carnet: 78 Edad: 58
Carnet: 69 Edad: 24
Carnet: 34 Edad: 0
Carnet: 41 Edad: 67
El tiempo fue: 0
Presione una tecla para continuar . . .

Cargar los datos y divirlos por edades

Entre 17 y 22: Carntet: 16
Entre 22 y 27: Carntet: 16
Carnet de oro: Carntet: 16
Entre 17 y 22: Carntet: 86
Entre 22 y 27: Carntet: 86
Carnet de oro: Carntet: 86
Entre 17 y 22: Carntet: 9
Entre 22 y 27: Carntet: 9
Carnet de oro: Carntet: 9
Entre 17 y 22: Carntet: 50
Entre 22 y 27: Carntet: 50
Carnet de oro: Carntet: 50
Entre 17 y 22: Carntet: 76
Entre 22 y 27: Carntet: 76
Carnet de oro: Carntet: 76
Entre 17 y 22: Carntet: 68
Entre 22 y 27: Carntet: 68
Entre 17 y 22: Carntet: 53
Entre 22 y 27: Carntet: 53
Carnet de oro: Carntet: 53
Entre 17 y 22: Carntet: 33
Entre 22 y 27: Carntet: 33
Carnet de oro: Carntet: 33
Entre 17 y 22: Carntet: 74
Entre 22 y 27: Carntet: 74
Carnet de oro: Carntet: 74
Entre 17 y 22: Carntet: 71
Entre 22 y 27: Carntet: 71
Carnet de oro: Carntet: 71
Menos de 17: Carntet: 78
Entre 17 y 22: Carntet: 78
Entre 22 y 27: Carntet: 78
Entre 17 y 22: Carntet: 28
Entre 22 y 27: Carntet: 28
Carnet de oro: Carntet: 28
Entre 17 y 22: Carntet: 23
Entre 22 y 27: Carntet: 23
Carnet de oro: Carntet: 23
Entre 17 y 22: Carntet: 41
Entre 22 y 27: Carntet: 41
Carnet de oro: Carntet: 41
Menos de 17: Carntet: 13
Entre 17 y 22: Carntet: 13
Entre 22 y 27: Carntet: 13
Entre 17 y 22: Carntet: 56
Entre 22 y 27: Carntet: 56
Carnet de oro: Carntet: 56
Entre 17 y 22: Carntet: 77
Entre 22 y 27: Carntet: 77
Carnet de oro: Carntet: 77
Entre 17 y 22: Carntet: 73
Entre 22 y 27: Carntet: 73
Carnet de oro: Carntet: 73
Entre 17 y 22: Carntet: 10
Entre 22 y 27: Carntet: 10
Carnet de oro: Carntet: 10
Entre 17 y 22: Carntet: 15
Entre 22 y 27: Carntet: 15
Carnet de oro: Carntet: 15
Entre 17 y 22: Carntet: 51
Entre 22 y 27: Carntet: 51
Carnet de oro: Carntet: 51
Menos de 17: Carntet: 80
Entre 17 y 22: Carntet: 80
Entre 22 y 27: Carntet: 80
Entre 17 y 22: Carntet: 84
Entre 22 y 27: Carntet: 84
Carnet de oro: Carntet: 84
Menos de 17: Carntet: 85
Entre 17 y 22: Carntet: 85
Entre 22 y 27: Carntet: 85
Entre 17 y 22: Carntet: 82
Entre 22 y 27: Carntet: 82
Carnet de oro: Carntet: 82
Entre 17 y 22: Carntet: 12
Entre 22 y 27: Carntet: 12
Carnet de oro: Carntet: 12
Entre 17 y 22: Carntet: 30
Entre 22 y 27: Carntet: 30
Carnet de oro: Carntet: 30
Menos de 17: Carntet: 55
Entre 17 y 22: Carntet: 55
Entre 22 y 27: Carntet: 55
Menos de 17: Carntet: 17
Entre 17 y 22: Carntet: 17
Entre 22 y 27: Carntet: 17
Entre 17 y 22: Carntet: 71
Entre 22 y 27: Carntet: 71
Carnet de oro: Carntet: 71
Menos de 17: Carntet: 58
Entre 17 y 22: Carntet: 58
Entre 22 y 27: Carntet: 58
Entre 17 y 22: Carntet: 37
Entre 22 y 27: Carntet: 37
Carnet de oro: Carntet: 37
Entre 17 y 22: Carntet: 15
Entre 22 y 27: Carntet: 15
Carnet de oro: Carntet: 15
Entre 17 y 22: Carntet: 59
Entre 22 y 27: Carntet: 59
Carnet de oro: Carntet: 59
Entre 17 y 22: Carntet: 8
Entre 22 y 27: Carntet: 8
Carnet de oro: Carntet: 8
Entre 17 y 22: Carntet: 61
Entre 22 y 27: Carntet: 61
Carnet de oro: Carntet: 61
Menos de 17: Carntet: 37
Entre 17 y 22: Carntet: 37
Entre 22 y 27: Carntet: 37
Entre 17 y 22: Carntet: 22
Entre 22 y 27: Carntet: 22
Carnet de oro: Carntet: 22
Entre 17 y 22: Carntet: 98
Entre 22 y 27: Carntet: 98
Carnet de oro: Carntet: 98
Menos de 17: Carntet: 85
Entre 17 y 22: Carntet: 85
Entre 22 y 27: Carntet: 85
Entre 17 y 22: Carntet: 4
Entre 22 y 27: Carntet: 4
Carnet de oro: Carntet: 4
Entre 17 y 22: Carntet: 45
Entre 22 y 27: Carntet: 45
Carnet de oro: Carntet: 45
Menos de 17: Carntet: 71
Entre 17 y 22: Carntet: 71
Entre 22 y 27: Carntet: 71
Entre 17 y 22: Carntet: 8
Entre 22 y 27: Carntet: 8
Entre 17 y 22: Carntet: 78
Entre 22 y 27: Carntet: 78
Carnet de oro: Carntet: 78
Entre 17 y 22: Carntet: 31
Entre 22 y 27: Carntet: 31
Carnet de oro: Carntet: 31
Entre 17 y 22: Carntet: 2
Entre 22 y 27: Carntet: 2
Entre 17 y 22: Carntet: 74
Entre 22 y 27: Carntet: 74
Entre 17 y 22: Carntet: 82
Entre 22 y 27: Carntet: 82
Carnet de oro: Carntet: 82
Entre 17 y 22: Carntet: 89
Entre 22 y 27: Carntet: 89
Carnet de oro: Carntet: 89
Entre 17 y 22: Carntet: 2
Entre 22 y 27: Carntet: 2
Carnet de oro: Carntet: 2
Menos de 17: Carntet: 43
Entre 17 y 22: Carntet: 43
Entre 22 y 27: Carntet: 43
Entre 17 y 22: Carntet: 3
Entre 22 y 27: Carntet: 3
Carnet de oro: Carntet: 3
Entre 17 y 22: Carntet: 61
Entre 22 y 27: Carntet: 61
Carnet de oro: Carntet: 61
Entre 17 y 22: Carntet: 50
Entre 22 y 27: Carntet: 50
Carnet de oro: Carntet: 50
Entre 17 y 22: Carntet: 18
Entre 22 y 27: Carntet: 18
Carnet de oro: Carntet: 18
Entre 17 y 22: Carntet: 0
Entre 22 y 27: Carntet: 0
Carnet de oro: Carntet: 0
Entre 17 y 22: Carntet: 9
Entre 22 y 27: Carntet: 9
Carnet de oro: Carntet: 9
Menos de 17: Carntet: 17
Entre 17 y 22: Carntet: 17
Entre 22 y 27: Carntet: 17
Entre 17 y 22: Carntet: 48
Entre 22 y 27: Carntet: 48
Entre 17 y 22: Carntet: 3
Entre 22 y 27: Carntet: 3
Carnet de oro: Carntet: 3
Entre 17 y 22: Carntet: 3
Entre 22 y 27: Carntet: 3
Carnet de oro: Carntet: 3
Entre 17 y 22: Carntet: 33
Entre 22 y 27: Carntet: 33
Carnet de oro: Carntet: 33
Entre 17 y 22: Carntet: 8
Entre 22 y 27: Carntet: 8
Carnet de oro: Carntet: 8
Entre 17 y 22: Carntet: 16
Entre 22 y 27: Carntet: 16
Carnet de oro: Carntet: 16
Entre 17 y 22: Carntet: 93
Entre 22 y 27: Carntet: 93
Carnet de oro: Carntet: 93
Entre 17 y 22: Carntet: 62
Entre 22 y 27: Carntet: 62
Carnet de oro: Carntet: 62
Entre 17 y 22: Carntet: 90
Entre 22 y 27: Carntet: 90
Carnet de oro: Carntet: 90
Entre 17 y 22: Carntet: 37
Entre 22 y 27: Carntet: 37
Carnet de oro: Carntet: 37
Menos de 17: Carntet: 25
Entre 17 y 22: Carntet: 25
Entre 22 y 27: Carntet: 25
Entre 17 y 22: Carntet: 30
Entre 22 y 27: Carntet: 30
Carnet de oro: Carntet: 30
Entre 17 y 22: Carntet: 15
Entre 22 y 27: Carntet: 15
Carnet de oro: Carntet: 15
Entre 17 y 22: Carntet: 82
Entre 22 y 27: Carntet: 82
Carnet de oro: Carntet: 82
Entre 17 y 22: Carntet: 36
Entre 22 y 27: Carntet: 36
Carnet de oro: Carntet: 36
Entre 17 y 22: Carntet: 56
Entre 22 y 27: Carntet: 56
Carnet de oro: Carntet: 56
Entre 17 y 22: Carntet: 14
Entre 22 y 27: Carntet: 14
Carnet de oro: Carntet: 14
Entre 17 y 22: Carntet: 36
Entre 22 y 27: Carntet: 36
Carnet de oro: Carntet: 36
Entre 17 y 22: Carntet: 65
Entre 22 y 27: Carntet: 65
Carnet de oro: Carntet: 65
Entre 17 y 22: Carntet: 75
Entre 22 y 27: Carntet: 75
Carnet de oro: Carntet: 75
Menos de 17: Carntet: 26
Entre 17 y 22: Carntet: 26
Entre 22 y 27: Carntet: 26
Menos de 17: Carntet: 4
Entre 17 y 22: Carntet: 4
Entre 22 y 27: Carntet: 4
Entre 17 y 22: Carntet: 73
Entre 22 y 27: Carntet: 73
Carnet de oro: Carntet: 73
Menos de 17: Carntet: 26
Entre 17 y 22: Carntet: 26
Entre 22 y 27: Carntet: 26
Entre 17 y 22: Carntet: 48
Entre 22 y 27: Carntet: 48
Carnet de oro: Carntet: 48
Entre 17 y 22: Carntet: 42
Entre 22 y 27: Carntet: 42
Carnet de oro: Carntet: 42
Menos de 17: Carntet: 75
Entre 17 y 22: Carntet: 75
Entre 22 y 27: Carntet: 75
Entre 17 y 22: Carntet: 64
Entre 22 y 27: Carntet: 64
Carnet de oro: Carntet: 64
Menos de 17: Carntet: 84
Entre 17 y 22: Carntet: 84
Entre 22 y 27: Carntet: 84
Entre 17 y 22: Carntet: 49
Entre 22 y 27: Carntet: 49
Carnet de oro: Carntet: 49
Menos de 17: Carntet: 55
Entre 17 y 22: Carntet: 55
Entre 22 y 27: Carntet: 55
Entre 17 y 22: Carntet: 11
Entre 22 y 27: Carntet: 11
Entre 17 y 22: Carntet: 18
Entre 22 y 27: Carntet: 18
Carnet de oro: Carntet: 18
Entre 17 y 22: Carntet: 44
Entre 22 y 27: Carntet: 44
Carnet de oro: Carntet: 44
Entre 17 y 22: Carntet: 57
Entre 22 y 27: Carntet: 57
Carnet de oro: Carntet: 57
Entre 17 y 22: Carntet: 23
Entre 22 y 27: Carntet: 23
Carnet de oro: Carntet: 23
Entre 17 y 22: Carntet: 24
Entre 22 y 27: Carntet: 24
Carnet de oro: Carntet: 24
Entre 17 y 22: Carntet: 53
Entre 22 y 27: Carntet: 53
Carnet de oro: Carntet: 53
Entre 17 y 22: Carntet: 85
Entre 22 y 27: Carntet: 85
Carnet de oro: Carntet: 85
Entre 17 y 22: Carntet: 35
Entre 22 y 27: Carntet: 35
Carnet de oro: Carntet: 35
Entre 17 y 22: Carntet: 36
Entre 22 y 27: Carntet: 36
Carnet de oro: Carntet: 36
Entre 17 y 22: Carntet: 48
Entre 22 y 27: Carntet: 48
Carnet de oro: Carntet: 48
Entre 17 y 22: Carntet: 30
Entre 22 y 27: Carntet: 30
Entre 17 y 22: Carntet: 49
Entre 22 y 27: Carntet: 49
Carnet de oro: Carntet: 49
Entre 17 y 22: Carntet: 46
Entre 22 y 27: Carntet: 46
Carnet de oro: Carntet: 46
Entre 17 y 22: Carntet: 54
Entre 22 y 27: Carntet: 54
Carnet de oro: Carntet: 54
Entre 17 y 22: Carntet: 21
Entre 22 y 27: Carntet: 21
Carnet de oro: Carntet: 21
Entre 17 y 22: Carntet: 8
Entre 22 y 27: Carntet: 8
Carnet de oro: Carntet: 8
Entre 17 y 22: Carntet: 88
Entre 22 y 27: Carntet: 88
Carnet de oro: Carntet: 88
Entre 17 y 22: Carntet: 49
Entre 22 y 27: Carntet: 49
Carnet de oro: Carntet: 49
Entre 17 y 22: Carntet: 9
Entre 22 y 27: Carntet: 9
Carnet de oro: Carntet: 9
Entre 17 y 22: Carntet: 43
Entre 22 y 27: Carntet: 43
Carnet de oro: Carntet: 43
Entre 17 y 22: Carntet: 47
Entre 22 y 27: Carntet: 47
Carnet de oro: Carntet: 47
Entre 17 y 22: Carntet: 28
Entre 22 y 27: Carntet: 28
Carnet de oro: Carntet: 28
Entre 17 y 22: Carntet: 15
Entre 22 y 27: Carntet: 15
Carnet de oro: Carntet: 15
Entre 17 y 22: Carntet: 0
Entre 22 y 27: Carntet: 0
Carnet de oro: Carntet: 0
Entre 17 y 22: Carntet: 23
Entre 22 y 27: Carntet: 23
Carnet de oro: Carntet: 23
Menos de 17: Carntet: 1
Entre 17 y 22: Carntet: 1
Entre 22 y 27: Carntet: 1
Entre 17 y 22: Carntet: 70
Entre 22 y 27: Carntet: 70
Carnet de oro: Carntet: 70
Entre 17 y 22: Carntet: 52
Entre 22 y 27: Carntet: 52
Carnet de oro: Carntet: 52
Entre 17 y 22: Carntet: 32
Entre 22 y 27: Carntet: 32
Carnet de oro: Carntet: 32
Entre 17 y 22: Carntet: 1
Entre 22 y 27: Carntet: 1
Entre 17 y 22: Carntet: 18
Entre 22 y 27: Carntet: 18
Carnet de oro: Carntet: 18
Menos de 17: Carntet: 45
Entre 17 y 22: Carntet: 45
Entre 22 y 27: Carntet: 45
Entre 17 y 22: Carntet: 65
Entre 22 y 27: Carntet: 65
Carnet de oro: Carntet: 65
Entre 17 y 22: Carntet: 89
Entre 22 y 27: Carntet: 89
Carnet de oro: Carntet: 89
Entre 17 y 22: Carntet: 19
Entre 22 y 27: Carntet: 19
Carnet de oro: Carntet: 19
Entre 17 y 22: Carntet: 69
Entre 22 y 27: Carntet: 69
Carnet de oro: Carntet: 69
Entre 17 y 22: Carntet: 46
Entre 22 y 27: Carntet: 46
Carnet de oro: Carntet: 46
Menos de 17: Carntet: 45
Entre 17 y 22: Carntet: 45
Entre 22 y 27: Carntet: 45
Entre 17 y 22: Carntet: 13
Entre 22 y 27: Carntet: 13
Carnet de oro: Carntet: 13
Entre 17 y 22: Carntet: 71
Entre 22 y 27: Carntet: 71
Carnet de oro: Carntet: 71
Entre 17 y 22: Carntet: 84
Entre 22 y 27: Carntet: 84
Carnet de oro: Carntet: 84
Entre 17 y 22: Carntet: 98
Entre 22 y 27: Carntet: 98
Carnet de oro: Carntet: 98
Entre 17 y 22: Carntet: 3
Entre 22 y 27: Carntet: 3
Entre 17 y 22: Carntet: 75
Entre 22 y 27: Carntet: 75
Carnet de oro: Carntet: 75
Menos de 17: Carntet: 50
Entre 17 y 22: Carntet: 50
Entre 22 y 27: Carntet: 50
Entre 17 y 22: Carntet: 18
Entre 22 y 27: Carntet: 18
Carnet de oro: Carntet: 18
Menos de 17: Carntet: 91
Entre 17 y 22: Carntet: 91
Entre 22 y 27: Carntet: 91
Menos de 17: Carntet: 19
Entre 17 y 22: Carntet: 19
Entre 22 y 27: Carntet: 19
Entre 17 y 22: Carntet: 64
Entre 22 y 27: Carntet: 64
Carnet de oro: Carntet: 64
Entre 17 y 22: Carntet: 89
Entre 22 y 27: Carntet: 89
Carnet de oro: Carntet: 89
Entre 17 y 22: Carntet: 10
Entre 22 y 27: Carntet: 10
Carnet de oro: Carntet: 10
Entre 17 y 22: Carntet: 6
Entre 22 y 27: Carntet: 6
Carnet de oro: Carntet: 6
Entre 17 y 22: Carntet: 21
Entre 22 y 27: Carntet: 21
Carnet de oro: Carntet: 21
Menos de 17: Carntet: 4
Entre 17 y 22: Carntet: 4
Entre 22 y 27: Carntet: 4
Entre 17 y 22: Carntet: 87
Entre 22 y 27: Carntet: 87
Carnet de oro: Carntet: 87
Entre 17 y 22: Carntet: 98
Entre 22 y 27: Carntet: 98
Carnet de oro: Carntet: 98
Entre 17 y 22: Carntet: 75
Entre 22 y 27: Carntet: 75
Carnet de oro: Carntet: 75
Entre 17 y 22: Carntet: 27
Entre 22 y 27: Carntet: 27
Carnet de oro: Carntet: 27
Entre 17 y 22: Carntet: 70
Entre 22 y 27: Carntet: 70
Carnet de oro: Carntet: 70
Entre 17 y 22: Carntet: 92
Entre 22 y 27: Carntet: 92
Carnet de oro: Carntet: 92
Menos de 17: Carntet: 24
Entre 17 y 22: Carntet: 24
Entre 22 y 27: Carntet: 24
Entre 17 y 22: Carntet: 13
Entre 22 y 27: Carntet: 13
Carnet de oro: Carntet: 13
Entre 17 y 22: Carntet: 15
Entre 22 y 27: Carntet: 15
Carnet de oro: Carntet: 15
Entre 17 y 22: Carntet: 1
Entre 22 y 27: Carntet: 1
Carnet de oro: Carntet: 1
Entre 17 y 22: Carntet: 13
Entre 22 y 27: Carntet: 13
Carnet de oro: Carntet: 13
Entre 17 y 22: Carntet: 29
Entre 22 y 27: Carntet: 29
Carnet de oro: Carntet: 29
Entre 17 y 22: Carntet: 67
Entre 22 y 27: Carntet: 67
Carnet de oro: Carntet: 67
Entre 17 y 22: Carntet: 61
Entre 22 y 27: Carntet: 61
Carnet de oro: Carntet: 61
Entre 17 y 22: Carntet: 49
Entre 22 y 27: Carntet: 49
Carnet de oro: Carntet: 49
Entre 17 y 22: Carntet: 92
Entre 22 y 27: Carntet: 92
Carnet de oro: Carntet: 92
Menos de 17: Carntet: 75
Entre 17 y 22: Carntet: 75
Entre 22 y 27: Carntet: 75
Entre 17 y 22: Carntet: 3
Entre 22 y 27: Carntet: 3
Carnet de oro: Carntet: 3
Entre 17 y 22: Carntet: 64
Entre 22 y 27: Carntet: 64
Carnet de oro: Carntet: 64
Menos de 17: Carntet: 92
Entre 17 y 22: Carntet: 92
Entre 22 y 27: Carntet: 92
Entre 17 y 22: Carntet: 35
Entre 22 y 27: Carntet: 35
Carnet de oro: Carntet: 35
Entre 17 y 22: Carntet: 44
Entre 22 y 27: Carntet: 44
Carnet de oro: Carntet: 44
Entre 17 y 22: Carntet: 51
Entre 22 y 27: Carntet: 51
Carnet de oro: Carntet: 51
Menos de 17: Carntet: 53
Entre 17 y 22: Carntet: 53
Entre 22 y 27: Carntet: 53
Entre 17 y 22: Carntet: 90
Entre 22 y 27: Carntet: 90
Carnet de oro: Carntet: 90
Entre 17 y 22: Carntet: 97
Entre 22 y 27: Carntet: 97
Carnet de oro: Carntet: 97
Entre 17 y 22: Carntet: 85
Entre 22 y 27: Carntet: 85
Carnet de oro: Carntet: 85
Entre 17 y 22: Carntet: 40
Entre 22 y 27: Carntet: 40
Carnet de oro: Carntet: 40
Entre 17 y 22: Carntet: 69
Entre 22 y 27: Carntet: 69
Carnet de oro: Carntet: 69
Entre 17 y 22: Carntet: 12
Entre 22 y 27: Carntet: 12
Carnet de oro: Carntet: 12
Entre 17 y 22: Carntet: 17
Entre 22 y 27: Carntet: 17
Carnet de oro: Carntet: 17
Menos de 17: Carntet: 18
Entre 17 y 22: Carntet: 18
Entre 22 y 27: Carntet: 18
Entre 17 y 22: Carntet: 75
Entre 22 y 27: Carntet: 75
Carnet de oro: Carntet: 75
Menos de 17: Carntet: 40
Entre 17 y 22: Carntet: 40
Entre 22 y 27: Carntet: 40
Entre 17 y 22: Carntet: 96
Entre 22 y 27: Carntet: 96
Carnet de oro: Carntet: 96
Entre 17 y 22: Carntet: 52
Entre 22 y 27: Carntet: 52
Carnet de oro: Carntet: 52
Entre 17 y 22: Carntet: 24
Entre 22 y 27: Carntet: 24
Carnet de oro: Carntet: 24
Entre 17 y 22: Carntet: 11
Entre 22 y 27: Carntet: 11
Carnet de oro: Carntet: 11
Entre 17 y 22: Carntet: 42
Entre 22 y 27: Carntet: 42
Carnet de oro: Carntet: 42
Entre 17 y 22: Carntet: 55
Entre 22 y 27: Carntet: 55
Carnet de oro: Carntet: 55
Entre 17 y 22: Carntet: 13
Entre 22 y 27: Carntet: 13
Carnet de oro: Carntet: 13
Menos de 17: Carntet: 81
Entre 17 y 22: Carntet: 81
Entre 22 y 27: Carntet: 81
Entre 17 y 22: Carntet: 62
Entre 22 y 27: Carntet: 62
Carnet de oro: Carntet: 62
Menos de 17: Carntet: 76
Entre 17 y 22: Carntet: 76
Entre 22 y 27: Carntet: 76
Entre 17 y 22: Carntet: 56
Entre 22 y 27: Carntet: 56
Carnet de oro: Carntet: 56
Entre 17 y 22: Carntet: 37
Entre 22 y 27: Carntet: 37
Carnet de oro: Carntet: 37
Entre 17 y 22: Carntet: 93
Entre 22 y 27: Carntet: 93
Carnet de oro: Carntet: 93
Menos de 17: Carntet: 79
Entre 17 y 22: Carntet: 79
Entre 22 y 27: Carntet: 79
Entre 17 y 22: Carntet: 50
Entre 22 y 27: Carntet: 50
Carnet de oro: Carntet: 50
Entre 17 y 22: Carntet: 5
Entre 22 y 27: Carntet: 5
Carnet de oro: Carntet: 5
Entre 17 y 22: Carntet: 26
Entre 22 y 27: Carntet: 26
Carnet de oro: Carntet: 26
Entre 17 y 22: Carntet: 21
Entre 22 y 27: Carntet: 21
Carnet de oro: Carntet: 21
Entre 17 y 22: Carntet: 59
Entre 22 y 27: Carntet: 59
Entre 17 y 22: Carntet: 41
Entre 22 y 27: Carntet: 41
Carnet de oro: Carntet: 41
Menos de 17: Carntet: 54
Entre 17 y 22: Carntet: 54
Entre 22 y 27: Carntet: 54
Entre 17 y 22: Carntet: 23
Entre 22 y 27: Carntet: 23
Carnet de oro: Carntet: 23
Entre 17 y 22: Carntet: 75
Entre 22 y 27: Carntet: 75
Carnet de oro: Carntet: 75
Entre 17 y 22: Carntet: 67
Entre 22 y 27: Carntet: 67
Carnet de oro: Carntet: 67
Entre 17 y 22: Carntet: 11
Entre 22 y 27: Carntet: 11
Carnet de oro: Carntet: 11
Entre 17 y 22: Carntet: 7
Entre 22 y 27: Carntet: 7
Carnet de oro: Carntet: 7
Entre 17 y 22: Carntet: 32
Entre 22 y 27: Carntet: 32
Carnet de oro: Carntet: 32
Entre 17 y 22: Carntet: 57
Entre 22 y 27: Carntet: 57
Carnet de oro: Carntet: 57
Entre 17 y 22: Carntet: 54
Entre 22 y 27: Carntet: 54
Carnet de oro: Carntet: 54
Entre 17 y 22: Carntet: 84
Entre 22 y 27: Carntet: 84
Carnet de oro: Carntet: 84
Entre 17 y 22: Carntet: 53
Entre 22 y 27: Carntet: 53
Carnet de oro: Carntet: 53
Entre 17 y 22: Carntet: 96
Entre 22 y 27: Carntet: 96
Carnet de oro: Carntet: 96
Entre 17 y 22: Carntet: 59
Entre 22 y 27: Carntet: 59
Carnet de oro: Carntet: 59
Entre 17 y 22: Carntet: 29
Entre 22 y 27: Carntet: 29
Carnet de oro: Carntet: 29
Entre 17 y 22: Carntet: 23
Entre 22 y 27: Carntet: 23
Carnet de oro: Carntet: 23
Entre 17 y 22: Carntet: 85
Entre 22 y 27: Carntet: 85
Carnet de oro: Carntet: 85
Entre 17 y 22: Carntet: 17
Entre 22 y 27: Carntet: 17
Carnet de oro: Carntet: 17
Menos de 17: Carntet: 17
Entre 17 y 22: Carntet: 17
Entre 22 y 27: Carntet: 17
Entre 17 y 22: Carntet: 96
Entre 22 y 27: Carntet: 96
Entre 17 y 22: Carntet: 69
Entre 22 y 27: Carntet: 69
Carnet de oro: Carntet: 69
Entre 17 y 22: Carntet: 37
Entre 22 y 27: Carntet: 37
Carnet de oro: Carntet: 37
Entre 17 y 22: Carntet: 26
Entre 22 y 27: Carntet: 26
Carnet de oro: Carntet: 26
Entre 17 y 22: Carntet: 26
Entre 22 y 27: Carntet: 26
Carnet de oro: Carntet: 26
Menos de 17: Carntet: 56
Entre 17 y 22: Carntet: 56
Entre 22 y 27: Carntet: 56
Entre 17 y 22: Carntet: 23
Entre 22 y 27: Carntet: 23
Carnet de oro: Carntet: 23
Entre 17 y 22: Carntet: 72
Entre 22 y 27: Carntet: 72
Carnet de oro: Carntet: 72
Entre 17 y 22: Carntet: 35
Entre 22 y 27: Carntet: 35
Carnet de oro: Carntet: 35
Menos de 17: Carntet: 11
Entre 17 y 22: Carntet: 11
Entre 22 y 27: Carntet: 11
Entre 17 y 22: Carntet: 5
Entre 22 y 27: Carntet: 5
Carnet de oro: Carntet: 5
Entre 17 y 22: Carntet: 93
Entre 22 y 27: Carntet: 93
Carnet de oro: Carntet: 93
Entre 17 y 22: Carntet: 60
Entre 22 y 27: Carntet: 60
Carnet de oro: Carntet: 60
Entre 17 y 22: Carntet: 1
Entre 22 y 27: Carntet: 1
Carnet de oro: Carntet: 1
Entre 17 y 22: Carntet: 13
Entre 22 y 27: Carntet: 13
Carnet de oro: Carntet: 13
Menos de 17: Carntet: 77
Entre 17 y 22: Carntet: 77
Entre 22 y 27: Carntet: 77
Entre 17 y 22: Carntet: 57
Entre 22 y 27: Carntet: 57
Entre 17 y 22: Carntet: 3
Entre 22 y 27: Carntet: 3
Carnet de oro: Carntet: 3
Entre 17 y 22: Carntet: 58
Entre 22 y 27: Carntet: 58
Carnet de oro: Carntet: 58
Menos de 17: Carntet: 77
Entre 17 y 22: Carntet: 77
Entre 22 y 27: Carntet: 77
Menos de 17: Carntet: 65
Entre 17 y 22: Carntet: 65
Entre 22 y 27: Carntet: 65
Entre 17 y 22: Carntet: 58
Entre 22 y 27: Carntet: 58
Carnet de oro: Carntet: 58
Menos de 17: Carntet: 0
Entre 17 y 22: Carntet: 0
Entre 22 y 27: Carntet: 0
Entre 17 y 22: Carntet: 62
Entre 22 y 27: Carntet: 62
Carnet de oro: Carntet: 62
Entre 17 y 22: Carntet: 40
Entre 22 y 27: Carntet: 40
Carnet de oro: Carntet: 40
Entre 17 y 22: Carntet: 88
Entre 22 y 27: Carntet: 88
Carnet de oro: Carntet: 88
Entre 17 y 22: Carntet: 90
Entre 22 y 27: Carntet: 90
Entre 17 y 22: Carntet: 53
Entre 22 y 27: Carntet: 53
Entre 17 y 22: Carntet: 11
Entre 22 y 27: Carntet: 11
Carnet de oro: Carntet: 11
Entre 17 y 22: Carntet: 11
Entre 22 y 27: Carntet: 11
Carnet de oro: Carntet: 11
Entre 17 y 22: Carntet: 30
Entre 22 y 27: Carntet: 30
Carnet de oro: Carntet: 30
Menos de 17: Carntet: 2
Entre 17 y 22: Carntet: 2
Entre 22 y 27: Carntet: 2
Entre 17 y 22: Carntet: 64
Entre 22 y 27: Carntet: 64
Carnet de oro: Carntet: 64
Entre 17 y 22: Carntet: 95
Entre 22 y 27: Carntet: 95
Entre 17 y 22: Carntet: 37
Entre 22 y 27: Carntet: 37
Carnet de oro: Carntet: 37
Entre 17 y 22: Carntet: 23
Entre 22 y 27: Carntet: 23
Carnet de oro: Carntet: 23
Entre 17 y 22: Carntet: 2
Entre 22 y 27: Carntet: 2
Carnet de oro: Carntet: 2
Entre 17 y 22: Carntet: 23
Entre 22 y 27: Carntet: 23
Entre 17 y 22: Carntet: 29
Entre 22 y 27: Carntet: 29
Carnet de oro: Carntet: 29
Entre 17 y 22: Carntet: 25
Entre 22 y 27: Carntet: 25
Carnet de oro: Carntet: 25
Entre 17 y 22: Carntet: 77
Entre 22 y 27: Carntet: 77
Carnet de oro: Carntet: 77
Entre 17 y 22: Carntet: 65
Entre 22 y 27: Carntet: 65
Carnet de oro: Carntet: 65
Entre 17 y 22: Carntet: 82
Entre 22 y 27: Carntet: 82
Carnet de oro: Carntet: 82
Menos de 17: Carntet: 64
Entre 17 y 22: Carntet: 64
Entre 22 y 27: Carntet: 64
Entre 17 y 22: Carntet: 43
Entre 22 y 27: Carntet: 43
Carnet de oro: Carntet: 43
Entre 17 y 22: Carntet: 76
Entre 22 y 27: Carntet: 76
Carnet de oro: Carntet: 76
Menos de 17: Carntet: 70
Entre 17 y 22: Carntet: 70
Entre 22 y 27: Carntet: 70
Entre 17 y 22: Carntet: 10
Entre 22 y 27: Carntet: 10
Carnet de oro: Carntet: 10
Entre 17 y 22: Carntet: 60
Entre 22 y 27: Carntet: 60
Carnet de oro: Carntet: 60
Entre 17 y 22: Carntet: 0
Entre 22 y 27: Carntet: 0
Carnet de oro: Carntet: 0
Entre 17 y 22: Carntet: 19
Entre 22 y 27: Carntet: 19
Carnet de oro: Carntet: 19
Entre 17 y 22: Carntet: 18
Entre 22 y 27: Carntet: 18
Carnet de oro: Carntet: 18
Entre 17 y 22: Carntet: 51
Entre 22 y 27: Carntet: 51
Carnet de oro: Carntet: 51
Entre 17 y 22: Carntet: 78
Entre 22 y 27: Carntet: 78
Carnet de oro: Carntet: 78
Entre 17 y 22: Carntet: 71
Entre 22 y 27: Carntet: 71
Carnet de oro: Carntet: 71
Menos de 17: Carntet: 58
Entre 17 y 22: Carntet: 58
Entre 22 y 27: Carntet: 58
Entre 17 y 22: Carntet: 76
Entre 22 y 27: Carntet: 76
Carnet de oro: Carntet: 76
Entre 17 y 22: Carntet: 19
Entre 22 y 27: Carntet: 19
Entre 17 y 22: Carntet: 95
Entre 22 y 27: Carntet: 95
Entre 17 y 22: Carntet: 40
Entre 22 y 27: Carntet: 40
Carnet de oro: Carntet: 40
Entre 17 y 22: Carntet: 85
Entre 22 y 27: Carntet: 85
Carnet de oro: Carntet: 85
Entre 17 y 22: Carntet: 96
Entre 22 y 27: Carntet: 96
Carnet de oro: Carntet: 96
Entre 17 y 22: Carntet: 11
Entre 22 y 27: Carntet: 11
Carnet de oro: Carntet: 11
Entre 17 y 22: Carntet: 35
Entre 22 y 27: Carntet: 35
Carnet de oro: Carntet: 35
Entre 17 y 22: Carntet: 70
Entre 22 y 27: Carntet: 70
Carnet de oro: Carntet: 70
Entre 17 y 22: Carntet: 13
Entre 22 y 27: Carntet: 13
Carnet de oro: Carntet: 13
Entre 17 y 22: Carntet: 87
Entre 22 y 27: Carntet: 87
Carnet de oro: Carntet: 87
Menos de 17: Carntet: 64
Entre 17 y 22: Carntet: 64
Entre 22 y 27: Carntet: 64
Entre 17 y 22: Carntet: 22
Entre 22 y 27: Carntet: 22
Carnet de oro: Carntet: 22
Entre 17 y 22: Carntet: 92
Entre 22 y 27: Carntet: 92
Carnet de oro: Carntet: 92
Entre 17 y 22: Carntet: 25
Entre 22 y 27: Carntet: 25
Carnet de oro: Carntet: 25
Entre 17 y 22: Carntet: 5
Entre 22 y 27: Carntet: 5
Carnet de oro: Carntet: 5
Entre 17 y 22: Carntet: 3
Entre 22 y 27: Carntet: 3
Carnet de oro: Carntet: 3
Entre 17 y 22: Carntet: 61
Entre 22 y 27: Carntet: 61
Carnet de oro: Carntet: 61
Entre 17 y 22: Carntet: 23
Entre 22 y 27: Carntet: 23
Carnet de oro: Carntet: 23
Entre 17 y 22: Carntet: 43
Entre 22 y 27: Carntet: 43
Entre 17 y 22: Carntet: 27
Entre 22 y 27: Carntet: 27
Entre 17 y 22: Carntet: 2
Entre 22 y 27: Carntet: 2
Carnet de oro: Carntet: 2
Entre 17 y 22: Carntet: 13
Entre 22 y 27: Carntet: 13
Carnet de oro: Carntet: 13
Entre 17 y 22: Carntet: 2
Entre 22 y 27: Carntet: 2
Carnet de oro: Carntet: 2
Entre 17 y 22: Carntet: 92
Entre 22 y 27: Carntet: 92
Carnet de oro: Carntet: 92
Entre 17 y 22: Carntet: 63
Entre 22 y 27: Carntet: 63
Carnet de oro: Carntet: 63
Entre 17 y 22: Carntet: 73
Entre 22 y 27: Carntet: 73
Carnet de oro: Carntet: 73
Entre 17 y 22: Carntet: 18
Entre 22 y 27: Carntet: 18
Carnet de oro: Carntet: 18
Entre 17 y 22: Carntet: 87
Entre 22 y 27: Carntet: 87
Carnet de oro: Carntet: 87
Entre 17 y 22: Carntet: 33
Entre 22 y 27: Carntet: 33
Carnet de oro: Carntet: 33
Entre 17 y 22: Carntet: 72
Entre 22 y 27: Carntet: 72
Carnet de oro: Carntet: 72
Entre 17 y 22: Carntet: 34
Entre 22 y 27: Carntet: 34
Carnet de oro: Carntet: 34
Entre 17 y 22: Carntet: 14
Entre 22 y 27: Carntet: 14
Menos de 17: Carntet: 77
Entre 17 y 22: Carntet: 77
Entre 22 y 27: Carntet: 77
Entre 17 y 22: Carntet: 2
Entre 22 y 27: Carntet: 2
Entre 17 y 22: Carntet: 58
Entre 22 y 27: Carntet: 58
Carnet de oro: Carntet: 58
Menos de 17: Carntet: 87
Entre 17 y 22: Carntet: 87
Entre 22 y 27: Carntet: 87
Entre 17 y 22: Carntet: 68
Entre 22 y 27: Carntet: 68
Entre 17 y 22: Carntet: 74
Entre 22 y 27: Carntet: 74
Menos de 17: Carntet: 86
Entre 17 y 22: Carntet: 86
Entre 22 y 27: Carntet: 86
Entre 17 y 22: Carntet: 45
Entre 22 y 27: Carntet: 45
Carnet de oro: Carntet: 45
Menos de 17: Carntet: 54
Entre 17 y 22: Carntet: 54
Entre 22 y 27: Carntet: 54
Entre 17 y 22: Carntet: 53
Entre 22 y 27: Carntet: 53
Entre 17 y 22: Carntet: 92
Entre 22 y 27: Carntet: 92
Carnet de oro: Carntet: 92
Entre 17 y 22: Carntet: 44
Entre 22 y 27: Carntet: 44
Carnet de oro: Carntet: 44
Entre 17 y 22: Carntet: 73
Entre 22 y 27: Carntet: 73
Carnet de oro: Carntet: 73
Entre 17 y 22: Carntet: 35
Entre 22 y 27: Carntet: 35
Carnet de oro: Carntet: 35
Entre 17 y 22: Carntet: 29
Entre 22 y 27: Carntet: 29
Carnet de oro: Carntet: 29
Entre 17 y 22: Carntet: 96
Entre 22 y 27: Carntet: 96
Entre 17 y 22: Carntet: 81
Entre 22 y 27: Carntet: 81
Carnet de oro: Carntet: 81
Entre 17 y 22: Carntet: 46
Entre 22 y 27: Carntet: 46
Carnet de oro: Carntet: 46
Entre 17 y 22: Carntet: 21
Entre 22 y 27: Carntet: 21
Carnet de oro: Carntet: 21
Entre 17 y 22: Carntet: 13
Entre 22 y 27: Carntet: 13
Carnet de oro: Carntet: 13
Entre 17 y 22: Carntet: 32
Entre 22 y 27: Carntet: 32
Carnet de oro: Carntet: 32
Menos de 17: Carntet: 12
Entre 17 y 22: Carntet: 12
Entre 22 y 27: Carntet: 12
Entre 17 y 22: Carntet: 85
Entre 22 y 27: Carntet: 85
Carnet de oro: Carntet: 85
Entre 17 y 22: Carntet: 13
Entre 22 y 27: Carntet: 13
Carnet de oro: Carntet: 13
Entre 17 y 22: Carntet: 86
Entre 22 y 27: Carntet: 86
Carnet de oro: Carntet: 86
Entre 17 y 22: Carntet: 16
Entre 22 y 27: Carntet: 16
Carnet de oro: Carntet: 16
Menos de 17: Carntet: 14
Entre 17 y 22: Carntet: 14
Entre 22 y 27: Carntet: 14
Entre 17 y 22: Carntet: 55
Entre 22 y 27: Carntet: 55
Carnet de oro: Carntet: 55
Entre 17 y 22: Carntet: 88
Entre 22 y 27: Carntet: 88
Carnet de oro: Carntet: 88
Menos de 17: Carntet: 86
Entre 17 y 22: Carntet: 86
Entre 22 y 27: Carntet: 86
Menos de 17: Carntet: 97
Entre 17 y 22: Carntet: 97
Entre 22 y 27: Carntet: 97
Entre 17 y 22: Carntet: 93
Entre 22 y 27: Carntet: 93
Carnet de oro: Carntet: 93
Entre 17 y 22: Carntet: 66
Entre 22 y 27: Carntet: 66
Carnet de oro: Carntet: 66
Entre 17 y 22: Carntet: 49
Entre 22 y 27: Carntet: 49
Carnet de oro: Carntet: 49
Entre 17 y 22: Carntet: 87
Entre 22 y 27: Carntet: 87
Carnet de oro: Carntet: 87
Entre 17 y 22: Carntet: 79
Entre 22 y 27: Carntet: 79
Carnet de oro: Carntet: 79
Entre 17 y 22: Carntet: 39
Entre 22 y 27: Carntet: 39
Entre 17 y 22: Carntet: 18
Entre 22 y 27: Carntet: 18
Carnet de oro: Carntet: 18
Entre 17 y 22: Carntet: 45
Entre 22 y 27: Carntet: 45
Carnet de oro: Carntet: 45
Menos de 17: Carntet: 41
Entre 17 y 22: Carntet: 41
Entre 22 y 27: Carntet: 41
Entre 17 y 22: Carntet: 34
Entre 22 y 27: Carntet: 34
Carnet de oro: Carntet: 34
Entre 17 y 22: Carntet: 25
Entre 22 y 27: Carntet: 25
Carnet de oro: Carntet: 25
Entre 17 y 22: Carntet: 68
Entre 22 y 27: Carntet: 68
Carnet de oro: Carntet: 68
Entre 17 y 22: Carntet: 76
Entre 22 y 27: Carntet: 76
Carnet de oro: Carntet: 76
Entre 17 y 22: Carntet: 21
Entre 22 y 27: Carntet: 21
Carnet de oro: Carntet: 21
Entre 17 y 22: Carntet: 69
Entre 22 y 27: Carntet: 69
Carnet de oro: Carntet: 69
Entre 17 y 22: Carntet: 32
Entre 22 y 27: Carntet: 32
Carnet de oro: Carntet: 32
Entre 17 y 22: Carntet: 17
Entre 22 y 27: Carntet: 17
Carnet de oro: Carntet: 17
Entre 17 y 22: Carntet: 88
Entre 22 y 27: Carntet: 88
Carnet de oro: Carntet: 88
Entre 17 y 22: Carntet: 82
Entre 22 y 27: Carntet: 82
Carnet de oro: Carntet: 82
Entre 17 y 22: Carntet: 2
Entre 22 y 27: Carntet: 2
Carnet de oro: Carntet: 2
Entre 17 y 22: Carntet: 55
Entre 22 y 27: Carntet: 55
Entre 17 y 22: Carntet: 1
Entre 22 y 27: Carntet: 1
Carnet de oro: Carntet: 1
Entre 17 y 22: Carntet: 61
Entre 22 y 27: Carntet: 61
Carnet de oro: Carntet: 61
Entre 17 y 22: Carntet: 3
Entre 22 y 27: Carntet: 3
Carnet de oro: Carntet: 3
Menos de 17: Carntet: 0
Entre 17 y 22: Carntet: 0
Entre 22 y 27: Carntet: 0
Menos de 17: Carntet: 75
Entre 17 y 22: Carntet: 75
Entre 22 y 27: Carntet: 75
Entre 17 y 22: Carntet: 92
Entre 22 y 27: Carntet: 92
Carnet de oro: Carntet: 92
Entre 17 y 22: Carntet: 57
Entre 22 y 27: Carntet: 57
Carnet de oro: Carntet: 57
Entre 17 y 22: Carntet: 21
Entre 22 y 27: Carntet: 21
Carnet de oro: Carntet: 21
Entre 17 y 22: Carntet: 22
Entre 22 y 27: Carntet: 22
Carnet de oro: Carntet: 22
Entre 17 y 22: Carntet: 81
Entre 22 y 27: Carntet: 81
Carnet de oro: Carntet: 81
Menos de 17: Carntet: 44
Entre 17 y 22: Carntet: 44
Entre 22 y 27: Carntet: 44
Entre 17 y 22: Carntet: 69
Entre 22 y 27: Carntet: 69
Carnet de oro: Carntet: 69
Entre 17 y 22: Carntet: 75
Entre 22 y 27: Carntet: 75
Carnet de oro: Carntet: 75
Entre 17 y 22: Carntet: 62
Entre 22 y 27: Carntet: 62
Carnet de oro: Carntet: 62
Entre 17 y 22: Carntet: 28
Entre 22 y 27: Carntet: 28
Carnet de oro: Carntet: 28
Entre 17 y 22: Carntet: 72
Entre 22 y 27: Carntet: 72
Carnet de oro: Carntet: 72
Entre 17 y 22: Carntet: 2
Entre 22 y 27: Carntet: 2
Carnet de oro: Carntet: 2
Menos de 17: Carntet: 56
Entre 17 y 22: Carntet: 56
Entre 22 y 27: Carntet: 56
Entre 17 y 22: Carntet: 15
Entre 22 y 27: Carntet: 15
Carnet de oro: Carntet: 15
Entre 17 y 22: Carntet: 58
Entre 22 y 27: Carntet: 58
Carnet de oro: Carntet: 58
Entre 17 y 22: Carntet: 90
Entre 22 y 27: Carntet: 90
Carnet de oro: Carntet: 90
Entre 17 y 22: Carntet: 38
Entre 22 y 27: Carntet: 38
Carnet de oro: Carntet: 38
Entre 17 y 22: Carntet: 38
Entre 22 y 27: Carntet: 38
Carnet de oro: Carntet: 38
Entre 17 y 22: Carntet: 72
Entre 22 y 27: Carntet: 72
Entre 17 y 22: Carntet: 9
Entre 22 y 27: Carntet: 9
Carnet de oro: Carntet: 9
Entre 17 y 22: Carntet: 89
Entre 22 y 27: Carntet: 89
Carnet de oro: Carntet: 89
Entre 17 y 22: Carntet: 98
Entre 22 y 27: Carntet: 98
Carnet de oro: Carntet: 98
Entre 17 y 22: Carntet: 80
Entre 22 y 27: Carntet: 80
Carnet de oro: Carntet: 80
Entre 17 y 22: Carntet: 58
Entre 22 y 27: Carntet: 58
Menos de 17: Carntet: 48
Entre 17 y 22: Carntet: 48
Entre 22 y 27: Carntet: 48
Menos de 17: Carntet: 14
Entre 17 y 22: Carntet: 14
Entre 22 y 27: Carntet: 14
Entre 17 y 22: Carntet: 23
Entre 22 y 27: Carntet: 23
Carnet de oro: Carntet: 23
Entre 17 y 22: Carntet: 93
Entre 22 y 27: Carntet: 93
Carnet de oro: Carntet: 93
Entre 17 y 22: Carntet: 95
Entre 22 y 27: Carntet: 95
Carnet de oro: Carntet: 95
Menos de 17: Carntet: 89
Entre 17 y 22: Carntet: 89
Entre 22 y 27: Carntet: 89
Menos de 17: Carntet: 44
Entre 17 y 22: Carntet: 44
Entre 22 y 27: Carntet: 44
Menos de 17: Carntet: 24
Entre 17 y 22: Carntet: 24
Entre 22 y 27: Carntet: 24
Menos de 17: Carntet: 98
Entre 17 y 22: Carntet: 98
Entre 22 y 27: Carntet: 98
Entre 17 y 22: Carntet: 19
Entre 22 y 27: Carntet: 19
Carnet de oro: Carntet: 19
Entre 17 y 22: Carntet: 0
Entre 22 y 27: Carntet: 0
Carnet de oro: Carntet: 0
Entre 17 y 22: Carntet: 35
Entre 22 y 27: Carntet: 35
Carnet de oro: Carntet: 35
Menos de 17: Carntet: 9
Entre 17 y 22: Carntet: 9
Entre 22 y 27: Carntet: 9
Menos de 17: Carntet: 13
Entre 17 y 22: Carntet: 13
Entre 22 y 27: Carntet: 13
Entre 17 y 22: Carntet: 10
Entre 22 y 27: Carntet: 10
Entre 17 y 22: Carntet: 7
Entre 22 y 27: Carntet: 7
Entre 17 y 22: Carntet: 48
Entre 22 y 27: Carntet: 48
Carnet de oro: Carntet: 48
Entre 17 y 22: Carntet: 28
Entre 22 y 27: Carntet: 28
Carnet de oro: Carntet: 28
Entre 17 y 22: Carntet: 27
Entre 22 y 27: Carntet: 27
Carnet de oro: Carntet: 27
Entre 17 y 22: Carntet: 0
Entre 22 y 27: Carntet: 0
Carnet de oro: Carntet: 0
Entre 17 y 22: Carntet: 18
Entre 22 y 27: Carntet: 18
Carnet de oro: Carntet: 18
Entre 17 y 22: Carntet: 53
Entre 22 y 27: Carntet: 53
Carnet de oro: Carntet: 53
Entre 17 y 22: Carntet: 81
Entre 22 y 27: Carntet: 81
Carnet de oro: Carntet: 81
Entre 17 y 22: Carntet: 68
Entre 22 y 27: Carntet: 68
Carnet de oro: Carntet: 68
Entre 17 y 22: Carntet: 48
Entre 22 y 27: Carntet: 48
Carnet de oro: Carntet: 48
Entre 17 y 22: Carntet: 96
Entre 22 y 27: Carntet: 96
Entre 17 y 22: Carntet: 74
Entre 22 y 27: Carntet: 74
Entre 17 y 22: Carntet: 91
Entre 22 y 27: Carntet: 91
Carnet de oro: Carntet: 91
Entre 17 y 22: Carntet: 2
Entre 22 y 27: Carntet: 2
Carnet de oro: Carntet: 2
Entre 17 y 22: Carntet: 95
Entre 22 y 27: Carntet: 95
Carnet de oro: Carntet: 95
Entre 17 y 22: Carntet: 48
Entre 22 y 27: Carntet: 48
Carnet de oro: Carntet: 48
Entre 17 y 22: Carntet: 24
Entre 22 y 27: Carntet: 24
Carnet de oro: Carntet: 24
Entre 17 y 22: Carntet: 10
Entre 22 y 27: Carntet: 10
Carnet de oro: Carntet: 10
Entre 17 y 22: Carntet: 62
Entre 22 y 27: Carntet: 62
Carnet de oro: Carntet: 62
Entre 17 y 22: Carntet: 0
Entre 22 y 27: Carntet: 0
Carnet de oro: Carntet: 0
Entre 17 y 22: Carntet: 13
Entre 22 y 27: Carntet: 13
Carnet de oro: Carntet: 13
Entre 17 y 22: Carntet: 6
Entre 22 y 27: Carntet: 6
Carnet de oro: Carntet: 6
Entre 17 y 22: Carntet: 22
Entre 22 y 27: Carntet: 22
Carnet de oro: Carntet: 22
Entre 17 y 22: Carntet: 21
Entre 22 y 27: Carntet: 21
Carnet de oro: Carntet: 21
Entre 17 y 22: Carntet: 9
Entre 22 y 27: Carntet: 9
Carnet de oro: Carntet: 9
Menos de 17: Carntet: 45
Entre 17 y 22: Carntet: 45
Entre 22 y 27: Carntet: 45
Entre 17 y 22: Carntet: 53
Entre 22 y 27: Carntet: 53
Carnet de oro: Carntet: 53
Entre 17 y 22: Carntet: 57
Entre 22 y 27: Carntet: 57
Carnet de oro: Carntet: 57
Entre 17 y 22: Carntet: 7
Entre 22 y 27: Carntet: 7
Carnet de oro: Carntet: 7
Entre 17 y 22: Carntet: 7
Entre 22 y 27: Carntet: 7
Carnet de oro: Carntet: 7
Entre 17 y 22: Carntet: 66
Entre 22 y 27: Carntet: 66
Carnet de oro: Carntet: 66
Entre 17 y 22: Carntet: 41
Entre 22 y 27: Carntet: 41
Entre 17 y 22: Carntet: 50
Entre 22 y 27: Carntet: 50
Carnet de oro: Carntet: 50
Entre 17 y 22: Carntet: 31
Entre 22 y 27: Carntet: 31
Carnet de oro: Carntet: 31
Entre 17 y 22: Carntet: 55
Entre 22 y 27: Carntet: 55
Carnet de oro: Carntet: 55
Entre 17 y 22: Carntet: 55
Entre 22 y 27: Carntet: 55
Carnet de oro: Carntet: 55
Entre 17 y 22: Carntet: 61
Entre 22 y 27: Carntet: 61
Carnet de oro: Carntet: 61
Entre 17 y 22: Carntet: 86
Entre 22 y 27: Carntet: 86
Carnet de oro: Carntet: 86
Menos de 17: Carntet: 97
Entre 17 y 22: Carntet: 97
Entre 22 y 27: Carntet: 97
Entre 17 y 22: Carntet: 77
Entre 22 y 27: Carntet: 77
Carnet de oro: Carntet: 77
Entre 17 y 22: Carntet: 70
Entre 22 y 27: Carntet: 70
Carnet de oro: Carntet: 70
Entre 17 y 22: Carntet: 24
Entre 22 y 27: Carntet: 24
Carnet de oro: Carntet: 24
Entre 17 y 22: Carntet: 21
Entre 22 y 27: Carntet: 21
Carnet de oro: Carntet: 21
Entre 17 y 22: Carntet: 73
Entre 22 y 27: Carntet: 73
Carnet de oro: Carntet: 73
Menos de 17: Carntet: 77
Entre 17 y 22: Carntet: 77
Entre 22 y 27: Carntet: 77
Entre 17 y 22: Carntet: 4
Entre 22 y 27: Carntet: 4
Carnet de oro: Carntet: 4
Entre 17 y 22: Carntet: 39
Entre 22 y 27: Carntet: 39
Carnet de oro: Carntet: 39
Menos de 17: Carntet: 33
Entre 17 y 22: Carntet: 33
Entre 22 y 27: Carntet: 33
Entre 17 y 22: Carntet: 29
Entre 22 y 27: Carntet: 29
Carnet de oro: Carntet: 29
Entre 17 y 22: Carntet: 18
Entre 22 y 27: Carntet: 18
Carnet de oro: Carntet: 18
Entre 17 y 22: Carntet: 37
Entre 22 y 27: Carntet: 37
Carnet de oro: Carntet: 37
Entre 17 y 22: Carntet: 26
Entre 22 y 27: Carntet: 26
Entre 17 y 22: Carntet: 44
Entre 22 y 27: Carntet: 44
Carnet de oro: Carntet: 44
Menos de 17: Carntet: 31
Entre 17 y 22: Carntet: 31
Entre 22 y 27: Carntet: 31
Entre 17 y 22: Carntet: 66
Entre 22 y 27: Carntet: 66
Carnet de oro: Carntet: 66
Entre 17 y 22: Carntet: 56
Entre 22 y 27: Carntet: 56
Carnet de oro: Carntet: 56
Entre 17 y 22: Carntet: 84
Entre 22 y 27: Carntet: 84
Carnet de oro: Carntet: 84
Entre 17 y 22: Carntet: 29
Entre 22 y 27: Carntet: 29
Entre 17 y 22: Carntet: 93
Entre 22 y 27: Carntet: 93
Carnet de oro: Carntet: 93
Menos de 17: Carntet: 6
Entre 17 y 22: Carntet: 6
Entre 22 y 27: Carntet: 6
Entre 17 y 22: Carntet: 70
Entre 22 y 27: Carntet: 70
Carnet de oro: Carntet: 70
Entre 17 y 22: Carntet: 90
Entre 22 y 27: Carntet: 90
Carnet de oro: Carntet: 90
Menos de 17: Carntet: 46
Entre 17 y 22: Carntet: 46
Entre 22 y 27: Carntet: 46
Entre 17 y 22: Carntet: 64
Entre 22 y 27: Carntet: 64
Carnet de oro: Carntet: 64
Entre 17 y 22: Carntet: 40
Entre 22 y 27: Carntet: 40
Carnet de oro: Carntet: 40
Menos de 17: Carntet: 88
Entre 17 y 22: Carntet: 88
Entre 22 y 27: Carntet: 88
Entre 17 y 22: Carntet: 90
Entre 22 y 27: Carntet: 90
Carnet de oro: Carntet: 90
Entre 17 y 22: Carntet: 16
Entre 22 y 27: Carntet: 16
Carnet de oro: Carntet: 16
Entre 17 y 22: Carntet: 29
Entre 22 y 27: Carntet: 29
Carnet de oro: Carntet: 29
Entre 17 y 22: Carntet: 23
Entre 22 y 27: Carntet: 23
Carnet de oro: Carntet: 23
Entre 17 y 22: Carntet: 37
Entre 22 y 27: Carntet: 37
Carnet de oro: Carntet: 37
Entre 17 y 22: Carntet: 62
Entre 22 y 27: Carntet: 62
Carnet de oro: Carntet: 62
Entre 17 y 22: Carntet: 47
Entre 22 y 27: Carntet: 47
Carnet de oro: Carntet: 47
Entre 17 y 22: Carntet: 53
Entre 22 y 27: Carntet: 53
Carnet de oro: Carntet: 53
Menos de 17: Carntet: 41
Entre 17 y 22: Carntet: 41
Entre 22 y 27: Carntet: 41
Entre 17 y 22: Carntet: 73
Entre 22 y 27: Carntet: 73
Carnet de oro: Carntet: 73
Entre 17 y 22: Carntet: 22
Entre 22 y 27: Carntet: 22
Carnet de oro: Carntet: 22
Menos de 17: Carntet: 3
Entre 17 y 22: Carntet: 3
Entre 22 y 27: Carntet: 3
Entre 17 y 22: Carntet: 35
Entre 22 y 27: Carntet: 35
Carnet de oro: Carntet: 35
Entre 17 y 22: Carntet: 67
Entre 22 y 27: Carntet: 67
Carnet de oro: Carntet: 67
Menos de 17: Carntet: 69
Entre 17 y 22: Carntet: 69
Entre 22 y 27: Carntet: 69
Entre 17 y 22: Carntet: 71
Entre 22 y 27: Carntet: 71
Carnet de oro: Carntet: 71
Entre 17 y 22: Carntet: 47
Entre 22 y 27: Carntet: 47
Carnet de oro: Carntet: 47
Entre 17 y 22: Carntet: 18
Entre 22 y 27: Carntet: 18
Carnet de oro: Carntet: 18
Menos de 17: Carntet: 21
Entre 17 y 22: Carntet: 21
Entre 22 y 27: Carntet: 21
Entre 17 y 22: Carntet: 92
Entre 22 y 27: Carntet: 92
Carnet de oro: Carntet: 92
Entre 17 y 22: Carntet: 2
Entre 22 y 27: Carntet: 2
Carnet de oro: Carntet: 2
Menos de 17: Carntet: 91
Entre 17 y 22: Carntet: 91
Entre 22 y 27: Carntet: 91
Entre 17 y 22: Carntet: 27
Entre 22 y 27: Carntet: 27
Carnet de oro: Carntet: 27
Entre 17 y 22: Carntet: 95
Entre 22 y 27: Carntet: 95
Carnet de oro: Carntet: 95
Entre 17 y 22: Carntet: 61
Entre 22 y 27: Carntet: 61
Carnet de oro: Carntet: 61
Entre 17 y 22: Carntet: 81
Entre 22 y 27: Carntet: 81
Carnet de oro: Carntet: 81
Entre 17 y 22: Carntet: 5
Entre 22 y 27: Carntet: 5
Carnet de oro: Carntet: 5
Entre 17 y 22: Carntet: 62
Entre 22 y 27: Carntet: 62
Carnet de oro: Carntet: 62
Entre 17 y 22: Carntet: 78
Entre 22 y 27: Carntet: 78
Carnet de oro: Carntet: 78
Entre 17 y 22: Carntet: 69
Entre 22 y 27: Carntet: 69
Menos de 17: Carntet: 34
Entre 17 y 22: Carntet: 34
Entre 22 y 27: Carntet: 34
Entre 17 y 22: Carntet: 41
Entre 22 y 27: Carntet: 41
Carnet de oro: Carntet: 41

C:\Users\tcoto.DESKTOP-QAVAARJ\source\repos\Operaciones_Dinamicas\Debug\Operaciones_Dinamicas.exe (process 28612) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

*/

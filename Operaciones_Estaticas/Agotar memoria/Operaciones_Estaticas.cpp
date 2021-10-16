#include <iostream>
using namespace std;

typedef struct T_Alumnos{
	int Carnet;
	int Edad;
};

int main() {
	T_Alumnos clase[500];
	for (int i = 0; i < 500; i++) {
		clase[i].Carnet = rand() % 100;
		clase[i].Edad = rand() % 100;
	}
	int inicio = time(NULL);
	for (int i = 0; i < 500; i++) {
		cout << "Edad: " << clase[i].Edad << " Carnet: " << clase[i].Carnet << endl;
	}
	int fin = time(NULL);
	cout << "Tiempo tardado" << difftime(fin, inicio);
	system("pause");
	/*for (int i = 0; i < 500; i++) {
		if (clase[i].Edad < 17) {
			cout << "Menos de 17: " << "Carntet: " << clase[i].Carnet << endl;
		}
		if (17 <= clase[i].Edad < 22) {
			cout << "Entre 17 y 22: " << "Carntet: " << clase[i].Carnet << " " << endl;
		}
		if (22 <= clase[i].Edad <= 25) {
			cout << "Entre 22 y 27: " << "Carntet: " << clase[i].Carnet << " " << endl;
		}
		if (clase[i].Edad >= 26) {
			cout << "Carnet de oro: " << "Carntet: " << clase[i].Carnet << " " << endl;
		}		
	}*/
	T_Alumnos aux;
	int final = 500;
	for (int i = 0; i < 500; i++) {
		final--;
		
		if (final != 249) {
			aux.Edad = clase[i].Edad;
			aux.Carnet = clase[i].Carnet;
			clase[i].Carnet = clase[final].Carnet;
			clase[i].Edad = clase[final].Edad;
			clase[final].Carnet = aux.Carnet;
			clase[final].Edad = aux.Edad;
			cout << "Edad: " << clase[i].Edad << " Carnet: " << clase[i].Carnet << endl;
		}
		else
		{
			break;
		}
	}
}

/*
Cargar los datos y mostar cuanto tiempo se dura:
Edad: 67 Carnet: 41
Edad: 0 Carnet: 34
Edad: 24 Carnet: 69
Edad: 58 Carnet: 78
Edad: 64 Carnet: 62
Edad: 45 Carnet: 5
Edad: 27 Carnet: 81
Edad: 91 Carnet: 61
Edad: 42 Carnet: 95
Edad: 36 Carnet: 27
Edad: 4 Carnet: 91
Edad: 53 Carnet: 2
Edad: 82 Carnet: 92
Edad: 16 Carnet: 21
Edad: 95 Carnet: 18
Edad: 26 Carnet: 47
Edad: 38 Carnet: 71
Edad: 12 Carnet: 69
Edad: 99 Carnet: 67
Edad: 94 Carnet: 35
Edad: 11 Carnet: 3
Edad: 33 Carnet: 22
Edad: 64 Carnet: 73
Edad: 11 Carnet: 41
Edad: 68 Carnet: 53
Edad: 44 Carnet: 47
Edad: 57 Carnet: 62
Edad: 59 Carnet: 37
Edad: 41 Carnet: 23
Edad: 78 Carnet: 29
Edad: 35 Carnet: 16
Edad: 42 Carnet: 90
Edad: 6 Carnet: 88
Edad: 42 Carnet: 40
Edad: 48 Carnet: 64
Edad: 5 Carnet: 46
Edad: 29 Carnet: 90
Edad: 50 Carnet: 70
Edad: 1 Carnet: 6
Edad: 48 Carnet: 93
Edad: 23 Carnet: 29
Edad: 54 Carnet: 84
Edad: 40 Carnet: 56
Edad: 76 Carnet: 66
Edad: 8 Carnet: 31
Edad: 39 Carnet: 44
Edad: 23 Carnet: 26
Edad: 38 Carnet: 37
Edad: 82 Carnet: 18
Edad: 41 Carnet: 29
Edad: 15 Carnet: 33
Edad: 58 Carnet: 39
Edad: 30 Carnet: 4
Edad: 6 Carnet: 77
Edad: 86 Carnet: 73
Edad: 45 Carnet: 21
Edad: 72 Carnet: 24
Edad: 29 Carnet: 70
Edad: 73 Carnet: 77
Edad: 12 Carnet: 97
Edad: 90 Carnet: 86
Edad: 36 Carnet: 61
Edad: 67 Carnet: 55
Edad: 74 Carnet: 55
Edad: 52 Carnet: 31
Edad: 50 Carnet: 50
Edad: 24 Carnet: 41
Edad: 30 Carnet: 66
Edad: 91 Carnet: 7
Edad: 37 Carnet: 7
Edad: 87 Carnet: 57
Edad: 83 Carnet: 53
Edad: 9 Carnet: 45
Edad: 58 Carnet: 9
Edad: 88 Carnet: 21
Edad: 46 Carnet: 22
Edad: 30 Carnet: 6
Edad: 68 Carnet: 13
Edad: 91 Carnet: 0
Edad: 55 Carnet: 62
Edad: 59 Carnet: 10
Edad: 37 Carnet: 24
Edad: 83 Carnet: 48
Edad: 41 Carnet: 95
Edad: 50 Carnet: 2
Edad: 36 Carnet: 91
Edad: 20 Carnet: 74
Edad: 21 Carnet: 96
Edad: 99 Carnet: 48
Edad: 84 Carnet: 68
Edad: 34 Carnet: 81
Edad: 99 Carnet: 53
Edad: 38 Carnet: 18
Edad: 88 Carnet: 0
Edad: 67 Carnet: 27
Edad: 93 Carnet: 28
Edad: 83 Carnet: 48
Edad: 21 Carnet: 7
Edad: 17 Carnet: 10
Edad: 14 Carnet: 13
Edad: 16 Carnet: 9
Edad: 51 Carnet: 35
Edad: 49 Carnet: 0
Edad: 56 Carnet: 19
Edad: 3 Carnet: 98
Edad: 8 Carnet: 24
Edad: 9 Carnet: 44
Edad: 2 Carnet: 89
Edad: 85 Carnet: 95
Edad: 43 Carnet: 93
Edad: 87 Carnet: 23
Edad: 3 Carnet: 14
Edad: 0 Carnet: 48
Edad: 18 Carnet: 58
Edad: 96 Carnet: 80
Edad: 81 Carnet: 98
Edad: 98 Carnet: 89
Edad: 57 Carnet: 9
Edad: 22 Carnet: 72
Edad: 92 Carnet: 38
Edad: 79 Carnet: 38
Edad: 57 Carnet: 90
Edad: 91 Carnet: 58
Edad: 88 Carnet: 15
Edad: 11 Carnet: 56
Edad: 34 Carnet: 2
Edad: 55 Carnet: 72
Edad: 46 Carnet: 28
Edad: 86 Carnet: 62
Edad: 33 Carnet: 75
Edad: 42 Carnet: 69
Edad: 16 Carnet: 44
Edad: 98 Carnet: 81
Edad: 51 Carnet: 22
Edad: 99 Carnet: 21
Edad: 76 Carnet: 57
Edad: 89 Carnet: 92
Edad: 12 Carnet: 75
Edad: 10 Carnet: 0
Edad: 69 Carnet: 3
Edad: 88 Carnet: 61
Edad: 89 Carnet: 1
Edad: 23 Carnet: 55
Edad: 85 Carnet: 2
Edad: 85 Carnet: 82
Edad: 26 Carnet: 88
Edad: 57 Carnet: 17
Edad: 32 Carnet: 32
Edad: 54 Carnet: 69
Edad: 89 Carnet: 21
Edad: 29 Carnet: 76
Edad: 92 Carnet: 68
Edad: 55 Carnet: 25
Edad: 49 Carnet: 34
Edad: 12 Carnet: 41
Edad: 60 Carnet: 45
Edad: 53 Carnet: 18
Edad: 23 Carnet: 39
Edad: 96 Carnet: 79
Edad: 29 Carnet: 87
Edad: 37 Carnet: 49
Edad: 49 Carnet: 66
Edad: 95 Carnet: 93
Edad: 16 Carnet: 97
Edad: 5 Carnet: 86
Edad: 82 Carnet: 88
Edad: 34 Carnet: 55
Edad: 1 Carnet: 14
Edad: 71 Carnet: 16
Edad: 63 Carnet: 86
Edad: 55 Carnet: 13
Edad: 53 Carnet: 85
Edad: 8 Carnet: 12
Edad: 45 Carnet: 32
Edad: 56 Carnet: 13
Edad: 58 Carnet: 21
Edad: 82 Carnet: 46
Edad: 44 Carnet: 81
Edad: 22 Carnet: 96
Edad: 61 Carnet: 29
Edad: 50 Carnet: 35
Edad: 66 Carnet: 73
Edad: 59 Carnet: 44
Edad: 39 Carnet: 92
Edad: 24 Carnet: 53
Edad: 10 Carnet: 54
Edad: 49 Carnet: 45
Edad: 13 Carnet: 86
Edad: 22 Carnet: 74
Edad: 18 Carnet: 68
Edad: 5 Carnet: 87
Edad: 91 Carnet: 58
Edad: 25 Carnet: 2
Edad: 14 Carnet: 77
Edad: 24 Carnet: 14
Edad: 74 Carnet: 34
Edad: 59 Carnet: 72
Edad: 70 Carnet: 33
Edad: 97 Carnet: 87
Edad: 77 Carnet: 18
Edad: 70 Carnet: 73
Edad: 68 Carnet: 63
Edad: 85 Carnet: 92
Edad: 80 Carnet: 2
Edad: 27 Carnet: 13
Edad: 99 Carnet: 2
Edad: 25 Carnet: 27
Edad: 24 Carnet: 43
Edad: 72 Carnet: 23
Edad: 81 Carnet: 61
Edad: 32 Carnet: 3
Edad: 93 Carnet: 5
Edad: 31 Carnet: 25
Edad: 42 Carnet: 92
Edad: 86 Carnet: 22
Edad: 0 Carnet: 64
Edad: 60 Carnet: 87
Edad: 74 Carnet: 13
Edad: 70 Carnet: 70
Edad: 33 Carnet: 35
Edad: 60 Carnet: 11
Edad: 67 Carnet: 96
Edad: 50 Carnet: 85
Edad: 94 Carnet: 40
Edad: 24 Carnet: 95
Edad: 25 Carnet: 19
Edad: 94 Carnet: 76
Edad: 2 Carnet: 58
Edad: 66 Carnet: 71
Edad: 93 Carnet: 78
Edad: 84 Carnet: 51
Edad: 64 Carnet: 18
Edad: 52 Carnet: 19
Edad: 87 Carnet: 0
Edad: 26 Carnet: 60
Edad: 57 Carnet: 10
Edad: 15 Carnet: 70
Edad: 27 Carnet: 76
Edad: 58 Carnet: 43
Edad: 9 Carnet: 64
Edad: 86 Carnet: 82
Edad: 87 Carnet: 65
Edad: 74 Carnet: 77
Edad: 27 Carnet: 25
Edad: 28 Carnet: 29
Edad: 20 Carnet: 23
Edad: 62 Carnet: 2
Edad: 96 Carnet: 23
Edad: 61 Carnet: 37
Edad: 25 Carnet: 95
Edad: 60 Carnet: 64
Edad: 16 Carnet: 2
Edad: 26 Carnet: 30
Edad: 71 Carnet: 11
Edad: 47 Carnet: 11
Edad: 20 Carnet: 53
Edad: 24 Carnet: 90
Edad: 63 Carnet: 88
Edad: 51 Carnet: 40
Edad: 29 Carnet: 62
Edad: 13 Carnet: 0
Edad: 78 Carnet: 58
Edad: 7 Carnet: 65
Edad: 0 Carnet: 77
Edad: 39 Carnet: 58
Edad: 60 Carnet: 3
Edad: 24 Carnet: 57
Edad: 8 Carnet: 77
Edad: 87 Carnet: 13
Edad: 50 Carnet: 1
Edad: 28 Carnet: 60
Edad: 84 Carnet: 93
Edad: 40 Carnet: 5
Edad: 4 Carnet: 11
Edad: 56 Carnet: 35
Edad: 50 Carnet: 72
Edad: 85 Carnet: 23
Edad: 16 Carnet: 56
Edad: 57 Carnet: 26
Edad: 57 Carnet: 26
Edad: 71 Carnet: 37
Edad: 61 Carnet: 69
Edad: 22 Carnet: 96
Edad: 12 Carnet: 17
Edad: 96 Carnet: 17
Edad: 41 Carnet: 85
Edad: 29 Carnet: 23
Edad: 65 Carnet: 29
Edad: 32 Carnet: 59
Edad: 55 Carnet: 96
Edad: 62 Carnet: 53
Edad: 34 Carnet: 84
Edad: 72 Carnet: 54
Edad: 69 Carnet: 57
Edad: 63 Carnet: 32
Edad: 83 Carnet: 7
Edad: 35 Carnet: 11
Edad: 48 Carnet: 67
Edad: 38 Carnet: 75
Edad: 42 Carnet: 23
Edad: 11 Carnet: 54
Edad: 75 Carnet: 41
Edad: 25 Carnet: 59
Edad: 70 Carnet: 21
Edad: 34 Carnet: 26
Edad: 83 Carnet: 5
Edad: 98 Carnet: 50
Edad: 1 Carnet: 79
Edad: 34 Carnet: 93
Edad: 34 Carnet: 37
Edad: 93 Carnet: 56
Edad: 5 Carnet: 76
Edad: 48 Carnet: 62
Edad: 0 Carnet: 81
Edad: 41 Carnet: 13
Edad: 55 Carnet: 55
Edad: 62 Carnet: 42
Edad: 77 Carnet: 11
Edad: 78 Carnet: 24
Edad: 43 Carnet: 52
Edad: 73 Carnet: 96
Edad: 13 Carnet: 40
Edad: 72 Carnet: 75
Edad: 10 Carnet: 18
Edad: 32 Carnet: 17
Edad: 95 Carnet: 12
Edad: 31 Carnet: 69
Edad: 88 Carnet: 40
Edad: 90 Carnet: 85
Edad: 89 Carnet: 97
Edad: 45 Carnet: 90
Edad: 14 Carnet: 53
Edad: 40 Carnet: 51
Edad: 58 Carnet: 44
Edad: 59 Carnet: 35
Edad: 5 Carnet: 92
Edad: 81 Carnet: 64
Edad: 29 Carnet: 3
Edad: 8 Carnet: 75
Edad: 97 Carnet: 92
Edad: 56 Carnet: 49
Edad: 27 Carnet: 61
Edad: 41 Carnet: 67
Edad: 40 Carnet: 29
Edad: 74 Carnet: 13
Edad: 77 Carnet: 1
Edad: 83 Carnet: 15
Edad: 92 Carnet: 13
Edad: 1 Carnet: 24
Edad: 59 Carnet: 92
Edad: 28 Carnet: 70
Edad: 84 Carnet: 27
Edad: 86 Carnet: 75
Edad: 70 Carnet: 98
Edad: 47 Carnet: 87
Edad: 3 Carnet: 4
Edad: 63 Carnet: 21
Edad: 63 Carnet: 6
Edad: 71 Carnet: 10
Edad: 40 Carnet: 89
Edad: 42 Carnet: 64
Edad: 13 Carnet: 19
Edad: 4 Carnet: 91
Edad: 32 Carnet: 18
Edad: 5 Carnet: 50
Edad: 39 Carnet: 75
Edad: 22 Carnet: 3
Edad: 47 Carnet: 98
Edad: 48 Carnet: 84
Edad: 64 Carnet: 71
Edad: 75 Carnet: 13
Edad: 12 Carnet: 45
Edad: 78 Carnet: 46
Edad: 62 Carnet: 69
Edad: 85 Carnet: 19
Edad: 44 Carnet: 89
Edad: 40 Carnet: 65
Edad: 8 Carnet: 45
Edad: 70 Carnet: 18
Edad: 23 Carnet: 1
Edad: 72 Carnet: 32
Edad: 87 Carnet: 52
Edad: 63 Carnet: 70
Edad: 3 Carnet: 1
Edad: 27 Carnet: 23
Edad: 69 Carnet: 0
Edad: 65 Carnet: 15
Edad: 43 Carnet: 28
Edad: 88 Carnet: 47
Edad: 37 Carnet: 43
Edad: 63 Carnet: 9
Edad: 81 Carnet: 49
Edad: 42 Carnet: 88
Edad: 60 Carnet: 8
Edad: 58 Carnet: 21
Edad: 88 Carnet: 54
Edad: 90 Carnet: 46
Edad: 43 Carnet: 49
Edad: 20 Carnet: 30
Edad: 67 Carnet: 48
Edad: 83 Carnet: 36
Edad: 26 Carnet: 35
Edad: 38 Carnet: 85
Edad: 29 Carnet: 53
Edad: 48 Carnet: 24
Edad: 59 Carnet: 23
Edad: 66 Carnet: 57
Edad: 55 Carnet: 44
Edad: 26 Carnet: 18
Edad: 25 Carnet: 11
Edad: 1 Carnet: 55
Edad: 96 Carnet: 49
Edad: 15 Carnet: 84
Edad: 42 Carnet: 64
Edad: 13 Carnet: 75
Edad: 96 Carnet: 42
Edad: 72 Carnet: 48
Edad: 6 Carnet: 26
Edad: 29 Carnet: 73
Edad: 5 Carnet: 4
Edad: 12 Carnet: 26
Edad: 93 Carnet: 75
Edad: 36 Carnet: 65
Edad: 41 Carnet: 36
Edad: 94 Carnet: 14
Edad: 52 Carnet: 56
Edad: 38 Carnet: 36
Edad: 55 Carnet: 82
Edad: 31 Carnet: 15
Edad: 41 Carnet: 30
Edad: 11 Carnet: 25
Edad: 86 Carnet: 37
Edad: 50 Carnet: 90
Edad: 34 Carnet: 62
Edad: 53 Carnet: 93
Edad: 52 Carnet: 16
Edad: 62 Carnet: 8
Edad: 54 Carnet: 33
Edad: 34 Carnet: 3
Edad: 56 Carnet: 3
Edad: 24 Carnet: 48
Edad: 13 Carnet: 17
Edad: 28 Carnet: 9
Edad: 80 Carnet: 0
Edad: 58 Carnet: 18
Edad: 55 Carnet: 50
Edad: 64 Carnet: 61
Edad: 76 Carnet: 3
Edad: 9 Carnet: 43
Edad: 61 Carnet: 2
Edad: 48 Carnet: 89
Edad: 53 Carnet: 82
Edad: 20 Carnet: 74
Edad: 23 Carnet: 2
Edad: 69 Carnet: 31
Edad: 59 Carnet: 78
Edad: 19 Carnet: 8
Edad: 3 Carnet: 71
Edad: 81 Carnet: 45
Edad: 92 Carnet: 4
Edad: 13 Carnet: 85
Edad: 89 Carnet: 98
Edad: 38 Carnet: 22
Edad: 10 Carnet: 37
Edad: 34 Carnet: 61
Edad: 61 Carnet: 8
Edad: 93 Carnet: 59
Edad: 69 Carnet: 15
Edad: 69 Carnet: 37
Edad: 0 Carnet: 58
Edad: 64 Carnet: 71
Edad: 15 Carnet: 17
Edad: 15 Carnet: 55
Edad: 39 Carnet: 30
Edad: 88 Carnet: 12
Edad: 54 Carnet: 82
Edad: 10 Carnet: 85
Edad: 74 Carnet: 84
Edad: 15 Carnet: 80
Edad: 41 Carnet: 51
Edad: 79 Carnet: 15
Edad: 98 Carnet: 10
Edad: 88 Carnet: 73
Edad: 32 Carnet: 77
Edad: 89 Carnet: 56
Edad: 8 Carnet: 13
Edad: 90 Carnet: 41
Edad: 63 Carnet: 23
Edad: 84 Carnet: 28
Edad: 0 Carnet: 78
Edad: 85 Carnet: 71
Edad: 71 Carnet: 74
Edad: 67 Carnet: 33
Edad: 95 Carnet: 53
Edad: 25 Carnet: 68
Edad: 29 Carnet: 76
Edad: 98 Carnet: 50
Edad: 93 Carnet: 9
Edad: 80 Carnet: 86
Edad: 49 Carnet: 16
Tiempo tardado0Presione una tecla para continuar . . .

Cargar los datos y dividirlo por edades

Entre 17 y 22: Carntet: 41
Entre 22 y 27: Carntet: 41
Carnet de oro: Carntet: 41
Menos de 17: Carntet: 34
Entre 17 y 22: Carntet: 34
Entre 22 y 27: Carntet: 34
Entre 17 y 22: Carntet: 69
Entre 22 y 27: Carntet: 69
Entre 17 y 22: Carntet: 78
Entre 22 y 27: Carntet: 78
Carnet de oro: Carntet: 78
Entre 17 y 22: Carntet: 62
Entre 22 y 27: Carntet: 62
Carnet de oro: Carntet: 62
Entre 17 y 22: Carntet: 5
Entre 22 y 27: Carntet: 5
Carnet de oro: Carntet: 5
Entre 17 y 22: Carntet: 81
Entre 22 y 27: Carntet: 81
Carnet de oro: Carntet: 81
Entre 17 y 22: Carntet: 61
Entre 22 y 27: Carntet: 61
Carnet de oro: Carntet: 61
Entre 17 y 22: Carntet: 95
Entre 22 y 27: Carntet: 95
Carnet de oro: Carntet: 95
Entre 17 y 22: Carntet: 27
Entre 22 y 27: Carntet: 27
Carnet de oro: Carntet: 27
Menos de 17: Carntet: 91
Entre 17 y 22: Carntet: 91
Entre 22 y 27: Carntet: 91
Entre 17 y 22: Carntet: 2
Entre 22 y 27: Carntet: 2
Carnet de oro: Carntet: 2
Entre 17 y 22: Carntet: 92
Entre 22 y 27: Carntet: 92
Carnet de oro: Carntet: 92
Menos de 17: Carntet: 21
Entre 17 y 22: Carntet: 21
Entre 22 y 27: Carntet: 21
Entre 17 y 22: Carntet: 18
Entre 22 y 27: Carntet: 18
Carnet de oro: Carntet: 18
Entre 17 y 22: Carntet: 47
Entre 22 y 27: Carntet: 47
Carnet de oro: Carntet: 47
Entre 17 y 22: Carntet: 71
Entre 22 y 27: Carntet: 71
Carnet de oro: Carntet: 71
Menos de 17: Carntet: 69
Entre 17 y 22: Carntet: 69
Entre 22 y 27: Carntet: 69
Entre 17 y 22: Carntet: 67
Entre 22 y 27: Carntet: 67
Carnet de oro: Carntet: 67
Entre 17 y 22: Carntet: 35
Entre 22 y 27: Carntet: 35
Carnet de oro: Carntet: 35
Menos de 17: Carntet: 3
Entre 17 y 22: Carntet: 3
Entre 22 y 27: Carntet: 3
Entre 17 y 22: Carntet: 22
Entre 22 y 27: Carntet: 22
Carnet de oro: Carntet: 22
Entre 17 y 22: Carntet: 73
Entre 22 y 27: Carntet: 73
Carnet de oro: Carntet: 73
Menos de 17: Carntet: 41
Entre 17 y 22: Carntet: 41
Entre 22 y 27: Carntet: 41
Entre 17 y 22: Carntet: 53
Entre 22 y 27: Carntet: 53
Carnet de oro: Carntet: 53
Entre 17 y 22: Carntet: 47
Entre 22 y 27: Carntet: 47
Carnet de oro: Carntet: 47
Entre 17 y 22: Carntet: 62
Entre 22 y 27: Carntet: 62
Carnet de oro: Carntet: 62
Entre 17 y 22: Carntet: 37
Entre 22 y 27: Carntet: 37
Carnet de oro: Carntet: 37
Entre 17 y 22: Carntet: 23
Entre 22 y 27: Carntet: 23
Carnet de oro: Carntet: 23
Entre 17 y 22: Carntet: 29
Entre 22 y 27: Carntet: 29
Carnet de oro: Carntet: 29
Entre 17 y 22: Carntet: 16
Entre 22 y 27: Carntet: 16
Carnet de oro: Carntet: 16
Entre 17 y 22: Carntet: 90
Entre 22 y 27: Carntet: 90
Carnet de oro: Carntet: 90
Menos de 17: Carntet: 88
Entre 17 y 22: Carntet: 88
Entre 22 y 27: Carntet: 88
Entre 17 y 22: Carntet: 40
Entre 22 y 27: Carntet: 40
Carnet de oro: Carntet: 40
Entre 17 y 22: Carntet: 64
Entre 22 y 27: Carntet: 64
Carnet de oro: Carntet: 64
Menos de 17: Carntet: 46
Entre 17 y 22: Carntet: 46
Entre 22 y 27: Carntet: 46
Entre 17 y 22: Carntet: 90
Entre 22 y 27: Carntet: 90
Carnet de oro: Carntet: 90
Entre 17 y 22: Carntet: 70
Entre 22 y 27: Carntet: 70
Carnet de oro: Carntet: 70
Menos de 17: Carntet: 6
Entre 17 y 22: Carntet: 6
Entre 22 y 27: Carntet: 6
Entre 17 y 22: Carntet: 93
Entre 22 y 27: Carntet: 93
Carnet de oro: Carntet: 93
Entre 17 y 22: Carntet: 29
Entre 22 y 27: Carntet: 29
Entre 17 y 22: Carntet: 84
Entre 22 y 27: Carntet: 84
Carnet de oro: Carntet: 84
Entre 17 y 22: Carntet: 56
Entre 22 y 27: Carntet: 56
Carnet de oro: Carntet: 56
Entre 17 y 22: Carntet: 66
Entre 22 y 27: Carntet: 66
Carnet de oro: Carntet: 66
Menos de 17: Carntet: 31
Entre 17 y 22: Carntet: 31
Entre 22 y 27: Carntet: 31
Entre 17 y 22: Carntet: 44
Entre 22 y 27: Carntet: 44
Carnet de oro: Carntet: 44
Entre 17 y 22: Carntet: 26
Entre 22 y 27: Carntet: 26
Entre 17 y 22: Carntet: 37
Entre 22 y 27: Carntet: 37
Carnet de oro: Carntet: 37
Entre 17 y 22: Carntet: 18
Entre 22 y 27: Carntet: 18
Carnet de oro: Carntet: 18
Entre 17 y 22: Carntet: 29
Entre 22 y 27: Carntet: 29
Carnet de oro: Carntet: 29
Menos de 17: Carntet: 33
Entre 17 y 22: Carntet: 33
Entre 22 y 27: Carntet: 33
Entre 17 y 22: Carntet: 39
Entre 22 y 27: Carntet: 39
Carnet de oro: Carntet: 39
Entre 17 y 22: Carntet: 4
Entre 22 y 27: Carntet: 4
Carnet de oro: Carntet: 4
Menos de 17: Carntet: 77
Entre 17 y 22: Carntet: 77
Entre 22 y 27: Carntet: 77
Entre 17 y 22: Carntet: 73
Entre 22 y 27: Carntet: 73
Carnet de oro: Carntet: 73
Entre 17 y 22: Carntet: 21
Entre 22 y 27: Carntet: 21
Carnet de oro: Carntet: 21
Entre 17 y 22: Carntet: 24
Entre 22 y 27: Carntet: 24
Carnet de oro: Carntet: 24
Entre 17 y 22: Carntet: 70
Entre 22 y 27: Carntet: 70
Carnet de oro: Carntet: 70
Entre 17 y 22: Carntet: 77
Entre 22 y 27: Carntet: 77
Carnet de oro: Carntet: 77
Menos de 17: Carntet: 97
Entre 17 y 22: Carntet: 97
Entre 22 y 27: Carntet: 97
Entre 17 y 22: Carntet: 86
Entre 22 y 27: Carntet: 86
Carnet de oro: Carntet: 86
Entre 17 y 22: Carntet: 61
Entre 22 y 27: Carntet: 61
Carnet de oro: Carntet: 61
Entre 17 y 22: Carntet: 55
Entre 22 y 27: Carntet: 55
Carnet de oro: Carntet: 55
Entre 17 y 22: Carntet: 55
Entre 22 y 27: Carntet: 55
Carnet de oro: Carntet: 55
Entre 17 y 22: Carntet: 31
Entre 22 y 27: Carntet: 31
Carnet de oro: Carntet: 31
Entre 17 y 22: Carntet: 50
Entre 22 y 27: Carntet: 50
Carnet de oro: Carntet: 50
Entre 17 y 22: Carntet: 41
Entre 22 y 27: Carntet: 41
Entre 17 y 22: Carntet: 66
Entre 22 y 27: Carntet: 66
Carnet de oro: Carntet: 66
Entre 17 y 22: Carntet: 7
Entre 22 y 27: Carntet: 7
Carnet de oro: Carntet: 7
Entre 17 y 22: Carntet: 7
Entre 22 y 27: Carntet: 7
Carnet de oro: Carntet: 7
Entre 17 y 22: Carntet: 57
Entre 22 y 27: Carntet: 57
Carnet de oro: Carntet: 57
Entre 17 y 22: Carntet: 53
Entre 22 y 27: Carntet: 53
Carnet de oro: Carntet: 53
Menos de 17: Carntet: 45
Entre 17 y 22: Carntet: 45
Entre 22 y 27: Carntet: 45
Entre 17 y 22: Carntet: 9
Entre 22 y 27: Carntet: 9
Carnet de oro: Carntet: 9
Entre 17 y 22: Carntet: 21
Entre 22 y 27: Carntet: 21
Carnet de oro: Carntet: 21
Entre 17 y 22: Carntet: 22
Entre 22 y 27: Carntet: 22
Carnet de oro: Carntet: 22
Entre 17 y 22: Carntet: 6
Entre 22 y 27: Carntet: 6
Carnet de oro: Carntet: 6
Entre 17 y 22: Carntet: 13
Entre 22 y 27: Carntet: 13
Carnet de oro: Carntet: 13
Entre 17 y 22: Carntet: 0
Entre 22 y 27: Carntet: 0
Carnet de oro: Carntet: 0
Entre 17 y 22: Carntet: 62
Entre 22 y 27: Carntet: 62
Carnet de oro: Carntet: 62
Entre 17 y 22: Carntet: 10
Entre 22 y 27: Carntet: 10
Carnet de oro: Carntet: 10
Entre 17 y 22: Carntet: 24
Entre 22 y 27: Carntet: 24
Carnet de oro: Carntet: 24
Entre 17 y 22: Carntet: 48
Entre 22 y 27: Carntet: 48
Carnet de oro: Carntet: 48
Entre 17 y 22: Carntet: 95
Entre 22 y 27: Carntet: 95
Carnet de oro: Carntet: 95
Entre 17 y 22: Carntet: 2
Entre 22 y 27: Carntet: 2
Carnet de oro: Carntet: 2
Entre 17 y 22: Carntet: 91
Entre 22 y 27: Carntet: 91
Carnet de oro: Carntet: 91
Entre 17 y 22: Carntet: 74
Entre 22 y 27: Carntet: 74
Entre 17 y 22: Carntet: 96
Entre 22 y 27: Carntet: 96
Entre 17 y 22: Carntet: 48
Entre 22 y 27: Carntet: 48
Carnet de oro: Carntet: 48
Entre 17 y 22: Carntet: 68
Entre 22 y 27: Carntet: 68
Carnet de oro: Carntet: 68
Entre 17 y 22: Carntet: 81
Entre 22 y 27: Carntet: 81
Carnet de oro: Carntet: 81
Entre 17 y 22: Carntet: 53
Entre 22 y 27: Carntet: 53
Carnet de oro: Carntet: 53
Entre 17 y 22: Carntet: 18
Entre 22 y 27: Carntet: 18
Carnet de oro: Carntet: 18
Entre 17 y 22: Carntet: 0
Entre 22 y 27: Carntet: 0
Carnet de oro: Carntet: 0
Entre 17 y 22: Carntet: 27
Entre 22 y 27: Carntet: 27
Carnet de oro: Carntet: 27
Entre 17 y 22: Carntet: 28
Entre 22 y 27: Carntet: 28
Carnet de oro: Carntet: 28
Entre 17 y 22: Carntet: 48
Entre 22 y 27: Carntet: 48
Carnet de oro: Carntet: 48
Entre 17 y 22: Carntet: 7
Entre 22 y 27: Carntet: 7
Entre 17 y 22: Carntet: 10
Entre 22 y 27: Carntet: 10
Menos de 17: Carntet: 13
Entre 17 y 22: Carntet: 13
Entre 22 y 27: Carntet: 13
Menos de 17: Carntet: 9
Entre 17 y 22: Carntet: 9
Entre 22 y 27: Carntet: 9
Entre 17 y 22: Carntet: 35
Entre 22 y 27: Carntet: 35
Carnet de oro: Carntet: 35
Entre 17 y 22: Carntet: 0
Entre 22 y 27: Carntet: 0
Carnet de oro: Carntet: 0
Entre 17 y 22: Carntet: 19
Entre 22 y 27: Carntet: 19
Carnet de oro: Carntet: 19
Menos de 17: Carntet: 98
Entre 17 y 22: Carntet: 98
Entre 22 y 27: Carntet: 98
Menos de 17: Carntet: 24
Entre 17 y 22: Carntet: 24
Entre 22 y 27: Carntet: 24
Menos de 17: Carntet: 44
Entre 17 y 22: Carntet: 44
Entre 22 y 27: Carntet: 44
Menos de 17: Carntet: 89
Entre 17 y 22: Carntet: 89
Entre 22 y 27: Carntet: 89
Entre 17 y 22: Carntet: 95
Entre 22 y 27: Carntet: 95
Carnet de oro: Carntet: 95
Entre 17 y 22: Carntet: 93
Entre 22 y 27: Carntet: 93
Carnet de oro: Carntet: 93
Entre 17 y 22: Carntet: 23
Entre 22 y 27: Carntet: 23
Carnet de oro: Carntet: 23
Menos de 17: Carntet: 14
Entre 17 y 22: Carntet: 14
Entre 22 y 27: Carntet: 14
Menos de 17: Carntet: 48
Entre 17 y 22: Carntet: 48
Entre 22 y 27: Carntet: 48
Entre 17 y 22: Carntet: 58
Entre 22 y 27: Carntet: 58
Entre 17 y 22: Carntet: 80
Entre 22 y 27: Carntet: 80
Carnet de oro: Carntet: 80
Entre 17 y 22: Carntet: 98
Entre 22 y 27: Carntet: 98
Carnet de oro: Carntet: 98
Entre 17 y 22: Carntet: 89
Entre 22 y 27: Carntet: 89
Carnet de oro: Carntet: 89
Entre 17 y 22: Carntet: 9
Entre 22 y 27: Carntet: 9
Carnet de oro: Carntet: 9
Entre 17 y 22: Carntet: 72
Entre 22 y 27: Carntet: 72
Entre 17 y 22: Carntet: 38
Entre 22 y 27: Carntet: 38
Carnet de oro: Carntet: 38
Entre 17 y 22: Carntet: 38
Entre 22 y 27: Carntet: 38
Carnet de oro: Carntet: 38
Entre 17 y 22: Carntet: 90
Entre 22 y 27: Carntet: 90
Carnet de oro: Carntet: 90
Entre 17 y 22: Carntet: 58
Entre 22 y 27: Carntet: 58
Carnet de oro: Carntet: 58
Entre 17 y 22: Carntet: 15
Entre 22 y 27: Carntet: 15
Carnet de oro: Carntet: 15
Menos de 17: Carntet: 56
Entre 17 y 22: Carntet: 56
Entre 22 y 27: Carntet: 56
Entre 17 y 22: Carntet: 2
Entre 22 y 27: Carntet: 2
Carnet de oro: Carntet: 2
Entre 17 y 22: Carntet: 72
Entre 22 y 27: Carntet: 72
Carnet de oro: Carntet: 72
Entre 17 y 22: Carntet: 28
Entre 22 y 27: Carntet: 28
Carnet de oro: Carntet: 28
Entre 17 y 22: Carntet: 62
Entre 22 y 27: Carntet: 62
Carnet de oro: Carntet: 62
Entre 17 y 22: Carntet: 75
Entre 22 y 27: Carntet: 75
Carnet de oro: Carntet: 75
Entre 17 y 22: Carntet: 69
Entre 22 y 27: Carntet: 69
Carnet de oro: Carntet: 69
Menos de 17: Carntet: 44
Entre 17 y 22: Carntet: 44
Entre 22 y 27: Carntet: 44
Entre 17 y 22: Carntet: 81
Entre 22 y 27: Carntet: 81
Carnet de oro: Carntet: 81
Entre 17 y 22: Carntet: 22
Entre 22 y 27: Carntet: 22
Carnet de oro: Carntet: 22
Entre 17 y 22: Carntet: 21
Entre 22 y 27: Carntet: 21
Carnet de oro: Carntet: 21
Entre 17 y 22: Carntet: 57
Entre 22 y 27: Carntet: 57
Carnet de oro: Carntet: 57
Entre 17 y 22: Carntet: 92
Entre 22 y 27: Carntet: 92
Carnet de oro: Carntet: 92
Menos de 17: Carntet: 75
Entre 17 y 22: Carntet: 75
Entre 22 y 27: Carntet: 75
Menos de 17: Carntet: 0
Entre 17 y 22: Carntet: 0
Entre 22 y 27: Carntet: 0
Entre 17 y 22: Carntet: 3
Entre 22 y 27: Carntet: 3
Carnet de oro: Carntet: 3
Entre 17 y 22: Carntet: 61
Entre 22 y 27: Carntet: 61
Carnet de oro: Carntet: 61
Entre 17 y 22: Carntet: 1
Entre 22 y 27: Carntet: 1
Carnet de oro: Carntet: 1
Entre 17 y 22: Carntet: 55
Entre 22 y 27: Carntet: 55
Entre 17 y 22: Carntet: 2
Entre 22 y 27: Carntet: 2
Carnet de oro: Carntet: 2
Entre 17 y 22: Carntet: 82
Entre 22 y 27: Carntet: 82
Carnet de oro: Carntet: 82
Entre 17 y 22: Carntet: 88
Entre 22 y 27: Carntet: 88
Carnet de oro: Carntet: 88
Entre 17 y 22: Carntet: 17
Entre 22 y 27: Carntet: 17
Carnet de oro: Carntet: 17
Entre 17 y 22: Carntet: 32
Entre 22 y 27: Carntet: 32
Carnet de oro: Carntet: 32
Entre 17 y 22: Carntet: 69
Entre 22 y 27: Carntet: 69
Carnet de oro: Carntet: 69
Entre 17 y 22: Carntet: 21
Entre 22 y 27: Carntet: 21
Carnet de oro: Carntet: 21
Entre 17 y 22: Carntet: 76
Entre 22 y 27: Carntet: 76
Carnet de oro: Carntet: 76
Entre 17 y 22: Carntet: 68
Entre 22 y 27: Carntet: 68
Carnet de oro: Carntet: 68
Entre 17 y 22: Carntet: 25
Entre 22 y 27: Carntet: 25
Carnet de oro: Carntet: 25
Entre 17 y 22: Carntet: 34
Entre 22 y 27: Carntet: 34
Carnet de oro: Carntet: 34
Menos de 17: Carntet: 41
Entre 17 y 22: Carntet: 41
Entre 22 y 27: Carntet: 41
Entre 17 y 22: Carntet: 45
Entre 22 y 27: Carntet: 45
Carnet de oro: Carntet: 45
Entre 17 y 22: Carntet: 18
Entre 22 y 27: Carntet: 18
Carnet de oro: Carntet: 18
Entre 17 y 22: Carntet: 39
Entre 22 y 27: Carntet: 39
Entre 17 y 22: Carntet: 79
Entre 22 y 27: Carntet: 79
Carnet de oro: Carntet: 79
Entre 17 y 22: Carntet: 87
Entre 22 y 27: Carntet: 87
Carnet de oro: Carntet: 87
Entre 17 y 22: Carntet: 49
Entre 22 y 27: Carntet: 49
Carnet de oro: Carntet: 49
Entre 17 y 22: Carntet: 66
Entre 22 y 27: Carntet: 66
Carnet de oro: Carntet: 66
Entre 17 y 22: Carntet: 93
Entre 22 y 27: Carntet: 93
Carnet de oro: Carntet: 93
Menos de 17: Carntet: 97
Entre 17 y 22: Carntet: 97
Entre 22 y 27: Carntet: 97
Menos de 17: Carntet: 86
Entre 17 y 22: Carntet: 86
Entre 22 y 27: Carntet: 86
Entre 17 y 22: Carntet: 88
Entre 22 y 27: Carntet: 88
Carnet de oro: Carntet: 88
Entre 17 y 22: Carntet: 55
Entre 22 y 27: Carntet: 55
Carnet de oro: Carntet: 55
Menos de 17: Carntet: 14
Entre 17 y 22: Carntet: 14
Entre 22 y 27: Carntet: 14
Entre 17 y 22: Carntet: 16
Entre 22 y 27: Carntet: 16
Carnet de oro: Carntet: 16
Entre 17 y 22: Carntet: 86
Entre 22 y 27: Carntet: 86
Carnet de oro: Carntet: 86
Entre 17 y 22: Carntet: 13
Entre 22 y 27: Carntet: 13
Carnet de oro: Carntet: 13
Entre 17 y 22: Carntet: 85
Entre 22 y 27: Carntet: 85
Carnet de oro: Carntet: 85
Menos de 17: Carntet: 12
Entre 17 y 22: Carntet: 12
Entre 22 y 27: Carntet: 12
Entre 17 y 22: Carntet: 32
Entre 22 y 27: Carntet: 32
Carnet de oro: Carntet: 32
Entre 17 y 22: Carntet: 13
Entre 22 y 27: Carntet: 13
Carnet de oro: Carntet: 13
Entre 17 y 22: Carntet: 21
Entre 22 y 27: Carntet: 21
Carnet de oro: Carntet: 21
Entre 17 y 22: Carntet: 46
Entre 22 y 27: Carntet: 46
Carnet de oro: Carntet: 46
Entre 17 y 22: Carntet: 81
Entre 22 y 27: Carntet: 81
Carnet de oro: Carntet: 81
Entre 17 y 22: Carntet: 96
Entre 22 y 27: Carntet: 96
Entre 17 y 22: Carntet: 29
Entre 22 y 27: Carntet: 29
Carnet de oro: Carntet: 29
Entre 17 y 22: Carntet: 35
Entre 22 y 27: Carntet: 35
Carnet de oro: Carntet: 35
Entre 17 y 22: Carntet: 73
Entre 22 y 27: Carntet: 73
Carnet de oro: Carntet: 73
Entre 17 y 22: Carntet: 44
Entre 22 y 27: Carntet: 44
Carnet de oro: Carntet: 44
Entre 17 y 22: Carntet: 92
Entre 22 y 27: Carntet: 92
Carnet de oro: Carntet: 92
Entre 17 y 22: Carntet: 53
Entre 22 y 27: Carntet: 53
Menos de 17: Carntet: 54
Entre 17 y 22: Carntet: 54
Entre 22 y 27: Carntet: 54
Entre 17 y 22: Carntet: 45
Entre 22 y 27: Carntet: 45
Carnet de oro: Carntet: 45
Menos de 17: Carntet: 86
Entre 17 y 22: Carntet: 86
Entre 22 y 27: Carntet: 86
Entre 17 y 22: Carntet: 74
Entre 22 y 27: Carntet: 74
Entre 17 y 22: Carntet: 68
Entre 22 y 27: Carntet: 68
Menos de 17: Carntet: 87
Entre 17 y 22: Carntet: 87
Entre 22 y 27: Carntet: 87
Entre 17 y 22: Carntet: 58
Entre 22 y 27: Carntet: 58
Carnet de oro: Carntet: 58
Entre 17 y 22: Carntet: 2
Entre 22 y 27: Carntet: 2
Menos de 17: Carntet: 77
Entre 17 y 22: Carntet: 77
Entre 22 y 27: Carntet: 77
Entre 17 y 22: Carntet: 14
Entre 22 y 27: Carntet: 14
Entre 17 y 22: Carntet: 34
Entre 22 y 27: Carntet: 34
Carnet de oro: Carntet: 34
Entre 17 y 22: Carntet: 72
Entre 22 y 27: Carntet: 72
Carnet de oro: Carntet: 72
Entre 17 y 22: Carntet: 33
Entre 22 y 27: Carntet: 33
Carnet de oro: Carntet: 33
Entre 17 y 22: Carntet: 87
Entre 22 y 27: Carntet: 87
Carnet de oro: Carntet: 87
Entre 17 y 22: Carntet: 18
Entre 22 y 27: Carntet: 18
Carnet de oro: Carntet: 18
Entre 17 y 22: Carntet: 73
Entre 22 y 27: Carntet: 73
Carnet de oro: Carntet: 73
Entre 17 y 22: Carntet: 63
Entre 22 y 27: Carntet: 63
Carnet de oro: Carntet: 63
Entre 17 y 22: Carntet: 92
Entre 22 y 27: Carntet: 92
Carnet de oro: Carntet: 92
Entre 17 y 22: Carntet: 2
Entre 22 y 27: Carntet: 2
Carnet de oro: Carntet: 2
Entre 17 y 22: Carntet: 13
Entre 22 y 27: Carntet: 13
Carnet de oro: Carntet: 13
Entre 17 y 22: Carntet: 2
Entre 22 y 27: Carntet: 2
Carnet de oro: Carntet: 2
Entre 17 y 22: Carntet: 27
Entre 22 y 27: Carntet: 27
Entre 17 y 22: Carntet: 43
Entre 22 y 27: Carntet: 43
Entre 17 y 22: Carntet: 23
Entre 22 y 27: Carntet: 23
Carnet de oro: Carntet: 23
Entre 17 y 22: Carntet: 61
Entre 22 y 27: Carntet: 61
Carnet de oro: Carntet: 61
Entre 17 y 22: Carntet: 3
Entre 22 y 27: Carntet: 3
Carnet de oro: Carntet: 3
Entre 17 y 22: Carntet: 5
Entre 22 y 27: Carntet: 5
Carnet de oro: Carntet: 5
Entre 17 y 22: Carntet: 25
Entre 22 y 27: Carntet: 25
Carnet de oro: Carntet: 25
Entre 17 y 22: Carntet: 92
Entre 22 y 27: Carntet: 92
Carnet de oro: Carntet: 92
Entre 17 y 22: Carntet: 22
Entre 22 y 27: Carntet: 22
Carnet de oro: Carntet: 22
Menos de 17: Carntet: 64
Entre 17 y 22: Carntet: 64
Entre 22 y 27: Carntet: 64
Entre 17 y 22: Carntet: 87
Entre 22 y 27: Carntet: 87
Carnet de oro: Carntet: 87
Entre 17 y 22: Carntet: 13
Entre 22 y 27: Carntet: 13
Carnet de oro: Carntet: 13
Entre 17 y 22: Carntet: 70
Entre 22 y 27: Carntet: 70
Carnet de oro: Carntet: 70
Entre 17 y 22: Carntet: 35
Entre 22 y 27: Carntet: 35
Carnet de oro: Carntet: 35
Entre 17 y 22: Carntet: 11
Entre 22 y 27: Carntet: 11
Carnet de oro: Carntet: 11
Entre 17 y 22: Carntet: 96
Entre 22 y 27: Carntet: 96
Carnet de oro: Carntet: 96
Entre 17 y 22: Carntet: 85
Entre 22 y 27: Carntet: 85
Carnet de oro: Carntet: 85
Entre 17 y 22: Carntet: 40
Entre 22 y 27: Carntet: 40
Carnet de oro: Carntet: 40
Entre 17 y 22: Carntet: 95
Entre 22 y 27: Carntet: 95
Entre 17 y 22: Carntet: 19
Entre 22 y 27: Carntet: 19
Entre 17 y 22: Carntet: 76
Entre 22 y 27: Carntet: 76
Carnet de oro: Carntet: 76
Menos de 17: Carntet: 58
Entre 17 y 22: Carntet: 58
Entre 22 y 27: Carntet: 58
Entre 17 y 22: Carntet: 71
Entre 22 y 27: Carntet: 71
Carnet de oro: Carntet: 71
Entre 17 y 22: Carntet: 78
Entre 22 y 27: Carntet: 78
Carnet de oro: Carntet: 78
Entre 17 y 22: Carntet: 51
Entre 22 y 27: Carntet: 51
Carnet de oro: Carntet: 51
Entre 17 y 22: Carntet: 18
Entre 22 y 27: Carntet: 18
Carnet de oro: Carntet: 18
Entre 17 y 22: Carntet: 19
Entre 22 y 27: Carntet: 19
Carnet de oro: Carntet: 19
Entre 17 y 22: Carntet: 0
Entre 22 y 27: Carntet: 0
Carnet de oro: Carntet: 0
Entre 17 y 22: Carntet: 60
Entre 22 y 27: Carntet: 60
Carnet de oro: Carntet: 60
Entre 17 y 22: Carntet: 10
Entre 22 y 27: Carntet: 10
Carnet de oro: Carntet: 10
Menos de 17: Carntet: 70
Entre 17 y 22: Carntet: 70
Entre 22 y 27: Carntet: 70
Entre 17 y 22: Carntet: 76
Entre 22 y 27: Carntet: 76
Carnet de oro: Carntet: 76
Entre 17 y 22: Carntet: 43
Entre 22 y 27: Carntet: 43
Carnet de oro: Carntet: 43
Menos de 17: Carntet: 64
Entre 17 y 22: Carntet: 64
Entre 22 y 27: Carntet: 64
Entre 17 y 22: Carntet: 82
Entre 22 y 27: Carntet: 82
Carnet de oro: Carntet: 82
Entre 17 y 22: Carntet: 65
Entre 22 y 27: Carntet: 65
Carnet de oro: Carntet: 65
Entre 17 y 22: Carntet: 77
Entre 22 y 27: Carntet: 77
Carnet de oro: Carntet: 77
Entre 17 y 22: Carntet: 25
Entre 22 y 27: Carntet: 25
Carnet de oro: Carntet: 25
Entre 17 y 22: Carntet: 29
Entre 22 y 27: Carntet: 29
Carnet de oro: Carntet: 29
Entre 17 y 22: Carntet: 23
Entre 22 y 27: Carntet: 23
Entre 17 y 22: Carntet: 2
Entre 22 y 27: Carntet: 2
Carnet de oro: Carntet: 2
Entre 17 y 22: Carntet: 23
Entre 22 y 27: Carntet: 23
Carnet de oro: Carntet: 23
Entre 17 y 22: Carntet: 37
Entre 22 y 27: Carntet: 37
Carnet de oro: Carntet: 37
Entre 17 y 22: Carntet: 95
Entre 22 y 27: Carntet: 95
Entre 17 y 22: Carntet: 64
Entre 22 y 27: Carntet: 64
Carnet de oro: Carntet: 64
Menos de 17: Carntet: 2
Entre 17 y 22: Carntet: 2
Entre 22 y 27: Carntet: 2
Entre 17 y 22: Carntet: 30
Entre 22 y 27: Carntet: 30
Carnet de oro: Carntet: 30
Entre 17 y 22: Carntet: 11
Entre 22 y 27: Carntet: 11
Carnet de oro: Carntet: 11
Entre 17 y 22: Carntet: 11
Entre 22 y 27: Carntet: 11
Carnet de oro: Carntet: 11
Entre 17 y 22: Carntet: 53
Entre 22 y 27: Carntet: 53
Entre 17 y 22: Carntet: 90
Entre 22 y 27: Carntet: 90
Entre 17 y 22: Carntet: 88
Entre 22 y 27: Carntet: 88
Carnet de oro: Carntet: 88
Entre 17 y 22: Carntet: 40
Entre 22 y 27: Carntet: 40
Carnet de oro: Carntet: 40
Entre 17 y 22: Carntet: 62
Entre 22 y 27: Carntet: 62
Carnet de oro: Carntet: 62
Menos de 17: Carntet: 0
Entre 17 y 22: Carntet: 0
Entre 22 y 27: Carntet: 0
Entre 17 y 22: Carntet: 58
Entre 22 y 27: Carntet: 58
Carnet de oro: Carntet: 58
Menos de 17: Carntet: 65
Entre 17 y 22: Carntet: 65
Entre 22 y 27: Carntet: 65
Menos de 17: Carntet: 77
Entre 17 y 22: Carntet: 77
Entre 22 y 27: Carntet: 77
Entre 17 y 22: Carntet: 58
Entre 22 y 27: Carntet: 58
Carnet de oro: Carntet: 58
Entre 17 y 22: Carntet: 3
Entre 22 y 27: Carntet: 3
Carnet de oro: Carntet: 3
Entre 17 y 22: Carntet: 57
Entre 22 y 27: Carntet: 57
Menos de 17: Carntet: 77
Entre 17 y 22: Carntet: 77
Entre 22 y 27: Carntet: 77
Entre 17 y 22: Carntet: 13
Entre 22 y 27: Carntet: 13
Carnet de oro: Carntet: 13
Entre 17 y 22: Carntet: 1
Entre 22 y 27: Carntet: 1
Carnet de oro: Carntet: 1
Entre 17 y 22: Carntet: 60
Entre 22 y 27: Carntet: 60
Carnet de oro: Carntet: 60
Entre 17 y 22: Carntet: 93
Entre 22 y 27: Carntet: 93
Carnet de oro: Carntet: 93
Entre 17 y 22: Carntet: 5
Entre 22 y 27: Carntet: 5
Carnet de oro: Carntet: 5
Menos de 17: Carntet: 11
Entre 17 y 22: Carntet: 11
Entre 22 y 27: Carntet: 11
Entre 17 y 22: Carntet: 35
Entre 22 y 27: Carntet: 35
Carnet de oro: Carntet: 35
Entre 17 y 22: Carntet: 72
Entre 22 y 27: Carntet: 72
Carnet de oro: Carntet: 72
Entre 17 y 22: Carntet: 23
Entre 22 y 27: Carntet: 23
Carnet de oro: Carntet: 23
Menos de 17: Carntet: 56
Entre 17 y 22: Carntet: 56
Entre 22 y 27: Carntet: 56
Entre 17 y 22: Carntet: 26
Entre 22 y 27: Carntet: 26
Carnet de oro: Carntet: 26
Entre 17 y 22: Carntet: 26
Entre 22 y 27: Carntet: 26
Carnet de oro: Carntet: 26
Entre 17 y 22: Carntet: 37
Entre 22 y 27: Carntet: 37
Carnet de oro: Carntet: 37
Entre 17 y 22: Carntet: 69
Entre 22 y 27: Carntet: 69
Carnet de oro: Carntet: 69
Entre 17 y 22: Carntet: 96
Entre 22 y 27: Carntet: 96
Menos de 17: Carntet: 17
Entre 17 y 22: Carntet: 17
Entre 22 y 27: Carntet: 17
Entre 17 y 22: Carntet: 17
Entre 22 y 27: Carntet: 17
Carnet de oro: Carntet: 17
Entre 17 y 22: Carntet: 85
Entre 22 y 27: Carntet: 85
Carnet de oro: Carntet: 85
Entre 17 y 22: Carntet: 23
Entre 22 y 27: Carntet: 23
Carnet de oro: Carntet: 23
Entre 17 y 22: Carntet: 29
Entre 22 y 27: Carntet: 29
Carnet de oro: Carntet: 29
Entre 17 y 22: Carntet: 59
Entre 22 y 27: Carntet: 59
Carnet de oro: Carntet: 59
Entre 17 y 22: Carntet: 96
Entre 22 y 27: Carntet: 96
Carnet de oro: Carntet: 96
Entre 17 y 22: Carntet: 53
Entre 22 y 27: Carntet: 53
Carnet de oro: Carntet: 53
Entre 17 y 22: Carntet: 84
Entre 22 y 27: Carntet: 84
Carnet de oro: Carntet: 84
Entre 17 y 22: Carntet: 54
Entre 22 y 27: Carntet: 54
Carnet de oro: Carntet: 54
Entre 17 y 22: Carntet: 57
Entre 22 y 27: Carntet: 57
Carnet de oro: Carntet: 57
Entre 17 y 22: Carntet: 32
Entre 22 y 27: Carntet: 32
Carnet de oro: Carntet: 32
Entre 17 y 22: Carntet: 7
Entre 22 y 27: Carntet: 7
Carnet de oro: Carntet: 7
Entre 17 y 22: Carntet: 11
Entre 22 y 27: Carntet: 11
Carnet de oro: Carntet: 11
Entre 17 y 22: Carntet: 67
Entre 22 y 27: Carntet: 67
Carnet de oro: Carntet: 67
Entre 17 y 22: Carntet: 75
Entre 22 y 27: Carntet: 75
Carnet de oro: Carntet: 75
Entre 17 y 22: Carntet: 23
Entre 22 y 27: Carntet: 23
Carnet de oro: Carntet: 23
Menos de 17: Carntet: 54
Entre 17 y 22: Carntet: 54
Entre 22 y 27: Carntet: 54
Entre 17 y 22: Carntet: 41
Entre 22 y 27: Carntet: 41
Carnet de oro: Carntet: 41
Entre 17 y 22: Carntet: 59
Entre 22 y 27: Carntet: 59
Entre 17 y 22: Carntet: 21
Entre 22 y 27: Carntet: 21
Carnet de oro: Carntet: 21
Entre 17 y 22: Carntet: 26
Entre 22 y 27: Carntet: 26
Carnet de oro: Carntet: 26
Entre 17 y 22: Carntet: 5
Entre 22 y 27: Carntet: 5
Carnet de oro: Carntet: 5
Entre 17 y 22: Carntet: 50
Entre 22 y 27: Carntet: 50
Carnet de oro: Carntet: 50
Menos de 17: Carntet: 79
Entre 17 y 22: Carntet: 79
Entre 22 y 27: Carntet: 79
Entre 17 y 22: Carntet: 93
Entre 22 y 27: Carntet: 93
Carnet de oro: Carntet: 93
Entre 17 y 22: Carntet: 37
Entre 22 y 27: Carntet: 37
Carnet de oro: Carntet: 37
Entre 17 y 22: Carntet: 56
Entre 22 y 27: Carntet: 56
Carnet de oro: Carntet: 56
Menos de 17: Carntet: 76
Entre 17 y 22: Carntet: 76
Entre 22 y 27: Carntet: 76
Entre 17 y 22: Carntet: 62
Entre 22 y 27: Carntet: 62
Carnet de oro: Carntet: 62
Menos de 17: Carntet: 81
Entre 17 y 22: Carntet: 81
Entre 22 y 27: Carntet: 81
Entre 17 y 22: Carntet: 13
Entre 22 y 27: Carntet: 13
Carnet de oro: Carntet: 13
Entre 17 y 22: Carntet: 55
Entre 22 y 27: Carntet: 55
Carnet de oro: Carntet: 55
Entre 17 y 22: Carntet: 42
Entre 22 y 27: Carntet: 42
Carnet de oro: Carntet: 42
Entre 17 y 22: Carntet: 11
Entre 22 y 27: Carntet: 11
Carnet de oro: Carntet: 11
Entre 17 y 22: Carntet: 24
Entre 22 y 27: Carntet: 24
Carnet de oro: Carntet: 24
Entre 17 y 22: Carntet: 52
Entre 22 y 27: Carntet: 52
Carnet de oro: Carntet: 52
Entre 17 y 22: Carntet: 96
Entre 22 y 27: Carntet: 96
Carnet de oro: Carntet: 96
Menos de 17: Carntet: 40
Entre 17 y 22: Carntet: 40
Entre 22 y 27: Carntet: 40
Entre 17 y 22: Carntet: 75
Entre 22 y 27: Carntet: 75
Carnet de oro: Carntet: 75
Menos de 17: Carntet: 18
Entre 17 y 22: Carntet: 18
Entre 22 y 27: Carntet: 18
Entre 17 y 22: Carntet: 17
Entre 22 y 27: Carntet: 17
Carnet de oro: Carntet: 17
Entre 17 y 22: Carntet: 12
Entre 22 y 27: Carntet: 12
Carnet de oro: Carntet: 12
Entre 17 y 22: Carntet: 69
Entre 22 y 27: Carntet: 69
Carnet de oro: Carntet: 69
Entre 17 y 22: Carntet: 40
Entre 22 y 27: Carntet: 40
Carnet de oro: Carntet: 40
Entre 17 y 22: Carntet: 85
Entre 22 y 27: Carntet: 85
Carnet de oro: Carntet: 85
Entre 17 y 22: Carntet: 97
Entre 22 y 27: Carntet: 97
Carnet de oro: Carntet: 97
Entre 17 y 22: Carntet: 90
Entre 22 y 27: Carntet: 90
Carnet de oro: Carntet: 90
Menos de 17: Carntet: 53
Entre 17 y 22: Carntet: 53
Entre 22 y 27: Carntet: 53
Entre 17 y 22: Carntet: 51
Entre 22 y 27: Carntet: 51
Carnet de oro: Carntet: 51
Entre 17 y 22: Carntet: 44
Entre 22 y 27: Carntet: 44
Carnet de oro: Carntet: 44
Entre 17 y 22: Carntet: 35
Entre 22 y 27: Carntet: 35
Carnet de oro: Carntet: 35
Menos de 17: Carntet: 92
Entre 17 y 22: Carntet: 92
Entre 22 y 27: Carntet: 92
Entre 17 y 22: Carntet: 64
Entre 22 y 27: Carntet: 64
Carnet de oro: Carntet: 64
Entre 17 y 22: Carntet: 3
Entre 22 y 27: Carntet: 3
Carnet de oro: Carntet: 3
Menos de 17: Carntet: 75
Entre 17 y 22: Carntet: 75
Entre 22 y 27: Carntet: 75
Entre 17 y 22: Carntet: 92
Entre 22 y 27: Carntet: 92
Carnet de oro: Carntet: 92
Entre 17 y 22: Carntet: 49
Entre 22 y 27: Carntet: 49
Carnet de oro: Carntet: 49
Entre 17 y 22: Carntet: 61
Entre 22 y 27: Carntet: 61
Carnet de oro: Carntet: 61
Entre 17 y 22: Carntet: 67
Entre 22 y 27: Carntet: 67
Carnet de oro: Carntet: 67
Entre 17 y 22: Carntet: 29
Entre 22 y 27: Carntet: 29
Carnet de oro: Carntet: 29
Entre 17 y 22: Carntet: 13
Entre 22 y 27: Carntet: 13
Carnet de oro: Carntet: 13
Entre 17 y 22: Carntet: 1
Entre 22 y 27: Carntet: 1
Carnet de oro: Carntet: 1
Entre 17 y 22: Carntet: 15
Entre 22 y 27: Carntet: 15
Carnet de oro: Carntet: 15
Entre 17 y 22: Carntet: 13
Entre 22 y 27: Carntet: 13
Carnet de oro: Carntet: 13
Menos de 17: Carntet: 24
Entre 17 y 22: Carntet: 24
Entre 22 y 27: Carntet: 24
Entre 17 y 22: Carntet: 92
Entre 22 y 27: Carntet: 92
Carnet de oro: Carntet: 92
Entre 17 y 22: Carntet: 70
Entre 22 y 27: Carntet: 70
Carnet de oro: Carntet: 70
Entre 17 y 22: Carntet: 27
Entre 22 y 27: Carntet: 27
Carnet de oro: Carntet: 27
Entre 17 y 22: Carntet: 75
Entre 22 y 27: Carntet: 75
Carnet de oro: Carntet: 75
Entre 17 y 22: Carntet: 98
Entre 22 y 27: Carntet: 98
Carnet de oro: Carntet: 98
Entre 17 y 22: Carntet: 87
Entre 22 y 27: Carntet: 87
Carnet de oro: Carntet: 87
Menos de 17: Carntet: 4
Entre 17 y 22: Carntet: 4
Entre 22 y 27: Carntet: 4
Entre 17 y 22: Carntet: 21
Entre 22 y 27: Carntet: 21
Carnet de oro: Carntet: 21
Entre 17 y 22: Carntet: 6
Entre 22 y 27: Carntet: 6
Carnet de oro: Carntet: 6
Entre 17 y 22: Carntet: 10
Entre 22 y 27: Carntet: 10
Carnet de oro: Carntet: 10
Entre 17 y 22: Carntet: 89
Entre 22 y 27: Carntet: 89
Carnet de oro: Carntet: 89
Entre 17 y 22: Carntet: 64
Entre 22 y 27: Carntet: 64
Carnet de oro: Carntet: 64
Menos de 17: Carntet: 19
Entre 17 y 22: Carntet: 19
Entre 22 y 27: Carntet: 19
Menos de 17: Carntet: 91
Entre 17 y 22: Carntet: 91
Entre 22 y 27: Carntet: 91
Entre 17 y 22: Carntet: 18
Entre 22 y 27: Carntet: 18
Carnet de oro: Carntet: 18
Menos de 17: Carntet: 50
Entre 17 y 22: Carntet: 50
Entre 22 y 27: Carntet: 50
Entre 17 y 22: Carntet: 75
Entre 22 y 27: Carntet: 75
Carnet de oro: Carntet: 75
Entre 17 y 22: Carntet: 3
Entre 22 y 27: Carntet: 3
Entre 17 y 22: Carntet: 98
Entre 22 y 27: Carntet: 98
Carnet de oro: Carntet: 98
Entre 17 y 22: Carntet: 84
Entre 22 y 27: Carntet: 84
Carnet de oro: Carntet: 84
Entre 17 y 22: Carntet: 71
Entre 22 y 27: Carntet: 71
Carnet de oro: Carntet: 71
Entre 17 y 22: Carntet: 13
Entre 22 y 27: Carntet: 13
Carnet de oro: Carntet: 13
Menos de 17: Carntet: 45
Entre 17 y 22: Carntet: 45
Entre 22 y 27: Carntet: 45
Entre 17 y 22: Carntet: 46
Entre 22 y 27: Carntet: 46
Carnet de oro: Carntet: 46
Entre 17 y 22: Carntet: 69
Entre 22 y 27: Carntet: 69
Carnet de oro: Carntet: 69
Entre 17 y 22: Carntet: 19
Entre 22 y 27: Carntet: 19
Carnet de oro: Carntet: 19
Entre 17 y 22: Carntet: 89
Entre 22 y 27: Carntet: 89
Carnet de oro: Carntet: 89
Entre 17 y 22: Carntet: 65
Entre 22 y 27: Carntet: 65
Carnet de oro: Carntet: 65
Menos de 17: Carntet: 45
Entre 17 y 22: Carntet: 45
Entre 22 y 27: Carntet: 45
Entre 17 y 22: Carntet: 18
Entre 22 y 27: Carntet: 18
Carnet de oro: Carntet: 18
Entre 17 y 22: Carntet: 1
Entre 22 y 27: Carntet: 1
Entre 17 y 22: Carntet: 32
Entre 22 y 27: Carntet: 32
Carnet de oro: Carntet: 32
Entre 17 y 22: Carntet: 52
Entre 22 y 27: Carntet: 52
Carnet de oro: Carntet: 52
Entre 17 y 22: Carntet: 70
Entre 22 y 27: Carntet: 70
Carnet de oro: Carntet: 70
Menos de 17: Carntet: 1
Entre 17 y 22: Carntet: 1
Entre 22 y 27: Carntet: 1
Entre 17 y 22: Carntet: 23
Entre 22 y 27: Carntet: 23
Carnet de oro: Carntet: 23
Entre 17 y 22: Carntet: 0
Entre 22 y 27: Carntet: 0
Carnet de oro: Carntet: 0
Entre 17 y 22: Carntet: 15
Entre 22 y 27: Carntet: 15
Carnet de oro: Carntet: 15
Entre 17 y 22: Carntet: 28
Entre 22 y 27: Carntet: 28
Carnet de oro: Carntet: 28
Entre 17 y 22: Carntet: 47
Entre 22 y 27: Carntet: 47
Carnet de oro: Carntet: 47
Entre 17 y 22: Carntet: 43
Entre 22 y 27: Carntet: 43
Carnet de oro: Carntet: 43
Entre 17 y 22: Carntet: 9
Entre 22 y 27: Carntet: 9
Carnet de oro: Carntet: 9
Entre 17 y 22: Carntet: 49
Entre 22 y 27: Carntet: 49
Carnet de oro: Carntet: 49
Entre 17 y 22: Carntet: 88
Entre 22 y 27: Carntet: 88
Carnet de oro: Carntet: 88
Entre 17 y 22: Carntet: 8
Entre 22 y 27: Carntet: 8
Carnet de oro: Carntet: 8
Entre 17 y 22: Carntet: 21
Entre 22 y 27: Carntet: 21
Carnet de oro: Carntet: 21
Entre 17 y 22: Carntet: 54
Entre 22 y 27: Carntet: 54
Carnet de oro: Carntet: 54
Entre 17 y 22: Carntet: 46
Entre 22 y 27: Carntet: 46
Carnet de oro: Carntet: 46
Entre 17 y 22: Carntet: 49
Entre 22 y 27: Carntet: 49
Carnet de oro: Carntet: 49
Entre 17 y 22: Carntet: 30
Entre 22 y 27: Carntet: 30
Entre 17 y 22: Carntet: 48
Entre 22 y 27: Carntet: 48
Carnet de oro: Carntet: 48
Entre 17 y 22: Carntet: 36
Entre 22 y 27: Carntet: 36
Carnet de oro: Carntet: 36
Entre 17 y 22: Carntet: 35
Entre 22 y 27: Carntet: 35
Carnet de oro: Carntet: 35
Entre 17 y 22: Carntet: 85
Entre 22 y 27: Carntet: 85
Carnet de oro: Carntet: 85
Entre 17 y 22: Carntet: 53
Entre 22 y 27: Carntet: 53
Carnet de oro: Carntet: 53
Entre 17 y 22: Carntet: 24
Entre 22 y 27: Carntet: 24
Carnet de oro: Carntet: 24
Entre 17 y 22: Carntet: 23
Entre 22 y 27: Carntet: 23
Carnet de oro: Carntet: 23
Entre 17 y 22: Carntet: 57
Entre 22 y 27: Carntet: 57
Carnet de oro: Carntet: 57
Entre 17 y 22: Carntet: 44
Entre 22 y 27: Carntet: 44
Carnet de oro: Carntet: 44
Entre 17 y 22: Carntet: 18
Entre 22 y 27: Carntet: 18
Carnet de oro: Carntet: 18
Entre 17 y 22: Carntet: 11
Entre 22 y 27: Carntet: 11
Menos de 17: Carntet: 55
Entre 17 y 22: Carntet: 55
Entre 22 y 27: Carntet: 55
Entre 17 y 22: Carntet: 49
Entre 22 y 27: Carntet: 49
Carnet de oro: Carntet: 49
Menos de 17: Carntet: 84
Entre 17 y 22: Carntet: 84
Entre 22 y 27: Carntet: 84
Entre 17 y 22: Carntet: 64
Entre 22 y 27: Carntet: 64
Carnet de oro: Carntet: 64
Menos de 17: Carntet: 75
Entre 17 y 22: Carntet: 75
Entre 22 y 27: Carntet: 75
Entre 17 y 22: Carntet: 42
Entre 22 y 27: Carntet: 42
Carnet de oro: Carntet: 42
Entre 17 y 22: Carntet: 48
Entre 22 y 27: Carntet: 48
Carnet de oro: Carntet: 48
Menos de 17: Carntet: 26
Entre 17 y 22: Carntet: 26
Entre 22 y 27: Carntet: 26
Entre 17 y 22: Carntet: 73
Entre 22 y 27: Carntet: 73
Carnet de oro: Carntet: 73
Menos de 17: Carntet: 4
Entre 17 y 22: Carntet: 4
Entre 22 y 27: Carntet: 4
Menos de 17: Carntet: 26
Entre 17 y 22: Carntet: 26
Entre 22 y 27: Carntet: 26
Entre 17 y 22: Carntet: 75
Entre 22 y 27: Carntet: 75
Carnet de oro: Carntet: 75
Entre 17 y 22: Carntet: 65
Entre 22 y 27: Carntet: 65
Carnet de oro: Carntet: 65
Entre 17 y 22: Carntet: 36
Entre 22 y 27: Carntet: 36
Carnet de oro: Carntet: 36
Entre 17 y 22: Carntet: 14
Entre 22 y 27: Carntet: 14
Carnet de oro: Carntet: 14
Entre 17 y 22: Carntet: 56
Entre 22 y 27: Carntet: 56
Carnet de oro: Carntet: 56
Entre 17 y 22: Carntet: 36
Entre 22 y 27: Carntet: 36
Carnet de oro: Carntet: 36
Entre 17 y 22: Carntet: 82
Entre 22 y 27: Carntet: 82
Carnet de oro: Carntet: 82
Entre 17 y 22: Carntet: 15
Entre 22 y 27: Carntet: 15
Carnet de oro: Carntet: 15
Entre 17 y 22: Carntet: 30
Entre 22 y 27: Carntet: 30
Carnet de oro: Carntet: 30
Menos de 17: Carntet: 25
Entre 17 y 22: Carntet: 25
Entre 22 y 27: Carntet: 25
Entre 17 y 22: Carntet: 37
Entre 22 y 27: Carntet: 37
Carnet de oro: Carntet: 37
Entre 17 y 22: Carntet: 90
Entre 22 y 27: Carntet: 90
Carnet de oro: Carntet: 90
Entre 17 y 22: Carntet: 62
Entre 22 y 27: Carntet: 62
Carnet de oro: Carntet: 62
Entre 17 y 22: Carntet: 93
Entre 22 y 27: Carntet: 93
Carnet de oro: Carntet: 93
Entre 17 y 22: Carntet: 16
Entre 22 y 27: Carntet: 16
Carnet de oro: Carntet: 16
Entre 17 y 22: Carntet: 8
Entre 22 y 27: Carntet: 8
Carnet de oro: Carntet: 8
Entre 17 y 22: Carntet: 33
Entre 22 y 27: Carntet: 33
Carnet de oro: Carntet: 33
Entre 17 y 22: Carntet: 3
Entre 22 y 27: Carntet: 3
Carnet de oro: Carntet: 3
Entre 17 y 22: Carntet: 3
Entre 22 y 27: Carntet: 3
Carnet de oro: Carntet: 3
Entre 17 y 22: Carntet: 48
Entre 22 y 27: Carntet: 48
Menos de 17: Carntet: 17
Entre 17 y 22: Carntet: 17
Entre 22 y 27: Carntet: 17
Entre 17 y 22: Carntet: 9
Entre 22 y 27: Carntet: 9
Carnet de oro: Carntet: 9
Entre 17 y 22: Carntet: 0
Entre 22 y 27: Carntet: 0
Carnet de oro: Carntet: 0
Entre 17 y 22: Carntet: 18
Entre 22 y 27: Carntet: 18
Carnet de oro: Carntet: 18
Entre 17 y 22: Carntet: 50
Entre 22 y 27: Carntet: 50
Carnet de oro: Carntet: 50
Entre 17 y 22: Carntet: 61
Entre 22 y 27: Carntet: 61
Carnet de oro: Carntet: 61
Entre 17 y 22: Carntet: 3
Entre 22 y 27: Carntet: 3
Carnet de oro: Carntet: 3
Menos de 17: Carntet: 43
Entre 17 y 22: Carntet: 43
Entre 22 y 27: Carntet: 43
Entre 17 y 22: Carntet: 2
Entre 22 y 27: Carntet: 2
Carnet de oro: Carntet: 2
Entre 17 y 22: Carntet: 89
Entre 22 y 27: Carntet: 89
Carnet de oro: Carntet: 89
Entre 17 y 22: Carntet: 82
Entre 22 y 27: Carntet: 82
Carnet de oro: Carntet: 82
Entre 17 y 22: Carntet: 74
Entre 22 y 27: Carntet: 74
Entre 17 y 22: Carntet: 2
Entre 22 y 27: Carntet: 2
Entre 17 y 22: Carntet: 31
Entre 22 y 27: Carntet: 31
Carnet de oro: Carntet: 31
Entre 17 y 22: Carntet: 78
Entre 22 y 27: Carntet: 78
Carnet de oro: Carntet: 78
Entre 17 y 22: Carntet: 8
Entre 22 y 27: Carntet: 8
Menos de 17: Carntet: 71
Entre 17 y 22: Carntet: 71
Entre 22 y 27: Carntet: 71
Entre 17 y 22: Carntet: 45
Entre 22 y 27: Carntet: 45
Carnet de oro: Carntet: 45
Entre 17 y 22: Carntet: 4
Entre 22 y 27: Carntet: 4
Carnet de oro: Carntet: 4
Menos de 17: Carntet: 85
Entre 17 y 22: Carntet: 85
Entre 22 y 27: Carntet: 85
Entre 17 y 22: Carntet: 98
Entre 22 y 27: Carntet: 98
Carnet de oro: Carntet: 98
Entre 17 y 22: Carntet: 22
Entre 22 y 27: Carntet: 22
Carnet de oro: Carntet: 22
Menos de 17: Carntet: 37
Entre 17 y 22: Carntet: 37
Entre 22 y 27: Carntet: 37
Entre 17 y 22: Carntet: 61
Entre 22 y 27: Carntet: 61
Carnet de oro: Carntet: 61
Entre 17 y 22: Carntet: 8
Entre 22 y 27: Carntet: 8
Carnet de oro: Carntet: 8
Entre 17 y 22: Carntet: 59
Entre 22 y 27: Carntet: 59
Carnet de oro: Carntet: 59
Entre 17 y 22: Carntet: 15
Entre 22 y 27: Carntet: 15
Carnet de oro: Carntet: 15
Entre 17 y 22: Carntet: 37
Entre 22 y 27: Carntet: 37
Carnet de oro: Carntet: 37
Menos de 17: Carntet: 58
Entre 17 y 22: Carntet: 58
Entre 22 y 27: Carntet: 58
Entre 17 y 22: Carntet: 71
Entre 22 y 27: Carntet: 71
Carnet de oro: Carntet: 71
Menos de 17: Carntet: 17
Entre 17 y 22: Carntet: 17
Entre 22 y 27: Carntet: 17
Menos de 17: Carntet: 55
Entre 17 y 22: Carntet: 55
Entre 22 y 27: Carntet: 55
Entre 17 y 22: Carntet: 30
Entre 22 y 27: Carntet: 30
Carnet de oro: Carntet: 30
Entre 17 y 22: Carntet: 12
Entre 22 y 27: Carntet: 12
Carnet de oro: Carntet: 12
Entre 17 y 22: Carntet: 82
Entre 22 y 27: Carntet: 82
Carnet de oro: Carntet: 82
Menos de 17: Carntet: 85
Entre 17 y 22: Carntet: 85
Entre 22 y 27: Carntet: 85
Entre 17 y 22: Carntet: 84
Entre 22 y 27: Carntet: 84
Carnet de oro: Carntet: 84
Menos de 17: Carntet: 80
Entre 17 y 22: Carntet: 80
Entre 22 y 27: Carntet: 80
Entre 17 y 22: Carntet: 51
Entre 22 y 27: Carntet: 51
Carnet de oro: Carntet: 51
Entre 17 y 22: Carntet: 15
Entre 22 y 27: Carntet: 15
Carnet de oro: Carntet: 15
Entre 17 y 22: Carntet: 10
Entre 22 y 27: Carntet: 10
Carnet de oro: Carntet: 10
Entre 17 y 22: Carntet: 73
Entre 22 y 27: Carntet: 73
Carnet de oro: Carntet: 73
Entre 17 y 22: Carntet: 77
Entre 22 y 27: Carntet: 77
Carnet de oro: Carntet: 77
Entre 17 y 22: Carntet: 56
Entre 22 y 27: Carntet: 56
Carnet de oro: Carntet: 56
Menos de 17: Carntet: 13
Entre 17 y 22: Carntet: 13
Entre 22 y 27: Carntet: 13
Entre 17 y 22: Carntet: 41
Entre 22 y 27: Carntet: 41
Carnet de oro: Carntet: 41
Entre 17 y 22: Carntet: 23
Entre 22 y 27: Carntet: 23
Carnet de oro: Carntet: 23
Entre 17 y 22: Carntet: 28
Entre 22 y 27: Carntet: 28
Carnet de oro: Carntet: 28
Menos de 17: Carntet: 78
Entre 17 y 22: Carntet: 78
Entre 22 y 27: Carntet: 78
Entre 17 y 22: Carntet: 71
Entre 22 y 27: Carntet: 71
Carnet de oro: Carntet: 71
Entre 17 y 22: Carntet: 74
Entre 22 y 27: Carntet: 74
Carnet de oro: Carntet: 74
Entre 17 y 22: Carntet: 33
Entre 22 y 27: Carntet: 33
Carnet de oro: Carntet: 33
Entre 17 y 22: Carntet: 53
Entre 22 y 27: Carntet: 53
Carnet de oro: Carntet: 53
Entre 17 y 22: Carntet: 68
Entre 22 y 27: Carntet: 68
Entre 17 y 22: Carntet: 76
Entre 22 y 27: Carntet: 76
Carnet de oro: Carntet: 76
Entre 17 y 22: Carntet: 50
Entre 22 y 27: Carntet: 50
Carnet de oro: Carntet: 50
Entre 17 y 22: Carntet: 9
Entre 22 y 27: Carntet: 9
Carnet de oro: Carntet: 9
Entre 17 y 22: Carntet: 86
Entre 22 y 27: Carntet: 86
Carnet de oro: Carntet: 86
Entre 17 y 22: Carntet: 16
Entre 22 y 27: Carntet: 16
Carnet de oro: Carntet: 16

AL darle la vuelta:
Edad: 49 Carnet: 16
Edad: 80 Carnet: 86
Edad: 93 Carnet: 9
Edad: 98 Carnet: 50
Edad: 29 Carnet: 76
Edad: 25 Carnet: 68
Edad: 95 Carnet: 53
Edad: 67 Carnet: 33
Edad: 71 Carnet: 74
Edad: 85 Carnet: 71
Edad: 0 Carnet: 78
Edad: 84 Carnet: 28
Edad: 63 Carnet: 23
Edad: 90 Carnet: 41
Edad: 8 Carnet: 13
Edad: 89 Carnet: 56
Edad: 32 Carnet: 77
Edad: 88 Carnet: 73
Edad: 98 Carnet: 10
Edad: 79 Carnet: 15
Edad: 41 Carnet: 51
Edad: 15 Carnet: 80
Edad: 74 Carnet: 84
Edad: 10 Carnet: 85
Edad: 54 Carnet: 82
Edad: 88 Carnet: 12
Edad: 39 Carnet: 30
Edad: 15 Carnet: 55
Edad: 15 Carnet: 17
Edad: 64 Carnet: 71
Edad: 0 Carnet: 58
Edad: 69 Carnet: 37
Edad: 69 Carnet: 15
Edad: 93 Carnet: 59
Edad: 61 Carnet: 8
Edad: 34 Carnet: 61
Edad: 10 Carnet: 37
Edad: 38 Carnet: 22
Edad: 89 Carnet: 98
Edad: 13 Carnet: 85
Edad: 92 Carnet: 4
Edad: 81 Carnet: 45
Edad: 3 Carnet: 71
Edad: 19 Carnet: 8
Edad: 59 Carnet: 78
Edad: 69 Carnet: 31
Edad: 23 Carnet: 2
Edad: 20 Carnet: 74
Edad: 53 Carnet: 82
Edad: 48 Carnet: 89
Edad: 61 Carnet: 2
Edad: 9 Carnet: 43
Edad: 76 Carnet: 3
Edad: 64 Carnet: 61
Edad: 55 Carnet: 50
Edad: 58 Carnet: 18
Edad: 80 Carnet: 0
Edad: 28 Carnet: 9
Edad: 13 Carnet: 17
Edad: 24 Carnet: 48
Edad: 56 Carnet: 3
Edad: 34 Carnet: 3
Edad: 54 Carnet: 33
Edad: 62 Carnet: 8
Edad: 52 Carnet: 16
Edad: 53 Carnet: 93
Edad: 34 Carnet: 62
Edad: 50 Carnet: 90
Edad: 86 Carnet: 37
Edad: 11 Carnet: 25
Edad: 41 Carnet: 30
Edad: 31 Carnet: 15
Edad: 55 Carnet: 82
Edad: 38 Carnet: 36
Edad: 52 Carnet: 56
Edad: 94 Carnet: 14
Edad: 41 Carnet: 36
Edad: 36 Carnet: 65
Edad: 93 Carnet: 75
Edad: 12 Carnet: 26
Edad: 5 Carnet: 4
Edad: 29 Carnet: 73
Edad: 6 Carnet: 26
Edad: 72 Carnet: 48
Edad: 96 Carnet: 42
Edad: 13 Carnet: 75
Edad: 42 Carnet: 64
Edad: 15 Carnet: 84
Edad: 96 Carnet: 49
Edad: 1 Carnet: 55
Edad: 25 Carnet: 11
Edad: 26 Carnet: 18
Edad: 55 Carnet: 44
Edad: 66 Carnet: 57
Edad: 59 Carnet: 23
Edad: 48 Carnet: 24
Edad: 29 Carnet: 53
Edad: 38 Carnet: 85
Edad: 26 Carnet: 35
Edad: 83 Carnet: 36
Edad: 67 Carnet: 48
Edad: 20 Carnet: 30
Edad: 43 Carnet: 49
Edad: 90 Carnet: 46
Edad: 88 Carnet: 54
Edad: 58 Carnet: 21
Edad: 60 Carnet: 8
Edad: 42 Carnet: 88
Edad: 81 Carnet: 49
Edad: 63 Carnet: 9
Edad: 37 Carnet: 43
Edad: 88 Carnet: 47
Edad: 43 Carnet: 28
Edad: 65 Carnet: 15
Edad: 69 Carnet: 0
Edad: 27 Carnet: 23
Edad: 3 Carnet: 1
Edad: 63 Carnet: 70
Edad: 87 Carnet: 52
Edad: 72 Carnet: 32
Edad: 23 Carnet: 1
Edad: 70 Carnet: 18
Edad: 8 Carnet: 45
Edad: 40 Carnet: 65
Edad: 44 Carnet: 89
Edad: 85 Carnet: 19
Edad: 62 Carnet: 69
Edad: 78 Carnet: 46
Edad: 12 Carnet: 45
Edad: 75 Carnet: 13
Edad: 64 Carnet: 71
Edad: 48 Carnet: 84
Edad: 47 Carnet: 98
Edad: 22 Carnet: 3
Edad: 39 Carnet: 75
Edad: 5 Carnet: 50
Edad: 32 Carnet: 18
Edad: 4 Carnet: 91
Edad: 13 Carnet: 19
Edad: 42 Carnet: 64
Edad: 40 Carnet: 89
Edad: 71 Carnet: 10
Edad: 63 Carnet: 6
Edad: 63 Carnet: 21
Edad: 3 Carnet: 4
Edad: 47 Carnet: 87
Edad: 70 Carnet: 98
Edad: 86 Carnet: 75
Edad: 84 Carnet: 27
Edad: 28 Carnet: 70
Edad: 59 Carnet: 92
Edad: 1 Carnet: 24
Edad: 92 Carnet: 13
Edad: 83 Carnet: 15
Edad: 77 Carnet: 1
Edad: 74 Carnet: 13
Edad: 40 Carnet: 29
Edad: 41 Carnet: 67
Edad: 27 Carnet: 61
Edad: 56 Carnet: 49
Edad: 97 Carnet: 92
Edad: 8 Carnet: 75
Edad: 29 Carnet: 3
Edad: 81 Carnet: 64
Edad: 5 Carnet: 92
Edad: 59 Carnet: 35
Edad: 58 Carnet: 44
Edad: 40 Carnet: 51
Edad: 14 Carnet: 53
Edad: 45 Carnet: 90
Edad: 89 Carnet: 97
Edad: 90 Carnet: 85
Edad: 88 Carnet: 40
Edad: 31 Carnet: 69
Edad: 95 Carnet: 12
Edad: 32 Carnet: 17
Edad: 10 Carnet: 18
Edad: 72 Carnet: 75
Edad: 13 Carnet: 40
Edad: 73 Carnet: 96
Edad: 43 Carnet: 52
Edad: 78 Carnet: 24
Edad: 77 Carnet: 11
Edad: 62 Carnet: 42
Edad: 55 Carnet: 55
Edad: 41 Carnet: 13
Edad: 0 Carnet: 81
Edad: 48 Carnet: 62
Edad: 5 Carnet: 76
Edad: 93 Carnet: 56
Edad: 34 Carnet: 37
Edad: 34 Carnet: 93
Edad: 1 Carnet: 79
Edad: 98 Carnet: 50
Edad: 83 Carnet: 5
Edad: 34 Carnet: 26
Edad: 70 Carnet: 21
Edad: 25 Carnet: 59
Edad: 75 Carnet: 41
Edad: 11 Carnet: 54
Edad: 42 Carnet: 23
Edad: 38 Carnet: 75
Edad: 48 Carnet: 67
Edad: 35 Carnet: 11
Edad: 83 Carnet: 7
Edad: 63 Carnet: 32
Edad: 69 Carnet: 57
Edad: 72 Carnet: 54
Edad: 34 Carnet: 84
Edad: 62 Carnet: 53
Edad: 55 Carnet: 96
Edad: 32 Carnet: 59
Edad: 65 Carnet: 29
Edad: 29 Carnet: 23
Edad: 41 Carnet: 85
Edad: 96 Carnet: 17
Edad: 12 Carnet: 17
Edad: 22 Carnet: 96
Edad: 61 Carnet: 69
Edad: 71 Carnet: 37
Edad: 57 Carnet: 26
Edad: 57 Carnet: 26
Edad: 16 Carnet: 56
Edad: 85 Carnet: 23
Edad: 50 Carnet: 72
Edad: 56 Carnet: 35
Edad: 4 Carnet: 11
Edad: 40 Carnet: 5
Edad: 84 Carnet: 93
Edad: 28 Carnet: 60
Edad: 50 Carnet: 1
Edad: 87 Carnet: 13
Edad: 8 Carnet: 77
Edad: 24 Carnet: 57
Edad: 60 Carnet: 3
Edad: 39 Carnet: 58
Edad: 0 Carnet: 77
Edad: 7 Carnet: 65
Edad: 78 Carnet: 58
Edad: 13 Carnet: 0
Edad: 29 Carnet: 62
Edad: 51 Carnet: 40
Edad: 63 Carnet: 88
Edad: 24 Carnet: 90
Edad: 20 Carnet: 53
Edad: 47 Carnet: 11
Edad: 71 Carnet: 11
Edad: 26 Carnet: 30
Edad: 16 Carnet: 2
Edad: 60 Carnet: 64


*/
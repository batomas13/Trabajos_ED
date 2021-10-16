#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <cctype> 
#include <cstdlib>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>          
#include <windows.h>
#include <stdlib.h> 
#include <math.h>
#include <sstream>
#include <random>
using namespace std;


void hola() {
	char nombre[] = "CARLOS";
	string str2(nombre);
	cout << str2.length() << endl;

	for (int i = 0; i < str2.length(); i++) {
		cout << i << endl;
	}

}
                     
void main() {             
	char buscar[] = "TOMAS";
	string str1 = buscar;
	char buscad2[31];
	hola();
	buscad2[30] = '\0';
	string str2(buscad2);
	//cout << str2.length();
}




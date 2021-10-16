#include <stdio.h>
#include <iostream>
#include <math.h>
#include <windows.h>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>
#include <string.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <string>

using namespace std;

//Globales
//**********************************************************
const int total = 30;
const int longitud = 6;
int Pistas = 0;
int Agrupacion_Pistas = 0;
int NewLetras = 0;
#define FPS 30.0

//Elementos de allegro que se utilizarán para el juego
//**********************************************************
ALLEGRO_DISPLAY* pantalla;
ALLEGRO_FONT* fuente;

//LAS SIGUIENTES DOS FUNCIONES SE USAN PARA GENERAR NUMEROS RANDOM "VERDADEROS"
//EN PERIODOS DE TIEMPO MUY CORTOS
long g_seed = 1;
inline int fastrand() {
	g_seed = (214013 * g_seed + 2531011);
	return (g_seed >> 16) & 0x7FFF;
}
char GenerarRandom()
{
	char c = 'A' + fastrand() % 24;
	return c;
}

typedef struct hilera {
	char caracter;
	int X;  //coordenada en X para el caracter de mas abajo de una hilada
	int Y;  //coordenada en Y para el caracter de mas abajo de una hilada
	int contador;  //Sirve para contar los caracteres que faltan de salir de la ventana cuando la hilera llega al final
};

void generar(hilera hilera[total])
{
	char nuevocaracter;
	for (int i = 0; i <= total; i++) {
		nuevocaracter = 33 + rand() % 93;
		hilera[i].caracter = nuevocaracter;
	}
}

void inicializar1(hilera hilera[total]) {
	for (int i = 0; i < total; i++) {
		hilera[i].X = fastrand() % 780 + 20;
		hilera[i].Y = fastrand() % 40 + 10;
		hilera[i].caracter = ' ';
		hilera[i].contador = 0;
	}
}




/*
CADA LINEA DE CARACTERES QUE VA CAYENDO SE GUARDA EN UN STACK, QUE ES UN ARREGLO DE CHAR
COMO SE VAN GENERANDO CARACTERES NUEVOS ENTONCES LOS CARACTERES EN EL STACK SE VAN DESPLAZANDO
A MODO DE UNA PILA FIFO, PERO COMO ES UN ARREGLO ENTONCES SE IMPLEMENTA MAS FACIL DE LA SIGUIENTE MANERA
*/
void desplazar(char stack[50]) {
	stack[5] = stack[4];
	stack[4] = stack[3];
	stack[3] = stack[2];
	stack[2] = stack[1];
	stack[1] = stack[0];
}

/*
DIBUJAR LO QUE HACE ES EN BASE A UN STACK DEFINIDO Y UN CONJUNTO DE COORDENADAS IMPRIME EN EL DISPLAY
LA SECUENCIA DE CARACTERES ASCII, Y A SU VEZ LLAMA A LA FUNCION DESPLAZAR PARA SACAR DEL STACK EL CARACTER MAS VIEJO Y
AÑADIR AL INICIO EL MAS NUEVO
*/
char actual[1];
void dibujar(hilera hilera[total]) {
	int o = 200;
	int count = 0;
	int x = 350;

	for (int i = 0; i < total; i++) {
		int PosX = hilera[i].X;
		int PosY = hilera[i].Y;
		actual[0] = hilera[i].caracter;
		//al_draw_text(fuente, al_map_rgb(0, 80, 0), 380, PosY -= 40, ALLEGRO_ALIGN_CENTRE, actual);
		al_draw_text(fuente, al_map_rgb(255, 255, 255), PosX, PosY, ALLEGRO_ALIGN_CENTRE, actual);
		actual[0] = hilera[i + 1].caracter;
		al_draw_text(fuente, al_map_rgb(0, 240, 0), PosX, PosY - 20, ALLEGRO_ALIGN_CENTRE, actual);
		actual[0] = hilera[i + 2].caracter;
		al_draw_text(fuente, al_map_rgb(0, 210, 0), PosX, PosY - 40, ALLEGRO_ALIGN_CENTRE, actual);
		al_draw_text(fuente, al_map_rgb(0, 180, 0), PosX, PosY - 60, ALLEGRO_ALIGN_CENTRE, actual);
		actual[0] = hilera[i + 3].caracter;
		al_draw_text(fuente, al_map_rgb(0, 150, 0), PosX, PosY - 80, ALLEGRO_ALIGN_CENTRE, actual);
		actual[0] = hilera[i + 4].caracter;
		al_draw_text(fuente, al_map_rgb(0, 120, 0), PosX, PosY - 100, ALLEGRO_ALIGN_CENTRE, actual);
		actual[0] = hilera[i + 5].caracter;
		al_draw_text(fuente, al_map_rgb(0, 90, 0), PosX, PosY - 120, ALLEGRO_ALIGN_CENTRE, actual);
		actual[0] = hilera[i + 6].caracter;
		al_draw_text(fuente, al_map_rgb(0, 50, 0), PosX, PosY - 120, ALLEGRO_ALIGN_CENTRE, actual);
		actual[0] = hilera[i + 7].caracter;
		al_draw_text(fuente, al_map_rgb(0, 30, 0), PosX, PosY - 120, ALLEGRO_ALIGN_CENTRE, actual);
		if (hilera[i].Y < 440) {
			hilera[i].Y += 20;
		}
		if (hilera[i].Y >= 440)
			hilera[i].contador++;
		if (hilera[i].contador > 1) {
			al_draw_text(fuente, al_map_rgb(255, 255, 255), hilera[i].X, PosY - (longitud - hilera[i].contador), ALLEGRO_ALIGN_CENTRE, actual);
			hilera[i].Y = rand() % 40;
			hilera[i].X = rand() % 780;
			hilera[i].contador = 0;
			o = 200;
		}
	}
	count++;
}


void guardarinventario(int Pilas, int Agrupacion_pilas, int tiempo, int letras) {
	FILE* archivo;
	fopen_s(&archivo, "archivo.txt", "w+"); 
	if (NULL == archivo) {
		printf("no se pudo abrir el archivo.");
	}
	else {
		fprintf(archivo, "%i\n", Pilas);
		fprintf(archivo, "%i\n", Agrupacion_pilas);
		fprintf(archivo, "%i\n", tiempo);
		fprintf(archivo, "%i\n", letras);
	}
	fclose(archivo);
}


int main() {
	if (!al_init()) {
		fprintf(stderr, "No se puede iniciar allegro!\n");
		return -1;
	}
	//Esta línea de código permite que la ventana tenga la capacidad de cambiar de tamaño
	al_set_new_display_flags(ALLEGRO_WINDOWED | ALLEGRO_RESIZABLE);
	pantalla = al_create_display(720, 480);
	al_set_window_position(pantalla, 200, 200);
	al_set_window_title(pantalla, "MATRIX");
	if (!pantalla) {
		fprintf(stderr, "No se puede crear la pantalla!\n");
		return -1;
	}
	//Líneas para obtener las funcionalidades del uso de las fuentes
	//*******************
	al_init_font_addon();
	al_init_ttf_addon();
	//*******************
	//Línea para obtener las funcionalidades de las imágenes
	//*******************
	al_init_image_addon();
	//*******************


	//Líneas para obtener las funcionalidades de los audios
	//*******************
	al_install_keyboard();
	al_install_audio();
	al_init_primitives_addon();
	al_init_acodec_addon();
	//*******************

	fuente = al_load_font("Georgia.ttf", 16, NULL);
	al_reserve_samples(1);
	ALLEGRO_SAMPLE* song = al_load_sample("AnyConv.com__Keyboard, typing sound effect.ogg");
	ALLEGRO_SAMPLE_INSTANCE* songInstance = al_create_sample_instance(song);

	al_set_sample_instance_playmode(songInstance, ALLEGRO_PLAYMODE_LOOP);
	al_attach_sample_instance_to_mixer(songInstance, al_get_default_mixer());
	al_play_sample_instance(songInstance);

	//Timers que se necesitarán para el juego
	//**********************************************************
	ALLEGRO_TIMER* primerTimer = al_create_timer(5 / FPS);
	ALLEGRO_TIMER* segundoTimer = al_create_timer(5.0 / FPS);
	ALLEGRO_TIMER* tercerTimer = al_create_timer(1.0 / FPS);
	//**********************************************************

	//Se crea una cola de eventos
	ALLEGRO_EVENT_QUEUE* colaEventos = al_create_event_queue();

	//Registro de los eventos
	//**********************************************************
	al_register_event_source(colaEventos, al_get_timer_event_source(primerTimer));
	al_register_event_source(colaEventos, al_get_timer_event_source(segundoTimer));
	al_register_event_source(colaEventos, al_get_timer_event_source(tercerTimer));
	al_register_event_source(colaEventos, al_get_keyboard_event_source());
	//**********************************************************

	ALLEGRO_KEYBOARD_STATE estadoTeclado;


	//Inicialización de los timer
	//**********************************************************
	al_start_timer(primerTimer);
	al_start_timer(segundoTimer);
	al_start_timer(tercerTimer);

	//**********************************************************
	bool hecho = true;
	int cont = 0;
	int tiempo_Completo;
	time_t inicio, fin;
	hilera conj_hileras[total * 2];
	inicializar1(conj_hileras);
	inicio = time(NULL);
	while (hecho) {
		ALLEGRO_EVENT eventos;
		al_wait_for_event(colaEventos, &eventos);
		if (eventos.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (eventos.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				al_clear_to_color(al_map_rgb(0, 0, 0));
				fin = time(NULL);
				tiempo_Completo = difftime(fin, inicio);
				guardarinventario(Pistas, Agrupacion_Pistas, tiempo_Completo, NewLetras);
				
				hecho = false;
				break;
			default:
				break;
			}
		}
		if (eventos.type == ALLEGRO_EVENT_TIMER) {
			if (eventos.timer.source == primerTimer) {

				al_clear_to_color(al_map_rgb(0, 0, 0));
				//AQUI VA LO QUE PASARIA EN EL EVENTO DADO POR EL PRIMER TIMER
				//AQUI VA LO QUE PASARIA EN EL EVENTO DADO POR EL PRIMER TIMER
				Pistas += 30;
				Agrupacion_Pistas += 10;
				NewLetras += 10 * 30;

				generar(conj_hileras);
				dibujar(conj_hileras);
				Sleep(1);
			}
		}
		al_flip_display();
	}
	boolean mostrar = true;
	while (mostrar) {
		ALLEGRO_EVENT eventos;
		al_wait_for_event(colaEventos, &eventos);
		if (eventos.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (eventos.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				mostrar = false;
				break;
			default:
				break;
			}
		}
		string tmp;
		string tmp2;
		string tmp3;
		string tmp4;
		char const *tiempo;
		char const *pistas;
		char const *acumulador_pistas;
		char const *letras;
		tmp = to_string(tiempo_Completo);
		tiempo = tmp.c_str();
		tmp2 = to_string(Pistas);
		pistas = tmp2.c_str();
		tmp3 = to_string(Agrupacion_Pistas);
		acumulador_pistas = tmp3.c_str();
		tmp4 = to_string(NewLetras);
		letras = tmp4.c_str();
		char actual[1];
		al_draw_text(fuente, al_map_rgb(250, 250, 15), 800 / 2, (40 * (150.0 / 768.0)), ALLEGRO_ALIGN_CENTRE, "Mostrar Resultados");
		al_draw_text(fuente, al_map_rgb(250, 250, 250), 800 / 2, (80 * (250.0 / 768.0)), ALLEGRO_ALIGN_CENTRE, "Tiempo: ");
		al_draw_text(fuente, al_map_rgb(250, 250, 250), 900 / 2, (80 * (250.0 / 768.0)), ALLEGRO_ALIGN_CENTRE, tiempo);
		al_draw_text(fuente, al_map_rgb(250, 250, 250), 800 / 2, (160 * (250.0 / 768.0)), ALLEGRO_ALIGN_CENTRE, "Pistas: ");
		al_draw_text(fuente, al_map_rgb(250, 250, 250), 900 / 2, (160 * (250.0 / 768.0)), ALLEGRO_ALIGN_CENTRE, pistas);
		al_draw_text(fuente, al_map_rgb(250, 250, 250), 800 / 2, (240 * (250.0 / 768.0)), ALLEGRO_ALIGN_CENTRE, "Agrupacion de pistas: ");
		al_draw_text(fuente, al_map_rgb(250, 250, 250), 980 / 2, (240 * (250.0 / 768.0)), ALLEGRO_ALIGN_CENTRE, acumulador_pistas);
		al_draw_text(fuente, al_map_rgb(250, 250, 250), 800 / 2, (300 * (250.0 / 768.0)), ALLEGRO_ALIGN_CENTRE, "Nuevas letras impresas: ");
		al_draw_text(fuente, al_map_rgb(250, 250, 250), 1050 / 2, (300 * (250.0 / 768.0)), ALLEGRO_ALIGN_CENTRE, letras);
		al_flip_display();
	}
	
}
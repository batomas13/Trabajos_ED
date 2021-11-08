
#include <math.h>
#include <windows.h>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>
//#include "personajes.h"

#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>



#define FPS 30.0

#define ANCHO 600
#define ALTO  600



int main(int argc, char const* argv[]) {

    ALLEGRO_DISPLAY* pantalla;

    if (!al_init()) {
        al_show_native_message_box(NULL, NULL, NULL,
            "Could not initialize Allegro5 ", NULL, NULL);
    }

    pantalla = al_create_display(ANCHO, ALTO);
    //al_set_new_display_flags(ALLEGRO_NOFRAME);
    al_set_window_position(pantalla, 200, 100);
    al_set_window_title(pantalla, "Space Invaders");

    if (!pantalla) {
        al_show_native_message_box(pantalla, "Sample Tittle", "Display Settings",
            "Display window was no created ", NULL, ALLEGRO_MESSAGEBOX_ERROR);
    }

    //L�neas para obtener las funcionalidades del uso de las fuentes
//*******************
    al_init_font_addon();
    al_init_ttf_addon();
    //*******************
    //L�nea para obtener las funcionalidades de las im�genes
    //*******************
    al_init_image_addon();
    //*******************


    // Inicializar el teclado
    al_install_keyboard();
    al_init_primitives_addon();
    ALLEGRO_KEYBOARD_STATE keyState;


    //L�neas para obtener las funcionalidades de los audios
    //*******************
    al_install_audio();
    al_init_acodec_addon();
    al_reserve_samples(1000);
    //*******************



    //Timers que se necesitar�n para el juego
    //**********************************************************
    ALLEGRO_TIMER* timer = al_create_timer(5 / FPS);

    //**********************************************************

    //Se crea una cola de eventos
    ALLEGRO_EVENT_QUEUE* colaEventos = al_create_event_queue();

    //Registro de los eventos
    //**********************************************************
    al_register_event_source(colaEventos, al_get_timer_event_source(timer));
    al_register_event_source(colaEventos, al_get_keyboard_event_source());
    al_register_event_source(colaEventos, al_get_display_event_source(pantalla));

    //**********************************************************



    //**********************************************************
    ALLEGRO_BITMAP* nave = al_load_bitmap("Recursos/nave.bmp");
    //ALLEGRO_BITMAP* buffer = al_create_bitmap(ANCHO, ALTO);
   // ALLEGRO_BITMAP* portada = al_load_bitmap("Recursos/portada.bmp");
   // ALLEGRO_BITMAP* fondo = al_load_bitmap("Recursos/fondo.bmp");
   //ALLEGRO_BITMAP* imgMuros = al_load_bitmap("Recursos/escudos.bmp");

    //ALLEGRO_SAMPLE* musicaFondo = al_load_sample("Recursos/Invaders.mid");

    bool done = false, draw = true, active = false;
    int x = 10, y = 10, moveSpeed = 5;
    int sourceX, sourceY;

    //Inicializaci�n de los timer
    //**********************************************************
    al_start_timer(timer);

    while (!done) {
        ALLEGRO_EVENT eventos;
        al_wait_for_event(colaEventos, &eventos);
        al_get_keyboard_state(&keyState);

        /* if (eventos.type == ALLEGRO_EVENT_KEY_DOWN) {
            switch (eventos.keyboard.keycode) {
            case ALLEGRO_KEY_ESCAPE:
                done = true;
                break;
            case ALLEGRO_KEY_DOWN:
                y += moveSpeed;
                break;
            case ALLEGRO_KEY_UP:
                y -= moveSpeed;
                break;
            case ALLEGRO_KEY_LEFT:
                x -= moveSpeed;
                break;
            case ALLEGRO_KEY_RIGHT:
                x += moveSpeed;
                break;

            default:
                break;
            }
        } */
        if (eventos.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            done = true;
        }
        else if (eventos.type == ALLEGRO_EVENT_TIMER) {
            if (al_key_down(&keyState, ALLEGRO_KEY_DOWN))
            {
                /* code */
            }

        }

        if (eventos.type == ALLEGRO_EVENT_TIMER) {
            al_get_keyboard_state(&keyState);
            active = true;
            if (al_key_down(&keyState, ALLEGRO_KEY_DOWN)) {
                y += moveSpeed;
            }
            else if (al_key_down(&keyState, ALLEGRO_KEY_UP)) {
                y -= moveSpeed;
            }
            else if (al_key_down(&keyState, ALLEGRO_KEY_RIGHT)) {
                x += moveSpeed;
            }
            else if (al_key_down(&keyState, ALLEGRO_KEY_LEFT)) {
                x -= moveSpeed;
            }
            else
                active = false;
            draw = true;
        }
        if (draw)
        {
            //al_draw_bitmap(nave, x, y, NULL);
            al_convert_mask_to_alpha(nave, al_map_rgb(255, 0, 255));
            al_draw_bitmap_region(nave, 0, 0, 30, 20, x, y, NULL);
            //al_draw_rectangle(x, y, x + 10, y + 10, al_map_rgb(44, 117, 225), 1);
            al_flip_display();
            al_clear_to_color(al_map_rgb(0, 0, 0));
        }




    }


    al_destroy_display(pantalla);
    al_destroy_event_queue(colaEventos);
    al_destroy_timer(timer);
    al_rest(5.0);
    return 0;
}
//
//
//    NAVE nave;
//    nave.inicializarStruct("Recursos/nave.bmp", "Recursos/bala2.bmp", 6, 12, 30, 20, ANCHO / 2, ALTO - 70, -8, 0, 3, "Recursos/shoot.wav", "Recursos/explosion.wav");
//
//    escudo escudo[30];
//    iniciarEscudo(escudo);
//
//    NAVE enemigo[60];
//    acomodarEnemigos(enemigo);
//    enemigo[0].inicializarStruct("Recursos/enemigos.bmp", "Recursos/Bala_enem.bmp", 6, 12, 25, 20, 50, 80, 8);
//    Balas disparos[nave.maxDisparos];
//    std::cout << "Enemigo maxDisp "<<enemigo[0].maxDisparos << std::endl;
//    Balas disparosEnemigo[enemigo[0].maxDisparos];
//
//    int random = rand() % 55;
//    int mov = 0;
//    int direccion = -5;
//    int velocidadJuego = 10;
//
//    play_midi(musicaFondo, 1);
//    mostrarPortada(portada);
//    while (!key[KEY_ESC]) {
//
//        clear_to_color(buffer, 0x000000); //limpiamos el buffer
//        /*Starts Control de la nave*/
//        /********************************/
//        nave.pintaNave(buffer, 0, 0);
//        nave.mueveNave();
//        crearBalaNave(nave, disparos);
//        dibujarEscudo(escudo, imgMuros, buffer);
//
//        if (enemigo[0].temporizador(velocidadJuego)) {
//            moverEnemigo(enemigo, mov, direccion);
//        }
//
//        nave.disparar(disparos, buffer);
//        for (int i = 0; i < 55; i++) {
//            if (eliminaBalaObjeto(nave, enemigo[i], disparos)) {
//                explosionEnemigo(enemigo[i], buffer);
//            }
//        }
//        eliminaBalaEscudo(nave, escudo, disparos);
//        /*Termina control de la nave*/
//
//        /********************************/
//
//        /*Starts Control del enemigo*/
//        dibujarEnemigo(enemigo, buffer, mov);
//        crearBalaEnemigo(enemigo, random);
//        enemigo[random].disparar(disparosEnemigo, buffer);
//
//        if (eliminaBalaObjeto(enemigo[random], nave, disparosEnemigo)) {
//            explosionNave(nave, buffer, fondo);
//        }
//        eliminaBalaEscudo(enemigo[random], escudo, disparosEnemigo);
//
//        mostrarFondo(fondo, buffer);
//        blit(buffer, screen, 0, 0, 0, 0, ANCHO, ALTO); //imprimir el buffer sobre la pantalla
//        
//    }

/*al_destroy_bitmap(buffer);
al_destroy_bitmap(portada);
al_destroy_bitmap(fondo);
al_destroy_bitmap(imgMuros);*/
//return 0;



//emigo
    //        dibujarEnemigo(enemigo, buffer, mov);
    //        crearBalaEnemigo(enemigo, random);
    //        enemigo[random].disparar(disparosEnemigo, buffer);
    //
    //        if (eliminaBalaObjeto(enemigo[random], nave, disparosEnemigo)) {
    //            explosionNave(nave, buffer, fondo);
    //        }
    //        eliminaBalaEscudo(enemigo[random], escudo, disparosEnemigo);
    //
    //        mostrarFondo(fondo, buffer);
    //        blit(buffer, screen, 0, 0, 0, 0, ANCHO, ALTO); //imprimir el buffer sobre la pantalla
    //        
    //    }

    /*al_destroy_bitmap(buffer);
    al_destroy_bitmap(portada);
    al_destroy_bitmap(fondo);
    al_destroy_bitmap(imgMuros);*/




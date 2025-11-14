#include <iostream>
#include "Juego.h"
#ifdef _WIN32
#include <windows.h>
#endif

int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif
    Juego juego;

    juego.iniciarRonda();
    juego.turnoJugador();
    juego.turnoCrupier();
    juego.determinarGanador();
    juego.reiniciar();

    return 0;
}
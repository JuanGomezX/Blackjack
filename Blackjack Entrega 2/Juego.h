/*
Clase: Juego
Responsabilidad: Controla el flujo general del juego:
creación de jugadores, manejo de turnos, reparto de cartas,
determinación de ganadores y reinicio de partidas.

Colaboraciones:  Contiene objetos de las clases Jugador,
 Crupier, Mazo y Apuesta. Coordina la interacción entre todas ellas.
*/

#ifndef JUEGO_H
#define JUEGO_H

#include <vector>
#include "Jugador.h"
#include "Crupier.h"
#include "Mazo.h"
#include "Apuesta.h"

class Juego
{
private:
    Jugador jugador;
    Crupier crupier;
    Mazo mazo;
    Apuesta apuesta;
    bool finRonda;

public:
    Juego();
    void iniciarRonda();
    void turnoJugador();
    void turnoCrupier();
    void determinarGanador();
    void mostrarEstadoInicial();
    void reiniciar();
};

#endif

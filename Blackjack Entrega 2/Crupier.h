/*
Clase: Crupier
Responsabilidad: Representa al crupier o la casa en el juego.
 Aplica las reglas automáticas del crupier (pedir hasta 17 puntos).

Colaboraciones:  Hereda de la clase Jugador.
 Usa la clase Mazo para tomar cartas.
*/

#ifndef CRUPIER_H
#define CRUPIER_H

#include "Jugador.h"
#include "Mazo.h"

class Crupier : public Jugador
{
public:
    Crupier();
    void jugarTurno(Mazo &mazo);
    void mostrarPrimeraCarta() const;
    bool debePedir() const;
};

#endif

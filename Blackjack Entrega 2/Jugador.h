/*
Clase: Jugador
Responsabilidad: Representa a un jugador del blackjack.
 Administra su mano de cartas, su saldo y sus apuestas.

Colaboraciones: Usa objetos de la clase Carta (su mano).
 Interactúa con las clases Apuesta y Juego.
*/

#ifndef JUGADOR_H
#define JUGADOR_H

#include <vector>
#include <string>
#include "Carta.h"

class Jugador
{
private:
    std::string nombre;
    std::vector<Carta> mano;

public:
    Jugador(std::string nombreJugador = "Jugador");
    void recibirCarta(const Carta &carta);
    int calcularValor() const;
    void mostrarMano() const;
    void limpiarMano();
    std::string getNombre() const;
    bool sePaso() const;

    // Métodos de acceso seguros (evitan acceder a 'mano' directamente)
    Carta obtenerPrimeraCarta() const { return mano.empty() ? Carta() : mano[0]; }
    bool tieneCartas() const { return !mano.empty(); }
    int cantidadCartas() const { return static_cast<int>(mano.size()); }
};

#endif

/*
Clase: Carta
Responsabilidad:  Representa una carta del mazo.
 Contiene su valor numérico y su palo.

Colaboraciones: Colabora con la clase Mazo (forma parte del mazo).
 Es utilizada por las clases Jugador y Crupier para formar sus manos.
 */

#ifndef CARTA_H
#define CARTA_H

#include <string>

class Carta
{
public:
    enum class Palo
    {
        CORAZONES,
        DIAMANTES,
        TREBOLES,
        PICAS
    };
    Carta(int rango = 1, Palo palo = Palo::PICAS);
    int getRango() const;
    Palo getPalo() const;
    int ValorBlackjack() const;
    std::string toString() const;

private:
    int rango_;
    Palo palo_;
};
#endif

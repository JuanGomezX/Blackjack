/*
Clase: Mazo
Responsabilidad: Administra la colección de cartas disponibles en el juego.
 Puede generarlas, barajarlas y repartirlas.

Colaboraciones: Contiene objetos de la clase Carta.
 Es utilizado por las clases Juego, Jugador y Crupier para entregar cartas.

*/

#ifndef MAZO_H
#define MAZO_H

#include <vector>
#include "Carta.h"

class Mazo
{
private:
    std::vector<Carta> cartas;

public:
    Mazo();
    void generarCartas();
    void barajar();
    Carta repartirCarta();
    int cartasRestantes() const;
};

#endif

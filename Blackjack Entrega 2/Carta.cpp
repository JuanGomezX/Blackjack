#include "Carta.h"
#include <sstream>
#include <string>
using namespace std;

// Constructor
Carta::Carta(int rango, Palo palo) : rango_(rango), palo_(palo) {}

int Carta::ValorBlackjack() const
{
    if (rango_ >= 11 && rango_ <= 13)
        return 10;
    return rango_;
}

string Carta::toString() const
{
    string nombreValor;

    if (rango_ == 1)
        nombreValor = "A";
    else if (rango_ == 11)
        nombreValor = "J";
    else if (rango_ == 12)
        nombreValor = "Q";
    else if (rango_ == 13)
        nombreValor = "K";
    else
        nombreValor = to_string(rango_);

    string simboloPalo;
    switch (palo_)
    {
    case Palo::CORAZONES:
        simboloPalo = u8"♥";
        break;
    case Palo::DIAMANTES:
        simboloPalo = u8"♦";
        break;
    case Palo::TREBOLES:
        simboloPalo = u8"♣";
        break;
    case Palo::PICAS:
        simboloPalo = u8"♠";
        break;
    }

    return nombreValor + simboloPalo;
}

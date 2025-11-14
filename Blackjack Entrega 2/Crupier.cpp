#include "Crupier.h"
#include <iostream>

Crupier::Crupier() : Jugador("Crupier ") {}

// Determina si el crupier debe pedir otra carta
bool Crupier::debePedir() const
{
    return calcularValor() < 17;
}

// Juega su turno automáticamente hasta tener 17 o más
void Crupier::jugarTurno(Mazo &mazo)
{
    while (debePedir())
    {
        recibirCarta(mazo.repartirCarta());
    }
}

// Muestra solo la primera carta del crupier
void Crupier::mostrarPrimeraCarta() const
{
    if (tieneCartas())
    {
        Carta c = obtenerPrimeraCarta();
        std::cout << "Carta visible del crupier: "
                  << c.toString()
                  << " (valor: " << c.ValorBlackjack() << ")"
                  << std::endl;
    }
}

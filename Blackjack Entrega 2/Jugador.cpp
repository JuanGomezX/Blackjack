#include <iostream>
#include "Jugador.h"

Jugador::Jugador(std::string nombreJugador)
{
    nombre = nombreJugador;
}

// Añade una carta a la mano del jugador

void Jugador::recibirCarta(const Carta &carta)

{
    mano.push_back(carta);
}

// Calcula el valor total de la mano del jugador
int Jugador::calcularValor() const
{
    int suma = 0;
    int ases = 0;

    for (const auto &c : mano)
    {
        int valor = c.ValorBlackjack();
        if (valor == 1) // Si es un As
            ases++;
        suma += valor;
    }

    // Si hay ases, los contamos como 11 si no nos pasamos
    while (ases > 0 && suma + 10 <= 21)
    {
        suma += 10;
        ases--;
    }
    return suma;
}

// Muestra la mano del jugador
void Jugador::mostrarMano() const
{
    std::cout << nombre << " tiene: ";
    for (const auto &c : mano)
    {
        std::cout << c.toString() << " ";
    }
    std::cout << "(valor: " << calcularValor() << ")" << std::endl;
}

// Limpia la mano del jugador
void Jugador::limpiarMano()
{
    mano.clear();
}

// Devuelve el nombre del jugador
std::string Jugador::getNombre() const
{
    return nombre;
}

// Verifica si el jugador se pasó de 21
bool Jugador::sePaso() const
{
    return calcularValor() > 21;
}

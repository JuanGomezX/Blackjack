#include "Mazo.h"
#include <algorithm> // Para std::shuffle
#include <random>    // Para std::default_random_engine
#include <chrono>    // Para semilla del generador aleatorio
#include <stdexcept> // Para lanzar excepciones si el mazo se queda vacío

// Constructor
Mazo::Mazo()
{
    generarCartas();
}

// Métodos
// Genera 52 cartas

void Mazo::generarCartas()
{
    cartas.clear();

    for (int palo = 0; palo < 4; ++palo)
    {
        for (int valor = 1; valor <= 13; ++valor)
        {
            cartas.emplace_back(valor, static_cast<Carta::Palo>(palo));
        }
    }
}

// Mezcla de las cartas

void Mazo::barajar()
{

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(cartas.begin(), cartas.end(), g);
}

// Reparte una carta del mazo
Carta Mazo::repartirCarta()
{
    if (cartas.empty())
    {
        throw std::out_of_range("No hay más cartas en el mazo.");
    }
    Carta c = cartas.back();
    cartas.pop_back();
    return c;
}

// Devuelve la cantidad de cartas restantes en el mazo
int Mazo::cartasRestantes() const
{
    return static_cast<int>(cartas.size());
}

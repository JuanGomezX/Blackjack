#include "Apuesta.h"
#include <iostream>

// Constructor
Apuesta::Apuesta(float m, float saldoInicial)
{
    monto = m;
    saldo = saldoInicial;
    resultado = "";
}

// Calcula el pago según el resultado
float Apuesta::calcularPago(bool blackjack, bool gana, bool empate)
{
    float pago = 0;
    if (blackjack)
    {
        std::cout << "¡Blackjack! Ganaste 1.5 veces tu apuesta." << std::endl;
        pago = monto * 1.5;
    }
    else if (gana)
    {
        std::cout << "Ganaste la ronda. Ganas el doble de  tu apuesta." << std::endl;
        pago = monto * 2;
    }
    else if (empate)
    {
        std::cout << "Empate. Recuperas tu apuesta." << std::endl;
        pago = monto;
    }
    else
    {
        std::cout << "Perdiste la ronda. Pierdes tu apuesta." << std::endl;
        pago = 0;
    }

    actualizarSaldo(pago);
    return pago;
}

// Devuelve el monto apostado
float Apuesta::getMonto() const
{
    return monto;
}

// Devuelve el resultado del juego
std::string Apuesta::getResultado() const
{
    return resultado;
}
// Establece el resultado del juego
void Apuesta::setResultado(std::string r)
{
    resultado = r;
}
// Muestra el saldo actual
void Apuesta::mostrarSaldo() const
{
    std::cout << "Saldo actual: " << saldo << std::endl;
}

// Devuelve el saldo actual
float Apuesta::getSaldo() const
{
    return saldo;
}

// Actualiza el saldo según el pago recibido
void Apuesta::actualizarSaldo(float pago)
{
    saldo -= monto;
    saldo += pago;
}

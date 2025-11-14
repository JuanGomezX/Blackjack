/*
Clase: Apuesta
Responsabilidad: Administra el monto apostado por el jugador y
 calcula los pagos o pérdidas según el resultado de la partida.

Colaboraciones: Se relaciona con la clase Jugador
 (cada jugador tiene una apuesta). Interactúa con la clase
 Juego para actualizar los saldos.
*/

#ifndef APUESTA_H
#define APUESTA_H

#include <iostream>
#include <string>

class Apuesta
{
private:
    float monto;
    float saldo;
    std::string resultado;

public:
    Apuesta(float m = 0, float saldoInicial = 50000);
    float calcularPago(bool blackjack, bool gana, bool empate);
    float getMonto() const;
    std::string getResultado() const;
    void setResultado(std::string r);

    void mostrarSaldo() const;
    float getSaldo() const;
    void actualizarSaldo(float pago);
};

#endif

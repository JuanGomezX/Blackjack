#include "Juego.h"
#include <iostream>
#include <limits>
#include <ctime>

Juego::Juego() : apuesta(0, 50000), finRonda(false) // Saldo inicial de 50.000 COP
{
    std::cout << "--------Bienvenido al Blackjack--------" << std::endl;
    mazo.generarCartas();
    mazo.barajar();
}

void Juego::iniciarRonda()
{
    jugador.limpiarMano();
    crupier.limpiarMano();
    mazo.barajar();

    float monto;
    std::cout << "Saldo actual: " << apuesta.getSaldo() << std::endl;
    std::cout << "Ingrese su apuesta: ";
    std::cin >> monto;

    // Se actualiza solo el monto, no el saldo
    apuesta = Apuesta(monto, apuesta.getSaldo());

    // Repartir cartas iniciales
    jugador.recibirCarta(mazo.repartirCarta());
    if (finRonda)
    {
        finRonda = false; // reset para la próxima ronda
        return;
    }

    crupier.recibirCarta(mazo.repartirCarta());
    jugador.recibirCarta(mazo.repartirCarta());
    crupier.recibirCarta(mazo.repartirCarta());
    mostrarEstadoInicial();
}

void Juego::mostrarEstadoInicial()
{
    std::cout << "\n-----Estado inicial-----" << std::endl;
    jugador.mostrarMano();
    crupier.mostrarPrimeraCarta();
}

void Juego::turnoJugador()
{
    std::string opcion;

    do
    {
        std::cout << "\n¿Deseas pedir otra carta (p) o plantarte (s)? ";
        std::cin >> opcion;

        // Limpia el buffer por si el usuario mete datos incorrectos
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // Si pide carta
        if (opcion == "p" || opcion == "P")
        {
            jugador.recibirCarta(mazo.repartirCarta());
            jugador.mostrarMano();

            if (jugador.sePaso())
            {
                std::cout << "\nTe pasaste de 21, perdiste." << std::endl;
                apuesta.calcularPago(false, false, false);
                apuesta.mostrarSaldo();
                finRonda = true;
                return; // Termina el turno del jugador
            }
        }
        // Si elige plantarse
        else if (opcion == "s" || opcion == "S")
        {
            std::cout << "\nTe has plantado con un valor de "
                      << jugador.calcularValor() << "." << std::endl;
        }
        // Si escribe algo inválido
        else
        {
            std::cout << "\n Opción inválida. Escribe 'p' para pedir o 's' para plantarte.\n";
        }

        // Repite hasta que elija 's' o se pase de 21
    } while ((opcion != "s" && opcion != "S") && !jugador.sePaso());
}

void Juego::turnoCrupier()
{
    std::cout << "\n-----Turno del Crupier-----" << std::endl;
    crupier.mostrarMano();

    while (crupier.debePedir())
    {
        std::cout << "El crupier pide una carta." << std::endl;
        crupier.recibirCarta(mazo.repartirCarta());
        crupier.mostrarMano();
    }
}

void Juego::determinarGanador()
{
    int valorJugador = jugador.calcularValor();
    int valorCrupier = crupier.calcularValor();

    std::cout << "\n--- Resultado final ---" << std::endl;
    jugador.mostrarMano();
    crupier.mostrarMano();

    bool blackjack = (valorJugador == 21 && jugador.cantidadCartas() == 2);

    if (jugador.sePaso())
    {
        apuesta.calcularPago(false, false, false);
        apuesta.setResultado("Pierde");
        std::cout << "El jugador se pasó. Gana el crupier." << std::endl;
    }
    else if (crupier.sePaso())
    {
        apuesta.calcularPago(false, true, false);
        apuesta.setResultado("Gana");
        std::cout << "El crupier se pasó. ¡Ganas la ronda!" << std::endl;
    }
    else if (valorJugador > valorCrupier)
    {
        apuesta.calcularPago(blackjack, true, false);
        apuesta.setResultado("Gana");
        std::cout << "Tu valor es mayor. ¡Ganaste!" << std::endl;
    }
    else if (valorJugador < valorCrupier)
    {
        apuesta.calcularPago(false, false, false);
        apuesta.setResultado("Pierde");
        std::cout << "El crupier tiene más valor. Perdiste." << std::endl;
    }
    else
    {
        apuesta.calcularPago(false, false, true);
        apuesta.setResultado("Empate");
        std::cout << "Empate. Se devuelve la apuesta." << std::endl;
    }

    apuesta.mostrarSaldo();
}

void Juego::reiniciar()
{
    std::cout << "\n¿Deseas jugar otra ronda? (s/n): ";
    char opcion;
    std::cin >> opcion;

    if (opcion == 's' || opcion == 'S')
    {
        jugador.limpiarMano();
        crupier.limpiarMano();
        mazo.barajar();
        iniciarRonda();
        turnoJugador();
        turnoCrupier();
        determinarGanador();
        reiniciar();
    }
    else
    {
        std::cout << "Gracias por jugar." << std::endl;
    }
}
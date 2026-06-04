#include "Sala.h"
#include "Heroe.h"
#include "Enemigo.h"
#include "Jefe.h"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <algorithm>

Sala::Sala(int numeroSala)
{
    std::cout << "Sala creada con numero: " << numeroSala << std::endl;
    this->numeroSala = numeroSala;

    if (numeroSala % 3 == 0 && numeroSala > 0)
    {
        enemigos.push_back(std::make_unique<Jefe>("Jefe"));
    }
    else if (numeroSala <= 4)
    {
        for (int i = 0; i < 2; i++)
        {
            enemigos.push_back(std::make_unique<Enemigo>("Enemigo", "Orco", 50, 20));
        }
    }
    else
    {
        for (int i = 0; i < 3; i++)
        {
            enemigos.push_back(std::make_unique<Enemigo>("Enemigo", "Orco", 60, 30));
        }
    }
}

int Sala::decision()
{
    int entradaPlayer;
    std::cout << "Que desea hacer?\n 1. Atacar.\n2. Usar Item. \nElige una opcion" << std::endl;
    std::cin >> entradaPlayer;

    while (entradaPlayer < 1 || entradaPlayer > 2)
    {
        std::cout << "Opcion no valida, ingrese una opcion valida" << std::endl;
        std::cin >> entradaPlayer;
    }

    return entradaPlayer;
}

bool Sala::combate(Heroe &player)
{
    // aleatoriamente se decide si el player recibe un item en esta sala.
    generarItem(player);
    // Contamos cuantos enemigos vivos tenemos al inicio de la funcion con un bucle for.
    int enemigosVivos = 0;
    for (int i = 0; i < enemigos.size(); i++)
    {
        if (enemigos[i]->estaVivo() == true)
        {
            enemigosVivos++;
        }
    }

    // Introducimos la Sala y anunciamos el inicio del combate.
    std::cout << "========== Sala " << numeroSala << " ==========" << std::endl;
    std::cout << "========== Combate en curso ==========" << std::endl;

    do
    {
        // comenzamos con el turno del player, pregnutando que quiere hacer, atacar o usar un item.
        std::cout << "========== TURNO " << player.getNombre() << " ==========" << std::endl;

        // recibimos la entrada del player y verificamos que sea valida.
        int entradaPlayer = decision();

        while (entradaPlayer == 2 && !player.tieneItems())
        {
            entradaPlayer = decision();
        }

        switch (entradaPlayer)
        {
        case 1:
        { // Mostramos los enemigos en batalla mediante la funcion seleccionarEnemigo.
            int objetivo = seleccionarEnemigo();

            std::cout << enemigos[objetivo - 1]->getNombre() << " seleccionado para ataque." << std::endl;
            // mostranmos habilidades de ataque y el player elige cual usar.
            player.mostrarHabilidades();
            std::cout << "Con cual de tus habilidades deseas atacar?" << std::endl;
            int opcion;
            std::cin >> opcion;
            // se entrega opcion como habilidad seleccionada y el enemigo previamente seleccionado como objetivo.
            player.usarHabilidad(opcion - 1, *enemigos[objetivo - 1]);
            if (!enemigos[objetivo - 1]->estaVivo())
            {
                enemigosVivos--;
            }

            break;
        }

        case 2:
            while (!player.tieneItems())
            {
                decision();
            }
            
            player.mostrarInv();
            std::cout << "Cual Item deseas usar?" << std::endl;
            int opcion;
            std::cin >> opcion;
            player.usarItem(opcion - 1);
            player.mostrarEstadoPersonaje();
            break;
        }

        // Iniciamos truno de los enemigos, con un For hacemos que cada enemigo ataque al player.
        for (int i = 0; i < enemigos.size(); i++)
        {
            // comprobamos que el enemigo este vivo para atacar.
            if (enemigos[i]->estaVivo() == true)
            {
                std::cout << "========== TURNO " << enemigos[i]->getNombre() << " ==========" << std::endl;
                // generamos un indice aleatorio para la habilidad del enemigo con la que atacara.
                int randomIndice = rand() % 4;
                enemigos[i]->usarHabilidad(randomIndice, player);
                player.mostrarEstadoPersonaje();
            }
        }

    } while (player.estaVivo() == true && enemigosVivos > 0);

    if (!player.estaVivo())
    {
        return false;
    }
    else
    {
        std::cout << "Todos los enemigos han sido derrotados" << std::endl;
        return true;
    }
}

void Sala::generarItem(Heroe &player)
{
    bool probabilidad = rand() % 2;
    if (!probabilidad)
    {
        return;
    }

    int indice = rand() % player.getInv().size();
    player.addItem(indice);
}

int Sala::seleccionarEnemigo()
{
    // Mostramos los enemigos en batalla mediante un for comprobando que este vivo.
    int objetivo = 0;
    for (int i = 0; i < enemigos.size(); i++)
    {
        if (!enemigos[i]->estaVivo())
        {
            std::cout << i + 1 << ". (ELIMINADO) ";
            enemigos[i]->mostrarEstadoPersonaje();
        }
        else
        {
            std::cout << i + 1 << ". ";
            enemigos[i]->mostrarEstadoPersonaje();
        }
    }

    do
    {
        std::cout << "Ingrese el numero correspondiente al enemigo que desea atacar." << std::endl;
        std::cin >> objetivo;
        // Comprobamos que el enemigo seleccionado este vivo, de lo contrario manipulamos la variable objetivo para que se cumpla la condicion del bucle.
        if (!enemigos[objetivo - 1]->estaVivo())
        {
            std::cout << "Enemigo seleccionado ya ha sido eliminado." << std::endl;
            objetivo = -1;
        }

    } while (objetivo < 0 || objetivo > enemigos.size());
    return objetivo;
}

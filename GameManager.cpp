#include <iostream>
#include "GameManager.h"

GameManager::GameManager()
{
    this->player = nullptr;
    this->sala = nullptr;
    this->numeroSala = 1;
}

std::string GameManager::crearPlayer()
{
    std::string nombrePlayer;
    int entradaPlayer;

    do
    {
        std::cout << "Ingresa el nombre para tu heroe: " << std::endl;
        std::cin >> nombrePlayer;

        std::cout << nombrePlayer << " es el nombre que ingresaste para tu Heroe, es correcto?" << std::endl;
        std::cout << "1. Si, guardar. \n 2. No, cambiar" << std::endl;
        std::cin >> entradaPlayer;

    } while (entradaPlayer == 2);

    std::cout << "Genial " << nombrePlayer << ", comnecemos!!!" << std::endl;

    return nombrePlayer;
}

void GameManager::iniciar()
{
    std::string nombrePlayer = crearPlayer();
    player = std::make_unique<Heroe>(nombrePlayer);
    std::cout << "numeroSala antes del for: " << numeroSala << std::endl;
    for (int i = 1; i <= 9; i++)
    {
        sala = std::make_unique<Sala>(numeroSala);
        if (sala->combate(*player)==true)
        {
            if (numeroSala < 9)
            {
                std::cout << "Felicidades, completaste la sala " << numeroSala << std::endl;
            }
            else
            {
                std::cout << "Felicidades, completaste todas la salas \n Game Over!" << std::endl;
            }
        }
        else
        {
            std::cout << "Estas eliminado. \n GameOver!" << std::endl;
            return;
        }
        numeroSala ++;
    }
}

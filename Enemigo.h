// Enemigo.h
#pragma once
#include "Personaje.h"

class Enemigo : public Personaje {
protected:
    std::string tipo;

public:
    Enemigo(std::string nombre, std::string tipo, int vida, int ataque);

    void usarHabilidad(int indice, Personaje &objetivo) override;
};
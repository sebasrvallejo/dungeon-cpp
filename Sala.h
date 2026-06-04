#pragma once
#include "Enemigo.h"
#include "Heroe.h"
#include <vector>
#include <memory>
#include <cstdlib>

//class Heroe;
//class Enemigo;
//class Jefe;

class Sala
{
private:
    int numeroSala;
    std::vector<std::unique_ptr<Enemigo>> enemigos;

public:
    Sala(int numeroSala);

    int decision();
    bool combate(Heroe &player);
    void estaLimpia();
    void generarItem(Heroe &player);
    int seleccionarEnemigo();
};
#pragma once
#include "Personaje.h"
#include "item.h"
#include <vector>


class Heroe : public Personaje {
private:
    int nivel;
    int turnosDescanso;
    std::vector<Item> inv;

public:
    Heroe(std::string nombre);

    int getNivel();
    std::vector<Item> getInv();
    void subirNivel();
    void usarHabilidad(int indice, Personaje &objetivo) override;
    void usarItem(int indice);
    void addItem(int indice);
    void mostrarInv();
    bool tieneItems();
};
// Jefe.h
#pragma once
#include "Enemigo.h"

class Jefe : public Enemigo {
private:
    int turno;

public:
    Jefe(std::string nombre);
    void usarHabilidad(int indice, Personaje& objetivo) override;
};
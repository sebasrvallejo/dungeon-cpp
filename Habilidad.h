#pragma once
#include <string>

enum class TipoHabilidad{
    ATAQUE,
    CURACION,
    ESCUDO,
    ESPECIAL
};

struct Habilidad
{
    std::string nombre;
    std::string descripcion;
    TipoHabilidad tipo;
    int valor;
    bool disponible;
    Habilidad(std::string nombre, std::string descripcion, TipoHabilidad tipo, int valor){
        this->nombre = nombre;
        this->descripcion = descripcion;
        this->tipo = tipo;
        this->valor = valor;
        this->disponible = true;
    }
};

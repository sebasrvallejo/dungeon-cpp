#pragma once
#include <string>

enum class TipoItem {
    POCION_PEQUENA,
    POCION_GRANDE,
    ELIXIR
};

struct Item {
    std::string nombre;
    std::string descripcion;
    TipoItem tipo;
    int valor;
    int cantidad;
    bool disponible;

    Item(std::string nombre, std::string descripcion, TipoItem tipo, int valor) {
        this->nombre = nombre;
        this->descripcion = descripcion;
        this->tipo = tipo;
        this->valor = valor;
        cantidad = 0;
        disponible = false;
    }
};



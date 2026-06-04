#include "Jefe.h"
#include <iostream>

Jefe::Jefe(std::string nombre) : Enemigo(nombre, "Jefe", 200, 40) {
    this->turno = 0;

    habilidades.clear();
    habilidades.push_back(Habilidad("Golpe Sismico", "60 dano devastador",              TipoHabilidad::ATAQUE,   60));
    habilidades.push_back(Habilidad("Furia",         "40 dano imparable",               TipoHabilidad::ATAQUE,   40));
    habilidades.push_back(Habilidad("Barrera",       "Reduce 70% el dano recibido",     TipoHabilidad::ESCUDO,   0));
    habilidades.push_back(Habilidad("Drenaje",       "Roba 30 HP del heroe",            TipoHabilidad::ESPECIAL, 30));
}

void Jefe::usarHabilidad(int indice, Personaje& objetivo) {
    turno++;
    Habilidad& hab = habilidades[indice];

    switch (hab.tipo) {
        case TipoHabilidad::ATAQUE:
            objetivo.recibirDano(hab.valor);
            mostrarMensaje(1, indice);
            break;

        case TipoHabilidad::ESCUDO:
            activarEscudo();
            mostrarMensaje(1, indice);
            break;

        case TipoHabilidad::ESPECIAL:
            objetivo.recibirDano(hab.valor);
            curar(hab.valor);
            mostrarMensaje(1, indice);
            break;
    }
}
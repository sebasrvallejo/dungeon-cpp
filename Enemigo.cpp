#include "Enemigo.h"
#include <iostream>

Enemigo::Enemigo(std::string nombre, std::string tipo, int vida, int ataque) : Personaje(nombre, vida, ataque)
{
    this->tipo = tipo;

    habilidades.push_back(Habilidad("Zarpazo", "Ataque directo de 15 dano", TipoHabilidad::ATAQUE, 15));
    habilidades.push_back(Habilidad("Mordida", "Ataque fuerte de 25 dano", TipoHabilidad::ATAQUE, 25));
    habilidades.push_back(Habilidad("Rugido", "Inhabilita el escudo del heroe", TipoHabilidad::ESPECIAL, 0));
    habilidades.push_back(Habilidad("Regenerar", "Restaura 20 HP", TipoHabilidad::CURACION, 20));
}

void Enemigo::usarHabilidad(int indice, Personaje &objetivo)
{
    Habilidad hab = habilidades[indice];

    switch (hab.tipo)
    {
    case TipoHabilidad::ATAQUE:
        objetivo.recibirDano(hab.valor);
        mostrarMensaje(1, indice);
        break;

    case TipoHabilidad::CURACION:
        curar(hab.valor);
        mostrarMensaje(1, indice);
        break;

    case TipoHabilidad::ESPECIAL:
        objetivo.desactivarEscudo();
        mostrarMensaje(1, indice);
        break;
    }
}
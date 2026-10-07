#include "Heroe.h"
#include <iostream>

Heroe::Heroe(std::string nombre) : Personaje(nombre, 100, 25)
{
    this->nivel = 1;

    habilidades.push_back(Habilidad("Espadazo", "Ataque directo de 25 dano", TipoHabilidad::ATAQUE, 25));
    habilidades.push_back(Habilidad("Golpe Brutal", "50 dano, disponible cada 2 turnos", TipoHabilidad::ATAQUE, 50));
    habilidades.push_back(Habilidad("Armadura", "Reduce 50% el dano recibido este turno", TipoHabilidad::ESCUDO, 0));
    habilidades.push_back(Habilidad("Descanso", "Restaura 40% del HP maximo", TipoHabilidad::CURACION, 0));

    inv.push_back(Item("Pocion pequena", "Restaura 30 HP", TipoItem::POCION_PEQUENA, 30));
    inv.push_back(Item("Pocion grande", "Restaura 60 HP", TipoItem::POCION_GRANDE, 60));
    inv.push_back(Item("Elixir", "Restaura todo el HP", TipoItem::ELIXIR, 0));
}

int Heroe::getNivel() { return nivel; }
std::vector<Item> Heroe::getInv() { return inv; }

void Heroe::subirNivel()
{
    nivel++;
    vidaMax += 10;
    ataque += 5;
    vida = vidaMax;
}

void Heroe::usarHabilidad(int indice, Personaje &objetivo)
{
    if (indice < 0 || indice >= habilidades.size())
    {
        std::cout << "Habilidad invalida." << std::endl;
        return;
    }

    Habilidad hab = habilidades[indice];

    if (!hab.disponible)
    {
        std::cout << hab.nombre << " no esta disponible este turno." << std::endl;
        return;
    }
    switch (hab.tipo)
    {
    case TipoHabilidad::ATAQUE:
        objetivo.recibirDano(hab.valor);
        mostrarMensaje(1, indice);
        if (indice == 1)
            habilidades[1].disponible = false;
        break;

    case TipoHabilidad::CURACION:
    {
        int cantidad = vidaMax * 0.4;
        curar(cantidad);
        mostrarMensaje(1, indice);
        break;
    }
    case TipoHabilidad::ESCUDO:
        Personaje::activarEscudo();
        mostrarMensaje(1, indice);
        break;
    }

    if (indice != 1 && !habilidades[1].disponible)
    {
        turnosDescanso++;
        if (turnosDescanso >= 2)
        {
            habilidades[1].disponible = true;
            turnosDescanso = 0;
        }
    }
}

void Heroe::usarItem(int indice)
{
    if (indice < 0 || indice > inv.size())
    {
        std::cout << "Ingrese un indice valido" << std::endl;
        return;
    }

    Item item = inv[indice];
    switch (item.tipo)
    {
    case TipoItem::POCION_GRANDE:
        if (item.disponible)
        {
            curar(item.valor);
            inv[indice].cantidad--;
            if (inv[indice].cantidad < 1)
            {
                inv[indice].disponible = false;
            }
        }
        break;

    case TipoItem::POCION_PEQUENA:
        if (item.disponible)
        {
            curar(item.valor);
            inv[indice].cantidad--;
            if (inv[indice].cantidad < 1)
            {
                inv[indice].disponible = false;
            }
        }
        break;

    case TipoItem::ELIXIR:
        if (item.disponible)
        {
            curar(vidaMax);
            inv[indice].cantidad--;
            if (inv[indice].cantidad < 1)
            {
                inv[indice].disponible = false;
            }
        }
        break;
    }

    std::cout << this->nombre << " uso " << inv[indice].nombre << " y recupero " << inv[indice].valor << " puntos de vida." << std::endl;

    turnosDescanso++;
    if (turnosDescanso >= 2)
    {
        turnosDescanso = 0;
    }
}

void Heroe::addItem(int indice)
{
    inv[indice].cantidad++;
    inv[indice].disponible = true;
}

bool Heroe::tieneItems() {
    for (int i = 0; i < inv.size(); i++) {
        if (inv[i].disponible) return true;
    }
    return false;
}

void Heroe::mostrarInv()
{
    for (int i = 0; i < inv.size(); i++)
    {
        if (inv[i].disponible == true)
        {
            std::cout << i + 1 << " ";
            std::cout << inv[i].nombre << " " << inv[i].descripcion << " " << inv[i].cantidad << std::endl;
        }
    }
}
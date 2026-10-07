#include "Personaje.h"
#include <iostream>

Personaje::Personaje(std::string nombre, int vida, int ataque)
{
    this->nombre = nombre;
    this->vida = vida;
    this->vidaMax = vida;
    this->ataque = ataque;
    this->vivo = true;
    this->escudo = false;
}

std::string Personaje::getNombre() { return nombre; }
int Personaje::getVida() { return vida; }
int Personaje::getVidaMax() { return vidaMax; }
int Personaje::getAtaque() { return ataque; }
bool Personaje::estaVivo() { return vivo; }
bool Personaje::tieneEscudo() { return escudo; }

void Personaje::recibirDano(int dano)
{
    if (!vivo)
        return;
    if (escudo)
    {
        dano = dano / 2;
        escudo = false;
    }

    vida -= dano;
    if (vida <= 0)
    {
        vida = 0;
        vivo = false;
        mostrarMensaje(2, dano);
    } else{
        mostrarEstadoPersonaje();
    }
    
}

void Personaje::activarEscudo() { escudo = true; }
void Personaje::desactivarEscudo() { escudo = false; }
/*void Personaje::atacar(Personaje &objetivo, int ataque) {
    objetivo.recibirDano(ataque);
}*/
void Personaje::curar(int valor)
{
    vida += valor;
    if (vida > vidaMax)
        vida = vidaMax;
}

void Personaje::mostrarHabilidades()
{
    for (int i = 0; i < habilidades.size(); i++)
    {
        std::cout << i + 1 << ". " << habilidades[i].nombre;
        if (!habilidades[i].disponible)
            std::cout << " (no disponible)";
        std::cout << " — " << habilidades[i].descripcion << std::endl;
    }
}

void Personaje::mostrarMensaje(int tipoMensaje, int valor)
{

    switch (tipoMensaje)
    {
    case 1:
        std::cout << this->nombre << " uso " << habilidades[valor].nombre << ", " << habilidades[valor].descripcion << std::endl;
        break;

    case 2:
        std::cout << this->nombre << " recibio " << valor << " de dano." << std::endl;
        mostrarEstadoPersonaje();
        break;
    }
}

void Personaje::mostrarEstadoPersonaje()
{
    std::cout << "|| " << this->nombre << " || vida: " << this->vida << " ||" << std::endl;
    if (this->vida <= 0)
    {
        std::cout << this->nombre << " ha sido eliminado." << std::endl;
    }
    
}
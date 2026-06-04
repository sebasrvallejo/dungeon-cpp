#pragma once
#include "Habilidad.h"
#include <vector>

class Personaje
{
protected:
    std::string nombre;
    int vida;
    int vidaMax;
    int ataque;
    bool vivo;
    bool escudo;
    std::vector<Habilidad> habilidades;

public:
    Personaje(std::string nombre, int vida, int ataque);

    // getters
    std::string getNombre();
    int getVida();
    int getVidaMax();
    int getAtaque();
    bool estaVivo();
    bool tieneEscudo();

    virtual void recibirDano(int dano);
    void activarEscudo();
    void desactivarEscudo();
    //void atacar(Personaje &objetivo, int ataque);
    virtual void usarHabilidad(int indice, Personaje& objetivo) = 0;
    void curar(int valor);
    void mostrarHabilidades();
    void mostrarMensaje(int tipoMensaje, int valor);
    void mostrarEstadoPersonaje();
};

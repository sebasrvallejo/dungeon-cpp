#include "Habilidad.h"
#include "Personaje.h"
#include <iostream>

Habilidad::Habilidad(std::string nombre, std::string descripcion, TipoHabilidad tipo, int valor)
{
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->tipo = tipo;
    this->valor = valor;
    this->disponible = true;
}

void combate(TipoHabilidad habilidad, Personaje *objetivo, int ataque){
    Personaje *pObjetivo = objetivo;
    switch (habilidad)
    {
    case TipoHabilidad::ATAQUE:
        //Habilidad::atacar(*pObjetivo, ataque);
        break;
    
    default:
        break;
    }
}
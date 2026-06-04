#include "Heroe.h"
#include "Sala.h"

class GameManager {
private:
    Heroe *player;
    Sala *sala;
    int numeroSala;

public:
    GameManager();
    std::string crearPlayer();
    void iniciar();
};
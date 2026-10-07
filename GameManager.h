#include "Heroe.h"
#include "Sala.h"
#include <memory>

class GameManager {
private:
    std::unique_ptr<Heroe> player;
    std::unique_ptr<Sala> sala;
    int numeroSala;

public:
    GameManager();
    std::string crearPlayer();
    void iniciar();
};
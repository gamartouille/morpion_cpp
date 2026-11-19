#pragma once
#include <memory>
#include "Grille.h"
#include "Joueur.h"

class Partie {
public:
    explicit Partie(int dimension = 3);
    void lancer();

private:
    void choisir_mode();

    Grille m_grille;
    std::unique_ptr<Joueur> m_joueurs[2];
    int m_courant = 0;
};
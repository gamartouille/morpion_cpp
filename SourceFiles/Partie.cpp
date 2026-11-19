#include "Partie.h"
#include <iostream>

Partie::Partie(int dimension) : m_grille(dimension) {
    choisir_mode();
}

void Partie::choisir_mode() {
    int mode = 0;
    while (mode != 1 && mode != 2) {
        std::cout << "1 : Joueur vs Bot\n2 : Joueur vs Joueur\nChoix : ";
        if (!(std::cin >> mode)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
    }
    m_joueurs[0] = std::make_unique<Humain>('X');
    if (mode == 1) m_joueurs[1] = std::make_unique<Bot>('O');
    else           m_joueurs[1] = std::make_unique<Humain>('O');
}

void Partie::lancer() {
    while (true) {
        m_grille.afficher_grille();
        Joueur& j = *m_joueurs[m_courant];

        j.placer_case(m_grille);

        if (m_grille.victoire(j.symbole())) {
            m_grille.afficher_grille();
            std::cout << j.nom() << " (" << j.symbole() << ") a gagne !\n";
            return;
        }
        if (m_grille.grille_remplie()) {
            m_grille.afficher_grille();
            std::cout << "Match nul.\n";
            return;
        }
        m_courant = 1 - m_courant;
    }
}
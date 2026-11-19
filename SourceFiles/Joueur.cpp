#include "Joueur.h"
#include <iostream>
#include <limits>
#include <utility>
#include <vector>

Humain::Humain(char symbole) : Joueur(symbole) {
    std::cout << "Pseudo du joueur " << symbole << " : ";
    std::cin >> m_pseudo;
}

void Humain::placer_case(Grille& grille) {
    while (true) {
        int l, c;
        std::cout << m_pseudo << " (" << m_symbole << "), ligne puis colonne : ";
        if (!(std::cin >> l >> c)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entree invalide.\n";
            continue;
        }
        if (grille.poser(l - 1, c - 1, m_symbole)) return;
        std::cout << "Position invalide ou deja occupee.\n";
    }
}

void Bot::placer_case(Grille& grille) {
    std::vector<std::pair<int,int>> libres;
    for (int l = 0; l < grille.dimension(); l++)
        for (int c = 0; c < grille.dimension(); c++)
            if (grille.case_libre(l, c)) libres.emplace_back(l, c);

    if (libres.empty()) return;
    std::uniform_int_distribution<size_t> dist(0, libres.size() - 1);
    auto [l, c] = libres[dist(m_gen)];
    grille.poser(l, c, m_symbole);
    std::cout << "Le bot joue en " << l + 1 << " " << c + 1 << "\n";
}
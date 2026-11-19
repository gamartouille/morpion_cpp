#include "Grille.h"
#include <iostream>
#include <vector>

Grille::Grille (int dimension) {
    this->dimension = dimension;
    creer_grille();
}

Grille::~Grille () {
    std::cout << "Bye bye gar";

}

void Grille::creer_grille() {
    tab = std::vector<std::vector<char>>(
        dimension, std::vector<char>(dimension, '.')
    );
}

void Grille::afficher_grille() {

    // Affichage des numéros des colonnes
    std::cout << "     ";

    for (int j = 0; j < dimension; j++) {
        std::cout << j + 1 << "   ";
    }

    std::cout << '\n';

    // Affichage des lignes
    for (int i = 0; i < dimension; i++) {

        // Bordure supérieure
        std::cout << "   ";

        for (int j = 0; j < dimension; j++) {
            std::cout << "+---";
        }

        std::cout << "+\n";

        // Contenu des cases
        std::cout << " " << i + 1 << " ";

        for (int j = 0; j < dimension; j++) {
            std::cout << "| " << tab[i][j] << " ";
        }

        std::cout << "|\n";
    }

    // Dernière bordure
    std::cout << "   ";

    for (int j = 0; j < dimension; j++) {
        std::cout << "+---";
    }

    std::cout << "+\n";
}
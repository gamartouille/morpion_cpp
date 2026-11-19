#include "Grille.h"
#include <iostream>
#include <random>
#include <vector>

Grille::Grille (int dimension) {
    this->m_dimension = dimension;
    creer_grille();
}

Grille::~Grille () {
    std::cout << "Bye bye gar";

}

void Grille::creer_grille() {
    tab = std::vector<std::vector<char>>(
        m_dimension, std::vector<char>(m_dimension, '.')
    );
}

void Grille::afficher_grille() {

    // Affichage des numéros des colonnes
    std::cout << "     ";

    for (int j = 0; j < m_dimension; j++) {
        std::cout << j + 1 << "   ";
    }

    std::cout << '\n';

    // Affichage des lignes
    for (int i = 0; i < m_dimension; i++) {

        // Bordure supérieure
        std::cout << "   ";

        for (int j = 0; j < m_dimension; j++) {
            std::cout << "+---";
        }

        std::cout << "+\n";

        // Contenu des cases
        std::cout << " " << i + 1 << " ";

        for (int j = 0; j < m_dimension; j++) {
            std::cout << "| " << tab[i][j] << " ";
        }

        std::cout << "|\n";
    }

    // Dernière bordure
    std::cout << "   ";

    for (int j = 0; j < m_dimension; j++) {
        std::cout << "+---";
    }

    std::cout << "+\n";

};

void Grille::ajouter_elem_bot() {

    std::random_device rd;                 
    std::mt19937 gen(rd());                 
    std::uniform_int_distribution<> dist(0, 2);

    m_compteur_tours+=1;
    int position_x = dist(gen);
    int position_y = dist(gen);
    std::string signe_joueur;

    if (m_compteur_tours % 2 == 0) {
        std::string signe_joueur = "X";
    } else {
        std::string signe_joueur = "O";
    }

    if (tab[position_x][position_y] != '.') {
        ajouter_elem_bot();
    }
    else {
        //Insertion de la valeur de signe_joueur dans le vecteur grille
        std::copy( signe_joueur.begin(), signe_joueur.end(), std::back_inserter(tab[position_x][position_y]));
    }

};

void Grille::ajouter_elem_joueur(int positionx, int positiony) {
    
    m_compteur_tours+=1;
    std::string signe_joueur;

    if (m_compteur_tours % 2 == 0) {
        std::string signe_joueur = "X";
    } else {
        std::string signe_joueur = "O";
    }

    if (tab[positionx][positiony] != '.') {
        std::cout << "Mettre une position valide";
    }
    else {
        std::copy( signe_joueur.begin(), signe_joueur.end(), std::back_inserter(tab[positionx][positiony]));
    }
};

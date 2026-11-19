#include "Grille.h"
#include <iostream>
#include <vector>
#include <random>

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

std::string Grille::ajouter_elem_bot() {

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

    if (tab[position_y][position_y] != '.') {
        ajouter_elem_bot();
    }

    return signe_joueur;

};

void Grille::ajouter_elem_joueur(int positionx, int positiony) {
    
    if (tab[positionx][positiony] != '.') {
        std::cout << "Mettre une position valide";
    }
    else {

    }
};

bool Grille::grille_remplie() const {
    for (const auto& ligne : tab)
        for (char x : ligne)
            if (x == '.') return false;
    return true;
}

bool Grille::case_libre(int l, int c) const {
    return l >= 0 && l < m_dimension && c >= 0 && c < m_dimension && tab[l][c] == '.';
}

bool Grille::poser(int l, int c, char symbole) {
    if (!case_libre(l, c)) return false;
    tab[l][c] = symbole;
    return true;
}

bool Grille::victoire(char s) const {
    const int n = m_dimension;
    for (int i = 0; i < n; i++) {
        bool ligne = true, col = true;
        for (int j = 0; j < n; j++) {
            ligne &= (tab[i][j] == s);
            col   &= (tab[j][i] == s);
        }
        if (ligne || col) return true;
    }
    bool d1 = true, d2 = true;
    for (int i = 0; i < n; i++) {
        d1 &= (tab[i][i] == s);
        d2 &= (tab[i][n - 1 - i] == s);
    }
    return d1 || d2;
}
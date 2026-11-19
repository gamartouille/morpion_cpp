#include "Grille.h"
#include <iostream>
#include <random>

Grille::Grille () {
    std::cout << "Hello gar";

}

Grille::~Grille () {
    std::cout << "Bye bye gar";

}

void Grille::ajouter_elem_bot(){

    std::random_device rd;                 
    std::mt19937 gen(rd());                 
    std::uniform_int_distribution<> dist(0, 2);

    compteur_tours+=1;
    int position_x = dist(gen);
    int position_y = dist(gen);
    std::string signe_joueur;

    if (compteur_tours % 2 == 0) {
        std::string signe_joueur = "X";
    } else {
        std::string signe_joueur = "O";
    }

    if (tab[position_x][position_y] != "-") {
        ajouter_elem_bot();
    }

    return [signe_joueur, position_x, position_y];

};

void Grille::ajouter_elem_joueur(position_x, position_y) {
    
    if (tab[position_x][position_y] != "-") {
        std::cout << "Mettre une position valide";
    }
    else {

    }
}
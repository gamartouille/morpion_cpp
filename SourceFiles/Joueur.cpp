#include "Joueur.h"
#include <iostream>
#include "Grille.h"
#include <random>

Joueur::Joueur () {
}

Joueur::~Joueur() {
    
}

Humain::Humain () {
    //Demander au joueur son pseudo
    std::string pseudo;
    std::cout << "Quel est votre pseudo ?";
    std::cin >> pseudo;
}

void Humain::placer_case(Grille grille) {

    grille.m_compteur_tours+=1;
    std::string signe_joueur;
    int positionx;
    int positiony;
    std::cout << "Quelle ligne voulez-vous remplir";
    std::cin >> positionx;
    std::cout << "Quelle colonne voulez-vous remplir";
    std::cin >> positiony;

    if (grille.m_compteur_tours % 2 == 0) {
        std::string signe_joueur = "X";
    } else {
        std::string signe_joueur = "O";
    }

    if (grille.tab[positionx][positiony] != '.') {
        std::cout << "Mettre une position valide";
    }
    else {
        std::copy( signe_joueur.begin(), signe_joueur.end(), std::back_inserter(grille.tab[positionx][positiony]));
    }
}

void Bot::placer_case(Grille grille) {

    std::random_device rd;                 
    std::mt19937 gen(rd());                 
    std::uniform_int_distribution<> dist(0, 2);

    grille.m_compteur_tours+=1;
    int position_x = dist(gen);
    int position_y = dist(gen);
    std::string signe_joueur;

    if (grille.m_compteur_tours % 2 == 0) {
        std::string signe_joueur = "X";
    } else {
        std::string signe_joueur = "O";
    }

    if (grille.tab[position_x][position_y] != '.') {
        placer_case();
    }
    else {
        //Insertion de la valeur de signe_joueur dans le vecteur grille
        std::copy( signe_joueur.begin(), signe_joueur.end(), std::back_inserter(grille.tab[position_x][position_y]));
    }
}
#pragma once
#include <vector>
#include <string>

class Grille{

    public :
    /**
     * @brief Construct a new my Grille object
     * 
     *
     */
    Grille (int dimension = 3);

    /**
     * @brief Destroy the my Grille object
     * 
     */
    ~Grille();

    void creer_grille();
    void afficher_grille();
    void ajouter_elem_joueur(int positionx, int positiony);
    std::string ajouter_elem_bot();
    int  dimension() const { return m_dimension; }
    bool case_libre(int l, int c) const;
    bool poser(int l, int c, char symbole);   // false si invalide
    bool grille_remplie() const;
    bool victoire(char symbole) const;

    int m_compteur_tours;
    std::vector<std::vector<char>> tab;


    private :
        int m_dimension;
};
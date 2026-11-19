#include <vector>
#include <string>

class Grille{

    public :
    /**
     * @brief Construct a new my Grille object
     * 
     *
     */
    Grille (int dimension);

    /**
     * @brief Destroy the my Grille object
     * 
     */
    ~Grille();

    void creer_grille();
    void afficher_grille();
    void ajouter_elem_bot();
    void ajouter_elem_joueur(int positionx, int positiony);

    int m_compteur_tours;
    std::vector<std::vector<char>> tab;


    private :
        int m_dimension;
};
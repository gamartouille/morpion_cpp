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
    std::string ajouter_elem_bot();
    void ajouter_elem_joueur(int positionx, int positiony);
    bool grille_remplie();

    private :
        std::vector<std::vector<char>> tab;
        int m_dimension;
        int m_compteur_tours;
};
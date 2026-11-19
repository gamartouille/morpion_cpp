#include <vector>

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
    private :
        int dimension;
        std::vector<std::vector<char>> tab;
};
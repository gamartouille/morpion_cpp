#include <iostream>

class Joueur {
public:
    void placer_case(Grille grille);
};

class Humain : public Joueur {
public : 
    std::string pseudo;
    void placer_case(Grille grille);
};

class Bot : public Joueur {
public :
    void placer_case(Grille grille);
};
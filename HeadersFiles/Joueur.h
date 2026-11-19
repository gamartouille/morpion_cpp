#pragma once
#include <string>
#include <random>
#include "Grille.h"

class Joueur {
public:
    explicit Joueur(char symbole) : m_symbole(symbole) {}
    virtual ~Joueur() = default;
    virtual void placer_case(Grille& grille) = 0;
    virtual std::string nom() const = 0;
    char symbole() const { return m_symbole; }
protected:
    char m_symbole;
};

class Humain : public Joueur {
public:
    Humain(char symbole);
    void placer_case(Grille& grille) override;
    std::string nom() const override { return m_pseudo; }
private:
    std::string m_pseudo;
};

class Bot : public Joueur {
public:
    Bot(char symbole) : Joueur(symbole), m_gen(std::random_device{}()) {}
    void placer_case(Grille& grille) override;
    std::string nom() const override { return "Bot"; }
private:
    std::mt19937 m_gen;
};
#ifndef BARALHO_HPP
#define BARALHO_HPP

#include "Cartas.hpp"
#include <vector>
#include <iostream>

using namespace std;

class Baralho{
    protected:
    vector <Carta> _cartas (60);
    string _nome;

    public:
    Baralho(vector <Carta> cartasP, string nomeP);
    ~Baralho();
    string getNome();
    void setNome(string nomeP);
};
#endif